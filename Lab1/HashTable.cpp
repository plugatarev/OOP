#include "HashTable.hpp"

HashTable::HashTable():list_(new HashList[_DEFAULT_HASHTABLE_SIZE]), capacity_(_DEFAULT_HASHTABLE_SIZE), size_(0){}

HashTable::HashTable(size_t size):list_(new HashList[size]),capacity_(size), size_(0){}

HashTable::~HashTable(){
    delete [] list_;
}
HashTable::HashTable(const HashTable& b){
    if (b.list_ != NULL){
        capacity_ = b.capacity_;
        size_ = b.size_;
        list_ = new HashList[b.capacity_];
        for (size_t i = 0; i < size_; i++){
            list_[i] = b.list_[i];
        }
    }
}

size_t HashTable::size() const{
    return size_;
}

bool operator!=(const HashTable& a, const HashTable& b){
    return false;
}

HashTable& HashTable::operator=(const HashTable& b){
    if (b != *this){
        capacity_ = b.capacity_;
        size_ = b.size_;
        delete[] list_;
        list_ = new HashList[size_];
        for (size_t i = 0; i < size_; i++){
            list_[i] = b.list_[i];
        }
    }
    return *this;
}

bool HashTable::insert(const Key& k, const Value& v){
    int hash = hashF(k);
}


bool HashTable::empty() const{
    return (size_ == 0);
}

int HashTable::hashF(const Key& k){
    return 0;
}
