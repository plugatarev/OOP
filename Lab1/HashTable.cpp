#include "HashTable.hpp"

HashTable::HashTable():list_(new HashList[_DEFAULT_HASTABLE_SIZE]), capacity_(_DEFAULT_HASTABLE_SIZE){}

HashTable::HashTable(size_t size):list_(new HashList[size]),capacity_(size){}

HashTable::~HashTable(){
    delete [] list_;
}
HashTable::HashTable(const HashTable& b):list_(new HashList[b.capacity_]),capacity_(b.capacity_){
    for (size_t i = 0; i < capacity_; i++){
        list_[i] = b.getlist(i);
    }
}

size_t HashTable::size() const{
    return capacity_;
}

HashList & HashTable::getlist(const int i) const {
    return list_[i];
}


HashTable& HashTable::operator=(const HashTable& b){
    if (&b != this){
        if (list_) delete[] list_;
        capacity_ = b.capacity_;
        for (size_t i = 0; i < capacity_; i++){
            list_[i] = b.getlist(i);
        }
    }
}
