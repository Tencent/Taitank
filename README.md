# Taitank Cross Platform Layout

![Taitank Group](https://img.shields.io/badge/group-Taitank-blue.svg) [![license](https://img.shields.io/badge/license-Apache%202-blue)](https://github.com/Tencent/Taitank/blob/main/LICENSE) [![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](https://github.com/Tencent/Taitank/pulls) ![node](https://img.shields.io/badge/node-%3E%3D10.0.0-green.svg) [![Actions Status](https://github.com/Tencent/Taitank/workflows/CMake/badge.svg?branch=main)](https://github.com/Tencent/Taitank/actions) [![Codecov](https://img.shields.io/codecov/c/github/Tencent/Taitank)](https://codecov.io/gh/Tencent/Taitank)

English | [简体中文](./README.zh_CN.md) | [Homepage](//tencent.github.io/Taitank/)

## Introduction

<p align="center"><img src="./assets/logo.jpg" width=300 height=300></p>

**Taitank** is a cross platform lightweight flex layout engine implemented in C++.

Taitank is now applied in 27 [Tencent](http://www.tencent.com/) apps such as Mobile QQ, Mobile QQ Browser, Tencent Video App, QQ Music App，reaching hundreds of millions of ordinary users.

## Advantages

* Fully supported Flex
* Fast Layout and Low memory consumption
* Multi platform support

## Project structure

```text
├── CMakeLists.txt                    # compiler script.
├── assets                            # assets.
├── benchmark                         # benchmark.
├── examples                          # Taitank layout examples.
├── javascript                        # wasm layout source code.
├── src                               # Taitank layout source code.
├── tests                             # Taitank layout test.
└── toolchain                         # toolchain.
```

## Getting started

### Preparing environment


1. [CMake](https://cmake.org/) : build Taitank layout.
2. [Android Studio](https://developer.android.com/studio) with NDK: build Android so.
3. [Xcode](https://developer.apple.com/xcode/) with iOS sdk: build iOS so.
4. [emscripten](https://emscripten.org/docs/getting_started/downloads.html): build wasm.
5. [Python](https://www.python.org/): script to build Taitank layout.

### Build your first libiary

Change directory to cmake to build your project.

```bash
cd cmake
```

### Support Platforms

| name           | description                                     |
|----------------|-------------------------------------------------|
| macos          | Build library for macos.                        |
| linux          | Build library for linux.                        |
| android        | Build library for android.                      |
| ios            | Build library for ios.                          |
| browser & node | Build wasm for browser and node.                |


### Testing

For testing we rely on [gtest](https://github.com/google/googletest)

If you make any changes you should pass all the tests.Tests are located in the `tests` directory. Run the tests by ececuting `build.sh`.

```bash
cd tests
./build.sh
```

### Benchmarks

Benchmarks are located in the `benchmark` directory. Run the benchmarks by ececuting `build.sh`.

```bash
cd benchmark
./build.sh
```

## Contribution

Developers are welcome to contribute to Tencent's open source, and we will also give them incentives to acknowledge and thank them. Here we provide an official description of Tencent's open source contribution. Specific contribution rules for each project are formulated by the project team. Developers can choose the appropriate project and participate according to the corresponding rules. The Tencent Project Management Committee will report regularly to qualified contributors and awards will be issued by the official contact.

## License

Taitank is [Apache-2.0 licensed](./LICENSE).
