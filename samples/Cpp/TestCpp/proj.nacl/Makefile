NACL_ARCH ?= x86_64
NACL_LIBC = newlib
CC      = $(NACL_ARCH)-nacl-gcc
CXX     = $(NACL_ARCH)-nacl-g++
CCFLAGS = -Wall
CXXFLAGS = -Wall
VISIBILITY =

DEFINES = -DCC_ENABLE_BOX2D_INTEGRATION
DEFINES = -DCC_ENABLE_CHIPMUNK_INTEGRATION
COCOS2DX_PATH = ../../../../cocos2dx
INCLUDES =  -I../ \
			-I../Classes \
			-I$(COCOS2DX_PATH) \
			-I$(COCOS2DX_PATH)/cocoa \
			-I$(COCOS2DX_PATH)/include \
			-I$(COCOS2DX_PATH)/platform/nacl \
			-I$(COCOS2DX_PATH)/kazmath/include \
			-I../../../../CocosDenshion/include \
			-I../../../../extensions/ \
			-I../../../../external/chipmunk/include/chipmunk \
			-I$(NACL_SDK_ROOT)/include


OBJECTS = ../Classes/AccelerometerTest/AccelerometerTest.o \
	../Classes/ActionManagerTest/ActionManagerTest.o \
	../Classes/ActionsEaseTest/ActionsEaseTest.o \
	../Classes/ActionsProgressTest/ActionsProgressTest.o \
	../Classes/ActionsTest/ActionsTest.o \
	../Classes/Box2DTest/Box2dTest.o \
	../Classes/Box2DTestBed/Box2dView.o \
	../Classes/Box2DTestBed/GLES-Render.o \
	../Classes/Box2DTestBed/Test.o \
	../Classes/Box2DTestBed/TestEntries.o \
	../Classes/BugsTest/Bug-1159.o \
	../Classes/BugsTest/Bug-1174.o \
	../Classes/BugsTest/Bug-350.o \
	../Classes/BugsTest/Bug-422.o \
	../Classes/BugsTest/Bug-458/Bug-458.o \
	../Classes/BugsTest/Bug-458/QuestionContainerSprite.o \
	../Classes/BugsTest/Bug-624.o \
	../Classes/BugsTest/Bug-886.o \
	../Classes/BugsTest/Bug-899.o \
	../Classes/BugsTest/Bug-914.o \
	../Classes/BugsTest/BugsTest.o \
	../Classes/ChipmunkTest/ChipmunkTest.o \
	../Classes/ClickAndMoveTest/ClickAndMoveTest.o \
	../Classes/ClippingNodeTest/ClippingNodeTest.o \
	../Classes/CocosDenshionTest/CocosDenshionTest.o \
	../Classes/CurrentLanguageTest/CurrentLanguageTest.o \
	../Classes/DrawPrimitivesTest/DrawPrimitivesTest.o \
	../Classes/EffectsAdvancedTest/EffectsAdvancedTest.o \
	../Classes/EffectsTest/EffectsTest.o \
	../Classes/ExtensionsTest/CocosBuilderTest/ButtonTest/ButtonTestLayer.o \
	../Classes/ExtensionsTest/CocosBuilderTest/CocosBuilderTest.o \
	../Classes/ExtensionsTest/CocosBuilderTest/HelloCocosBuilder/HelloCocosBuilderLayer.o \
	../Classes/ExtensionsTest/CocosBuilderTest/AnimationsTest/AnimationsTestLayer.o \
	../Classes/ExtensionsTest/CocosBuilderTest/MenuTest/MenuTestLayer.o \
	../Classes/ExtensionsTest/CocosBuilderTest/TestHeader/TestHeaderLayer.o \
	../Classes/ExtensionsTest/ControlExtensionTest/CCControlButtonTest/CCControlButtonTest.o \
	../Classes/ExtensionsTest/ControlExtensionTest/CCControlColourPicker/CCControlColourPickerTest.o \
	../Classes/ExtensionsTest/ControlExtensionTest/CCControlScene.o \
	../Classes/ExtensionsTest/ControlExtensionTest/CCControlSceneManager.o \
	../Classes/ExtensionsTest/ControlExtensionTest/CCControlSliderTest/CCControlSliderTest.o \
	../Classes/ExtensionsTest/ControlExtensionTest/CCControlSwitchTest/CCControlSwitchTest.o \
	../Classes/ExtensionsTest/ControlExtensionTest/CCControlPotentiometerTest/CCControlPotentiometerTest.o \
	../Classes/ExtensionsTest/ControlExtensionTest/CCControlStepperTest/CCControlStepperTest.o \
	../Classes/ExtensionsTest/TableViewTest/TableViewTestScene.o \
	../Classes/ExtensionsTest/TableViewTest/CustomTableViewCell.o \
	../Classes/ExtensionsTest/ExtensionsTest.o \
	../Classes/ExtensionsTest/NotificationCenterTest/NotificationCenterTest.o \
	../Classes/FontTest/FontTest.o \
	../Classes/IntervalTest/IntervalTest.o \
	../Classes/KeypadTest/KeypadTest.o \
	../Classes/LabelTest/LabelTest.o \
	../Classes/LayerTest/LayerTest.o \
	../Classes/MenuTest/MenuTest.o \
	../Classes/MotionStreakTest/MotionStreakTest.o \
	../Classes/MutiTouchTest/MutiTouchTest.o \
	../Classes/NodeTest/NodeTest.o \
	../Classes/ParallaxTest/ParallaxTest.o \
	../Classes/ParticleTest/ParticleTest.o \
	../Classes/PerformanceTest/PerformanceNodeChildrenTest.o \
	../Classes/PerformanceTest/PerformanceParticleTest.o \
	../Classes/PerformanceTest/PerformanceSpriteTest.o \
	../Classes/PerformanceTest/PerformanceTest.o \
	../Classes/PerformanceTest/PerformanceTextureTest.o \
	../Classes/PerformanceTest/PerformanceTouchesTest.o \
	../Classes/RenderTextureTest/RenderTextureTest.o \
	../Classes/RotateWorldTest/RotateWorldTest.o \
	../Classes/SceneTest/SceneTest.o \
	../Classes/SchedulerTest/SchedulerTest.o \
	../Classes/ShaderTest/ShaderTest.o \
	../Classes/SpriteTest/SpriteTest.o \
	../Classes/TextInputTest/TextInputTest.o \
	../Classes/Texture2dTest/Texture2dTest.o \
	../Classes/TextureCacheTest/TextureCacheTest.o \
	../Classes/TileMapTest/TileMapTest.o \
	../Classes/TouchesTest/Ball.o \
	../Classes/TouchesTest/Paddle.o \
	../Classes/TouchesTest/TouchesTest.o \
	../Classes/TransitionsTest/TransitionsTest.o \
	../Classes/UserDefaultTest/UserDefaultTest.o \
	../Classes/ZwoptexTest/ZwoptexTest.o \
	../Classes/controller.o \
	../Classes/testBasic.o \
	../Classes/AppDelegate.o \
	../Classes/VisibleRect.o \
	./main.o

