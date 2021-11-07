#include "HashTable.hpp"
#include <stdexcept>
typedef std::string Key;

HashTable::HashTable():size_(0){
    list_ = new HashList*[DefaultSize];
    capacity_ = DefaultSize;
    for (size_t i = 0; i < DefaultSize; i++) list_[i] = nullptr;
}

HashTable::HashTable(size_t capacity):list_(new HashList*[capacity]),capacity_(capacity), size_(0){
    for (size_t i = 0; i < capacity; i++) list_[i] = nullptr;
}

HashTable::~HashTable(){
    for (size_t i = 0; i < capacity_; i++){
        if (list_[i] != nullptr) list_[i]->~HashList(); 
    }
    delete[] list_;
}
HashTable::HashTable(const HashTable& b){
    if (b.capacity_ != 0){
        capacity_ = b.capacity_;
        size_ = b.size_;
        list_ = new HashList*[b.capacity_];
        for (size_t i = 0; i < capacity_; i++){
            list_[i] = nullptr;
            if (b.list_[i] != NULL) {
                list_[i] = new HashList(*b.list_[i]);
            }
        }
    }
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
        if (a.list_[i] == NULL) continue;
        bool flag = 0;
        if (*a.list_[i] == *b.list_[i]) flag = 1;
        b.list_[i]->reverse();
        if (*a.list_[i] == *b.list_[i]) flag = 1;
        if (!flag) return true;
    }
    return false;
}

bool operator==(const HashTable& a, const HashTable& b){
    return (!(a != b));
}

HashTable& HashTable::operator=(const HashTable& b){
    if (b != *this){
        capacity_ = b.capacity_;
        size_ = b.size_;
        delete[] list_;
        list_ = new HashList*[capacity_];
        for (size_t i = 0; i < capacity_; i++){
            list_[i] = nullptr;
            if (b.list_[i] != NULL) {
                list_[i] = new HashList();
                *list_[i] = *b.list_[i];
            }
        }
    }
    return *this;
}

bool HashTable::insert(const Key& k, const Value& v){
    if (size() > int(ResizeOn * capacity_)) resize();
    size_t hash = hashF(k);
    size_++;
    if (list_[hash] == nullptr) list_[hash] = new HashList();
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
	for (int i = 0; i < k.length(); i++) {
		hash += (k[i] % 5) * pow(3,i);
	}
	return hash % capacity_;
}

bool HashTable::resize(){
    if (capacity_ * 2 < INT_MAX && capacity_ * 2 > 0) throw std::runtime_error("capacity is more than INT_MAX");
    int c = capacity();
    capacity_ = capacity_ * 2;

    HashList** tmp = new HashList*[capacity_];
    for (size_t i = 0; i < capacity_; i++){
        tmp[i] = nullptr;
    }
    for (size_t i = 0; i < c; i++){
        if (list_[i] != nullptr){
            Entry* l = list_[i]->pop();
            while (l != nullptr){
                size_t hash = hashF(l->key);
                if (tmp[hash] == nullptr) tmp[hash] = new HashList();
                tmp[hash]->insert(l->key,l->value);
                delete l;
                Entry* l = list_[i]->pop();
                if (l == nullptr) break;
            }
        }
    }
    list_ = tmp;
    return true;
}

void HashTable::clear(){
    if (size_ == 0) return;
    for (size_t i = 0; i < capacity_;i++){
        if (list_[i] != nullptr){
            list_[i]->freeList();
            list_[i] = nullptr;
        }
    }
    delete[] list_;
    list_ = new HashList*[capacity_];
    for (size_t i = 0; i < capacity_; i++){
        list_[i] = nullptr;
    }
    size_ = 0;
}

Value& HashTable::operator[](const Key& k){
    int hash = hashF(k);
    if (list_[hash] == nullptr) list_[hash] = new HashList();
    return list_[hash]->search_and_insert(k,&size_);
}

Value& HashTable::at(const Key& k){
    if (size() == 0) throw std::out_of_range("no such element exists");
    int hash = hashF(k);
    //exception if no such element exists
    if (list_[hash] == nullptr) throw std::out_of_range("no such element exists");
    return list_[hash]->at(k);
}

const Value& HashTable::at(const Key& k) const{
    if (size() == 0) throw std::out_of_range("no such element exists");
    int hash = hashF(k);
    //exception if no such element exists
    if (list_[hash] == nullptr) throw std::out_of_range("no such element exists");
    return (const_cast<Value&>(list_[hash]->at(k)));
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

void HashTable::print_HashTable() const{
      for (size_t i = 0; i < capacity_; i++){
            if (list_[i] != NULL) list_[i]->printList();
      }   
}