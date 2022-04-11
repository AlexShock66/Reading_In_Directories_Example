# Sample code for searching and listing files under a directory in C++
## 1. [Dirent](https://pubs.opengroup.org/onlinepubs/7908799/xsh/dirent.h.html)
- Using `opendir/readdir` functions to get a list of files in a directory.
- To use the functions opendir/readdir, you should have `#include <dirent.h>` on top of your header file.

## 2. C++17 [std::filesystem](https://en.cppreference.com/w/cpp/filesystem)
- Usingse `std::filesystem::recursive_directory_iterator` to get a list of files in in a directory.
- This method is part of the <filesystem> library added in C++17. You should change the `set(CMAKE_CXX_STANDARD 14)` in your CMakeLists txt to `set(CMAKE_CXX_STANDARD 17)` to enable C++17.