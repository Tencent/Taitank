# Build Project

## Preparing environment

1. Install [CMake](https://cmake.org/)
2. Set env PROJECT_CMAKE_PATH 
```
export PROJECT_CMAKE_PATH="user cmake path"
```
### Build for Android

1. Install [Android Studio](https://developer.android.com/studio) with NDK
2. Set env PROJECT_ANDROID_NDK_PATH
```
export PROJECT_ANDROID_NDK_PATH="your android ndk path"
```

### Build for macos or ios

1. Install [Xcode](https://developer.apple.com/xcode/)
2. Install [clang](https://clang.llvm.org/)

### Build for Linux

1. Install [clang](https://clang.llvm.org/)

### Build for Windows

1. Install [Visual Studio](https://visualstudio.microsoft.com/zh-hans/)

## Run script

### Build in windows system
```
generate.bat
```
change directory to build and open Taitank.sln by Visual Studio to build lib.

### Build in linux system or macos system
```
./generate.sh
```
