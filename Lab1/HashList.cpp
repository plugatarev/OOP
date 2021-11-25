#include "HashList.hpp"
#include "Header.hpp"
#include "Entry.hpp"
#include <iostream>
HashList::HashList():head_(nullptr){}

HashList::HashList(HashList & b){
    Entry* tmp = b.head_;
    while (tmp != nullptr){
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
        head_ = new Entry(const_cast<Key&>(k),const_cast<Value&>(v));
        return true;
    }
    head_ = new Entry(const_cast<Key&>(k),const_cast<Value&>(v),head_);
    return true;
}


void HashList::freeList(){
    while(head_ != nullptr){
        Entry* next = head_->next;
        delete head_;
        head_ = next;
    }
}

void HashList::printList() const{
    Entry* tmp = head_;
    while (tmp != nullptr){
        std::cout << tmp->key << " " << tmp->value.age << " " << tmp->value.name <<std::endl;
        tmp = tmp->next;
    }
}


bool HashList::search(const Key& k) const{
    Entry* tmp = head_;
    while (tmp != nullptr){
        if (tmp->key == k) return true;
        tmp = tmp->next;
    }
    return false;
}

bool HashList::remove(const Key& k){
    if (head_->key == k){
        Entry* t = head_;
        head_ = head_->next;
        delete t;
        // CR: redundant
        t = nullptr;
        return true;
    }
    Entry* before_tmp = head_;
    Entry* tmp = head_;
    while (tmp->next != nullptr && tmp->key != k) {
        before_tmp = tmp;
        tmp = tmp->next;
    }
    if (tmp->key == k){
        before_tmp->next = tmp->next;
        delete tmp;
        // CR: redundant
        tmp = nullptr;
        return true;
    }
    return false;

}

Value& HashList::at(const Key& k) const{
    Entry* tmp = head_;
    while (tmp != nullptr){
        if (tmp->key == k) return tmp->value;
        tmp = tmp->next;
    }
    throw std::out_of_range("no such element exists");
}

HashList & HashList::operator=(const HashList& other){
    if (*this != other){
        freeList();
        Entry* tmp = other.head_;
        while (tmp != nullptr){
            insert(tmp->key, tmp->value);
            tmp = tmp->next;
        }
    }
    return *this;
}

bool operator==(const HashList& a, const HashList& b){
    Entry* tmp_a = a.head_;
    Entry* tmp_b = b.head_;
    int count1 = 0;
    int count2 = 0;

    while (tmp_a != nullptr || tmp_b != nullptr){
        if (tmp_a != nullptr){
            count1++;
            tmp_a = tmp_a->next;
        }

        if (tmp_b != nullptr){
            count2++;
            tmp_b = tmp_b->next;
        }
    }
    if (count1 != count2) return false;

    tmp_a = a.head_;
    tmp_b = b.head_; 
    bool flag = false;   
    while (tmp_a != nullptr){
        while (tmp_b != nullptr){
            if (*tmp_a == *tmp_b){
                flag = true;
                break;
            }
            tmp_b = tmp_b->next;
        }
        if (flag == false) return false;
        flag = false;
        tmp_a = tmp_a->next;
        tmp_b = b.head_;    
    }
    return true;
}

bool operator!=(const HashList& a, const HashList& b){
    return (!operator==(a,b));
}

Entry* HashList::pop(){
    if (head_ == nullptr) return nullptr;
    Entry* tmp = head_;
    head_ = head_->next;
    return tmp;
}

// CR: why not have only this method and use it in HashTable::get_value_by_key?
// CR: this way there will be no code duplication
Value* HashList::search(const Key& k){
    Entry* tmp = head_;
    while (tmp != nullptr){
        if (tmp->key == k) return &(tmp->value);
        tmp = tmp->next;
    }
    return nullptr;
}

void HashList::reverse(){
    Entry* current = head_;
    Entry *prev = nullptr, *next = nullptr;

    while (current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head_ = prev;
}