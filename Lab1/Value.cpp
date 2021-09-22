#include "Value.hpp"
#include <iostream>
Value::Value(std::string n, unsigned a) : name(n), age(a), next(nullptr){}

Value::Value(const Value & other) : name(other.name), age(other.age), next(nullptr) {}

Value::Value(const Value & other, Value* val) : name(other.name), age(other.age), next(val){}

Value::~Value() {}

