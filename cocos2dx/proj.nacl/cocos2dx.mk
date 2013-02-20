# This makefile is included by each of the cocos2d-x libraries and examples
# when building for Native Client.  It defines a set of variables that all
# cocos2dx projects have in common.

NACL_LIBC = newlib
NACL_ARCH ?= x86_64
NACL_AR ?= $(NACL_ARCH)-nacl-ar
NACL_CC ?= $(NACL_ARCH)-nacl-gcc
NACL_CXX ?= $(NACL_ARCH)-nacl-g++
CCFLAGS ?= -Wall
CXXFLAGS ?= -Wall
ARFLAGS ?= cr

THIS_MAKEFILE := $(CURDIR)/$(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))

# The top level of the cocos2dx-x source tree.  The parent Makefile will
# often define this, but in case is doesn't we can find it relative to
# THIS_MAKEFILE
COCOS_ROOT ?= $(realpath $(dir $(THIS_MAKEFILE))/../..)

NACLPORTS_ROOT ?= $(NACL_SDK_ROOT)/ports
NACLPORTS_INCLUDE ?= $(NACLPORTS_ROOT)/include
OBJ_DIR ?= out/$(NACL_ARCH)
LIB_DIR ?= $(COCOS_ROOT)/lib/nacl

INCLUDES += -I$(NACL_SDK_ROOT)/include -I$(NACLPORTS_INCLUDE) -I$(NACLPORTS_INCLUDE)/libxml2

ifeq ($(DEBUG), 1)
BIN_DIR = bin/debug
CCFLAGS += -g3 -O0
CXXFLAGS += -g3 -O0
LIB_DIR := $(LIB_DIR)/Debug
OBJ_DIR := $(OBJ_DIR)/Debug
MULTILIB_SUFFIX := $(NACL_LIBC)_$(NACL_ARCH)/Debug
DEFINES += -DDEBUG -DCOCOS2D_DEBUG=1
else
BIN_DIR = bin/release
CCFLAGS += -O3
CXXFLAGS += -O3
LIB_DIR := $(LIB_DIR)/Release
OBJ_DIR := $(OBJ_DIR)/Release
MULTILIB_SUFFIX := $(NACL_LIBC)_$(NACL_ARCH)/Release
DEFINES += -DNDEBUG
endif

# The default library search path consists of the cocos2dx library path, the
# main nacl sdk library path and the naclports library path.
LDFLAGS += -L$(LIB_DIR)
LDFLAGS += -L$(NACL_SDK_ROOT)/lib/$(MULTILIB_SUFFIX)
LDFLAGS += -L$(NACLPORTS_ROOT)/lib/$(MULTILIB_SUFFIX)

# Some cococs sources use #pragma mark
CCFLAGS += -Wno-unknown-pragmas
CXXFLAGS += -Wno-unknown-pragmas

ifdef NACL_MOUNTS
DEFINES += -DOLD_NACL_MOUNTS
STATICLIBS += -lnacl-mounts
else
STATICLIBS += -lnacl_io
endif

SOUNDLIBS := -lalut -lopenal -lvorbisfile -lvorbis -logg
STATICLIBS += $(SOUNDLIBS) -lfreetype -lxml2 -lpng -ljpeg -ltiff -llua
STATICLIBS += -lppapi_gles2 -lppapi -lppapi_cpp -lnosys
SHAREDLIBS += -lpthread -lcocosdenshion -lcocos2d -lz

OBJECTS := $(SOURCES:.cpp=.o)
OBJECTS := $(OBJECTS:.c=.o)
OBJECTS := $(subst ../,,$(OBJECTS))
OBJECTS := $(subst $(COCOS_ROOT)/,,$(OBJECTS))
OBJECTS := $(addprefix $(OBJ_DIR)/, $(OBJECTS))
DEPS = $(OBJECTS:.o=.d)
