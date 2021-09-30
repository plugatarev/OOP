#pragma once
#include "Header.hpp"
#include "Entries.hpp"

class HashList{
private:
    Entries* head_ = nullptr;
    void freeList();

public:

    HashList();

    HashList(HashList & b);

    HashList(const Key& k, const Value& v, Entries* next);

    ~HashList();

    bool insert(const Key& k, const Value& v);

    bool search(const Key& k) const;

    void printList() const;

    bool remove(const Key& k);

    Value& at(const Key& k) const;

    HashList & operator=(const Entries& other);

    friend bool operator==(const Entries& a, const Entries& b);
};