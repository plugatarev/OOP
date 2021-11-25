#pragma once
#include "Entry.hpp"
typedef std::string Key;

// CR: i think it's better to hide HashTable implementation details from user
// CR: so you can declare HashList as inner class of HashTable and define in separate file
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

    Value* search(const Key& k);

    HashList& operator=(const HashList& other);

    Entry* pop();

    void freeList();

    void reverse();

    friend bool operator==(const HashList& a, const HashList& b);

    friend bool operator!=(const HashList& a, const HashList& b);
private:
    Entry* head_ = nullptr;

};