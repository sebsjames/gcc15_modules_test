# Seb's C++ modules g++ bug

Demonstrating a build issue that occurs for me in g++15/master but not in clang++. This may be an issue in nlohmann json or in gcc (I don't know which).

## Setup

To reproduce, clone this repo recursively, or after cloning do

```bash
git submodule init
git submodule update
```
To bring in nlohmann::json on the **develop** branch (which is modules compatible).

## Build

### With compiler commands

Edit build_g++.sh script with the path to your g++-15 binary. The script first compiles tools.cppm, then test1.cppm.

You can also see that clang++ (version 18 and up) compiles the modules successfully.

### With CMake

You can also run a g++ or clang++ build with cmake:

```bash
mkdir bgcc
cd bgcc
CXX=/path/to/g++-15 cmake .. -GNinja
ninja
cd ..

```bash
mkdir bclang
cd bclang
CXX=/path/to/clang++ cmake .. -GNinja
ninja
```

## The code and error

test1.cppm `#includes` **has_tools.h**, which `imports` tools.

If the line
```c++
#include <has_tools.h>
```
comes before
```c++
#include <nlohmann/json.hpp>
```
then I see the g++ error:

```
[11:46:26 gcc15_modules_test] ./build_g++.sh
In file included from /opt/gcc-15/include/c++/15.2.1/algorithm:63,
                 from json/include/nlohmann/json.hpp:21,
                 from test1.cppm:4:
/opt/gcc-15/include/c++/15.2.1/bits/stl_algo.h:5633:5: error: redefinition of ‘template<class _ForwardIterator, class _Compare> constexpr _ForwardIterator std::__min_element(_ForwardIterator, _ForwardIterator, _Compare)’
 5633 |     __min_element(_ForwardIterator __first, _ForwardIterator __last,
      |     ^~~~~~~~~~~~~
compilation terminated due to -Wfatal-errors.
[11:46:29 gcc15_modules_test]
```
