NACL_ARCH ?= x86_64
NACL_LIBC = newlib
NACL_AR ?= $(NACL_ARCH)-nacl-ar
NACL_CC ?= $(NACL_ARCH)-nacl-gcc
NACL_CXX ?= $(NACL_ARCH)-nacl-g++
CCFLAGS = -Wall
CXXFLAGS = -Wall
VISIBILITY =
ARFLAGS = cr

LIBS =

INCLUDES = -I.. \
			-I../platform/third_party/linux/libfreetype2 \
			-I../cocoa \
			-I../include \
			-I../kazmath/include \
			-I../platform \
			-I../../extensions \
			-I../../extensions/CCBReader \
			-I../../extensions/GUI/CCControlExtension \
			-I../../extensions/GUI/CCControlExtension \
                        -I../../external/chipmunk/include/chipmunk \
			-I../../extensions/network \
			-I../platform/nacl

NACLPORTS_INCLUDE ?= $(NACL_SDK_ROOT)/toolchain/linux_x86_$(NACL_LIBC)/$(NACL_ARCH)-nacl/usr/include
INCLUDES += -I$(COCOS2DX_PATH)/platform/third_party/nacl
INCLUDES += -I$(NACL_SDK_ROOT)/include
INCLUDES += -I$(NACLPORTS_INCLUDE)
INCLUDES += -I$(NACLPORTS_INCLUDE)/libxml2

SOURCES = ../actions/CCAction.cpp \
../actions/CCActionCamera.cpp \
../actions/CCActionEase.cpp \
../actions/CCActionGrid.cpp \
../actions/CCActionGrid3D.cpp \
../actions/CCActionInstant.cpp \
../actions/CCActionInterval.cpp \
../actions/CCActionManager.cpp \
../actions/CCActionPageTurn3D.cpp \
../actions/CCActionProgressTimer.cpp \
../actions/CCActionTiledGrid.cpp \
../actions/CCActionCatmullRom.cpp \
../actions/CCActionTween.cpp \
../base_nodes/CCAtlasNode.cpp \
../base_nodes/CCNode.cpp \
../cocoa/CCAffineTransform.cpp \
../cocoa/CCAutoreleasePool.cpp \
../cocoa/CCGeometry.cpp \
../cocoa/CCNS.cpp \
../cocoa/CCObject.cpp \
../cocoa/CCSet.cpp \
../cocoa/CCZone.cpp \
../cocoa/CCArray.cpp \
../cocoa/CCDictionary.cpp \
../cocoa/CCString.cpp \
../draw_nodes/CCDrawingPrimitives.cpp \
../draw_nodes/CCDrawNode.cpp \
../effects/CCGrabber.cpp \
../effects/CCGrid.cpp \
../keypad_dispatcher/CCKeypadDelegate.cpp \
../keypad_dispatcher/CCKeypadDispatcher.cpp \
../label_nodes/CCLabelAtlas.cpp \
../label_nodes/CCLabelBMFont.cpp \
../label_nodes/CCLabelTTF.cpp \
../layers_scenes_transitions_nodes/CCLayer.cpp \
../layers_scenes_transitions_nodes/CCScene.cpp \
../layers_scenes_transitions_nodes/CCTransition.cpp \
../layers_scenes_transitions_nodes/CCTransitionPageTurn.cpp \
../layers_scenes_transitions_nodes/CCTransitionProgress.cpp \
../menu_nodes/CCMenu.cpp \
../menu_nodes/CCMenuItem.cpp \
../misc_nodes/CCMotionStreak.cpp \
../misc_nodes/CCProgressTimer.cpp \
../misc_nodes/CCClippingNode.cpp \
../misc_nodes/CCRenderTexture.cpp \
../particle_nodes/CCParticleExamples.cpp \
../particle_nodes/CCParticleSystem.cpp \
../particle_nodes/CCParticleSystemQuad.cpp \
../particle_nodes/CCParticleBatchNode.cpp \
../platform/CCSAXParser.cpp \
../platform/CCThread.cpp \
../platform/platform.cpp \
../platform/CCEGLViewProtocol.cpp \
../platform/nacl/CCCommon.cpp \
../platform/nacl/CCFileUtils.cpp \
../platform/nacl/CCApplication.cpp \
../platform/nacl/CCEGLView.cpp \
../platform/nacl/CCImage.cpp \
../platform/nacl/CCInstance.cpp \
../platform/nacl/jpeg_mem_src.cpp \
../script_support/CCScriptSupport.cpp \
../sprite_nodes/CCAnimation.cpp \
../sprite_nodes/CCAnimationCache.cpp \
../sprite_nodes/CCSprite.cpp \
../sprite_nodes/CCSpriteBatchNode.cpp \
../sprite_nodes/CCSpriteFrame.cpp \
../sprite_nodes/CCSpriteFrameCache.cpp \
../support/CCPointExtension.cpp \
../support/CCProfiling.cpp \
../support/CCUserDefault.cpp \
../support/TransformUtils.cpp \
../support/base64.cpp \
../support/ccUtils.cpp \
../support/CCVertex.cpp \
../support/CCNotificationCenter.cpp \
../support/image_support/TGAlib.cpp \
../support/zip_support/ZipUtils.cpp \
../support/zip_support/ioapi.cpp \
../support/zip_support/unzip.cpp \
../support/data_support/ccCArray.cpp \
../text_input_node/CCIMEDispatcher.cpp \
../text_input_node/CCTextFieldTTF.cpp \
../textures/CCTexture2D.cpp \
../textures/CCTextureAtlas.cpp \
../textures/CCTextureCache.cpp \
../textures/CCTexturePVR.cpp \
../tilemap_parallax_nodes/CCParallaxNode.cpp \
../tilemap_parallax_nodes/CCTMXLayer.cpp \
../tilemap_parallax_nodes/CCTMXObjectGroup.cpp \
../tilemap_parallax_nodes/CCTMXTiledMap.cpp \
../tilemap_parallax_nodes/CCTMXXMLParser.cpp \
../tilemap_parallax_nodes/CCTileMapAtlas.cpp \
../touch_dispatcher/CCTouchDispatcher.cpp \
../touch_dispatcher/CCTouchHandler.cpp \
../touch_dispatcher/CCTouch.cpp \
../shaders/CCGLProgram.cpp \
../shaders/ccGLStateCache.cpp \
../shaders/CCShaderCache.cpp \
../shaders/ccShaders.cpp \
../kazmath/src/aabb.c \
../kazmath/src/plane.c \
../kazmath/src/vec2.c \
../kazmath/src/mat3.c \
../kazmath/src/quaternion.cpp \
../kazmath/src/vec3.cpp \
../kazmath/src/mat4.cpp \
../kazmath/src/ray2.cpp \
../kazmath/src/vec4.cpp \
../kazmath/src/neon_matrix_impl.cpp \
../kazmath/src/utility.cpp \
../kazmath/src/GL/mat4stack.cpp \
../kazmath/src/GL/matrix.cpp \
../CCCamera.cpp \
../CCConfiguration.cpp \
../CCDirector.cpp \
../CCScheduler.cpp \
../cocos2d.cpp

