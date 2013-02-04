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

OBJECTS = ../src/chipmunk.o \
../src/cpBody.o \
../src/cpSpace.o \
../src/cpSpatialIndex.o \
../src/cpArbiter.o \
../src/cpCollision.o \
../src/cpSpaceComponent.o \
../src/cpSweep1D.o \
../src/cpArray.o \
../src/cpHashSet.o \
../src/cpSpaceHash.o \
../src/cpVect.o \
../src/cpBB.o \
../src/cpPolyShape.o \
../src/cpSpaceQuery.o \
../src/cpBBTree.o \
../src/cpShape.o \
../src/cpSpaceStep.o \
../src/constraints/cpConstraint.o \
../src/constraints/cpPivotJoint.o \
../src/constraints/cpDampedRotarySpring.o \
../src/constraints/cpRatchetJoint.o \
../src/constraints/cpDampedSpring.o \
../src/constraints/cpRotaryLimitJoint.o \
../src/constraints/cpGearJoint.o \
../src/constraints/cpSimpleMotor.o \
../src/constraints/cpGrooveJoint.o \
../src/constraints/cpSlideJoint.o \
../src/constraints/cpPinJoint.o

DEPS = $(OBJECTS:.o=.d)

ifeq ($(DEBUG), 1)
CCFLAGS += -g3 -O0
CXXFLAGS += -g3 -O0
DEFINES += -DDEBUG -DCC_ENABLE_CHIPMUNK_INTEGRATION -DCOCOS2D_DEBUG=1
LIB_DIR = ../../../lib/nacl/Debug
else
CCFLAGS += -O3
CXXFLAGS += -O3
DEFINES += -DNDEBUG -DCC_ENABLE_CHIPMUNK_INTEGRATION
LIB_DIR = ../../../lib/nacl/Release
endif

TARGET= $(LIB_DIR)/libchipmunk.a

all: $(TARGET)

####### Build rules
$(TARGET): $(OBJECTS)
	$(NACL_AR) $(ARFLAGS) $(TARGET) $(OBJECTS)

####### Compile
%.o: %.cpp
	$(NACL_CXX) -MMD $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

%.o: %.c
	$(NACL_CC) -MMD $(CCFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET) $(DEPS) core

-include $(DEPS)
