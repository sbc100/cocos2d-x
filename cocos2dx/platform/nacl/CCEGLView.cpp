/*
 * based on linux/CCEGLView.cpp
 *
 *  Created on: Aug 8, 2011
 *      Author: laschweinski
 */

#include "CCEGLView.h"
#include "CCGL.h"
#include "ccMacros.h"
#include "CCDirector.h"
#include "CCInstance.h"
#include "touch_dispatcher/CCTouch.h"
#include "touch_dispatcher/CCTouchDispatcher.h"
#include "text_input_node/CCIMEDispatcher.h"

#include "ppapi/c/ppb_opengles2.h"
#include "ppapi/cpp/graphics_3d.h"
#include "ppapi/cpp/graphics_3d_client.h"
#include "ppapi/cpp/size.h"
#include "ppapi/cpp/module.h"
#include "ppapi/cpp/completion_callback.h"
#include "ppapi/gles2/gl2ext_ppapi.h"

class OpenGLContext : public pp::Graphics3DClient
{
public:
    OpenGLContext(pp::Instance* instance, int width, int height);
    ~OpenGLContext();

    virtual void Graphics3DContextLost()
    {
        assert(!"Unexpectedly lost graphics context");
    }

    bool MakeContextCurrent();
    void InvalidateContext();
    void ResizeContext(int width, int height);
    void FlushContext();
private:
    pp::Graphics3D m_context;
    const struct PPB_OpenGLES2* m_gles2_interface;
    pp::Instance* m_instance;
    int m_width;
    int m_height;
};

OpenGLContext::OpenGLContext(pp::Instance* instance, int width, int height) :
   pp::Graphics3DClient(instance), m_instance(instance), m_width(width), m_height(height)
{
    pp::Module* module = pp::Module::Get();
    assert(module);
    m_gles2_interface = static_cast<const struct PPB_OpenGLES2*>(
            module->GetBrowserInterface(PPB_OPENGLES2_INTERFACE));
    assert(m_gles2_interface);
}

OpenGLContext::~OpenGLContext()
{
    CCLOG("OpenGLContext::~OpenGLContext");
    glSetCurrentContextPPAPI(0);
}

bool OpenGLContext::MakeContextCurrent()
{
    CCLOG("OpenGLContext::MakeContextCurrent %dx%d", m_width, m_height);

    // Lazily create the Pepper context.
    if (m_context.is_null())
    {
        int32_t attribs[] = {
            PP_GRAPHICS3DATTRIB_ALPHA_SIZE, 8,
            PP_GRAPHICS3DATTRIB_DEPTH_SIZE, 24,
            PP_GRAPHICS3DATTRIB_STENCIL_SIZE, 8,
            PP_GRAPHICS3DATTRIB_SAMPLES, 0,
            PP_GRAPHICS3DATTRIB_SAMPLE_BUFFERS, 0,
            PP_GRAPHICS3DATTRIB_WIDTH, m_width,
            PP_GRAPHICS3DATTRIB_HEIGHT, m_height,
            PP_GRAPHICS3DATTRIB_NONE
        };
        m_context = pp::Graphics3D(m_instance, pp::Graphics3D(), attribs);
        if (m_context.is_null())
        {
            glSetCurrentContextPPAPI(0);
            return false;
        }
        bool rtn = m_instance->BindGraphics(m_context);
        assert(rtn && "BindGraphics failed");
        if (!rtn)
          return false;
    }

    CCLOG("glSetCurrentContextPPAPI: %p", m_context.pp_resource());
    glSetCurrentContextPPAPI(m_context.pp_resource());
    return true;
}

void OpenGLContext::InvalidateContext()
{
    CCLOG("InvalidateContext");
    glSetCurrentContextPPAPI(0);
}

void OpenGLContext::ResizeContext(int width, int height)
{
    CCLOG("OpenGLContext::ResizeContext %d %d", width, height);
    if (!m_context.is_null())
    {
        m_context.ResizeBuffers(width, height);
    }
}

void OpenGLContext::FlushContext()
{
    //CCLOG("OpenGLContext::FlushContext");
    m_context.SwapBuffers(pp::BlockUntilComplete());
}


NS_CC_BEGIN

CCEGLView::CCEGLView() : bIsInit(false), bIsMouseDown(false), m_fFrameZoomFactor(1.0f), m_context(NULL)
{
    CCLOG("CCEGLView::CCEGLView");
    pthread_mutex_init(&m_mutex, NULL);
}

CCEGLView::~CCEGLView()
{
}

