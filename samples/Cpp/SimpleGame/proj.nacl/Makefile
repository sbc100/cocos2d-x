NACL_ARCH = x86_64
NACL_LIBC = newlib
CC      = $(NACL_ARCH)-nacl-gcc
CXX     = $(NACL_ARCH)-nacl-g++
CCFLAGS = -Wall
CXXFLAGS = -Wall
VISIBILITY =

COCOS_ROOT = ../../../..
COCOS2DX_PATH = $(COCOS_ROOT)/cocos2dx

INCLUDES = -I../ \
	-I../Classes \
	-I$(COCOS2DX_PATH) \
	-I$(COCOS2DX_PATH)/cocoa \
	-I$(COCOS2DX_PATH)/include \
	-I$(COCOS2DX_PATH)/platform/nacl \
	-I$(COCOS2DX_PATH)/kazmath/include \
	-I$(COCOS_ROOT)/CocosDenshion/include \
	-I$(NACL_SDK_ROOT)/include

SOURCES = main.cpp \
        ../Classes/AppDelegate.cpp \
        ../Classes/HelloWorldScene.cpp \
        ../Classes/GameOverScene.cpp

include $(COCOS_ROOT)/cocos2dx/proj.nacl/cocos2dx.mk

SHAREDLIBS += -lchipmunk -lbox2d 

TARGET = $(BIN_DIR)/SimpleGame.nexe
NMF = $(basename $(TARGET)).nmf

all: $(TARGET) $(NMF)

####### Build rules
$(TARGET): $(OBJECTS) $(LIB_DIR)/libcocos2d.a
	@mkdir -p $(@D)
	$(NACL_CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) -o $@ $(SHAREDLIBS) $(STATICLIBS)

####### Compile
$(OBJ_DIR)/%.o: ../%.cpp
	@mkdir -p $(@D)
	$(NACL_CXX) -MMD $(CXXFLAGS) $(INCLUDES) $(DEFINES) -c $< -o $@

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(NACL_CXX) -MMD $(CXXFLAGS) $(INCLUDES) $(DEFINES) -c $< -o $@

$(OBJ_DIR)/%.o: ../%.c
	@mkdir -p $(@D)
	$(NACL_CC) -MMD $(CCFLAGS) $(INCLUDES) $(DEFINES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(TARGET) core


$(NMF): $(TARGET)
	$(NACL_SDK_ROOT)/tools/create_nmf.py -o $(NMF) $(TARGET) --objdump=i686-nacl-objdump -L$(NACL_SDK_ROOT)/toolchain/linux_x86_newlib/x86_64-nacl/lib/ -s $(BIN_DIR)

run: all
	/bin/cp -ar ../Resources/ .
	$(NACL_SDK_ROOT)/tools/httpd.py --no_dir_check

-include $(DEPS)

.PHONY: run clean nmf
