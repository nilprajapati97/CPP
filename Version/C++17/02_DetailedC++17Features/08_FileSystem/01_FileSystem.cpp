
/*
✅ 8. Filesystem Library
=============================================================================
Q1. How do you check if a file exists using C++17 filesystem?
Q2. How do you get a list of all .txt files in a directory?

🧠 Challenge:
Create a folder logs if it doesn't exist. Then scan and delete all .tmp files.



✅ Q1. How do you check if a file exists using C++17 filesystem?
==========================================================================
#include <filesystem>
namespace fs = std::filesystem;

bool fileExists(const std::string& path) {
    return fs::exists(path);
}

🔍 fs::exists(path) returns true if the path exists (file or directory).

✅ Q2. How do you get a list of all .txt files in a directory?
==========================================================================================
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

void listTxtFiles(const fs::path& dirPath) {
    for (const auto& entry : fs::directory_iterator(dirPath)) {
        if (entry.path().extension() == ".txt") {
            std::cout << entry.path() << '\n';
        }
    }
}

📌 fs::directory_iterator iterates over files; entry.path().extension() gives file extension

🧠 Challenge: Create a folder logs if it doesn't exist. Then scan and delete all .tmp files.

*/
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    fs::path logDir = "logs";

    // Create 'logs' directory if it doesn't exist
    if (!fs::exists(logDir)) {
        fs::create_directory(logDir);
        std::cout << "Created directory: " << logDir << "\n";
    }

    // Iterate and delete all .tmp files in 'logs'
    for (const auto& entry : fs::directory_iterator(logDir)) {
        if (entry.path().extension() == ".tmp") {
            fs::remove(entry.path());
            std::cout << "Deleted: " << entry.path() << '\n';
        }
    }

    return 0;
}

/*
Output
============


✅ This code:

    Ensures the logs folder exists.
    Iterates through its contents.
    Deletes all files ending with .tmp.

Let me know if you want the .tmp files to be logged before deletion or moved to a trash folder instead.
*/