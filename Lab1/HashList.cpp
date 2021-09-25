#include "HashList.hpp"
#include "Header.hpp"

HashList::HashList(){
    head_ = nullptr;
}

HashList::HashList(HashList & b){
    Value* tmp = b.head_;
    while (tmp != NULL){
        insert(*tmp);
        tmp = tmp->next;
    }
}

HashList::~HashList(){
    freeList();
}

bool HashList::insert(const Value & v){
    if (search(v)) return false;
    if (head_ == nullptr) {
        head_ = new Value(v);
        return true;
    }
    head_ = new Value(v,head_);
}


void HashList::freeList(){
    while(head_ != NULL){
        Value* next = head_->next;
        delete head_;
        head_ = next;
    }
}

void HashList::printList() const{
    Value* tmp = head_;
    while (tmp != NULL){
        std::cout << tmp->age << " ";
        tmp = tmp->next;
    }
}


bool HashList::search(const Value & v){
    Value* tmp = head_;
    while (tmp != NULL){
        if (*tmp == v) return true;
        tmp = tmp->next;
    }
    return false;
}

bool HashList::remove(Value & v){
    if (*head_ == v){
        Value* tmp = head_;
        head_ = head_->next;
        delete tmp;
        return true;
    }
    Value* before_tmp = head_;
    Value* tmp = head_->next;
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


 