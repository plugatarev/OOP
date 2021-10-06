#pragma once
#include "Header.hpp"
#include "Entries.hpp"
typedef std::string Key;

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

    //Return a reference to the value of the existing element whose is equivalent to k.
   //exception out_of_range if no element with key k existed. 
    Value& at(const Key& k) const;

    bool search_and_insert(const Key& k, const Value& v);

    HashList& operator=(const HashList& other);

    Entries* pop();

    friend bool operator==(const HashList& a, const HashList& b);

    friend bool operator!=(const HashList& a, const HashList& b);
};