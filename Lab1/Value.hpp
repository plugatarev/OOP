#pragma once
#include "Header.hpp"
class Value {
public:
    Value();
    Value (std::string n, unsigned a = 0) : name(n), age(a) {}
    Value(const Value & other);
    Value(const Value & other, Value* val);
    ~Value();
    std::string name;
    unsigned age;
    Value* next;
};

