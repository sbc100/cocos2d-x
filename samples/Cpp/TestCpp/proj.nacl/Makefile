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


SOURCES = ../Classes/AccelerometerTest/AccelerometerTest.cpp \
	../Classes/ActionManagerTest/ActionManagerTest.cpp \
	../Classes/ActionsEaseTest/ActionsEaseTest.cpp \
	../Classes/ActionsProgressTest/ActionsProgressTest.cpp \
	../Classes/ActionsTest/ActionsTest.cpp \
	../Classes/Box2DTest/Box2dTest.cpp \
	../Classes/Box2DTestBed/Box2dView.cpp \
	../Classes/Box2DTestBed/GLES-Render.cpp \
	../Classes/Box2DTestBed/Test.cpp \
	../Classes/Box2DTestBed/TestEntries.cpp \
	../Classes/BugsTest/Bug-1159.cpp \
	../Classes/BugsTest/Bug-1174.cpp \
	../Classes/BugsTest/Bug-350.cpp \
	../Classes/BugsTest/Bug-422.cpp \
	../Classes/BugsTest/Bug-458/Bug-458.cpp \
	../Classes/BugsTest/Bug-458/QuestionContainerSprite.cpp \
	../Classes/BugsTest/Bug-624.cpp \
	../Classes/BugsTest/Bug-886.cpp \
	../Classes/BugsTest/Bug-899.cpp \
	../Classes/BugsTest/Bug-914.cpp \
	../Classes/BugsTest/BugsTest.cpp \
	../Classes/ChipmunkTest/ChipmunkTest.cpp \
	../Classes/ClickAndMoveTest/ClickAndMoveTest.cpp \
	../Classes/ClippingNodeTest/ClippingNodeTest.cpp \
	../Classes/CocosDenshionTest/CocosDenshionTest.cpp \
	../Classes/CurrentLanguageTest/CurrentLanguageTest.cpp \
	../Classes/DrawPrimitivesTest/DrawPrimitivesTest.cpp \
	../Classes/EffectsAdvancedTest/EffectsAdvancedTest.cpp \
	../Classes/EffectsTest/EffectsTest.cpp \
	../Classes/ExtensionsTest/CocosBuilderTest/ButtonTest/ButtonTestLayer.cpp \
	../Classes/ExtensionsTest/CocosBuilderTest/CocosBuilderTest.cpp \
	../Classes/ExtensionsTest/CocosBuilderTest/HelloCocosBuilder/HelloCocosBuilderLayer.cpp \
	../Classes/ExtensionsTest/CocosBuilderTest/AnimationsTest/AnimationsTestLayer.cpp \
	../Classes/ExtensionsTest/CocosBuilderTest/MenuTest/MenuTestLayer.cpp \
	../Classes/ExtensionsTest/CocosBuilderTest/TestHeader/TestHeaderLayer.cpp \
	../Classes/ExtensionsTest/ControlExtensionTest/CCControlButtonTest/CCControlButtonTest.cpp \
	../Classes/ExtensionsTest/ControlExtensionTest/CCControlColourPicker/CCControlColourPickerTest.cpp \
	../Classes/ExtensionsTest/ControlExtensionTest/CCControlScene.cpp \
	../Classes/ExtensionsTest/ControlExtensionTest/CCControlSceneManager.cpp \
	../Classes/ExtensionsTest/ControlExtensionTest/CCControlSliderTest/CCControlSliderTest.cpp \
	../Classes/ExtensionsTest/ControlExtensionTest/CCControlSwitchTest/CCControlSwitchTest.cpp \
	../Classes/ExtensionsTest/ControlExtensionTest/CCControlPotentiometerTest/CCControlPotentiometerTest.cpp \
	../Classes/ExtensionsTest/ControlExtensionTest/CCControlStepperTest/CCControlStepperTest.cpp \
	../Classes/ExtensionsTest/TableViewTest/TableViewTestScene.cpp \
	../Classes/ExtensionsTest/TableViewTest/CustomTableViewCell.cpp \
	../Classes/ExtensionsTest/ExtensionsTest.cpp \
	../Classes/ExtensionsTest/NotificationCenterTest/NotificationCenterTest.cpp \
	../Classes/FontTest/FontTest.cpp \
	../Classes/IntervalTest/IntervalTest.cpp \
	../Classes/KeypadTest/KeypadTest.cpp \
	../Classes/LabelTest/LabelTest.cpp \
	../Classes/LayerTest/LayerTest.cpp \
	../Classes/MenuTest/MenuTest.cpp \
	../Classes/MotionStreakTest/MotionStreakTest.cpp \
	../Classes/MutiTouchTest/MutiTouchTest.cpp \
	../Classes/NodeTest/NodeTest.cpp \
	../Classes/ParallaxTest/ParallaxTest.cpp \
	../Classes/ParticleTest/ParticleTest.cpp \
	../Classes/PerformanceTest/PerformanceNodeChildrenTest.cpp \
	../Classes/PerformanceTest/PerformanceParticleTest.cpp \
	../Classes/PerformanceTest/PerformanceSpriteTest.cpp \
	../Classes/PerformanceTest/PerformanceTest.cpp \
	../Classes/PerformanceTest/PerformanceTextureTest.cpp \
	../Classes/PerformanceTest/PerformanceTouchesTest.cpp \
	../Classes/RenderTextureTest/RenderTextureTest.cpp \
	../Classes/RotateWorldTest/RotateWorldTest.cpp \
	../Classes/SceneTest/SceneTest.cpp \
	../Classes/SchedulerTest/SchedulerTest.cpp \
	../Classes/ShaderTest/ShaderTest.cpp \
	../Classes/SpriteTest/SpriteTest.cpp \
	../Classes/TextInputTest/TextInputTest.cpp \
	../Classes/Texture2dTest/Texture2dTest.cpp \
	../Classes/TextureCacheTest/TextureCacheTest.cpp \
	../Classes/TileMapTest/TileMapTest.cpp \
	../Classes/TouchesTest/Ball.cpp \
	../Classes/TouchesTest/Paddle.cpp \
	../Classes/TouchesTest/TouchesTest.cpp \
	../Classes/TransitionsTest/TransitionsTest.cpp \
	../Classes/UserDefaultTest/UserDefaultTest.cpp \
	../Classes/ZwoptexTest/ZwoptexTest.cpp \
	../Classes/controller.cpp \
	../Classes/testBasic.cpp \
	../Classes/AppDelegate.cpp \
	../Classes/VisibleRect.cpp \
	main.cpp

