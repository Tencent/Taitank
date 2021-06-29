# Taitank Cross Platform Layout

![Taitank Group](https://img.shields.io/badge/group-Taitank-blue.svg) [![license](https://img.shields.io/badge/license-Apache%202-blue)](https://github.com/ilikethese/Taitank/blob/main/License) [![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](https://github.com/ilikethese/Taitank/pulls) ![node](https://img.shields.io/badge/node-%3E%3D10.0.0-green.svg) [![Actions Status](https://github.com/ilikethese/Taitank/workflows/CMake/badge.svg?branch=main)](https://github.com/ilikethese/Taitank/actions) [![Codecov](https://img.shields.io/codecov/c/github/ilikethese/Taitank)](https://codecov.io/gh/ilikethese/Taitank)

[English](./README.md) | 简体中文 | [Homepage](//tencent.github.io/ilikethese/)

## 介绍

<p align="center"><img src="./assets/logo.jpg" width=300 height=300></p>

Taitank 是一个支持 Flex 的跨平台的轻量级的 c++ 排版引擎。

到目前为止，[腾讯](http://www.tencent.com/)内已经有了27款流行 App 在使用 Taitank 排版引擎，包括手机QQ、手机QQ浏览器、腾讯视频App，QQ音乐App等，每日触达数亿用户。

## 特征

* 完整支持 Flex 布局。
* 高效率排版、节省内存
* 多平台支持

## Project structure

```text
├── CMakeLists.txt                    # 编译脚本。
├── assets                            # 资源文件。
├── benchmark                         # benchmark。
├── examples                          # taitank layout 例子。
├── javascript                        # wasm layout 代码。
├── src                               # taitank layout 源代码。
├── tests                             # taitank layout 测试用例。
└── toolchain                         # 编译工具链。
```

## 开始

### 准备环境

用户需要以下软件：

1. [CMake](https://cmake.org/) : 用以编译 taitank layout 源代码
2. [Android Studio](https://developer.android.com/studio) 和 NDK: 用以编译 Android so
3. [Xcode](https://developer.apple.com/xcode/) 和 iOS sdk: 用以编译 iOS so.
4. [emscripten](https://emscripten.org/docs/getting_started/downloads.html): 用以编译 wasm.
5. [Python](https://www.python.org/): 用以执行编译脚本.

### 编译出你的库

切换到 cmake 目录

```bash
cd cmake
```

### 支持的平台

| name           | description                                     |
|----------------|-------------------------------------------------|
| macos          | Build library for macos.                        |
| linux          | Build library for linux.                        |
| android        | Build library for android.                      |
| ios            | Build library for ios.                          |
| browser & node | Build wasm for browser and node.                |


### 测试

我们依赖 [gtest](https://github.com/google/googletest)

```bash
cd tests
build.sh
```

### 性能测试

```bash
cd tests
./build.sh
```

## 贡献

欢迎开发人员为腾讯的开源做出贡献，我们将持续激励他们并感谢他们。我们提供了腾讯对开源贡献的说明，每个项目的具体贡献规则由项目团队制定。开发人员可以选择适当的项目并根据相应的规则参与。腾讯项目管理委员会将定期汇报合格的贡献者，奖项将由官方联络人颁发。

## 许可协议

Taitank 遵守 [Apache-2.0 licensed](./LICENSE) 协议。
