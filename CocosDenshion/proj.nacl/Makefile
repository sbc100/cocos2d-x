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

COCOS_ROOT = ../..

NACLPORTS_INCLUDE ?= $(NACL_SDK_ROOT)/toolchain/linux_x86_$(NACL_LIBC)/$(NACL_ARCH)-nacl/usr/include
INCLUDES = -I../include \
	-I$(NACL_SDK_ROOT)/include\
	-I$(NACLPORTS_INCLUDE)

SOURCES = ../blackberry/SimpleAudioEngine.cpp

include $(COCOS_ROOT)/cocos2dx/proj.nacl/cocos2dx.mk

TARGET = $(LIB_DIR)/libcocosdenshion.a

####### Build rules
$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(NACL_AR) $(ARFLAGS) $(TARGET) $(OBJECTS)

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

.PHONY: clean all
