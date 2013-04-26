#!/bin/bash
# Build script to build all components for Native Client.
#
# By default this script will only build debug versions.
# Pass "all" as an argument to build clean and also build
# release config.
#
# Before running this script you need to set NACL_SDK_ROOT
# and add the NaCl compiler bin folder to your path.
#
# There are several libraries from naclports that are
# prerequisite for building cocos2dx on NaCl.  These ship
# with recent versions of the NaCl SDK or you can build
# them yourself by checking out naclports and running:
# $ make png tiff freetype xml2 freealut jpeg vorbis ogg

if [ -z "$NACL_SDK_ROOT" ]; then
   echo "Please set \$NACL_SDK_ROOT"
   exit 1
fi

SCRIPT_DIR=$(dirname ${BASH_SOURCE})
OUTPUT_DEBUG=lib/nacl/Debug/
OUTPUT_RELEASE=lib/nacl/Release/

set -e
set -x

cd $SCRIPT_DIR

mkdir -p $OUTPUT_DEBUG
mkdir -p $OUTPUT_RELEASE

export MAKEFLAGS="-j10 PLATFORM=nacl"

if [ "$1" = "clean" ]; then
    make DEBUG=1 clean
    make DEBUG=0 clean
    exit 0
fi

make NACL_ARCH=x86_64 DEBUG=1 all
make NACL_ARCH=x86_64 DEBUG=0 all

make NACL_ARCH=i686 DEBUG=1 all
make NACL_ARCH=i686 DEBUG=0 all

make NACL_ARCH=arm DEBUG=1 all
make NACL_ARCH=arm DEBUG=0 all
