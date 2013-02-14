NACL_ARCH = x86_64
NACL_LIBC = newlib
CC      = $(NACL_ARCH)-nacl-gcc
CXX     = $(NACL_ARCH)-nacl-g++
CCFLAGS = -Wall
CXXFLAGS = -Wall
VISIBILITY =

COCOS_ROOT = ../../../../
COCOS2DX_PATH = $(COCOS_ROOT)/cocos2dx

INCLUDES =  -I../ \
	-I../Classes \
	-I$(COCOS2DX_PATH) \
	-I$(COCOS2DX_PATH)/cocoa \
	-I$(COCOS2DX_PATH)/include \
	-I$(COCOS2DX_PATH)/platform/nacl \
	-I$(COCOS2DX_PATH)/kazmath/include \
	-I$(COCOS_ROOT)/CocosDenshion/include \
	-I$(COCOS_ROOT)/scripting/lua/lua \
	-I$(COCOS_ROOT)/scripting/lua/tolua \
	-I$(COCOS_ROOT)/scripting/lua/cocos2dx_support \
	-I$(NACL_SDK_ROOT)/include \


SOURCES = ./main.cpp \
        ../Classes/AppDelegate.cpp \
        $(COCOS_ROOT)/scripting/lua/cocos2dx_support/CCLuaEngine.cpp \
        $(COCOS_ROOT)/scripting/lua/cocos2dx_support/Cocos2dxLuaLoader.cpp \
        $(COCOS_ROOT)/scripting/lua/cocos2dx_support/LuaCocos2d.cpp \
        $(COCOS_ROOT)/scripting/lua/cocos2dx_support/tolua_fix.c

include $(COCOS_ROOT)/cocos2dx/proj.nacl/cocos2dx.mk

STATICLIBS += -llua -lnosys

TARGET = $(BIN_DIR)/TestLua.nexe
NMF = $(basename $(TARGET)).nmf

all: $(TARGET) $(NMF)

####### Build rules
$(TARGET): $(OBJECTS) $(LIB_DIR)/libcocos2d.a
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(OBJECTS) -o $@ $(SHAREDLIBS) $(STATICLIBS)

####### Compile
%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) -MMD $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

%.o: %.c
	@mkdir -p $(@D)
	$(CC) -MMD $(CCFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET) $(DEPS) core


$(NMF): $(TARGET)
	$(NACL_SDK_ROOT)/tools/create_nmf.py -o $(NMF) $(TARGET) --objdump=i686-nacl-objdump -L$(NACL_SDK_ROOT)/toolchain/linux_x86_newlib/x86_64-nacl/lib/ -s $(BIN_DIR)

run: all
	/bin/cp -ar ../Resources/ .
	$(NACL_SDK_ROOT)/tools/httpd.py --no_dir_check

-include $(DEPS)

.PHONY: run clean nmf
