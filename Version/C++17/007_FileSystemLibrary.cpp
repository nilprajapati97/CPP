#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main() {
    for (const auto& entry : fs::directory_iterator(".")) {
        std::cout << entry.path() << '\n';
    }
}
