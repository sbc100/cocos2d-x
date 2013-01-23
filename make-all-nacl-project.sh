#!/bin/bash

MAKEFLAGS="-j10 CC=x86_64-nacl-gcc CXX=x86_64-nacl-g++"
TXTCOLOR_DEFAULT="\033[0;m"
TXTCOLOR_RED="\033[0;31m"
TXTCOLOR_GREEN="\033[0;32m"

COCOS2DX20_TRUNK=`pwd`
OUTPUT_DEBUG=$COCOS2DX20_TRUNK/lib/nacl/Debug/
OUTPUT_RELEASE=$COCOS2DX20_TRUNK/lib/nacl/Release/

check_make_result()
{
  if [ 0 != $? ]; then
    exit 1
  fi
}

mkdir -p $OUTPUT_DEBUG
mkdir -p $OUTPUT_RELEASE

#make $MAKEFLAGS -C $COCOS2DX20_TRUNK/cocos2dx/proj.nacl clean
make $MAKEFLAGS -C $COCOS2DX20_TRUNK/cocos2dx/proj.nacl debug
check_make_result
cp $COCOS2DX20_TRUNK/cocos2dx/proj.nacl/libcocos2d.a $OUTPUT_DEBUG
rm $COCOS2DX20_TRUNK/cocos2dx/proj.nacl/libcocos2d.a

#make $MAKEFLAGS -C $COCOS2DX20_TRUNK/cocos2dx/proj.nacl clean
#make $MAKEFLAGS -C $COCOS2DX20_TRUNK/cocos2dx/proj.nacl release
#check_make_result
#cp $COCOS2DX20_TRUNK/cocos2dx/proj.nacl/libcocos2d.a $OUTPUT_RELEASE
#rm $COCOS2DX20_TRUNK/cocos2dx/proj.nacl/libcocos2d.a

make $MAKEFLAGS -C $COCOS2DX20_TRUNK/samples/Cpp/HelloCpp/proj.nacl clean
make $MAKEFLAGS -C $COCOS2DX20_TRUNK/samples/Cpp/HelloCpp/proj.nacl debug
check_make_result
#make $MAKEFLAGS -C $COCOS2DX20_TRUNK/samples/Cpp/HelloCpp/proj.nacl clean
#make $MAKEFLAGS -C $COCOS2DX20_TRUNK/samples/Cpp/HelloCpp/proj.nacl release
#check_make_result

#make $MAKEFLAGS -C $COCOS2DX20_TRUNK/samples/Cpp/TestCpp/proj.nacl clean
#make $MAKEFLAGS -C $COCOS2DX20_TRUNK/samples/Cpp/TestCpp/proj.nacl debug
#check_make_result
#make $MAKEFLAGS -C $COCOS2DX20_TRUNK/samples/Cpp/TestCpp/proj.nacl clean
#make $MAKEFLAGS -C $COCOS2DX20_TRUNK/samples/Cpp/TestCpp/proj.nacl release
#check_make_result

