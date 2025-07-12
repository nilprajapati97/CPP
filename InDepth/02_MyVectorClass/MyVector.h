#pragma once
#include <iostream>
#include <stdexcept>
#include <algorithm>  // std::copy

template<typename T>
class MyVector {
private:
    T* _data;
    size_t _size;
    size_t _capacity;

    void reallocate(size_t new_cap) {
        T* new_data = new T[new_cap];
        std::copy(_data, _data + _size, new_data);
        delete[] _data;
        _data = new_data;
        _capacity = new_cap;
    }

public:
    // Constructors
    MyVector() : _data(nullptr), _size(0), _capacity(0) {}

    explicit MyVector(size_t count, const T& value = T()) {
        _size = count;
        _capacity = count;
        _data = new T[_capacity];
        std::fill(_data, _data + _size, value);
    }

    // Copy Constructor
    MyVector(const MyVector& other)
        : _size(other._size), _capacity(other._capacity) {
        _data = new T[_capacity];
        std::copy(other._data, other._data + _size, _data);
    }

    // Move Constructor
    MyVector(MyVector&& other) noexcept
        : _data(other._data), _size(other._size), _capacity(other._capacity) {
        other._data = nullptr;
        other._size = 0;
        other._capacity = 0;
    }

    // Copy Assignment
    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            delete[] _data;
            _size = other._size;
            _capacity = other._capacity;
            _data = new T[_capacity];
            std::copy(other._data, other._data + _size, _data);
        }
        return *this;
    }

    // Move Assignment
    MyVector& operator=(MyVector&& other) noexcept {
        if (this != &other) {
            delete[] _data;
            _data = other._data;
            _size = other._size;
            _capacity = other._capacity;
            other._data = nullptr;
            other._size = 0;
            other._capacity = 0;
        }
        return *this;
    }

    // Destructor
    ~MyVector() {
        delete[] _data;
    }

    // Element access
    T& operator[](size_t index) {
        return _data[index];
    }

    const T& operator[](size_t index) const {
        return _data[index];
    }

    T& at(size_t index) {
        if (index >= _size) throw std::out_of_range("Index out of bounds");
        return _data[index];
    }

    const T& at(size_t index) const {
        if (index >= _size) throw std::out_of_range("Index out of bounds");
        return _data[index];
    }

    T& front() { return _data[0]; }
    T& back() { return _data[_size - 1]; }

    // Capacity
    size_t size() const { return _size; }
    size_t capacity() const { return _capacity; }
    bool empty() const { return _size == 0; }

    void reserve(size_t new_cap) {
        if (new_cap > _capacity) {
            reallocate(new_cap);
        }
    }

    void resize(size_t new_size, T value = T()) {
        if (new_size > _capacity)
            reallocate(new_size * 2);
        if (new_size > _size)
            std::fill(_data + _size, _data + new_size, value);
        _size = new_size;
    }

    // Modifiers
    void push_back(const T& value) {
        if (_size >= _capacity)
            reallocate(_capacity == 0 ? 1 : _capacity * 2);
        _data[_size++] = value;
    }

    void pop_back() {
        if (_size > 0) --_size;
    }

    void clear() {
        _size = 0;
    }

    // Iterators
    T* begin() { return _data; }
    T* end() { return _data + _size; }

    const T* begin() const { return _data; }
    const T* end() const { return _data + _size; }

    // Insert at index
    void insert(size_t index, const T& value) {
        if (index > _size) throw std::out_of_range("Index out of bounds");
        if (_size >= _capacity)
            reallocate(_capacity == 0 ? 1 : _capacity * 2);
        for (size_t i = _size; i > index; --i)
            _data[i] = _data[i - 1];
        _data[index] = value;
        ++_size;
    }

    // Erase at index
    void erase(size_t index) {
        if (index >= _size) throw std::out_of_range("Index out of bounds");
        for (size_t i = index; i < _size - 1; ++i)
            _data[i] = _data[i + 1];
        --_size;
    }
};
