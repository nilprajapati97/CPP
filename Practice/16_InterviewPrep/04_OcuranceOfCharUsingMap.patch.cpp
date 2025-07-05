#include <iostream>
#include <unordered_map>

void countCharacterOccurrences(const std::string &str) {
    std::unordered_map<char, int> charCount;

    // Count occurrences
    for (char ch : str) {
        charCount[ch]++;
    }

    // Print results
    std::cout << "Character occurrences:\n";
    for (const auto &pair : charCount) {
        std::cout << "'" << pair.first << "' -> " << pair.second << " times\n";
    }
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);  // Read input string

    countCharacterOccurrences(input);

    return 0;
}
