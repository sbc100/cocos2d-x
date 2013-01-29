#include "platform/CCCommon.h"
#include "CCInstance.h"
#include "CCEGLView.h"
#include <ppapi/cpp/instance.h>
#include <ppapi/cpp/module.h>
#ifndef OLD_NACL_MOUNTS
#include "nacl_mounts/nacl_mounts.h"
#endif

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

USING_NS_CC;

CocosPepperInstance::CocosPepperInstance(PP_Instance instance) : pp::Instance(instance),
#ifdef OLD_NACL_MOUNTS
    m_runner(NULL),
#endif
    m_running(false)
{
    RequestInputEvents(PP_INPUTEVENT_CLASS_MOUSE);
    RequestFilteringInputEvents(PP_INPUTEVENT_CLASS_KEYBOARD);

#ifndef OLD_NACL_MOUNTS
    CCLOG("%p %p", pp_instance(), pp::Module::Get()->get_browser_interface());
    nacl_mounts_init_ppapi(pp_instance(), pp::Module::Get()->get_browser_interface());
    open("/dev/null", O_RDONLY);  // should return 0==STDIN
    open("/dev/console0", O_WRONLY);  // should return 1==STDOUT
    open("/dev/console3", O_WRONLY);  // should return 2==STDERR
    CCLOG("done nacl_mounts_init_ppapi");
#endif
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
               m_size.width(), m_size.height());
        return;
    }

    CCLOG("DidChangeView %dx%d", m_size.width(), m_size.height());
    m_size = position.size();
    pthread_create(&m_cocos_thread, NULL, cocos_main, this);
    m_running = true;
}


bool CocosPepperInstance::Init(uint32_t argc, const char* argn[], const char* argv[])
{
#ifdef OLD_NACL_MOUNTS
    m_runner = new MainThreadRunner(this);
#endif

    CCLOG("CocosPepperInstance::Init");
    return true;
}

bool CocosPepperInstance::HandleInputEvent(const pp::InputEvent& event)
{
    CCEGLView::sharedOpenGLView()->AddEvent(event);
    return true;
}

