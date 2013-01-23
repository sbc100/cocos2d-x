#include <ppapi/cpp/module.h>
#include "ppapi/gles2/gl2ext_ppapi.h"

class CocosPepperModule : public pp::Module
{
public:
    CocosPepperModule() : pp::Module() {}

    virtual bool Init()
    {
        return glInitializePPAPI(get_browser_interface()) == GL_TRUE;
    }

    virtual ~CocosPepperModule() {}

    virtual pp::Instance* CreateInstance(PP_Instance instance)
    {
        return new CocosPepperInstance(instance);
    }
};
