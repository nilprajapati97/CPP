#include "StringClass.h"

int main() {
    MyString s1("Hello");
    MyString s2(" World");

    MyString s3 = s1 + s2;

    std::cout << "Concatenated: " << s3 << "\n";    // Hello World
    std::cout << "Length: " << s3.length() << "\n"; // 11
    std::cout << "First char: " << s3[0] << "\n";   // H

    s3[0] = 'h';
    std::cout << "Modified: " << s3 << "\n";        // hello World
    
    return 0;
}
/*
Output:
Concatenated: Hello World
Length: 11
First char: H
Modified: hello World
*/