include $(COCOS2DX_PATH)/../extensions/proj.nacl/Makefile
SOURCES += $(addprefix ../../../../extensions/, $(EXTENSIONS_SOURCES))

SHAREDLIBS = -pthread
OBJ_DIR ?= out/$(NACL_ARCH)

ifeq ($(DEBUG), 1)
BIN_DIR = bin/debug
CCFLAGS += -g3 -O0
CXXFLAGS += -g3 -O0
LIB_DIR = ../../../../lib/nacl/Debug
OBJ_DIR := $(OBJ_DIR)/Debug
DEFINES += -DDEBUG -DCOCOS2D_DEBUG=1
STATICLIBS = -L$(NACL_SDK_ROOT)/lib/$(NACL_LIBC)_$(NACL_ARCH)/Debug
else
BIN_DIR = bin/release
CCFLAGS += -O3
CXXFLAGS += -O3
LIB_DIR = ../../../../lib/nacl/Release
OBJ_DIR := $(OBJ_DIR)/Release
DEFINES += -DNDEBUG
STATICLIBS = -L$(NACL_SDK_ROOT)/lib/$(NACL_LIBC)_$(NACL_ARCH)/Release
endif

SHAREDLIBS += -L$(LIB_DIR)

STATICLIBS += -lopenal -lvorbisfile -lvorbis -logg  -lalut -lfontconfig -lfreetype -lexpat -lxml2 -lpng -ljpeg -ltiff -lppapi_gles2 -lnacl-mounts -lppapi -lppapi_cpp
SHAREDLIBS += -lcocos2d -lcocosdenshion -lchipmunk -lbox2d -lz

OBJECTS := $(SOURCES:.cpp=.o)
OBJECTS := $(OBJECTS:.c=.o)
OBJECTS := $(subst ../,,$(OBJECTS))
OBJECTS := $(addprefix $(OBJ_DIR)/, $(OBJECTS))
DEPS = $(OBJECTS:.o=.d)

TARGET = $(BIN_DIR)/TestCpp.nexe
NMF = $(basename $(TARGET)).nmf

all: $(TARGET) $(NMF)

####### Build rules
$(TARGET): $(OBJECTS) $(LIB_DIR)/libcocos2d.a $(LIB_DIR)/libcocosdenshion.a
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(OBJECTS) -o $@ $(SHAREDLIBS) $(STATICLIBS)

####### Compile
$(OBJ_DIR)/%.o: ../%.cpp
	@mkdir -p $(@D)
	$(CXX) -MMD $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

$(OBJ_DIR)/%.o: ../../../../%.cpp
	@mkdir -p $(@D)
	$(CXX) -MMD $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) -MMD $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

$(OBJ_DIR)/%.o: ../%.c
	@mkdir -p $(@D)
	$(CC) -MMD $(CCFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(TARGET) core


$(NMF): $(TARGET)
	$(NACL_SDK_ROOT)/tools/create_nmf.py -o $(NMF) $(TARGET) --objdump=i686-nacl-objdump -L$(NACL_SDK_ROOT)/toolchain/linux_x86_newlib/x86_64-nacl/lib/ -s $(BIN_DIR)

run: all
	/bin/cp -ar ../Resources/ .
	$(NACL_SDK_ROOT)/tools/httpd.py --no_dir_check

.PHONY: run clean nmf
