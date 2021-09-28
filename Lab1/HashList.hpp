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

    HashList(const HashMap & v, HashMap* next);

    ~HashList();

    bool insert(const HashMap & v);

    bool remove(HashMap & v);

    bool search(const HashMap & v);

    void printList() const;

    HashList & operator=(const HashMap& other);

    friend bool operator==(const HashMap& a, const HashMap& b);
};