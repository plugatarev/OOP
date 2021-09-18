#include "HashTable.hpp"

HashTable::HashTable():list_(new Value[_DEFAULT_HASTABLE_SIZE]), capacity_(_DEFAULT_HASTABLE_SIZE){}

HashTable::~HashTable(){
    delete [] list_;
}
HashTable::HashTable(const HashTable& b):list_(new Value[b.capacity_]),capacity_(b.capacity_){
    for (size_t i = 0; i < capacity_; i++){
        list_[i].age = b.list_[i].age;
        list_[i].name = b.list_[i].name;
    }
}
