#pragma once
#include "Header.hpp"
#include "Value.hpp"
class HashList{
private:
    Value* head_;
    Value val_;

    void freeList();

public:

    HashList();

    HashList(HashList & b);

    HashList(const Value & v);

    HashList(const Value & v, Value* next);


    ~HashList();

    bool insert(const Value & v);

    bool remove(const Value & v);

    bool search(const Value & v);

    friend bool operator==(const HashList& a, const HashList& b);

    friend bool operator!=(const HashList& a, const HashList& b);
};