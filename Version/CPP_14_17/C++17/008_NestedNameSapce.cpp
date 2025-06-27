
#include <iostream>
#include <filesystem>
namespace company::product::module {
    void show() {
        std::cout << "Nested namespace\n";
    }
}
int main() {
    company::product::module::show();
}
