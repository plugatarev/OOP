#pragma once
#include "Header.hpp"
#include "Value.hpp"
class HashList{
private:
    Value* head_ = nullptr;
    void freeList();

public:

    HashList();

    HashList(HashList & b);

    HashList(const Value & v, Value* next);

    ~HashList();

    bool insert(const Value & v);

    bool remove(Value & v);

    bool search(const Value & v);

    void printList() const;

    HashList & operator=(const HashList& other);

    friend bool operator==(const HashList& a, const HashList& b);
};