#include "array.hpp"
#include <cassert>
#include <iostream>
#include <algorithm>

int_array::int_array(int capacity): data_(new Value[capacity]), capacity_(capacity) {}

int_array::int_array(int_array & other) : capacity_(other.capacity_), size_(other.size_), data_(new Value[other.size_]) {
    std::copy(other.data_, other.data_ + size_, data_);
}

int_array::~int_array() {
    delete[] data_;
}


void int_array::resize(){
    Value* arr = new Value[capacity_ * 2];
    capacity_ = capacity_ * 2;
    for (int i = 0; i < size_; i++){
        arr[i] = data_[i];
    }
    delete [] data_;
    data_ = arr;
}

int int_array::push_back(int i) {
    if (size_ + 1 == capacity_) resize();
    //data_[size_] = i;
    size_++;
    return size_;
}

Value int_array::at(int i) {
    assert(i < size_ && i >= 0);
    return data_[i];
}

int int_array::pop_back() {
    assert(size_ > 0);
    size_--;
    return data_[size_];
}

int int_array::size() {
    return size_;
}

int_array & int_array::operator=(int_array & other){
    if (&other != this){
        delete [] data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new Value [capacity_];
        std::copy(other.data_, other.data_ + size_, data_);
    }
    return *this;
}

void int_array::print_arr() const{
    for (size_t i = 0; i < size_; i++){
        std::cout << data_[i] << " ";
    }
    std::cout << std::endl;
}
