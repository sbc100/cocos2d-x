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
#include "touch_dispatcher/CCTouch.h"
#include "touch_dispatcher/CCTouchDispatcher.h"
#include "text_input_node/CCIMEDispatcher.h"

NS_CC_BEGIN

CCEGLView::CCEGLView()
: bIsInit(false)
, m_fFrameZoomFactor(1.0f)
{
}

CCEGLView::~CCEGLView()
{
}

void CCEGLView::setFrameSize(float width, float height)
{
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

    /* Swap buffers */
}

void CCEGLView::setIMEKeyboardState(bool bOpen)
{
}

bool CCEGLView::initGL()
{
    return true;
}

void CCEGLView::destroyGL()
{
}

CCEGLView* CCEGLView::sharedOpenGLView()
{
    static CCEGLView* s_pEglView = NULL;
    if (s_pEglView == NULL)
    {
        s_pEglView = new CCEGLView();
    }
    return s_pEglView;
}

NS_CC_END
