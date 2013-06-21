
// C++ includes
#include <map>
#include <functional>
#include <string>

// test inclues
#include "controller.h"
#include "testResource.h"
#include "tests.h"

#ifdef MISSING_LAMBDA
#define CREATE_SCENE_FUNC(NAME) static TestScene* create_##NAME() { return new NAME(); }
CREATE_SCENE_FUNC(AccelerometerTestScene)
CREATE_SCENE_FUNC(ActionManagerTestScene)
CREATE_SCENE_FUNC(ActionsEaseTestScene)
CREATE_SCENE_FUNC(ProgressActionsTestScene)
CREATE_SCENE_FUNC(ActionsTestScene)
CREATE_SCENE_FUNC(Box2DTestScene)
CREATE_SCENE_FUNC(Box2dTestBedScene)
CREATE_SCENE_FUNC(BugsTestScene)
#if (CC_TARGET_PLATFORM != CC_PLATFORM_MARMALADE)
CREATE_SCENE_FUNC(ChipmunkAccelTouchTestScene)
#endif
CREATE_SCENE_FUNC(ClickAndMoveTestScene)
#if (CC_TARGET_PLATFORM != CC_PLATFORM_MARMALADE)
CREATE_SCENE_FUNC(ClippingNodeTestScene)
#endif
CREATE_SCENE_FUNC(CocosDenshionTestScene)
CREATE_SCENE_FUNC(ConfigurationTestScene)
#if (CC_TARGET_PLATFORM != CC_PLATFORM_EMSCRIPTEN)
#if (CC_TARGET_PLATFORM != CC_PLATFORM_NACL)
#if (CC_TARGET_PLATFORM != CC_PLATFORM_MARMALADE)
#if (CC_TARGET_PLATFORM != CC_PLATFORM_BADA)
CREATE_SCENE_FUNC(CurlTestScene)
#endif
#endif
#endif
#endif
CREATE_SCENE_FUNC(CurrentLanguageTestScene)
CREATE_SCENE_FUNC(DrawPrimitivesTestScene)
CREATE_SCENE_FUNC(EffectAdvanceScene)
CREATE_SCENE_FUNC(EffectTestScene)
CREATE_SCENE_FUNC(ExtensionsTestScene)
CREATE_SCENE_FUNC(FileUtilsTestScene)
CREATE_SCENE_FUNC(FontTestScene)
CREATE_SCENE_FUNC(IntervalTestScene)
#ifdef KEYBOARD_SUPPORT
CREATE_SCENE_FUNC(KeyboardTestScene)
#endif
#if (CC_TARGET_PLATFORM != CC_PLATFORM_BADA)
CREATE_SCENE_FUNC(KeypadTestScene)
#endif
CREATE_SCENE_FUNC(AtlasTestScene)
CREATE_SCENE_FUNC(LayerTestScene)
#ifndef MISSING_LAMBDA
CREATE_SCENE_FUNC(MenuTestScene)
#endif
CREATE_SCENE_FUNC(MotionStreakTestScene)
CREATE_SCENE_FUNC(MutiTouchTestScene)
CREATE_SCENE_FUNC(CocosNodeTestScene)
CREATE_SCENE_FUNC(ParallaxTestScene)
CREATE_SCENE_FUNC(ParticleTestScene)
#ifndef MISSING_LAMBDA
CREATE_SCENE_FUNC(PerformanceTestScene)
#endif
CREATE_SCENE_FUNC(RenderTextureScene)
CREATE_SCENE_FUNC(RotateWorldTestScene)
CREATE_SCENE_FUNC(SceneTestScene)
CREATE_SCENE_FUNC(SchedulerTestScene)
CREATE_SCENE_FUNC(ShaderTestScene)
CREATE_SCENE_FUNC(SpineTestScene)
CREATE_SCENE_FUNC(SpriteTestScene)
CREATE_SCENE_FUNC(TextInputTestScene)
CREATE_SCENE_FUNC(TextureTestScene)
#if (CC_TARGET_PLATFORM != CC_PLATFORM_MARMALADE)
CREATE_SCENE_FUNC(TextureCacheTestScene)
#endif
CREATE_SCENE_FUNC(TextureAtlasEncryptionTestScene)
CREATE_SCENE_FUNC(TileMapTestScene)
#ifndef MISSING_LAMBDA
CREATE_SCENE_FUNC(PongScene)
#endif
CREATE_SCENE_FUNC(TransitionsTestScene)
CREATE_SCENE_FUNC(UserDefaultTestScene)
CREATE_SCENE_FUNC(ZwoptexTestScene)
#define TEST_FUNC(NAME) create_##NAME
#else
#define TEST_FUNC(NAME) [](){ return new NAME(); }
#endif


