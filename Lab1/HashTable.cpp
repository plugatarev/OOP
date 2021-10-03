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

size_t HashTable::capacity() const{
    return capacity_;
}

bool operator!=(const HashTable& a, const HashTable& b){
    if (a.size_ != b.size_ || a.capacity_ != b.capacity_) return false;
    for (size_t i = 0; i < a.size_; i++){
            if (!(a.list_[i] == b.list_[i])) return false;
        }
        return true;
}

bool operator==(const HashTable& a, const HashTable& b){
    return (!(a != b));
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
    if (hash >= capacity_) resize();
    size_++;
    return list_[hash].insert(const_cast<Key&>(k),const_cast<Value&>(v));    
}

bool HashTable::erase(const Key& k){
    int hash =  hashF(k);
    assert(hash < capacity_);
    if (list_[hash].remove(k)) return true;
    return false;
}


bool HashTable::empty() const{
    return (size_ == 0);
}

size_t HashTable::hashF(const Key& k) const{
    size_t hash = 0;
	for (int i = 0; i < k.length(); i++) {
		hash += (k[i] % 3) * pow(3,i);
	}
	return hash;
}

bool HashTable::resize(){
    assert(2 * capacity_ > INT_MAX);
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

Value& HashTable::operator[](const Key& k){
    int hash = hashF(k);
    assert(hash < capacity_);
    if (!list_[hash].search(k)) insert(k,Value());
    return list_[hash].at(k);
}

Value& HashTable::at(const Key& k){
    int hash = hashF(k);
    assert(hash < capacity_);
    //exception if no such element exists
    return list_[hash].at(k);
}

const Value& HashTable::at(const Key& k) const{
    int hash = hashF(k);
    assert(hash < capacity_);
    //exception if no such element exists
    return (const_cast<Value&>(list_[hash].at(k)));
}

bool HashTable::contains(const Key& k) const{
    size_t hash = hashF(k);
    assert(hash < capacity_);
    return list_[hash].search(k);
}

void HashTable::swap(HashTable& b){
    HashTable tmp;
    tmp = b;
    b = *this;
    *this = tmp;
}

void HashTable::print_HashTable() const{
      for (size_t i = 0; i < size_; i++){
         list_[i].printList();
      }
   }