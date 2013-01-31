NACL_ARCH ?= x86_64
NACL_LIBC = newlib
AR      ?= $(NACL_ARCH)-nacl-ar
CC      ?= $(NACL_ARCH)-nacl-gcc
CXX     ?= $(NACL_ARCH)-nacl-g++
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

OBJECTS = ../actions/CCAction.o \
../actions/CCActionCamera.o \
../actions/CCActionEase.o \
../actions/CCActionGrid.o \
../actions/CCActionGrid3D.o \
../actions/CCActionInstant.o \
../actions/CCActionInterval.o \
../actions/CCActionManager.o \
../actions/CCActionPageTurn3D.o \
../actions/CCActionProgressTimer.o \
../actions/CCActionTiledGrid.o \
../actions/CCActionCatmullRom.o \
../actions/CCActionTween.o \
../base_nodes/CCAtlasNode.o \
../base_nodes/CCNode.o \
../cocoa/CCAffineTransform.o \
../cocoa/CCAutoreleasePool.o \
../cocoa/CCGeometry.o \
../cocoa/CCNS.o \
../cocoa/CCObject.o \
../cocoa/CCSet.o \
../cocoa/CCZone.o \
../cocoa/CCArray.o \
../cocoa/CCDictionary.o \
../cocoa/CCString.o \
../draw_nodes/CCDrawingPrimitives.o \
../draw_nodes/CCDrawNode.o \
../effects/CCGrabber.o \
../effects/CCGrid.o \
../keypad_dispatcher/CCKeypadDelegate.o \
../keypad_dispatcher/CCKeypadDispatcher.o \
../label_nodes/CCLabelAtlas.o \
../label_nodes/CCLabelBMFont.o \
../label_nodes/CCLabelTTF.o \
../layers_scenes_transitions_nodes/CCLayer.o \
../layers_scenes_transitions_nodes/CCScene.o \
../layers_scenes_transitions_nodes/CCTransition.o \
../layers_scenes_transitions_nodes/CCTransitionPageTurn.o \
../layers_scenes_transitions_nodes/CCTransitionProgress.o \
../menu_nodes/CCMenu.o \
../menu_nodes/CCMenuItem.o \
../misc_nodes/CCMotionStreak.o \
../misc_nodes/CCProgressTimer.o \
../misc_nodes/CCClippingNode.o \
../misc_nodes/CCRenderTexture.o \
../particle_nodes/CCParticleExamples.o \
../particle_nodes/CCParticleSystem.o \
../particle_nodes/CCParticleSystemQuad.o \
../particle_nodes/CCParticleBatchNode.o \
../platform/CCSAXParser.o \
../platform/CCThread.o \
../platform/platform.o \
../platform/CCEGLViewProtocol.o \
../platform/nacl/CCCommon.o \
../platform/nacl/CCFileUtils.o \
../platform/nacl/CCApplication.o \
../platform/nacl/CCEGLView.o \
../platform/nacl/CCImage.o \
../platform/nacl/CCInstance.o \
../platform/nacl/jpeg_mem_src.o \
../script_support/CCScriptSupport.o \
../sprite_nodes/CCAnimation.o \
../sprite_nodes/CCAnimationCache.o \
../sprite_nodes/CCSprite.o \
../sprite_nodes/CCSpriteBatchNode.o \
../sprite_nodes/CCSpriteFrame.o \
../sprite_nodes/CCSpriteFrameCache.o \
../support/CCPointExtension.o \
../support/CCProfiling.o \
../support/CCUserDefault.o \
../support/TransformUtils.o \
../support/base64.o \
../support/ccUtils.o \
../support/CCVertex.o \
../support/CCNotificationCenter.o \
../support/image_support/TGAlib.o \
../support/zip_support/ZipUtils.o \
../support/zip_support/ioapi.o \
../support/zip_support/unzip.o \
../support/data_support/ccCArray.o \
../text_input_node/CCIMEDispatcher.o \
../text_input_node/CCTextFieldTTF.o \
../textures/CCTexture2D.o \
../textures/CCTextureAtlas.o \
../textures/CCTextureCache.o \
../textures/CCTexturePVR.o \
../tilemap_parallax_nodes/CCParallaxNode.o \
../tilemap_parallax_nodes/CCTMXLayer.o \
../tilemap_parallax_nodes/CCTMXObjectGroup.o \
../tilemap_parallax_nodes/CCTMXTiledMap.o \
../tilemap_parallax_nodes/CCTMXXMLParser.o \
../tilemap_parallax_nodes/CCTileMapAtlas.o \
../touch_dispatcher/CCTouchDispatcher.o \
../touch_dispatcher/CCTouchHandler.o \
../touch_dispatcher/CCTouch.o \
../shaders/CCGLProgram.o \
../shaders/ccGLStateCache.o \
../shaders/CCShaderCache.o \
../shaders/ccShaders.o \
../kazmath/src/aabb.o \
../kazmath/src/plane.o \
../kazmath/src/vec2.o \
../kazmath/src/mat3.o \
../kazmath/src/quaternion.o \
../kazmath/src/vec3.o \
../kazmath/src/mat4.o \
../kazmath/src/ray2.o \
../kazmath/src/vec4.o \
../kazmath/src/neon_matrix_impl.o \
../kazmath/src/utility.o \
../kazmath/src/GL/mat4stack.o \
../kazmath/src/GL/matrix.o \
../CCCamera.o \
../CCConfiguration.o \
../CCDirector.o \
../CCScheduler.o \
../cocos2d.o


DEFINES += -DCC_ENABLE_CHIPMUNK_INTEGRATION

LIB_DIR_ROOT ?= ../../lib/nacl

ifeq ($(DEBUG), 1)
CCFLAGS += -g3 -O0
CXXFLAGS += -g3 -O0
DEFINES += -DDEBUG -DCOCOS2D_DEBUG=1
LIB_DIR = $(LIB_DIR_ROOT)/Debug
else
CCFLAGS += -O3
CXXFLAGS += -O3
DEFINES += -DNDEBUG
LIB_DIR = $(LIB_DIR_ROOT)/Release
endif

TARGET = $(LIB_DIR)/libcocos2d.a

all: $(TARGET)

####### Build rules
$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

####### Compile
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET) core
