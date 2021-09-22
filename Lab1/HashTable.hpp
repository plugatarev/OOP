#pragma once
#include "Header.hpp"
#include "HashList.hpp"
class HashTable {

private:
   HashList* list_;
   int capacity_;
   int size_;
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
  
   Value& operator[](const Key& k);

   Value& at(const Key& k);
   const Value& at(const Key& k) const;
  
   size_t size() const;

   bool empty() const;

   HashList & getlist(const int i) const;

   friend bool operator==(const HashTable& a, const HashTable& b);
   friend bool operator!=(const HashTable& a, const HashTable& b);
};