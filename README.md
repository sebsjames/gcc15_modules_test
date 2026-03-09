Demonstrating a build issue that occurs in g++15 but not in clang++

To reproduce, clone this repo recursively, or after cloning do

```bash
git submodule init
git submodule update
```
To bring in nlohmann::json on the **develop** branch

The build_g++.sh script (you will have to edit the path to your g++-15 binary) first compiles tools.cppm, then test1.cppm.

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