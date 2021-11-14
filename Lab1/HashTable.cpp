#include "HashTable.hpp"
#include <stdexcept>
typedef std::string Key;

HashTable::HashTable(size_t capacity):list_(new HashList*[capacity]),capacity_(capacity), size_(0){
    for (int i = 0; i < capacity_; i++) list_[i] = nullptr;
}

HashTable::~HashTable(){
    for (size_t i = 0; i < capacity_; i++){
        if (list_[i] != nullptr) delete list_[i]; 
        list_[i] = nullptr;
    }
    delete[] list_;
    list_ = nullptr;
}
HashTable::HashTable(const HashTable& b){
    //if (b.size_ != 0){
        capacity_ = b.capacity_;
        size_ = b.size_;
        list_ = new HashList*[b.capacity_];
        for (size_t i = 0; i < capacity_; i++){
            list_[i] = nullptr;
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

bool operator!=(const HashTable& a, const HashTable& b){
    if (a.size_ != b.size_ || a.capacity_ != b.capacity_) return true;
    for (size_t i = 0; i < a.capacity_; i++){
        if ( (a.list_[i] == nullptr && b.list_[i] != nullptr) || (a.list_[i] != nullptr && b.list_[i] == nullptr)) return true;
        if (a.list_[i] == nullptr) continue;
        if (*a.list_[i] != *b.list_[i]) return true;
    }
    return false;
}

bool operator==(const HashTable& a, const HashTable& b){
    return (!(a != b));
}

HashTable& HashTable::operator=(const HashTable& b){
    
    if (b != *this){
        clear();
        delete[] list_;
        list_ = nullptr;
        capacity_ = b.capacity_;
        size_ = b.size_;
        list_ = new HashList*[capacity_];
        for (size_t i = 0; i < capacity_; i++){
            list_[i] = nullptr;
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
    if (list_[hash]->search(k)){
        list_[hash]->insert(const_cast<Key&>(k),const_cast<Value&>(v));   
        return false;
    }
    size_++;
    return list_[hash]->insert(const_cast<Key&>(k),const_cast<Value&>(v));    
}

bool HashTable::erase(const Key& k){
    if (size() == 0) return false;
    int hash =  hashF(k);
    if (list_[hash] == nullptr) return false;
    if (list_[hash]->remove(k)){
        size_--;
        return true;
    }
    return false;
}


bool HashTable::empty() const{
    return (size() == 0);
}

size_t HashTable::hashF(const Key& k) const{
    size_t hash = 0;
	for (size_t i = 0; i < k.length(); i++) {
		hash += (k[i] % 5) * pow(3,i);
	}
	return hash % capacity_;
}

bool HashTable::resize(){
    if ( !(capacity_ * 2 < UINT_MAX && capacity_ * 2 > 0)) throw std::runtime_error("capacity is more than UINT_MAX");
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
                l = nullptr;
                l = list_[i]->pop();
            }
            delete list_[i];
        }
    }
    delete[] list_;
    list_ = nullptr;
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
        Value v;
        list_[hash]->insert(k, v);
        return *list_[hash]->search(k);
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
    HashTable tmp = b;
    b = *this;
    *this = tmp;
}

void HashTable::operator<<(const HashTable& a) const{
      for (size_t i = 0; i < capacity_; i++){
            if (list_[i] != nullptr) list_[i]->printList();
      }   
}