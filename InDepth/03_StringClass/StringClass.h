/*
✅ Goals: MyString Should Support
======================================================================================================
Dynamic memory allocation
Dynamic resizing
Copy/move semantics
String manipulation methods (append, insert, erase, replace)
Comparison operators
Iterators
Stream insertion and extraction operators
======================================================================================================

Constructor from const char*

Copy/move constructors and assignment

Concatenation

Length / capacity tracking

operator[], c_str(), and printing

*/
#pragma once
#include <cstring>      // for strlen, strcpy, strcat
#include <iostream>     // for ostream

class MyString {
private:
    char* _data;
    size_t _length;

public:
    // Default constructor
    MyString() : _data(new char[1]{'\0'}), _length(0) {}

    // Constructor from const char*
    MyString(const char* str) {
        _length = std::strlen(str);
        _data = new char[_length + 1];
        std::strcpy(_data, str);
    }

    // Copy constructor
    MyString(const MyString& other) {
        _length = other._length;
        _data = new char[_length + 1];
        std::strcpy(_data, other._data);
    }

    // Move constructor
    MyString(MyString&& other) noexcept
        : _data(other._data), _length(other._length) {
        other._data = nullptr;
        other._length = 0;
    }

    // Copy assignment
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] _data;
            _length = other._length;
            _data = new char[_length + 1];
            std::strcpy(_data, other._data);
        }
        return *this;
    }

    // Move assignment
    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) {
            delete[] _data;
            _data = other._data;
            _length = other._length;
            other._data = nullptr;
            other._length = 0;
        }
        return *this;
    }

    // Destructor
    ~MyString() {
        delete[] _data;
    }

    // Accessors
    size_t length() const { return _length; }
    const char* c_str() const { return _data; }

    // Indexing
    char& operator[](size_t index) {
        return _data[index];
    }

    const char& operator[](size_t index) const {
        return _data[index];
    }

    // Concatenation
    MyString operator+(const MyString& other) const {
        size_t new_len = _length + other._length;
        char* new_data = new char[new_len + 1];

        std::strcpy(new_data, _data);
        std::strcat(new_data, other._data);

        MyString result(new_data);
        delete[] new_data;
        return result;
    }

    // Stream output
    friend std::ostream& operator<<(std::ostream& os, const MyString& str) {
        os << str._data;
        return os;
    }
};
// Stream input