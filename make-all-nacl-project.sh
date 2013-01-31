#!/bin/bash
# Build script to build all components for Native Client.
#
# By default this script will only build debug versions.
# Pass "all" as an argument to build clean and also build
# release config.

MAKEFLAGS=-j10
TXTCOLOR_DEFAULT="\033[0;m"
TXTCOLOR_RED="\033[0;31m"
TXTCOLOR_GREEN="\033[0;32m"

COCOS2DX20_TRUNK=`pwd`
OUTPUT_DEBUG=lib/nacl/Debug/
OUTPUT_RELEASE=lib/nacl/Release/

set -e

mkdir -p $OUTPUT_DEBUG
mkdir -p $OUTPUT_RELEASE

cd $COCOS2DX20_TRUNK

clean()
{
    make $MAKEFLAGS -C cocos2dx/proj.nacl $1 clean
    make $MAKEFLAGS -C CocosDenshion/proj.nacl $1 clean
    make $MAKEFLAGS -C external/chipmunk/proj.nacl $1 clean
    make $MAKEFLAGS -C external/Box2D/proj.nacl $1 clean
    make $MAKEFLAGS -C samples/Cpp/HelloCpp/proj.nacl $1 clean
    make $MAKEFLAGS -C samples/Cpp/TestCpp/proj.nacl $1 clean
    make $MAKEFLAGS -C samples/Cpp/SimpleGame/proj.nacl $1 clean
}

if [ "$1" = "all" ]; then
    clean DEBUG=1
fi

make $MAKEFLAGS -C cocos2dx/proj.nacl DEBUG=1
make $MAKEFLAGS -C CocosDenshion/proj.nacl DEBUG=1
make $MAKEFLAGS -C external/chipmunk/proj.nacl DEBUG=1
make $MAKEFLAGS -C external/Box2D/proj.nacl DEBUG=1
make $MAKEFLAGS -C samples/Cpp/HelloCpp/proj.nacl DEBUG=1
make $MAKEFLAGS -C samples/Cpp/SimpleGame/proj.nacl DEBUG=1

if [ "$1" = "all" ]; then
    clean DEBUG=0
    make $MAKEFLAGS -C cocos2dx/proj.nacl DEBUG=0
    make $MAKEFLAGS -C CocosDenshion/proj.nacl DEBUG=0
    make $MAKEFLAGS -C external/chipmunk/proj.nacl DEBUG=0
    make $MAKEFLAGS -C external/Box2D/proj.nacl DEBUG=0
    make $MAKEFLAGS -C samples/Cpp/HelloCpp/proj.nacl DEBUG=0
    make $MAKEFLAGS -C samples/Cpp/SimpleGame/proj.nacl DEBUG=0
fi
