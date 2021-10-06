#include "HashList.hpp"
#include "Header.hpp"
#include "Entries.hpp"
HashList::HashList():head_(nullptr){}

HashList::HashList(HashList & b){
    Entries* tmp = b.head_;
    while (tmp != NULL){
        insert(tmp->key, tmp->value);
        tmp = tmp->next;
    }
}

HashList::~HashList(){
    freeList();
}

bool HashList::insert(const Key& k, const Value& v){
    //if (search(k)) return false;
    if (head_ == nullptr) {
        head_ = new Entries(const_cast<Key&>(k),const_cast<Value&>(v));
        return true;
    }
    head_ = new Entries(const_cast<Key&>(k),const_cast<Value&>(v),head_);
    return true;
}


void HashList::freeList(){
    while(head_ != NULL){
        Entries* next = head_->next;
        delete head_;
        head_ = next;
    }
}

void HashList::printList() const{
    Entries* tmp = head_;
    while (tmp != NULL){
        std::cout << tmp->key << " " << tmp->value.age << " " << tmp->value.name <<std::endl;
        tmp = tmp->next;
    }
}


bool HashList::search(const Key& k) const{
    Entries* tmp = head_;
    while (tmp != NULL){
        if (tmp->key == k) return true;
        tmp = tmp->next;
    }
    return false;
}

bool HashList::remove(const Key& k){
    Entries* before_tmp = head_;
    Entries* tmp = head_;
    while (tmp->next != NULL || tmp->key != k) {
        before_tmp = tmp;
        tmp = tmp->next;
    }
    if (tmp->key == k){
        before_tmp->next = tmp->next;
        delete tmp;
        return true;
    }
    return false;

}

Value& HashList::at(const Key& k) const{
    Entries* tmp = head_;
    while (tmp != NULL){
        if (tmp->key == k) return tmp->value;
        tmp = tmp->next;
    }
    throw std::out_of_range("no such element exists");
}

HashList & HashList::operator=(const HashList& other){
    if (*this != other){
        freeList();
        Entries* tmp = other.head_;
        while (tmp != NULL){
        insert(tmp->key, tmp->value);
        tmp = tmp->next;
        }
    }
    *this;
}

bool operator==(const HashList& a, const HashList& b){
    Entries* tmp_a = a.head_;
    Entries* tmp_b = b.head_;

    while (tmp_a != NULL || tmp_b != NULL){
        if (!(*tmp_a == *tmp_b)) return false;
    }
    if ((tmp_a == NULL && tmp_b != NULL) || (tmp_b == NULL && tmp_a != NULL)) return false;
    return true;
}

bool operator!=(const HashList& a, const HashList& b){
    return (!operator==(a,b));
}

Entries* HashList::pop(){
    if (head_ == NULL) return NULL;
    Entries* tmp = new Entries(head_->key,head_->value);
    remove(head_->key);
    return tmp;
}

bool HashList::search_and_insert(const Key& k, const Value& v){
    Entries* tmp = head_;
    while (tmp != NULL){
        if (tmp->key == k) return true;
        tmp = tmp->next;
    }
    return insert(k,v);
}