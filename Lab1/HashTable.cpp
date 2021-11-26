#include "HashTable.hpp"
#include <stdexcept>
#include <limits.h>
#include <cmath>
#include <memory>
typedef std::string Key;

HashTable::HashTable(size_t capacity):list_(new HashList*[capacity]()),capacity_(capacity), size_(0){
    // CR: replace new HashList*[capacity] -> new HashList*[capacity]() and pointers will be init to nullptr - ok
}

HashTable::~HashTable(){
    // CR: can optimize using size_ - maybe so?
    for (size_t i = 0; i < capacity_ && size_ > 0; i++){
        if (list_[i] != nullptr){
            delete list_[i];
            --size_;
        } 
    }
    delete[] list_;
}
HashTable::HashTable(const HashTable& b):list_(new HashList*[b.capacity_]()){
    //if (b.size_ != 0){
        capacity_ = b.capacity_;
        size_ = b.size_;
        // CR: new HashList*[b.capacity_] -> new HashList*[b.capacity_]() - ok
        // CR: it will initialize pointers with nullptr - ok
        for (size_t i = 0; i < capacity_; i++){
            if (b.list_[i] != nullptr) {
                list_[i] = new HashList(*b.list_[i]);
            }
        }
    //}
}

size_t HashTable::size() const{
    return size_;
}

size_t HashTable::capacity() const{
    return capacity_;
}

bool HashTable::is_equal_table(const HashTable& b) const{
    for (size_t i = 0; i < capacity_; i++){
        if (list_[i] != nullptr){
            Entry* t = list_[i]->get_head();
            while (t != nullptr){
                if (b.contains(t->key) && !(b.get_value_by_key(t->key) == t->value)) return true;
                t = t->next;
            }
        }
    }
    return false;
}

bool operator!=(const HashTable& a, const HashTable& b){
    // CR: it's ok to have different capacity_
    if (a.size_ != b.size_) return true;
    if (a.capacity_ > b.capacity_) return a.is_equal_table(b);     
    return b.is_equal_table(a);
}

bool operator==(const HashTable& a, const HashTable& b){
    return (!(a != b));
}

HashTable& HashTable::operator=(const HashTable& b){
    capacity_ = b.capacity_;
    if (b != *this){
        // CR: i guess you do clear inside HashList & HashTable::HashList::operator=(const HashList& other), no? - we are creating a new table with new capacity, old table deletes
        clear();
        delete[] list_;
        capacity_ = b.capacity_;
        size_ = b.size_;
        // CR: new HashList*[capacity_]() - ok
        list_ = new HashList*[capacity_]();
        for (size_t i = 0; i < capacity_; i++){
            if (b.list_[i] != nullptr) {
                list_[i] = new HashList();
                *list_[i] = *b.list_[i];
            }
        }
    }
    return *this;
}

bool HashTable::insert(const Key& k, const Value& v){
    if (size() > size_t(ResizeOn * capacity_)) resize();
    size_t hash = hashF(k);
    if (list_[hash] == nullptr) list_[hash] = new HashList();
    // CR: you can do it in one go, just replace the result from the search
    Value* val = list_[hash]->search(k);
    if (val != nullptr){
        // CR: now you have two entries with the same key, instead of replacing old value
        // CR: please fix it and write a test for this situation
        val->age = v.age;
        val->name = v.name;
        return false;
    }
    size_++;
    return list_[hash]->insert(const_cast<Key&>(k),const_cast<Value&>(v));    
}

bool HashTable::erase(const Key& k){
    if (size() == 0) return false;
    int hash = hashF(k);
    if (list_[hash] == nullptr) return false;
    if (list_[hash]->remove(k)){
        if (list_[hash]->get_head() == nullptr) delete list_[hash];
        size_--;
        return true;
    }
    return false;
}


bool HashTable::empty() const{
    return size() == 0;
}

size_t HashTable::hashF(const Key& k) const{
    size_t hash = 0;
	for (size_t i = 0; i < k.length(); i++) {
		hash += (k[i] % 5) * pow(3,i);
	}
	return hash % capacity_;
}

bool HashTable::resize(){
    // CR: https://www.cplusplus.com/reference/limits/numeric_limits/
    if ( !(capacity_ * 2 < UINT_MAX && capacity_ * 2 > capacity_)) throw std::runtime_error("capacity is more than UINT_MAX");
    size_t c = capacity();
    capacity_ = capacity_ * 2;

    HashList** tmp = new HashList*[capacity_];
    for (size_t i = 0; i < capacity_; i++){
        tmp[i] = nullptr;
    }
    for (size_t i = 0; i < c; i++){
        if (list_[i] != nullptr){
            Entry* l = (list_[i]->pop());
            while (l != nullptr){
                size_t hash = hashF(l->key);
                if (tmp[hash] == nullptr) tmp[hash] = new HashList();
                tmp[hash]->insert(l->key,l->value);
                delete l;
                l = list_[i]->pop();
            }
            delete list_[i];
        }
    }
    delete[] list_;
    list_ = tmp;
    return true;
}

void HashTable::clear(){
    if (size_ == 0) return;
    for (size_t i = 0; i < capacity_;i++){
        if (list_[i] != nullptr){
            delete list_[i];
            list_[i] = nullptr;
        }
    }
    size_ = 0;
}

Value& HashTable::operator[](const Key& k){
    int hash = hashF(k);
    if (list_[hash] == nullptr) list_[hash] = new HashList();
    Value* tmp = list_[hash]->search(k);
    if (tmp == nullptr){
        size_++;
        // CR: will be destroyed after return from fuction - TODO: deleted Value
        // CR: please fix and write a test - ok
        std::unique_ptr<Value> val(new Value());
        list_[hash]->insert(k, *val);
        // CR: well, you already have a value, no? -  yes, ok
        return *val;
    }

    return *tmp;
}

Value& HashTable::get_value_by_key(const Key& k) const{
    if (size() == 0) throw std::out_of_range("no such element exists");
    int hash = hashF(k);
    //exception if no such element exists
    if (list_[hash] == nullptr) throw std::out_of_range("no such element exists");
    return list_[hash]->at(k);
}

Value& HashTable::at(const Key& k){
    return get_value_by_key(k);
}

const Value& HashTable::at(const Key& k) const{
    return (const_cast<Value&>(get_value_by_key(k)));
}

bool HashTable::contains(const Key& k) const{
    if (size() == 0) return false;
    size_t hash = hashF(k);
    if (list_[hash] == nullptr) return false;
    return list_[hash]->search(k);
}

void HashTable::swap(HashTable& b){
    // CR: we copy everything three times, could've just swap fields - ok
    std::swap(list_, b.list_);
    std::swap(capacity_, b.capacity_);
    std::swap(size_, b.size_);
}

void HashTable::operator<<(const HashTable& a) const{
      for (size_t i = 0; i < capacity_; i++){
            if (list_[i] != nullptr) list_[i]->printList();
      }   
}