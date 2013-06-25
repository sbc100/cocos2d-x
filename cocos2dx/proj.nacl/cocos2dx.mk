# This makefile is included by each of the cocos2d-x libraries and examples
# when building for Native Client.  It defines a set of variables that all
# cocos2dx projects have in common.

ifeq ($(NACL_SDK_ROOT),)
  $(error $$NACL_SDK_ROOT not set)
endif

NACL_SDK_VERSION_MIN=27.186236
VERSION_CHECK:=$(shell $(NACL_SDK_ROOT)/tools/getos.py --check-version=$(NACL_SDK_VERSION_MIN) 2>&1)
ifneq ($(VERSION_CHECK),)
  $(error $(VERSION_CHECK))
endif

all:

ifeq ($(NACL_GLIBC),1)
NACL_LIBC = glibc
else
NACL_LIBC = newlib
endif

NACL_ARCH ?= x86_64
CCFLAGS += -Wall -Werror
CXXFLAGS += -Wall -Werror -std=gnu++0x
ifeq ($(NACL_ARCH),pnacl)
NACL_AR ?= $(NACL_ARCH)-ar
NACL_CC ?= $(NACL_ARCH)-clang
NACL_CXX ?= $(NACL_ARCH)-clang++
CXXFLAGS += -Wno-overloaded-virtual -Wno-unused-private-field
else
NACL_AR ?= $(NACL_ARCH)-nacl-ar
NACL_CC ?= $(NACL_ARCH)-nacl-gcc
NACL_CXX ?= $(NACL_ARCH)-nacl-g++
CFLAGS += -Wno-deprecated-declarations
# GCC 4.6 is primary platform for cocos2d v.3, because it's default compiler for Android,
# Blackberry, some Linux distributions.It supports all important features of c++11, but have
# no flag "-std=c++11" (which was turned on in version 4.7).
CXXFLAGS += -Wno-deprecated-declarations
endif
ARFLAGS = cr

THIS_MAKEFILE := $(CURDIR)/$(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))

# The top level of the cocos2dx-x source tree.  The parent Makefile will
# often define this, but in case is doesn't we can find it relative to
# THIS_MAKEFILE
ifndef COCOS_ROOT
COCOS_ROOT := $(realpath $(dir $(THIS_MAKEFILE))/../..)
endif
COCOS_SRC := $(COCOS_ROOT)/cocos2dx

ifeq ($(NACL_ARCH),pnacl)
ARCH_DIR := $(NACL_ARCH)
else
ifeq ($(NACL_ARCH),i686)
ARCH_DIR := $(NACL_LIBC)_x86_32
else
ARCH_DIR := $(NACL_LIBC)_$(NACL_ARCH)
endif
endif

ifeq ($(NACL_ARCH),pnacl)
PORTS_ARCH_DIR := $(NACL_LIBC)_$(NACL_ARCH)
EXE_EXT := .pexe
TARGET_SUFFIX = $(EXE_EXT)
else
PORTS_ARCH_DIR := $(ARCH_DIR)
EXE_EXT := .nexe
TARGET_SUFFIX = _$(NACL_ARCH)$(EXE_EXT)
endif

NACLPORTS_ROOT ?= $(NACL_SDK_ROOT)/ports
NACLPORTS_INCLUDE ?= $(NACLPORTS_ROOT)/include
OUT_DIR ?= obj
OBJ_DIR ?= $(OUT_DIR)/$(NACL_LIBC)_$(NACL_ARCH)
LIB_DIR ?= $(COCOS_ROOT)/lib/nacl/$(ARCH_DIR)

ifeq ($(NACL_GLIBC),1)
COCOS_LIB = $(LIB_DIR)/libcocos2d.so
else
COCOS_LIB = $(LIB_DIR)/libcocos2d.a
endif

ifdef USE_BOX2D
DEFINES += -DCC_ENABLE_BOX2D_INTEGRATION=1
else
DEFINES += -DCC_ENABLE_CHIPMUNK_INTEGRATION=1
endif

INCLUDES += -I$(COCOS_SRC) \
	-I$(COCOS_SRC)/cocoa \
	-I$(COCOS_SRC)/include \
	-I$(COCOS_SRC)/kazmath/include \
	-I$(COCOS_SRC)/platform \
	-I$(COCOS_SRC)/platform/nacl \
	-I$(NACL_SDK_ROOT)/include \
	-isystem $(NACLPORTS_INCLUDE) \
	-isystem $(NACLPORTS_INCLUDE)/libxml2

