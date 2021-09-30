#pragma once
#include "Header.hpp"
#include "HashList.hpp"
class HashTable {

private:
   HashList* list_;
   int capacity_ = 0;
   int size_ = 0;
   size_t hashF(const Key& k);

   int hashF(const Value&) const;
public:
   HashTable();
   HashTable(size_t size);
   ~HashTable();

   HashTable& operator=(const HashTable& b);

   HashTable(const HashTable& b);

   void swap(HashTable& b);

   void clear();

   bool erase(const Key& k);

   bool insert(const Key& k, const Value& v);

   bool contains(const Key& k) const;

   //Return a reference to the mapped value of the existing element whose key is equivalent to key.
   //Reference to the mapped value of the new element if no element with key key existed.  
   Value& operator[](const Key& k);

   Value& at(const Key& k);
   const Value& at(const Key& k) const;
  
   size_t size() const;

   bool empty() const;

   bool resize();

   friend bool operator==(const HashTable& a, const HashTable& b);
   friend bool operator!=(const HashTable& a, const HashTable& b);
};