# Classes C++ [![Build Status][travis-badge]][travis-link][![MIT License][license-badge]](LICENSE.md)
Repository for implementation of mathematical structures in as C++ classes.

### Table of Contents

**[Prerequisites](#prereq)**  
**[Installation](#install)**  
**[Build With](#build)**  
**[Authors](#authors)**  
**[License](#license)**

##<a name="prereq"></a> Prerequisites
To build the project you need to install CMake. [Here](https://cmake.org/install/) are the instructions

##<a name="install"></a> Installation
First you need to clone the repository to your computer:
```bash
git clone git@github.com:RokKos/classes-c-.git
```
or
```bash
git clone https://github.com/RokKos/classes-c-.git
```

Then go to the root folder of the project:
```bash
cd classes-c-/
```

Then create a build folder where your build and run tests.
```bash
mkdir -p build
cd build/
cmake ..
make -j8
../bin/tests
```

or you can run the bash script that does this automatically:
```bash
./run_all_test.sh
```
If all tests are green then you are good to go.

## Built With
* [Google Tests](https://github.com/google/googletest) - Google's C++ test framework
* [CMake](https://cmake.org/) - Cross-platform free and open-source software for managing the build process of software using a compiler-independent method

##<a name="authors"></a> Authors

* **RokKos** - [RokKos](https://github.com/RokKos)

##<a name="license"></a> License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/RokKos/classes-c-/blob/master/LICENSE) file for details.


[travis-badge]:    https://travis-ci.org/RokKos/classes-c-.svg?branch=master
[travis-link]:     https://travis-ci.org/RokKos/classes-c-
[license-badge]:   https://img.shields.io/badge/license-MIT-007EC7.svg
