THIS_MAKEFILE := $(CURDIR)/$(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))

# The top level of the cocos2dx-x source tree.  The parent Makefile will
# often define this, but in case is doesn't we can find it relative to
# THIS_MAKEFILE
COCOS_ROOT ?= $(realpath $(dir $(THIS_MAKEFILE))/../..)

OBJ_DIR ?= out/$(NACL_ARCH)
LIB_DIR ?= $(COCOS_ROOT)/lib/nacl

ifeq ($(DEBUG), 1)
BIN_DIR = bin/debug
CCFLAGS += -g3 -O0
CXXFLAGS += -g3 -O0
LIB_DIR := $(LIB_DIR)/Debug
OBJ_DIR := $(OBJ_DIR)/Debug
DEFINES += -DDEBUG -DCOCOS2D_DEBUG=1
STATICLIBS = -L$(NACL_SDK_ROOT)/lib/$(NACL_LIBC)_$(NACL_ARCH)/Debug
else
BIN_DIR = bin/release
CCFLAGS += -O3
CXXFLAGS += -O3
LIB_DIR := $(LIB_DIR)/Release
OBJ_DIR := $(OBJ_DIR)/Release
DEFINES += -DNDEBUG
STATICLIBS = -L$(NACL_SDK_ROOT)/lib/$(NACL_LIBC)_$(NACL_ARCH)/Release
endif

SOUNDLIBS = -lalut -lopenal -lvorbisfile -lvorbis -logg
FONTLIBS = -lfontconfig -lfreetype -lexpat

ifdef NACL_MOUNTS
DEFINES += -DOLD_NACL_MOUNTS
STATICLIBS += -lnacl-mounts
else
STATICLIBS += -lnacl_io
endif

STATICLIBS += $(SOUNDLIBS) $(FONTLIBS) -lxml2 -lpng -ljpeg -ltiff -llua 
STATICLIBS += -lppapi_gles2 -lppapi -lppapi_cpp -lnosys
SHAREDLIBS += -L$(LIB_DIR)
SHAREDLIBS += -lpthread -lcocosdenshion -lcocos2d -lz

OBJECTS := $(SOURCES:.cpp=.o)
OBJECTS := $(OBJECTS:.c=.o)
OBJECTS := $(subst ../,,$(OBJECTS))
OBJECTS := $(subst $(COCOS_ROOT)/,,$(OBJECTS))
OBJECTS := $(addprefix $(OBJ_DIR)/, $(OBJECTS))
DEPS = $(OBJECTS:.o=.d)
