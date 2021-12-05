//#include <gtest/gtest.h>
#include "HashTable.hpp"
#include <iostream>
int main(int argc, char ** argv) {
    HashTable ht;
    ht["key"];
    ht["key2"];
    ht.at("key").age = 42;
    assert(ht.at("key2").age != 42);
}