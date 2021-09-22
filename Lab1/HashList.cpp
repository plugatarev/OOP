#include "HashList.hpp"
#include "Value.hpp"

HashList::HashList(){}

HashList::HashList(HashList & b):size_(b.size_){
    HashList* tmp = &b;
    while (tmp != nullptr){
        push(*(tmp->val_));
        tmp = tmp->next_;
    }
}

HashList::HashList(const Value & v){
    push(v);
}

void HashList::push(const Value & v){
    // HashList* h = new HashList();
    // val_ = new Value(v);
    // h->val_ = val_;
    // (h->size_)++;
    // if (size_ == 0) h->next_ = nullptr;
    // this = h;
    // else{
    //     HashList* t = this;
        
    // }
}