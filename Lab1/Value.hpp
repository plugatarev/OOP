#include <iostream>
struct Value {
   Value();
   Value (std::string n, unsigned a = 0) : name(n), age(a) {}
   std::string name;
   unsigned age;
};