OBJ_DIR ?= out/$(NACL_ARCH)
LIB_DIR ?= ../../lib/nacl

ifeq ($(DEBUG), 1)
CCFLAGS += -g3 -O0
CXXFLAGS += -g3 -O0
DEFINES += -DDEBUG -DCOCOS2D_DEBUG=1
LIB_DIR := $(LIB_DIR)/Debug
OBJ_DIR := $(OBJ_DIR)/Debug
else
CCFLAGS += -O3
CXXFLAGS += -O3
DEFINES += -DNDEBUG
LIB_DIR := $(LIB_DIR)/Release
OBJ_DIR := $(OBJ_DIR)/Release
endif

TARGET = $(LIB_DIR)/libcocos2d.a

OBJECTS := $(SOURCES:.cpp=.o)
OBJECTS := $(OBJECTS:.c=.o)
OBJECTS := $(subst ../,,$(OBJECTS))
OBJECTS := $(addprefix $(OBJ_DIR)/, $(OBJECTS))
DEPS = $(OBJECTS:.o=.d)
DEFINES += -DCC_ENABLE_CHIPMUNK_INTEGRATION

all: $(TARGET)

####### Build rules
$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(NACL_AR) $(ARFLAGS) $@ $^

####### Compile
$(OBJ_DIR)/%.o: ../%.cpp
	@mkdir -p $(@D)
	$(NACL_CXX) -MMD $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

$(OBJ_DIR)/%.o: ../%.c
	@mkdir -p $(@D)
	$(NACL_CC) -MMD $(CCFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET) $(DEPS) core

-include $(DEPS)
