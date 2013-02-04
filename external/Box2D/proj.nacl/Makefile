NACL_ARCH ?= x86_64
NACL_LIBC = newlib
NACL_AR ?= $(NACL_ARCH)-nacl-ar
NACL_CC ?= $(NACL_ARCH)-nacl-gcc
NACL_CXX ?= $(NACL_ARCH)-nacl-g++
CCFLAGS = -Wall -std=gnu99
CXXFLAGS = -Wall
VISIBILITY =
ARFLAGS = cr

LIBS =

INCLUDES = -I../..

OBJECTS = ../Collision/Shapes/b2ChainShape.o \
../Collision/Shapes/b2CircleShape.o \
../Collision/Shapes/b2EdgeShape.o \
../Collision/Shapes/b2PolygonShape.o \
../Collision/b2BroadPhase.o \
../Collision/b2CollideCircle.o \
../Collision/b2CollideEdge.o \
../Collision/b2CollidePolygon.o \
../Collision/b2Collision.o \
../Collision/b2Distance.o \
../Collision/b2DynamicTree.o \
../Collision/b2TimeOfImpact.o \
../Common/b2BlockAllocator.o \
../Common/b2Draw.o \
../Common/b2Math.o \
../Common/b2Settings.o \
../Common/b2StackAllocator.o \
../Common/b2Timer.o \
../Dynamics/Contacts/b2ChainAndCircleContact.o \
../Dynamics/Contacts/b2ChainAndPolygonContact.o \
../Dynamics/Contacts/b2CircleContact.o \
../Dynamics/Contacts/b2Contact.o \
../Dynamics/Contacts/b2ContactSolver.o \
../Dynamics/Contacts/b2EdgeAndCircleContact.o \
../Dynamics/Contacts/b2EdgeAndPolygonContact.o \
../Dynamics/Contacts/b2PolygonAndCircleContact.o \
../Dynamics/Contacts/b2PolygonContact.o \
../Dynamics/Joints/b2DistanceJoint.o \
../Dynamics/Joints/b2FrictionJoint.o \
../Dynamics/Joints/b2GearJoint.o \
../Dynamics/Joints/b2Joint.o \
../Dynamics/Joints/b2MouseJoint.o \
../Dynamics/Joints/b2PrismaticJoint.o \
../Dynamics/Joints/b2PulleyJoint.o \
../Dynamics/Joints/b2RevoluteJoint.o \
../Dynamics/Joints/b2RopeJoint.o \
../Dynamics/Joints/b2WeldJoint.o \
../Dynamics/Joints/b2WheelJoint.o \
../Dynamics/b2Body.o \
../Dynamics/b2ContactManager.o \
../Dynamics/b2Fixture.o \
../Dynamics/b2Island.o \
../Dynamics/b2World.o \
../Dynamics/b2WorldCallbacks.o \
../Rope/b2Rope.o

DEPS = $(OBJECTS:.o=.d)

LIB_DIR?=../../../lib/nacl
ifeq ($(DEBUG), 1)
CCFLAGS += -g3 -O0
CXXFLAGS += -g3 -O0
DEFINES += -DDEBUG -DCOCOS2D_DEBUG=1
LIB_DIR := $(LIB_DIR)/Debug
else
CCFLAGS += -O3
CXXFLAGS += -O3
DEFINES += -DNDEBUG
LIB_DIR := $(LIB_DIR)/Release
endif

TARGET = $(LIB_DIR)/libbox2d.a

####### Build rules
$(TARGET): $(OBJECTS)
	$(NACL_AR) $(ARFLAGS) $(TARGET) $(OBJECTS)

####### Compile
%.o: %.cpp
	$(NACL_CXX) -MMD $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

%.o: %.c
	$(NALC_CC) -MMD $(CCFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET) $(DEPS) core

-include $(DEPS)
