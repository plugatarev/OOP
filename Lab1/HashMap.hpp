#pragma once
#include "Header.hpp"
#include "Value.hpp"

class HashMap{
public:
    Key key;
    Value value;
    HashMap* next = nullptr;

    HashMap();

    HashMap (Key k, Value& v);
    HashMap(const HashMap & other);

    HashMap(const HashMap & other, HashMap* v);

    ~HashMap();

    bool operator==(const HashMap& p);
};