static struct {
	const char *test_name;
	std::function<TestScene*()> callback;
} g_aTestNames[] = {

	{ "Accelerometer", TEST_FUNC(AccelerometerTestScene) },
	{ "ActionManagerTest", TEST_FUNC(ActionManagerTestScene) },
	{ "ActionsEaseTest", TEST_FUNC(ActionsEaseTestScene) },
	{ "ActionsProgressTest", TEST_FUNC(ProgressActionsTestScene) },
	{ "ActionsTest", TEST_FUNC(ActionsTestScene) },
	{ "Box2dTest", TEST_FUNC(Box2DTestScene) },
	{ "Box2dTestBed", TEST_FUNC(Box2dTestBedScene) },
	{ "BugsTest", TEST_FUNC(BugsTestScene) },
#if (CC_TARGET_PLATFORM != CC_PLATFORM_MARMALADE)
	{ "ChipmunkTest", TEST_FUNC(ChipmunkAccelTouchTestScene) },
#endif
	{ "ClickAndMoveTest", TEST_FUNC(ClickAndMoveTestScene) },
#if (CC_TARGET_PLATFORM != CC_PLATFORM_MARMALADE)
	{ "ClippingNodeTest", TEST_FUNC(ClippingNodeTestScene) },
#endif
	{ "CocosDenshionTest", TEST_FUNC(CocosDenshionTestScene) },
	{ "ConfigurationTest", TEST_FUNC(ConfigurationTestScene) },
#if (CC_TARGET_PLATFORM != CC_PLATFORM_EMSCRIPTEN)
#if (CC_TARGET_PLATFORM != CC_PLATFORM_NACL)
#if (CC_TARGET_PLATFORM != CC_PLATFORM_MARMALADE)
#if (CC_TARGET_PLATFORM != CC_PLATFORM_BADA)
	{ "CurlTest", TEST_FUNC(CurlTestScene) },
#endif
#endif
#endif
#endif
	{ "CurrentLanguageTest", TEST_FUNC(CurrentLanguageTestScene) },
	{ "DrawPrimitivesTest", TEST_FUNC(DrawPrimitivesTestScene) },
	{ "EffectAdvancedTest", TEST_FUNC(EffectAdvanceScene) },
	{ "EffectsTest", TEST_FUNC(EffectTestScene) },
	{ "ExtensionsTest", TEST_FUNC(ExtensionsTestScene) },
	{ "FileUtilsTest", TEST_FUNC(FileUtilsTestScene) },
	{ "FontTest", TEST_FUNC(FontTestScene) },
	{ "IntervalTest", TEST_FUNC(IntervalTestScene) },
#ifdef KEYBOARD_SUPPORT
	{ "KeyboardTest", TEST_FUNC(KeyboardTestScene) },
#endif
#if (CC_TARGET_PLATFORM != CC_PLATFORM_BADA)
	{ "KeypadTest", TEST_FUNC(KeypadTestScene) },
#endif
	{ "LabelTest", TEST_FUNC(AtlasTestScene) },
	{ "LayerTest", TEST_FUNC(LayerTestScene) },
#ifndef MISSING_LAMBDA
	{ "MenuTest", TEST_FUNC(MenuTestScene) },
#endif
	{ "MotionStreakTest", TEST_FUNC(MotionStreakTestScene) },
	{ "MutiTouchTest", TEST_FUNC(MutiTouchTestScene) },
	{ "NodeTest", TEST_FUNC(CocosNodeTestScene) },
	{ "ParallaxTest", TEST_FUNC(ParallaxTestScene) },
	{ "ParticleTest", TEST_FUNC(ParticleTestScene) },
#ifndef MISSING_LAMBDA
	{ "PerformanceTest", TEST_FUNC(PerformanceTestScene) },
#endif
	{ "RenderTextureTest", TEST_FUNC(RenderTextureScene) },
	{ "RotateWorldTest", TEST_FUNC(RotateWorldTestScene) },
	{ "SceneTest", TEST_FUNC(SceneTestScene) },
	{ "SchedulerTest", TEST_FUNC(SchedulerTestScene) },
	{ "ShaderTest", TEST_FUNC(ShaderTestScene) },
	{ "SpineTest", TEST_FUNC(SpineTestScene) },
	{ "SpriteTest", TEST_FUNC(SpriteTestScene) },
	{ "TextInputTest", TEST_FUNC(TextInputTestScene) },
	{ "Texture2DTest", TEST_FUNC(TextureTestScene) },
#if (CC_TARGET_PLATFORM != CC_PLATFORM_MARMALADE)
	{ "TextureCacheTest", TEST_FUNC(TextureCacheTestScene) },
#endif
	{ "TexturePackerEncryption", TEST_FUNC(TextureAtlasEncryptionTestScene) },
	{ "TileMapTest", TEST_FUNC(TileMapTestScene) },
#ifndef MISSING_LAMBDA
	{ "TouchesTest", TEST_FUNC(PongScene) },
#endif
	{ "TransitionsTest", TEST_FUNC(TransitionsTestScene) },
	{ "UserDefaultTest", TEST_FUNC(UserDefaultTestScene) },
	{ "ZwoptexTest", TEST_FUNC(ZwoptexTestScene) },
};