void CCEGLView::setFrameSize(float width, float height)
{
    CCLOG("CCEGLView::setFrameSize %f %f", width, height);
    CCEGLViewProtocol::setFrameSize(width, height);
    initGL((int)width, (int)height);
}

void CCEGLView::setViewPortInPoints(float x , float y , float w , float h)
{
    glViewport((GLint)(x * m_fScaleX * m_fFrameZoomFactor+ m_obViewPortRect.origin.x * m_fFrameZoomFactor),
            (GLint)(y * m_fScaleY * m_fFrameZoomFactor + m_obViewPortRect.origin.y * m_fFrameZoomFactor),
            (GLsizei)(w * m_fScaleX * m_fFrameZoomFactor),
            (GLsizei)(h * m_fScaleY * m_fFrameZoomFactor));
}

void CCEGLView::setScissorInPoints(float x , float y , float w , float h)
{
    glScissor((GLint)(x * m_fScaleX * m_fFrameZoomFactor + m_obViewPortRect.origin.x * m_fFrameZoomFactor),
            (GLint)(y * m_fScaleY * m_fFrameZoomFactor + m_obViewPortRect.origin.y * m_fFrameZoomFactor),
            (GLsizei)(w * m_fScaleX * m_fFrameZoomFactor),
            (GLsizei)(h * m_fScaleY * m_fFrameZoomFactor));
}


bool CCEGLView::isOpenGLReady()
{
    return bIsInit;
}

void CCEGLView::end()
{
    delete this;
    exit(0);
}

void CCEGLView::swapBuffers()
{
    if (!bIsInit)
        return;

    m_context->FlushContext();
}

void CCEGLView::setIMEKeyboardState(bool bOpen)
{
}

bool CCEGLView::initGL(int width, int height)
{
    CCLOG("initGL: instance=%p", g_instance);
    if (m_context == NULL)
      m_context = new OpenGLContext(g_instance, width, height);
    CCLOG("initGL: m_context=%p", m_context);
    bool rtn = m_context->MakeContextCurrent();
    m_context->ResizeContext(width, height);
    CCLOG("MakeContextCurrent returned: %d", rtn);
    assert(rtn == true && "MakeContextCurrent failed");
    if (!rtn)
      return false;
    bIsInit = true;
    return true;
}

void CCEGLView::destroyGL()
{
    delete m_context;
    bIsInit = false;
    CCLOG("destroyGL");
}

CCEGLView* CCEGLView::sharedOpenGLView()
{
    static CCEGLView* s_pEglView = NULL;
    if (s_pEglView == NULL)
    {
        CCLOG("creating CCEGLView");
        s_pEglView = new CCEGLView();
    }
    return s_pEglView;
}


void CCEGLView::ProcessEventQueue()
{
    pthread_mutex_lock(&m_mutex);
    while (m_event_queue.size())
    {
        pp::InputEvent event = m_event_queue.front();
        m_event_queue.pop();
        PP_InputEvent_Type type = event.GetType();
        switch (type)
        {
            case PP_INPUTEVENT_TYPE_MOUSEDOWN:
            case PP_INPUTEVENT_TYPE_MOUSEUP:
            case PP_INPUTEVENT_TYPE_MOUSEMOVE:
                {
                    pp::MouseInputEvent* mouse_event = reinterpret_cast<pp::MouseInputEvent*>(&event);
                    pp::Point pos = mouse_event->GetPosition();
                    float x = pos.x();
                    float y = pos.y();
                    int touchID = 1;
                    //CCLOG("touchevent at: %.0f %.0f", x, y);
                    switch (type)
                    {
                        case PP_INPUTEVENT_TYPE_MOUSEDOWN:
                            handleTouchesBegin(1, &touchID, &x, &y);
                            bIsMouseDown = true;
                            break;
                        case PP_INPUTEVENT_TYPE_MOUSEUP:
                            handleTouchesEnd(1, &touchID, &x, &y);
                            bIsMouseDown = false;
                            break;
                        case PP_INPUTEVENT_TYPE_MOUSEMOVE:
                            if (bIsMouseDown)
                                handleTouchesMove(1, &touchID, &x, &y);
                            break;
                        default:
                            break;
                    }
                    break;
                }
            default:
                CCLOG("unhandled event type: %d", type);
                break;
        }
    }
    pthread_mutex_unlock(&m_mutex);
}

void CCEGLView::AddEvent(const pp::InputEvent& event)
{
    pthread_mutex_lock(&m_mutex);
    m_event_queue.push(event);
    pthread_mutex_unlock(&m_mutex);
}

CocosPepperInstance* CCEGLView::g_instance;

NS_CC_END
