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
