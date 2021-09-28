#include "HashList.hpp"
#include "Header.hpp"
#include "HashMap.hpp"

HashList::HashList(){
    head_ = nullptr;
}

HashList::HashList(HashList & b){
    HashMap* tmp = b.head_;
    while (tmp != NULL){
        insert(*tmp);
        tmp = tmp->next;
    }
}

HashList::~HashList(){
    freeList();
}

bool HashList::insert(const HashMap & v){
    if (search(v)) return false;
    if (head_ == nullptr) {
        head_ = new HashMap(v);
        return true;
    }
    head_ = new HashMap(v,head_);
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


bool HashList::search(const HashMap & v){
    HashMap* tmp = head_;
    while (tmp != NULL){
        if (*tmp == v) return true;
        tmp = tmp->next;
    }
    return false;
}

bool HashList::remove(HashMap & v){
    if (*head_ == v){
        HashMap* tmp = head_;
        head_ = head_->next;
        delete tmp;
        return true;
    }
    HashMap* before_tmp = head_;
    HashMap* tmp = head_->next;
    while (tmp != NULL){
        if (*tmp == v) {
            before_tmp->next = tmp->next;
            delete tmp;
            return true;
        }
        before_tmp = tmp;
        tmp = tmp->next;
    }
    return false;
}


 