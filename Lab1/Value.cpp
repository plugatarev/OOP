#include "Value.hpp"
#include <iostream>
Value::Value(std::string n, unsigned a) : name(n), age(a){}

Value::Value(const Value & other) : name(other.name), age(other.age) {}

Value::~Value() {}
