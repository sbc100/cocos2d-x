#!/bin/bash
# exit this script if any commmand fails
set -e

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
COCOS2DX_ROOT="$DIR"/../..
CORES=`nproc`
echo ${CORES}
export NDK_ROOT=$HOME/bin/android-ndk

if [ "$GEN_JSB"x = "YES"x ]; then
    if [ "$TRAVIS_PULL_REQUEST" != "false" ]; then
        exit 0
    fi
    cd $COCOS2DX_ROOT/tools/travis-scripts
    ./generate-jsbindings.sh
fi

build_android()
{
    cd $COCOS2DX_ROOT/samples/$1/$2/proj.android
    ln -sf ../../../../android_build_objs obj
    ./build_native.sh -j ${CORES}
}

if [ "$PLATFORM"x = "android"x ]; then
    cd $COCOS2DX_ROOT/tools/travis-scripts
    #./generate-jsbindings.sh
    
    cd $COCOS2DX_ROOT
    mkdir -p android_build_objs
    build_android Cpp HelloCpp
    build_android Cpp TestCpp
    build_android Cpp AssetsManagerTest
    build_android Javascript TestJavascript
    build_android Lua HelloLua
    build_android Lua TestLua
fi

if [ "$PLATFORM"x = "nacl"x ]; then
    cd $COCOS2DX_ROOT
    export NACL_SDK_ROOT=$HOME/bin/nacl_sdk/pepper_canary
    if [ "${NACL_GLIBC}" = "1" ]; then
        export PATH=$PATH:$NACL_SDK_ROOT/toolchain/linux_x86_glibc/bin
    else
        export PATH=$PATH:$NACL_SDK_ROOT/toolchain/linux_x86_newlib/bin
    fi
    export PATH=$PATH:$NACL_SDK_ROOT/toolchain/linux_arm_newlib/bin
    make -j${CORES}
fi

if [ "$PLATFORM"x = "linux"x ]; then
    cd $COCOS2DX_ROOT
    make -j${CORES}
fi

if [ "$PLATFORM"x = "emscripten"x ]; then
    cd $COCOS2DX_ROOT
    export PYTHON=/usr/bin/python
    export LLVM=$HOME/bin/clang+llvm-3.2/bin
    sudo mkdir -p /Library/Fonts
    sudo cp samples/Cpp/TestCpp/Resources/fonts/arial.ttf /Library/Fonts/Arial.ttf
    make -f Makefile.emscripten -j${CORES}
fi

if [ "$PLATFORM"x = "ios"x ]; then
    cd $COCOS2DX_ROOT/tools/travis-scripts
    ./generate-jsbindings.sh

    cd $COCOS2DX_ROOT
    xctool/xctool.sh -project samples/Cpp/HelloCpp/proj.ios/HelloCpp.xcodeproj -scheme HelloCpp test
    xctool/xctool.sh -project samples/Cpp/SimpleGame/proj.ios/SimpleGame.xcodeproj -scheme SimpleGame test
    xctool/xctool.sh -project samples/Cpp/TestCpp/proj.ios/TestCpp.xcodeproj -scheme TestCpp test
    #xctool/xctool.sh -project samples/Cpp/AssetsManagerTest/proj.ios/AssetsManagerTest.xcodeproj -scheme AssetsManagerTest test
    #xctool/xctool.sh -project samples/Javascript/CocosDragonJS/proj.ios/CocosDragonJS.xcodeproj -scheme CocosDragonJS test
    #xctool/xctool.sh -project samples/Javascript/CrystalCraze/proj.ios/CrystalCraze.xcodeproj -scheme CrystalCraze test
    xctool/xctool.sh -project samples/Javascript/MoonWarriors/proj.ios/MoonWarriors.xcodeproj -scheme MoonWarriors test
    xctool/xctool.sh -project samples/Javascript/TestJavascript/proj.ios/TestJavascript.xcodeproj -scheme TestJavascript test
    #xctool/xctool.sh -project samples/Javascript/WatermelonWithMe/proj.ios/WatermelonWithMe.xcodeproj -scheme WatermelonWithMe test
    xctool/xctool.sh -project samples/Lua/HelloLua/proj.ios/HelloLua.xcodeproj -scheme HelloLua test
    xctool/xctool.sh -project samples/Lua/TestLua/proj.ios/TestLua.xcodeproj -scheme TestLua test
fi
