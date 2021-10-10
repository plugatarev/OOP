#pragma once
#include "Header.hpp"
#include "HashList.hpp"
typedef std::string Key;

class HashTable {
public:

   //Creates empty HashTabes with default capacity
   HashTable();

   //Creates empty HashTabes with size capacity
   HashTable(size_t size);
   ~HashTable();

   HashTable& operator=(const HashTable& b);

   HashTable(const HashTable& b);

   //swaps the HashTabes
   void swap(HashTable& b);

   //clears the HashTabes
   void clear();

   //Removes the element (if one exists) with the key equivalent to key.
   bool erase(const Key& k);
   
   //Inserts element(s) into the container
   bool insert(const Key& k, const Value& v);

   //checks if the Value contains element with specific key
   bool contains(const Key& k) const;

   //Return a reference to the value of the existing element whose is equivalent to k.
   //Reference to the mapped value of the new element if no element with key k existed.  
   Value& operator[](const Key& k);

   //Return a reference to the value of the existing element whose is equivalent to k.
   //exception out_of_range if no element with key k existed. 
   Value& at(const Key& k);
   const Value& at(const Key& k) const;
   
   //Returns the number of elements
   size_t size() const;

   //Returns the capacity of HashTable
   size_t capacity() const;

   //checks whether the hashtable is empty
   bool empty() const;

   //Retunrs true if a equal b. Retunr false if a not equal b
   friend bool operator==(const HashTable& a, const HashTable& b);

   //Retunrs true if a not equal b. Retunr false if a equal b
   friend bool operator!=(const HashTable& a, const HashTable& b);

   //Prints HashTable
   void print_HashTable() const;
   
private:
   HashList** list_;
   size_t capacity_ = 0;
   size_t size_ = 0;
   const int DefaultSize = 16;

   const double ResizeOn = 0.75;

   size_t hashF(const Key& k) const;

   //if hashtable overflows сhange the size 
   bool resize();
};