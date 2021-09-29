#include "HashList.hpp"
#include "Header.hpp"
#include "HashMap.hpp"

HashList::HashList(){
    head_ = nullptr;
}

HashList::HashList(HashList & b){
    HashMap* tmp = b.head_;
    while (tmp != NULL){
        insert(tmp->key, tmp->value);
        tmp = tmp->next;
    }
}

HashList::~HashList(){
    freeList();
}

bool HashList::insert(const Key& k, const Value& v){
    if (search(k)) return false;
    if (head_ == nullptr) {
        head_ = new HashMap(const_cast<Key&>(k),const_cast<Value&>(v));
        return true;
    }
    head_ = new HashMap(const_cast<Key&>(k),const_cast<Value&>(v),head_);
    return true;
}


void HashList::freeList(){
    while(head_ != NULL){
        HashMap* next = head_->next;
        delete head_;
        head_ = next;
    }
}

void HashList::printList() const{
    HashMap* tmp = head_;
    while (tmp != NULL){
        std::cout << tmp->key << " ";
        tmp = tmp->next;
    }
}


bool HashList::search(const Key& k) const{
    HashMap* tmp = head_;
    while (tmp != NULL){
        if (tmp->key == k) return true;
        tmp = tmp->next;
    }
    return false;
}

bool HashList::remove(const Key& k){
    if (head_->key == k){
        HashMap* tmp = head_;
        head_ = head_->next;
        delete tmp;
        return true;
    }
    HashMap* before_tmp = head_;
    HashMap* tmp = head_->next;
    while (tmp != NULL){
        if (tmp->key == k) {
            before_tmp->next = tmp->next;
            delete tmp;
            return true;
        }
        before_tmp = tmp;
        tmp = tmp->next;
    }
    return false;
}

Value& HashList::at(const Key& k) const{
    HashMap* tmp = head_;
    while (tmp != NULL){
        if (tmp->key == k) return tmp->value;
        tmp = tmp->next;
    }
}
