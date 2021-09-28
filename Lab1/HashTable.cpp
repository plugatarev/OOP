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
    if (size_ == capacity_) resize();
    int hash = hashF(k);
    list_[hash].insert(const_cast<Key&>(k),const_cast<Value&>(v));
    size_++;
}

bool HashTable::erase(const Key& k){
    int hash =  hashF(k);
    list_[hash].remove(k);
}


bool HashTable::empty() const{
    return (size_ == 0);
}

size_t HashTable::hashF(const Key& k){
    size_t hash = 0;
    int m = 1e9 + 9;
    int p = 31;
    long long power_of_p = 1;
    for (int i = 0; i < k.length(); i++) {
        hash = (hash+ (k[i] - 'a' + 1) * power_of_p) % m;
        power_of_p = (power_of_p * p) % m;
    }
   
   //return positive remainder only
    return (hash % m + m) % m;
}

bool HashTable::resize(){
    if (2 * capacity_ > INT_MAX)
    capacity_ = 2 * capacity_;
    size_ = 2 * size_;
    HashList* tmp = new HashList[capacity_];
    for (size_t i = 0; i < size_; i++){
        tmp[i] = list_[i];
    }
    delete[] list_;
    list_ = tmp;
    return true;
}

void HashTable::clear(){
    delete [] list_;
    capacity_ = 0;
    size_ = 0;
}