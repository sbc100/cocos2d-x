NACL_ARCH ?= x86_64
NACL_LIBC = newlib
AR      = $(NACL_ARCH)-nacl-ar
CC      = $(NACL_ARCH)-nacl-gcc
CXX     = $(NACL_ARCH)-nacl-g++
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


INCLUDES += -I$(COCOS2DX_PATH)/platform/third_party/nacl -I$(NACL_SDK_ROOT)/include -I$(NACL_SDK_ROOT)/toolchain/linux_x86_$(NACL_LIBC)/$(NACL_ARCH)-nacl/usr/include/libxml2

OBJECTS = ../blackberry/SimpleAudioEngine.o

ifeq ($(DEBUG), 1)
CCFLAGS += -g3 -O0
CXXFLAGS += -g3 -O0
DEFINES += -DDEBUG -DCC_ENABLE_CHIPMUNK_INTEGRATION -DCOCOS2D_DEBUG=1
LIB_DIR = ../../lib/nacl/Debug
else
CCFLAGS += -O3
CXXFLAGS += -O3
DEFINES += -DNDEBUG -DCC_ENABLE_CHIPMUNK_INTEGRATION
LIB_DIR = ../../lib/nacl/Release
endif

TARGET	= $(LIB_DIR)/libcocosdenshion.a

####### Build rules
$(TARGET): $(OBJECTS) 
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS)

####### Compile
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

clean: 
	rm -f $(OBJECTS) $(TARGET) core
