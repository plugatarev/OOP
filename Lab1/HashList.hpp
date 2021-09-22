#pragma once
#include "Header.hpp"
#include "Value.hpp"
class HashList{
private:
    Value* val_;
    HashList* next_ = nullptr;
    int size_ = 0;
public:
    HashList();
    HashList(HashList & b);
    HashList(const Value & v);
    ~HashList();
    void insert(const Value & v);
    friend bool operator==(const HashList& a, const HashList& b);
    friend bool operator!=(const HashList& a, const HashList& b);
};