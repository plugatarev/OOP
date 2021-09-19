#pragma once
#include "Header.hpp"
#include "Value.hpp"
struct HashList{
private:
    Value* val_;
    HashList* next_;
public:
    HashList();
    HashList(const HashList & b);
    HashList(const Value & val);
    ~HashList();
    void insert();
};