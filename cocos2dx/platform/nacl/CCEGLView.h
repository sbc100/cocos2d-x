/*
 * CCEGLView.h
 *
 *  Created on: Aug 8, 2011
 *      Author: laschweinski
 */

#ifndef CCEGLVIEW_H_
#define CCEGLVIEW_H_

#include "platform/CCCommon.h"
#include "cocoa/CCGeometry.h"
#include "platform/CCEGLViewProtocol.h"
#include "CCInstance.h"

#include "ppapi/cpp/instance.h"

bool initExtensions();

class OpenGLContext;

NS_CC_BEGIN

class CCEGLView : public CCEGLViewProtocol
{
public:
    CCEGLView();
    virtual ~CCEGLView();

    /**
     * iPixelWidth, height: the window's size
     * iWidth ,height: the point size, which may scale.
     * iDepth is not the buffer depth of opengl, it indicate how may bits for a pixel
     */
    virtual void setFrameSize(float width, float height);
    virtual void setViewPortInPoints(float x , float y , float w , float h);
    virtual void setScissorInPoints(float x , float y , float w , float h);

    /*
     * Set zoom factor for frame. This method is for debugging big resolution (e.g.new ipad) app on desktop.
     */
    virtual bool isOpenGLReady();
    virtual void end();
    virtual void swapBuffers();
    virtual void setIMEKeyboardState(bool bOpen);

    /**
     @brief get the shared main open gl window
     */
    static CCEGLView* sharedOpenGLView();
    static CocosPepperInstance* g_instance;
private:
    bool initGL(int width, int height);
    void destroyGL();
    bool bIsInit;
    float m_fFrameZoomFactor;
    OpenGLContext* m_context;
};

NS_CC_END

#endif /* CCEGLVIEW_H_ */
