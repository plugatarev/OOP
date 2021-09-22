#include "HashList.hpp"
#include "Header.hpp"

HashList::HashList(){}

HashList::HashList(HashList & b){
    
}

HashList::HashList(const Value & v){
}

bool HashList::insert(const Value & v){
    if (search(v)) return false;
    if (head_ == nullptr) {
        head_ = new Value(v);
        return true;
    }
    head_ = new Value(v,head_->next);
}

void HashList::freeList(){
    Value* tmp = head_->next;
    while (head_ != nullptr){
        delete head_;
        head_ = tmp;
        tmp = tmp->next;
    }
}

bool HashList::search(const Value & v){
    
}