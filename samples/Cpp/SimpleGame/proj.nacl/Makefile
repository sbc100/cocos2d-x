COCOS_ROOT = ../../../..
COCOS2DX_PATH = $(COCOS_ROOT)/cocos2dx

INCLUDES = -I.. \
	-I../Classes \
	-I$(COCOS_ROOT)/CocosDenshion/include \

SOURCES = main.cpp \
        ../Classes/AppDelegate.cpp \
        ../Classes/HelloWorldScene.cpp \
        ../Classes/GameOverScene.cpp

include $(COCOS_ROOT)/cocos2dx/proj.nacl/cocos2dx.mk

SHAREDLIBS += -lbox2d

APP_NAME = SimpleGame
TARGET = $(BIN_DIR)/$(APP_NAME)$(TARGET_SUFFIX)
NMF = $(BIN_DIR)/$(APP_NAME).nmf

all: $(NMF)

$(TARGET): $(OBJECTS) $(COCOS_LIB) $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_LINK)$(NACL_CXX) $(LDFLAGS) $(LDFLAGS) $(OBJECTS) -o $@ $(SHAREDLIBS) $(STATICLIBS)

$(OBJ_DIR)/%.o: ../%.cpp
	@mkdir -p $(@D)
	$(LOG_CXX)$(NACL_CXX) -MMD $(CXXFLAGS) $(INCLUDES) $(DEFINES) -c $< -o $@

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(LOG_CXX)$(NACL_CXX) -MMD $(CXXFLAGS) $(INCLUDES) $(DEFINES) -c $< -o $@

$(NMF): $(TARGET)
	$(NACL_SDK_ROOT)/tools/create_nmf.py -o $@ $(BIN_DIR)/*$(EXE_EXT) $(NMF_FLAGS) -s $(BIN_DIR)

run: all
	/bin/cp -ar ../Resources/ .
	$(NACL_SDK_ROOT)/tools/httpd.py --no_dir_check

.PHONY: run
