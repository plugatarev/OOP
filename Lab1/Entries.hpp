#pragma once
#include "Header.hpp"
#include "Value.hpp"
typedef std::string Key;

class Entries{
public:
    Key key;
    Value value;
    Entries* next = nullptr;

    Entries();

    Entries (Key& k, Value& v);
    Entries(const Entries& other);

    Entries(Key& k, Value& v, Entries* next);

    ~Entries();

    bool operator==(const Entries& p);
};