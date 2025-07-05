✅ 1. Reverse Words in a Sentence (In-place)
Input: "I love C++"
Output: "C++ love I"

Key Concepts:
std::reverse, character-level manipulation

In-place without extra memory

cpp
Copy
Edit
void reverseWords(std::string &s) {
    std::reverse(s.begin(), s.end());
    size_t start = 0, end = 0, len = s.length();
    while (start < len) {
        while (start < len && s[start] == ' ') ++start;
        end = start;
        while (end < len && s[end] != ' ') ++end;
        std::reverse(s.begin() + start, s.begin() + end);
        start = end;
    }
}
✅ 2. Check if Two Strings are Anagrams
Input: "listen", "silent"
Output: true

Key Concepts:
std::unordered_map, std::sort

Time-space tradeoff

cpp
Copy
Edit
bool areAnagrams(const std::string &a, const std::string &b) {
    if (a.size() != b.size()) return false;
    std::unordered_map<char, int> count;
    for (char c : a) count[c]++;
    for (char c : b) {
        if (--count[c] < 0) return false;
    }
    return true;
}
✅ 3. Longest Substring Without Repeating Characters
Input: "abcabcbb"
Output: 3 → "abc"

Key Concepts:
Sliding window, map for index tracking

cpp
Copy
Edit
int lengthOfLongestSubstring(const std::string &s) {
    std::unordered_map<char, int> map;
    int maxLen = 0, start = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (map.count(s[i]) && map[s[i]] >= start)
            start = map[s[i]] + 1;
        map[s[i]] = i;
        maxLen = std::max(maxLen, i - start + 1);
    }
    return maxLen;
}
✅ 4. Custom strstr() Implementation
Input: haystack = "hello world", needle = "world"
Output: Pointer to "world"

Key Concepts:
Manual pointer logic

Memory efficiency

cpp
Copy
Edit
const char* my_strstr(const char *haystack, const char *needle) {
    if (!*needle) return haystack;
    for (; *haystack; ++haystack) {
        const char *h = haystack, *n = needle;
        while (*h && *n && *h == *n) { ++h; ++n; }
        if (!*n) return haystack;
    }
    return nullptr;
}
✅ 5. Implement atoi()
Input: " -42 "
Output: -42

Key Concepts:
Edge cases: whitespaces, overflow, signs

cpp
Copy
Edit
int myAtoi(const std::string &s) {
    int i = 0, sign = 1;
    long result = 0;
    while (s[i] == ' ') ++i;
    if (s[i] == '-' || s[i] == '+') sign = (s[i++] == '-') ? -1 : 1;
    while (isdigit(s[i])) {
        result = result * 10 + (s[i++] - '0');
        if (result * sign > INT_MAX) return INT_MAX;
        if (result * sign < INT_MIN) return INT_MIN;
    }
    return static_cast<int>(result * sign);
}
✅ 6. Detect Palindrome (Ignoring Spaces and Case)
Input: "A man a plan a canal Panama"
Output: true

cpp
Copy
Edit
bool isPalindrome(const std::string &s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        while (i < j && !isalnum(s[i])) ++i;
        while (i < j && !isalnum(s[j])) --j;
        if (tolower(s[i++]) != tolower(s[j--])) return false;
    }
    return true;
}
✅ 7. Group Anagrams Together
Input: ["bat", "tab", "tan", "nat", "cat"]
Output: {["bat", "tab"], ["tan", "nat"], ["cat"]}

cpp
Copy
Edit
std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> map;
    for (auto &s : strs) {
        std::string key = s;
        std::sort(key.begin(), key.end());
        map[key].push_back(s);
    }
    std::vector<std::vector<std::string>> res;
    for (auto &[_, group] : map) res.push_back(group);
    return res;
}
✅ 8. Remove Duplicate Characters from a String
Input: "programming"
Output: "progamin"

cpp
Copy
Edit
std::string removeDuplicates(const std::string &str) {
    std::unordered_set<char> seen;
    std::string result;
    for (char c : str) {
        if (seen.insert(c).second)
            result += c;
    }
    return result;
}
✅ 9. Check if s1 is a rotation of s2
Input: "waterbottle", "erbottlewat"
Output: true

cpp
Copy
Edit
bool isRotation(const std::string &s1, const std::string &s2) {
    return s1.length() == s2.length() &&
           (s1 + s1).find(s2) != std::string::npos;
}
✅ 10. String Compression (Run-length encoding)
Input: "aaabbcc"
Output: "a3b2c2"

cpp
Copy
Edit
std::string compress(const std::string &s) {
    std::string result;
    int count = 1;
    for (int i = 1; i <= s.length(); ++i) {
        if (s[i] == s[i - 1]) count++;
        else {
            result += s[i - 1] + std::to_string(count);
            count = 1;
        }
    }
    return result.length() < s.length() ? result : s;
}