include $(COCOS2DX_PATH)/../extensions/proj.nacl/Makefile
OBJECTS += $(addprefix ../../../../extensions/proj.nacl/, $(EXTENSIONS_OBJECTS))

SHAREDLIBS = -pthread

ifeq ($(DEBUG), 1)
BIN_DIR = bin/debug
CCFLAGS += -g3 -O0
CXXFLAGS += -g3 -O0
LIB_DIR = ../../../../lib/nacl/Debug
DEFINES += -DDEBUG -DCOCOS2D_DEBUG=1
STATICLIBS = -L$(NACL_SDK_ROOT)/lib/$(NACL_LIBC)_$(NACL_ARCH)/Debug
else
BIN_DIR = bin/release
CCFLAGS += -O3
CXXFLAGS += -O3
LIB_DIR = ../../../../lib/nacl/Release
DEFINES += -DNDEBUG
STATICLIBS = -L$(NACL_SDK_ROOT)/lib/$(NACL_LIBC)_$(NACL_ARCH)/Release
endif

SHAREDLIBS += -L$(LIB_DIR)

STATICLIBS += -lfontconfig -lfreetype -lexpat -lxml2 -lpng -ljpeg -ltiff -lppapi_gles2 -lnacl-mounts -lppapi -lppapi_cpp
SHAREDLIBS += -lcocos2d -lcocosdenshion  -lchipmunk -lbox2d -lz

TARGET = $(BIN_DIR)/TestCpp.nexe
NMF = $(basename $(TARGET)).nmf

all: $(TARGET) $(NMF)

####### Build rules
$(TARGET): $(OBJECTS) $(LIB_DIR)/libcocos2d.a
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(OBJECTS) -o $@ $(SHAREDLIBS) $(STATICLIBS)

####### Compile
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET) core


$(NMF): $(TARGET)
	$(NACL_SDK_ROOT)/tools/create_nmf.py -o $(NMF) $(TARGET) --objdump=i686-nacl-objdump -L$(NACL_SDK_ROOT)/toolchain/linux_x86_newlib/x86_64-nacl/lib/ -s $(BIN_DIR)

run: all
	/bin/cp -ar ../Resources/ .
	$(NACL_SDK_ROOT)/tools/httpd.py --no_dir_check

.PHONY: run clean nmf
