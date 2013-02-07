#include "platform/CCCommon.h"
#include "CCInstance.h"
#include "CCEGLView.h"
#include <ppapi/cpp/instance.h>
#include <ppapi/cpp/module.h>
#ifndef OLD_NACL_MOUNTS
#include "nacl_io/nacl_io.h"
#endif

#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

USING_NS_CC;

CocosPepperInstance::CocosPepperInstance(PP_Instance instance) : pp::Instance(instance),
#ifdef OLD_NACL_MOUNTS
    m_runner(NULL),
#endif
    m_running(false)
{
    RequestInputEvents(PP_INPUTEVENT_CLASS_MOUSE);
    RequestFilteringInputEvents(PP_INPUTEVENT_CLASS_KEYBOARD);
}

void CocosPepperInstance::DidChangeView(const pp::View& view)
{
    pp::Rect position = view.GetRect();
    if (m_size == position.size())
    {
        // Size did not change.
        return;
    }

    if (m_running)
    {
        CCLOG("DidChangeView (%dx%d) while cocos thread already running",
               position.size().width(), position.size().height());
        return;
    }

    m_size = position.size();
    CCLOG("DidChangeView %dx%d", m_size.width(), m_size.height());
    pthread_create(&m_cocos_thread, NULL, cocos_main, this);
    m_running = true;
}


bool CocosPepperInstance::Init(uint32_t argc, const char* argn[], const char* argv[])
{
    CCLOG("CocosPepperInstance::Init");
#ifdef OLD_NACL_MOUNTS
    m_runner = new MainThreadRunner(this);
#else
    CCLOG("%p %p", pp_instance(), pp::Module::Get()->get_browser_interface());
    nacl_io_init_ppapi(pp_instance(), pp::Module::Get()->get_browser_interface());
    CCLOG("done nacl_mounts_init_ppapi");


    umount("/");
    int rtn = mount("Resources",  /* source. Use relative URL */
          "/",  /* target */
          "httpfs",  /* filesystemtype */
          0,  /* mountflags */
          "");  /* data */

    if (rtn != 0)
    {
        CCLOG("mount failed: %d %s", errno, strerror(errno));
        return false;
    }

#endif
    return true;
}

bool CocosPepperInstance::HandleInputEvent(const pp::InputEvent& event)
{
    CCEGLView::sharedOpenGLView()->AddEvent(event);
    return true;
}

