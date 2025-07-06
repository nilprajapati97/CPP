/*
✅ 1. Frequency Counter (Word or Character Count)
=========================================================
🔍 Overview:
A frequency counter is a data structure that counts the occurrences of each unique element (word or character) in a collection, such as a string or file. 
It is commonly implemented using associative containers like `std::map` or `std::unordered_map` in C++.

🔧 Use Case:
--------------
Count how many times each word (or character) appears in a file, log, sentence, etc.

📌 Why std::map?
--------------------
`std::map` is a perfect choice for frequency counting because:
- It provides a key-value pair structure where keys are the words/characters and values are their counts.
- It automatically sorts the keys, making it easy to iterate in order.
- It ensures unique keys, so each word/character is counted only once.
- It allows efficient insertions and lookups, making it suitable for counting operations.


✅ Code Example – Word Frequency Counter
*/
#include <iostream>
#include <sstream>
#include <map>
#include <string>
using namespace std;

int main() {
    string text = "the cat sat on the mat and the cat slept";

    map<string, int> freq;

    stringstream ss(text);
    string word;

    while (ss >> word) {
        freq[word]++;
    }

    cout << "Word Frequency:\n";
    for (const auto& [word, count] : freq) {
        cout << word << " => " << count << "\n";
    }

    return 0;
}
/*


🧾 Output:
===========
Word Frequency:
and => 1
cat => 2
mat => 1
on => 1
sat => 1
slept => 1
the => 3

*/