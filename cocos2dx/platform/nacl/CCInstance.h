#ifndef CC_INSTANCE_H
#define CC_INSTANCE_H

#include <ppapi/cpp/instance.h>
#include <ppapi/cpp/input_event.h>

#define OLD_NACL_MOUNTS 1

#ifdef OLD_NACL_MOUNTS
#include "nacl-mounts/base/MainThreadRunner.h"
#endif

extern "C" void* cocos_main(void* arg);

class CocosPepperInstance : public pp::Instance {
public:
    explicit CocosPepperInstance(PP_Instance instance);

    virtual ~CocosPepperInstance()
    {
#ifdef OLD_NACL_MOUNTS
        if (m_runner)
            delete m_runner;
#endif
    }

    virtual bool Init(uint32_t argc, const char* argn[], const char* argv[]);

    void DidChangeView(const pp::View& view);

    bool HandleInputEvent(const pp::InputEvent& event)
    {
        return false;
    }

    bool quit() const { return quit_; }

    pp::Size m_size;
#ifdef OLD_NACL_MOUNTS
    MainThreadRunner* m_runner;
#endif
private:
    pthread_t m_cocos_thread;
    int width_;
    int height_;
    bool quit_;
};

#endif /* !CC_INSTANCE_H */
