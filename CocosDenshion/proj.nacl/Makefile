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
	-I../platform/nacl/


NACLPORTS_INCLUDE ?= $(NACL_SDK_ROOT)/toolchain/linux_x86_$(NACL_LIBC)/$(NACL_ARCH)-nacl/usr/include
INCLUDES += -I$(COCOS2DX_PATH)/platform/third_party/nacl -I$(NACL_SDK_ROOT)/include 
INCLUDES += -I$(NACLPORTS_INCLUDE)
INCLUDES += -I$(NACLPORTS_INCLUDE)/libxml2


OBJECTS = ../blackberry/SimpleAudioEngine.o

LIB_DIR ?= ../../lib/nacl

ifeq ($(DEBUG), 1)
CCFLAGS += -g3 -O0
CXXFLAGS += -g3 -O0
DEFINES += -DDEBUG -DCC_ENABLE_CHIPMUNK_INTEGRATION -DCOCOS2D_DEBUG=1
LIB_DIR := $(LIB_DIR)/Debug
else
CCFLAGS += -O3
CXXFLAGS += -O3
DEFINES += -DNDEBUG -DCC_ENABLE_CHIPMUNK_INTEGRATION
LIB_DIR := $(LIB_DIR)/Release
endif

TARGET	= $(LIB_DIR)/libcocosdenshion.a

####### Build rules
$(TARGET): $(OBJECTS) 
	$(NACL_AR) $(ARFLAGS) $(TARGET) $(OBJECTS)

####### Compile
%.o: %.cpp
	$(NACL_CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

%.o: %.c
	$(NACL_CC) $(CCFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

clean: 
	rm -f $(OBJECTS) $(TARGET) core
