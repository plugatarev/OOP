#include "array.hpp"
#include <cassert>
#include <iostream>
//#include <algorithm>

int_array::int_array(int capacity): data_(new int[capacity]), capacity_(capacity) {}

int_array::int_array(int_array & other) : size_(other.size_), capacity_(other.capacity_), data_(new int [other.size_]){
    for (size_t i = 0; i < size_; i++){
        data_[i] = other.data_[i];
    }
    //std::copy(other.size_, other.size_ + size_, data_);
}

int_array::~int_array() {
    delete[] data_;
}


void int_array::resize(){
    int* arr = new int[capacity_ * 2];
    capacity_ = capacity_ * 2;
    for (int i = 0; i < size_; i++){
        arr[i] = data_[i];
    }
    delete [] data_;
    data_ = arr;
}

int int_array::push_back(int i) {
    if (size_ + 1 == capacity_) resize();
    data_[size_] = i;
    size_++;
    return size_;
}

int int_array::at(int i) {
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

void int_array::print_arr() const{
    for (size_t i = 0; i < size_; i++){
        std::cout << data_[i] << " ";
    }
    std::cout << std::endl;
}


void test(){
    int_array arr(2);
    arr.push_back(13);
    arr.push_back(42);
    arr.push_back(23);
    arr.push_back(23);

    arr.print_arr();

    int_array arr_test(arr);
    arr.print_arr();
}

int main(int argc, char const *argv[]) {
    test();
    // int_array arr(2);
    // arr.push_back(13);
    // arr.push_back(42);
    // arr.push_back(23);
    // arr.push_back(23);

    // // 13
    // std::cout << arr.at(0) << std::endl;
    // // 42
    // std::cout << arr.pop_back() << std::endl;
    // // 1
    // std::cout << "Size: " << arr.size() << std::endl; 
    // arr.~int_array();
    return 0;
}
