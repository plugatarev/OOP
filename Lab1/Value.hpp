#pragma once
#include "Header.hpp"
class Value {
public:

    std::string name;
    unsigned age;
    Value* next;

    Value();

    Value (std::string n, unsigned a = 0);
    Value(const Value & other);

    Value(const Value & other, Value* val);

    ~Value();

    bool operator==(const Value& b);

};
