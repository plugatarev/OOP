#pragma once
#include "Header.hpp"
#include "Value.hpp"
typedef std::string Key;

class Entry{
public:
    Key key;
    Value value;
    Entry* next = nullptr;

    Entry();

    Entry (Key& k, Value& v);
    Entry(const Entry& other);

    Entry(Key& k, Value& v, Entry* next);

    ~Entry();

    bool operator==(const Entry& p);
};