static int g_testCount = sizeof(g_aTestNames) / sizeof(g_aTestNames[0]);

#define LINE_SPACE          40

static Point s_tCurPos = PointZero;

TestController::TestController()
: _beginPos(PointZero)
{
    // add close menu
    MenuItemImage *pCloseItem = MenuItemImage::create(s_pPathClose, s_pPathClose, CC_CALLBACK_1(TestController::closeCallback, this) );
    Menu* pMenu =Menu::create(pCloseItem, NULL);

    pMenu->setPosition( PointZero );
    pCloseItem->setPosition(ccp( VisibleRect::right().x - 30, VisibleRect::top().y - 30));

    // add menu items for tests
    _itemMenu = Menu::create();
    for (int i = 0; i < g_testCount; ++i)
    {
// #if (CC_TARGET_PLATFORM == CC_PLATFORM_MARMALADE)
//         LabelBMFont* label = LabelBMFont::create(g_aTestNames[i].c_str(),  "fonts/arial16.fnt");
// #else
        LabelTTF* label = LabelTTF::create( g_aTestNames[i].test_name, "Arial", 24);
// #endif        
        MenuItemLabel* pMenuItem = MenuItemLabel::create(label, CC_CALLBACK_1(TestController::menuCallback, this));

        _itemMenu->addChild(pMenuItem, i + 10000);
        pMenuItem->setPosition( ccp( VisibleRect::center().x, (VisibleRect::top().y - (i + 1) * LINE_SPACE) ));
    }

    _itemMenu->setContentSize(CCSizeMake(VisibleRect::getVisibleRect().size.width, (g_testCount + 1) * (LINE_SPACE)));
    _itemMenu->setPosition(s_tCurPos);
    addChild(_itemMenu);

    setTouchEnabled(true);

    addChild(pMenu, 1);

}

TestController::~TestController()
{
}

void TestController::menuCallback(Object * pSender)
{

	Director::sharedDirector()->purgeCachedData();

    // get the userdata, it's the index of the menu item clicked
    MenuItem* pMenuItem = (MenuItem *)(pSender);
    int idx = pMenuItem->getZOrder() - 10000;

    // create the test scene and run it
    TestScene* pScene = g_aTestNames[idx].callback();

    if (pScene)
    {
        pScene->runThisTest();
        pScene->release();
    }
}

void TestController::closeCallback(Object * pSender)
{
    Director::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void TestController::ccTouchesBegan(Set *pTouches, Event *pEvent)
{
    SetIterator it = pTouches->begin();
    Touch* touch = (Touch*)(*it);

    _beginPos = touch->getLocation();    
}

void TestController::ccTouchesMoved(Set *pTouches, Event *pEvent)
{
    SetIterator it = pTouches->begin();
    Touch* touch = (Touch*)(*it);

    Point touchLocation = touch->getLocation();    
    float nMoveY = touchLocation.y - _beginPos.y;

    Point curPos  = _itemMenu->getPosition();
    Point nextPos = ccp(curPos.x, curPos.y + nMoveY);

    if (nextPos.y < 0.0f)
    {
        _itemMenu->setPosition(PointZero);
        return;
    }

    if (nextPos.y > ((g_testCount + 1)* LINE_SPACE - VisibleRect::getVisibleRect().size.height))
    {
        _itemMenu->setPosition(ccp(0, ((g_testCount + 1)* LINE_SPACE - VisibleRect::getVisibleRect().size.height)));
        return;
    }

    _itemMenu->setPosition(nextPos);
    _beginPos = touchLocation;
    s_tCurPos   = nextPos;
}
