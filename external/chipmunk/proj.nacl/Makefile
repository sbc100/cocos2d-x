NACL_ARCH ?= x86_64
NACL_AR ?= $(NACL_ARCH)-nacl-ar
NACL_CC ?= $(NACL_ARCH)-nacl-gcc
NACL_CXX ?= $(NACL_ARCH)-nacl-g++
CCFLAGS = -Wall -std=gnu99
CXXFLAGS = -Wall
VISIBILITY =
ARFLAGS = cr

LIBS =

INCLUDES = -I../include/chipmunk

SOURCES = ../src/chipmunk.cpp \
../src/cpBody.cpp \
../src/cpSpace.cpp \
../src/cpSpatialIndex.cpp \
../src/cpArbiter.cpp \
../src/cpCollision.cpp \
../src/cpSpaceComponent.cpp \
../src/cpSweep1D.cpp \
../src/cpArray.cpp \
../src/cpHashSet.cpp \
../src/cpSpaceHash.cpp \
../src/cpVect.cpp \
../src/cpBB.cpp \
../src/cpPolyShape.cpp \
../src/cpSpaceQuery.cpp \
../src/cpBBTree.cpp \
../src/cpShape.cpp \
../src/cpSpaceStep.cpp \
../src/constraints/cpConstraint.cpp \
../src/constraints/cpPivotJoint.cpp \
../src/constraints/cpDampedRotarySpring.cpp \
../src/constraints/cpRatchetJoint.cpp \
../src/constraints/cpDampedSpring.cpp \
../src/constraints/cpRotaryLimitJoint.cpp \
../src/constraints/cpGearJoint.cpp \
../src/constraints/cpSimpleMotor.cpp \
../src/constraints/cpGrooveJoint.cpp \
../src/constraints/cpSlideJoint.cpp \
../src/constraints/cpPinJoint.cpp

OBJ_DIR ?= out/$(NACL_ARCH)

ifeq ($(DEBUG), 1)
CCFLAGS += -g3 -O0
CXXFLAGS += -g3 -O0
DEFINES += -DDEBUG -DCC_ENABLE_CHIPMUNK_INTEGRATION -DCOCOS2D_DEBUG=1
LIB_DIR = ../../../lib/nacl/Debug
OBJ_DIR := $(OBJ_DIR)/Debug
else
CCFLAGS += -O3
CXXFLAGS += -O3
DEFINES += -DNDEBUG -DCC_ENABLE_CHIPMUNK_INTEGRATION
LIB_DIR = ../../../lib/nacl/Release
OBJ_DIR := $(OBJ_DIR)/Release
endif

OBJECTS := $(SOURCES:.cpp=.o)
OBJECTS := $(OBJECTS:.c=.o)
OBJECTS := $(subst ../,,$(OBJECTS))
OBJECTS := $(addprefix $(OBJ_DIR)/, $(OBJECTS))
DEPS = $(OBJECTS:.o=.d)

TARGET = $(LIB_DIR)/libchipmunk.a

all: $(TARGET)

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
	rm -rf $(OBJ_DIR)
	rm -f $(TARGET) core

-include $(DEPS)
