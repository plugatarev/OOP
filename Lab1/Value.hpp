#pragma once
#include <iostream>
struct Value {
public:
    Value();
    Value (std::string n, unsigned a = 0) : name(n), age(a) {}
    Value(Value & other);
    ~Value();
    std::string name;
    unsigned age;
};

