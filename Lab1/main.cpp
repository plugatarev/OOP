//#include <gtest/gtest.h>
#include "HashTable.hpp"
#include <iostream>
bool operator==(const Value& a,const Value& b);
Key gen_random(int len) {
    Key s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return s;
}

void fill_table(HashTable& a, int n = 5){
    
    for (size_t i = 0; i < n; i++){
        Value* v = new Value(gen_random(5), i + 2);
        a.insert(gen_random(5),*v);
    }
}
using namespace std;


int main(int argc, char ** argv) {
    
}