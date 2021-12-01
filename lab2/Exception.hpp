#pragma once
#include <iostream>
class interpreter_error: public std::runtime_error {
 public:
    interpreter_error(std::string msg): std::runtime_error(msg) {}
};