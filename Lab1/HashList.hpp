#pragma once
#include "Header.hpp"
#include "HashMap.hpp"

class HashList{
private:
    HashMap* head_ = nullptr;
    void freeList();

public:

    HashList();

    HashList(HashList & b);

    HashList(const Key& k, const Value& v, HashMap* next);

    ~HashList();

    bool insert(const Key& k, const Value& v);

    bool search(const Key& k) const;

    void printList() const;

    bool remove(const Key& k);

    Value& at(const Key& k) const;

    HashList & operator=(const HashMap& other);

    friend bool operator==(const HashMap& a, const HashMap& b);
};