ifeq ($(DEBUG), 1)
CONFIG = Debug
BIN_DIR = bin/debug
CFLAGS += -g3 -O0
CXXFLAGS += -g3 -O0
DEFINES += -D_DEBUG -DCOCOS2D_DEBUG=1
else
CONFIG = Release
BIN_DIR = bin/release
CFLAGS += -O3
CXXFLAGS += -O3
DEFINES += -DNDEBUG
endif

LIB_DIR := $(LIB_DIR)/$(CONFIG)
OBJ_DIR := $(OBJ_DIR)/$(CONFIG)
MULTILIB_DIR := $(ARCH_DIR)/$(CONFIG)
PORTS_MULTILIB_DIR := $(PORTS_ARCH_DIR)/$(CONFIG)

ifndef V
LOG_CC = @echo " CC $@";
LOG_CXX = @echo " CXX $@";
LOG_AR = @echo " AR $@";
LOG_LINK = @echo " LINK $@";
LOG_LDSO = @echo " LDSO $@";
endif

NMF_FLAGS = --objdump=i686-nacl-objdump
NMF_FLAGS += -L$(COCOS_ROOT)/lib/nacl/glibc_x86_32/$(CONFIG)
NMF_FLAGS += -L$(COCOS_ROOT)/lib/nacl/glibc_x86_64/$(CONFIG)
NMF_FLAGS += -L$(NACL_SDK_ROOT)/toolchain/linux_x86_$(NACL_LIBC)/x86_64-nacl/lib32/
NMF_FLAGS += -L$(NACL_SDK_ROOT)/toolchain/linux_x86_$(NACL_LIBC)/x86_64-nacl/lib64/
NMF_FLAGS += -L$(NACL_SDK_ROOT)/lib/$(NACL_LIBC)_x86_32/Release
NMF_FLAGS += -L$(NACL_SDK_ROOT)/lib/$(NACL_LIBC)_x86_64/Release
NMF_FLAGS += -L$(NACLPORTS_ROOT)/lib/$(NACL_LIBC)_x86_32/Release
NMF_FLAGS += -L$(NACLPORTS_ROOT)/lib/$(NACL_LIBC)_x86_64/Release

# The default library search path consists of the cocos2dx library path, the
# main nacl sdk library path and the naclports library path.
LDFLAGS += -L$(LIB_DIR)
LDFLAGS += -L$(NACL_SDK_ROOT)/lib/$(MULTILIB_DIR)
LDFLAGS += -L$(NACLPORTS_ROOT)/lib/$(PORTS_MULTILIB_DIR)

# Some cococs sources use #pragma mark
CFLAGS += -Wno-unknown-pragmas
CXXFLAGS += -Wno-unknown-pragmas

ifeq ($(NACL_GLIBC),1)
CFLAGS += -fPIC
CXXFLAGS += -fPIC
endif

ifeq ($(NACL_ARCH),arm)
# Don't warn about mangling of 'va_list' on arm builds
CFLAGS += -Wno-psabi
CXXFLAGS += -Wno-psabi
endif

SOUNDLIBS := -lalut -lopenal -lvorbisfile -lvorbis -logg
STATICLIBS += $(SOUNDLIBS) -lfreetype -lxml2 -lwebp -lpng -ljpeg -ltiff -llua -lchipmunk
STATICLIBS += -lnacl_io -lppapi_gles2 -lppapi -lppapi_cpp
SHAREDLIBS += -lpthread -lcocosdenshion -lcocos2d -lz

OBJECTS := $(SOURCES:.cpp=.o)
OBJECTS := $(OBJECTS:.c=.o)
OBJECTS := $(subst ../,,$(OBJECTS))
OBJECTS := $(subst $(COCOS_ROOT)/,,$(OBJECTS))
OBJECTS := $(addprefix $(OBJ_DIR)/, $(OBJECTS))
DEPS = $(OBJECTS:.o=.d)
CORE_MAKEFILE_LIST := $(MAKEFILE_LIST)
-include $(DEPS)

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(TARGET) core

.PHONY: all clean
