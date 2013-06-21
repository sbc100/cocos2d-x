#ifndef _TEST_BASIC_H_
#define _TEST_BASIC_H_

#include "cocos2d.h"
#include "VisibleRect.h"

USING_NS_CC;
using namespace std;

class TestScene : public Scene
{
public:
    TestScene(bool bPortrait = false);
    virtual void onEnter();

    virtual void runThisTest() = 0;
};

typedef Layer* (*NEWTESTFUNC)();

#define TESTLAYER_CREATE_FUNC(className) \
static Layer* create##className() \
{ return new className(); }

#define CF(className) create##className

// GCC < 4.6 does not support lambda expressions
#if defined(__GNUC__) &&  __GNUC__ < 4 || __GNUC__ == 4 && __GNUC_MINOR__ < 6
#define MISSING_LAMBDA
#endif

#ifdef MISSING_LAMBDA
// Don't use C++11 lambdas
#define CL(__className__) CF(__className__)
#else
// Use C++11 lamdas
#define CL(__className__) [](){ return new __className__();}
#endif

#endif
