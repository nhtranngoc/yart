# Yet Another Ray Tracer (YART)
[![Build Status](https://travis-ci.com/nhtranngoc/yart.svg?branch=master)](https://travis-ci.com/nhtranngoc/yart)


Inspired by ["The Ray Tracer Challenge"](http://www.raytracerchallenge.com/), a book by Jamis Buck, I set out to build a ray tracer in C++ as an attempt to transition from C and practicing test-driven development.

As with [YACE](https://github.com/nhtranngoc/yace), I will continue to use CMake as a build system and CppUTest as a testing framework.

# Build Instructions
Before running CMake, it is necessary to run the following commands:
```shell
export CC=path/to/arm-none-eabi-gcc
export CXX=path/to/arm-none-eabi-g++
```
This will set the path to the ARM cross compilers and set them to CMake cache. 

```shell
cd ./build/
cmake -DCMAKE_TOOLCHAIN_FILE=../arm-none-eabi-toolchain.cmake
make
```

For testing, it is necessary to remove `CMakeCache.txt` and `CMakeFiles/` in `build` folder before running `cmake ..`. By omitting the toolchain file, CMake assume we are building for testing and will only compile `/tests` folder.

# References

https://r4nd0m6uy.ch/cmake-and-cpputest.html
