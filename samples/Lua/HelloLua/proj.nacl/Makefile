COCOS_ROOT = ../../../..
COCOS2DX_PATH = $(COCOS_ROOT)/cocos2dx

INCLUDES =  -I.. \
	-I../Classes \
	-I$(COCOS_ROOT)/CocosDenshion/include \
	-I$(COCOS_ROOT)/scripting/lua/lua \
	-I$(COCOS_ROOT)/scripting/lua/tolua \
	-I$(COCOS_ROOT)/scripting/lua/cocos2dx_support \
	-I$(NACL_SDK_ROOT)/include \


SOURCES = main.cpp \
        ../Classes/AppDelegate.cpp \
        $(COCOS_ROOT)/scripting/lua/cocos2dx_support/CCLuaEngine.cpp \
        $(COCOS_ROOT)/scripting/lua/cocos2dx_support/CCLuaStack.cpp \
        $(COCOS_ROOT)/scripting/lua/cocos2dx_support/Cocos2dxLuaLoader.cpp \
        $(COCOS_ROOT)/scripting/lua/cocos2dx_support/LuaCocos2d.cpp \
        $(COCOS_ROOT)/scripting/lua/cocos2dx_support/tolua_fix.c

include $(COCOS_ROOT)/cocos2dx/proj.nacl/cocos2dx.mk

APP_NAME = HelloLua
TARGET = $(BIN_DIR)/$(APP_NAME)$(TARGET_SUFFIX)
NMF = $(BIN_DIR)/$(APP_NAME).nmf

all: $(NMF)

$(TARGET): $(OBJECTS) $(COCOS_LIB)
	@mkdir -p $(@D)
	$(LOG_LINK)$(NACL_CXX) $(LDFLAGS) $(OBJECTS) -o $@ $(SHAREDLIBS) $(STATICLIBS)

$(OBJ_DIR)/%.o: ../%.cpp
	@mkdir -p $(@D)
	$(LOG_CXX)$(NACL_CXX) -MMD $(CXXFLAGS) $(INCLUDES) $(DEFINES) -c $< -o $@

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(LOG_CXX)$(NACL_CXX) -MMD $(CXXFLAGS) $(INCLUDES) $(DEFINES) -c $< -o $@

$(OBJ_DIR)/%.o: $(COCOS_ROOT)/%.cpp
	@mkdir -p $(@D)
	$(LOG_CXX)$(NACL_CXX) -MMD $(CXXFLAGS) $(INCLUDES) $(DEFINES) -c $< -o $@

$(OBJ_DIR)/%.o: $(COCOS_ROOT)/%.c
	@mkdir -p $(@D)
	$(LOG_CC)$(NACL_CC) -MMD $(CFLAGS) $(INCLUDES) $(DEFINES) -c $< -o $@

$(NMF): $(TARGET)
	$(NACL_SDK_ROOT)/tools/create_nmf.py -o $@ $(BIN_DIR)/*$(EXE_EXT) $(NMF_FLAGS) -s $(BIN_DIR)

run: all
	/bin/cp -ar ../Resources/ .
	$(NACL_SDK_ROOT)/tools/httpd.py --no_dir_check
