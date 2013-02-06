NACL_ARCH = x86_64
NACL_LIBC = newlib
CC      = $(NACL_ARCH)-nacl-gcc
CXX     = $(NACL_ARCH)-nacl-g++
CCFLAGS = -Wall
CXXFLAGS = -Wall
VISIBILITY =

COCOS2DX_PATH = ../../../../cocos2dx
INCLUDES =  -I../ \
			-I../Classes \
			-I$(COCOS2DX_PATH) \
			-I$(COCOS2DX_PATH)/cocoa \
			-I$(COCOS2DX_PATH)/include \
			-I$(COCOS2DX_PATH)/platform/nacl \
			-I$(COCOS2DX_PATH)/kazmath/include \
			-I../../../../CocosDenshion/include \
			-I$(NACL_SDK_ROOT)/include


SOURCES = main.cpp \
        ../Classes/AppDelegate.cpp \
        ../Classes/HelloWorldScene.cpp \
        ../Classes/GameOverScene.cpp

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

SOUNDLIBS = -lalut -lopenal -lvorbisfile -lvorbis -logg
FONTLIBS = -lfontconfig -lfreetype -lexpat 

STATICLIBS += $(SOUNDLIBS) $(FONTLIBS) -lxml2 -lpng -ljpeg -ltiff -lppapi_gles2 -lnacl-mounts -lppapi -lppapi_cpp
SHAREDLIBS += -lcocos2d -lcocosdenshion -lchipmunk -lbox2d -lz

OBJECTS := $(SOURCES:.cpp=.o)
OBJECTS := $(OBJECTS:.c=.o)
OBJECTS := $(subst ../,,$(OBJECTS))
OBJECTS := $(addprefix $(OBJ_DIR)/, $(OBJECTS))
DEPS = $(OBJECTS:.o=.d)

TARGET = $(BIN_DIR)/SimpleGame.nexe
NMF = $(basename $(TARGET)).nmf

all: $(TARGET) $(NMF)

####### Build rules
$(TARGET): $(OBJECTS) $(LIB_DIR)/libcocos2d.a
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(OBJECTS) -o $@ $(SHAREDLIBS) $(STATICLIBS)

####### Compile
$(OBJ_DIR)/%.o: ../%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

$(OBJ_DIR)/%.o: ../%.c
	@mkdir -p $(@D)
	$(CC) $(CCFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(TARGET) core


$(NMF): $(TARGET)
	$(NACL_SDK_ROOT)/tools/create_nmf.py -o $(NMF) $(TARGET) --objdump=i686-nacl-objdump -L$(NACL_SDK_ROOT)/toolchain/linux_x86_newlib/x86_64-nacl/lib/ -s $(BIN_DIR)

run: all
	/bin/cp -ar ../Resources/ .
	$(NACL_SDK_ROOT)/tools/httpd.py --no_dir_check

.PHONY: run clean nmf
