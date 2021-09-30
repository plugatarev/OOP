#pragma once
#include "Header.hpp"
#include "HashList.hpp"
class HashTable {

private:
   HashList* list_;
   int capacity_ = 0;
   int size_ = 0;
   size_t hashF(const Key& k);
public:
   HashTable();
   HashTable(size_t size);
   ~HashTable();

   HashTable& operator=(const HashTable& b);

   HashTable(const HashTable& b);

   void swap(HashTable& b);

   //clears the hashtable
   void clear();

   //Removes the element (if one exists) with the key equivalent to key.
   bool erase(const Key& k);
   
   //Inserts element(s) into the container
   bool insert(const Key& k, const Value& v);

   bool contains(const Key& k) const;

   //Return a reference to the value of the existing element whose is equivalent to k.
   //Reference to the mapped value of the new element if no element with key k existed.  
   Value& operator[](const Key& k);

   //Return a reference to the value of the existing element whose is equivalent to k.
   //exception ... if no element with key k existed. 
   Value& at(const Key& k);
   const Value& at(const Key& k) const;
   
   //Returns the number of elements
   size_t size() const;

   //checks whether the hashtable is empty
   bool empty() const;

   //if hashtable overflows сhange the size twice
   bool resize();

   friend bool operator==(const HashTable& a, const HashTable& b);
   friend bool operator!=(const HashTable& a, const HashTable& b);
};