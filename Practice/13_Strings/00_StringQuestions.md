✅ 1. Difference between std::string and C-style strings (char*)
==================================================================
Q: Explain differences and when to use std::string vs char*.

Key Points:
std::string handles memory automatically.

char* is raw; error-prone for memory leaks and overflows.

Use char* for low-level C APIs or embedded.

Prefer std::string in modern C++ (RAII, safety, easier manipulation).

✅ 2. Reverse a String In-Place (with std::string)
==================================================================
void reverseString(string& str) {
    int i = 0, j = str.length() - 1;
    while (i < j) {
        swap(str[i++], str[j--]);
    }
}
✅ 3. Remove Duplicate Characters Without Extra Space
==================================================================
void removeDuplicates(string &str) {
    unordered_set<char> seen;
    int index = 0;
    for (char ch : str) {
        if (seen.find(ch) == seen.end()) {
            seen.insert(ch);
            str[index++] = ch;
        }
    }
    str.resize(index);
}
✅ 4. Find First Non-Repeating Character
==================================================================
char firstNonRepeating(const string& str) {
    unordered_map<char, int> freq;
    for (char ch : str) freq[ch]++;
    for (char ch : str)
        if (freq[ch] == 1) return ch;
    return '\0'; // Not found
}
✅ 5. Implement strstr() (C++ version)
==================================================================
int myStrStr(const string& haystack, const string& needle) {
    if (needle.empty()) return 0;
    for (int i = 0; i <= haystack.size() - needle.size(); ++i) {
        if (haystack.substr(i, needle.size()) == needle)
            return i;
    }
    return -1;
}
✅ 6. Palindrome Check (Ignoring Non-Alphabet)
==================================================================
bool isPalindrome(const string& str) {
    int i = 0, j = str.length() - 1;
    while (i < j) {
        while (i < j && !isalnum(str[i])) i++;
        while (i < j && !isalnum(str[j])) j--;
        if (tolower(str[i++]) != tolower(str[j--]))
            return false;
    }
    return true;
}
✅ 7. Compress String (aabcc → a2b1c2)
==================================================================
string compress(const string& str) {
    string result;
    int count = 1;
    for (size_t i = 1; i <= str.length(); ++i) {
        if (i < str.length() && str[i] == str[i-1])
            ++count;
        else {
            result += str[i-1] + to_string(count);
            count = 1;
        }
    }
    return (result.length() < str.length()) ? result : str;
}
✅ 8. Longest Substring Without Repeating Characters
==================================================================
int longestUniqueSubstring(const string& s) {
    unordered_map<char, int> seen;
    int maxLen = 0, start = 0;
    for (int end = 0; end < s.length(); ++end) {
        if (seen.count(s[end]))
            start = max(seen[s[end]] + 1, start);
        seen[s[end]] = end;
        maxLen = max(maxLen, end - start + 1);
    }
    return maxLen;
}
✅ 9. Implement String Tokenizer (like strtok())
==================================================================
vector<string> tokenize(const string& str, char delim) {
    vector<string> tokens;
    string token;
    for (char ch : str) {
        if (ch == delim) {
            if (!token.empty()) tokens.push_back(token);
            token.clear();
        } else {
            token += ch;
        }
    }
    if (!token.empty()) tokens.push_back(token);
    return tokens;
}
✅ 10. Custom String Class (OOP, deep copy, operator overloading)
==================================================================
class MyString {
    char* data;
public:
    MyString(const char* str = "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    MyString(const MyString& other) { // Deep Copy
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] data;
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    ~MyString() { delete[] data; }

    void print() { cout << data << endl; }
};

✅ Interview Concepts to Be Ready For
==================================================================
Concept	Be Prepared To...
std::string internals	Explain SSO (Small String Optimization)
std::string_view	    Know the use-case and lifetime issues
Immutability	        Discuss const-correctness
Encoding	            UTF-8 handling and why char isn't enough
Performance	            Copy vs move, when to use reserve()
STL tricks	            Use of transform(), accumulate(), find_if()

