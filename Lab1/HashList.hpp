#pragma once
#include "Header.hpp"
#include "Entry.hpp"
typedef std::string Key;

class HashList{
public:

    HashList();

    HashList(HashList & b);

    HashList(const Key& k, const Value& v, Entry* next = nullptr);

    ~HashList();

    bool insert(const Key& k, const Value& v);

    bool search(const Key& k) const;

    void printList() const;

    bool remove(const Key& k);

    //Return a reference to the value of the existing element whose is equivalent to k.
   //exception out_of_range if no element with key k existed. 
    Value& at(const Key& k) const;

    Value& search_and_insert(const Key& k, size_t* size);

    HashList& operator=(const HashList& other);

    Entry* pop();

    void freeList();

    void reverse();

    friend bool operator==(const HashList& a, const HashList& b);

    friend bool operator!=(const HashList& a, const HashList& b);
private:
    Entry* head_ = nullptr;

};