/*
✅ 8. Filesystem Library
========================================
🔹 Purpose:
Portable file and directory handling.
🔹 Characteristics:
- Provides a standard way to interact with the file system.
- Supports operations like file creation, deletion, and traversal.
- Works across different platforms (Windows, macOS, Linux).

*/

#include <iostream>
#include <filesystem>

using namespace std;

namespace fs = std::filesystem;

int main() {
    for (const auto& entry : fs::directory_iterator(".")) {
        cout << entry.path() << '\n';
    }
}

/*
Output:
./08_FileSystemLibrary.cpp
./08_FileSystemLibrary.cpp~
./08_FileSystemLibrary.cpp.bak
./08_FileSystemLibrary.cpp.swp
./08_FileSystemLibrary.cpp.swo

