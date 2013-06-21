#include "BugsTest.h"
#include "Bug-350.h"
#include "Bug-422.h"
#include "Bug-458/Bug-458.h"
#include "Bug-624.h"
#include "Bug-886.h"
#include "Bug-899.h"
#include "Bug-914.h"
#include "Bug-1159.h"
#include "Bug-1174.h"

#define TEST_BUG(__bug__)									\
{															\
	Scene* pScene = Scene::create();					\
	Bug##__bug__##Layer* pLayer = new Bug##__bug__##Layer();	\
	pLayer->init();                                         \
	pScene->addChild(pLayer);                               \
	Director::sharedDirector()->replaceScene(pScene);     \
	pLayer->autorelease();                                  \
}

enum
{
    LINE_SPACE = 40,
    kItemTagBasic = 5432,
};

static Point s_tCurPos = PointZero;

#ifdef MISSING_LAMBDA
#define BUG_FUNC(name) void func_##name(Object*) TEST_BUG(name)
BUG_FUNC(350)
BUG_FUNC(422)
BUG_FUNC(458)
BUG_FUNC(624)
BUG_FUNC(886)
BUG_FUNC(899)
BUG_FUNC(914)
BUG_FUNC(1159)
BUG_FUNC(1174)
#define TEST_BUG_FUNC(NAME) func_##name
#else
#define TEST_BUG_FUNC(NAME) [](Object* sender) TEST_BUG(NAME)
#endif

static struct {
	const char *test_name;
	std::function<void(Object*)> callback;
} g_bugs[] = {
	{ "Bug-350", TEST_BUG_FUNC(350) },
	{ "Bug-422", TEST_BUG_FUNC(422) },
	{ "Bug-458", TEST_BUG_FUNC(458) },
	{ "Bug-624", TEST_BUG_FUNC(624) },
	{ "Bug-886", TEST_BUG_FUNC(886) },
	{ "Bug-899", TEST_BUG_FUNC(899) },
	{ "Bug-914", TEST_BUG_FUNC(914) },
	{ "Bug-1159", TEST_BUG_FUNC(1159) },
	{ "Bug-1174", TEST_BUG_FUNC(1174) },
};

static const int g_maxitems = sizeof(g_bugs) / sizeof(g_bugs[0]);


////////////////////////////////////////////////////////
//
// BugsTestMainLayer
//
////////////////////////////////////////////////////////
void BugsTestMainLayer::onEnter()
{
    Layer::onEnter();

    Size s = Director::sharedDirector()->getWinSize();
    _itmeMenu = Menu::create();
    MenuItemFont::setFontName("Arial");
    MenuItemFont::setFontSize(24);
    for (int i = 0; i < g_maxitems; ++i)
    {
        MenuItemFont* pItem = MenuItemFont::create(g_bugs[i].test_name, g_bugs[i].callback);
        pItem->setPosition(ccp(s.width / 2, s.height - (i + 1) * LINE_SPACE));
        _itmeMenu->addChild(pItem, kItemTagBasic + i);
    }

    _itmeMenu->setPosition(s_tCurPos);
    addChild(_itmeMenu);
    setTouchEnabled(true);
}

void BugsTestMainLayer::ccTouchesBegan(Set *pTouches, Event *pEvent)
{
    SetIterator it = pTouches->begin();
    Touch* touch = (Touch*)(*it);

    _beginPos = touch->getLocation();    
}

void BugsTestMainLayer::ccTouchesMoved(Set *pTouches, Event *pEvent)
{
    SetIterator it = pTouches->begin();
    Touch* touch = (Touch*)(*it);

    Point touchLocation = touch->getLocation();    
    float nMoveY = touchLocation.y - _beginPos.y;

    Point curPos  = _itmeMenu->getPosition();
    Point nextPos = ccp(curPos.x, curPos.y + nMoveY);
    Size winSize = Director::sharedDirector()->getWinSize();
    if (nextPos.y < 0.0f)
    {
        _itmeMenu->setPosition(PointZero);
        return;
    }

    if (nextPos.y > ((g_maxitems + 1)* LINE_SPACE - winSize.height))
    {
        _itmeMenu->setPosition(ccp(0, ((g_maxitems + 1)* LINE_SPACE - winSize.height)));
        return;
    }

    _itmeMenu->setPosition(nextPos);
    _beginPos = touchLocation;
    s_tCurPos   = nextPos;
}

////////////////////////////////////////////////////////
//
// BugsTestBaseLayer
//
////////////////////////////////////////////////////////
void BugsTestBaseLayer::onEnter()
{
    Layer::onEnter();

    MenuItemFont::setFontName("Arial");
    MenuItemFont::setFontSize(24);
    MenuItemFont* pMainItem = MenuItemFont::create("Back", CC_CALLBACK_1(BugsTestBaseLayer::backCallback, this));
    pMainItem->setPosition(ccp(VisibleRect::rightBottom().x - 50, VisibleRect::rightBottom().y + 25));
    Menu* pMenu = Menu::create(pMainItem, NULL);
    pMenu->setPosition( PointZero );
    addChild(pMenu);
}

void BugsTestBaseLayer::backCallback(Object* pSender)
{
//    Director::sharedDirector()->enableRetinaDisplay(false);
    BugsTestScene* pScene = new BugsTestScene();
    pScene->runThisTest();
    pScene->autorelease();
}

////////////////////////////////////////////////////////
//
// BugsTestScene
//
////////////////////////////////////////////////////////
void BugsTestScene::runThisTest()
{
    Layer* pLayer = new BugsTestMainLayer();
    addChild(pLayer);
    pLayer->release();

    Director::sharedDirector()->replaceScene(this);
}
