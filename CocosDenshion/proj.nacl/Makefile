COCOS_ROOT = ../..

INCLUDES = -I../include

SOURCES = ../blackberry/SimpleAudioEngine.cpp

include $(COCOS_ROOT)/cocos2dx/proj.nacl/cocos2dx.mk

ifeq ($(NACL_GLIBC),1)
TARGET = $(LIB_DIR)/libcocosdenshion.so
CXXFLAGS += -fPIC
CCFLAGS += -fPIC
else
TARGET = $(LIB_DIR)/libcocosdenshion.a
endif

all: $(TARGET)

ifeq ($(NACL_GLIBC),1)
$(TARGET): $(OBJECTS) $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_LDSO)$(NACL_CXX) -shared $(CXXFLAGS) -o $@ $(OBJECTS)
else
$(TARGET): $(OBJECTS) $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_AR)$(NACL_AR) $(ARFLAGS) $(TARGET) $(OBJECTS)
endif

$(OBJ_DIR)/%.o: ../%.cpp $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_CXX)$(NACL_CXX) -MMD $(CXXFLAGS) $(INCLUDES) $(DEFINES) -c $< -o $@
