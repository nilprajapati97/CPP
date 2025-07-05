#include <iostream>
#include <cctype>

void reverseString(std::string &str) {
    int left = 0, right = str.length() - 1;

    while (left < right) {
        // Skip non-alphabetic characters
        if (!isalpha(str[left])) {
            left++;
        } else if (!isalpha(str[right])) {
            right--;
        } else {
            std::swap(str[left], str[right]);
            left++;
            right--;
        }
    }
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    reverseString(input);

    std::cout << "Reversed string: " << input << std::endl;
    return 0;
}
