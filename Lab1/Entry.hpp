#pragma once
#include "Header.hpp"
#include "Value.hpp"
typedef std::string Key;

// CR: class -> struct since everything is public - Ok
struct Entry{
    Key& key;
    Value& value;
    Entry* next = nullptr;

    //Entry();

    Entry(const Entry& other);

    Entry(Key& k, Value& v, Entry* next = nullptr);

    ~Entry();

    bool operator==(const Entry& p);
};