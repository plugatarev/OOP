#pragma once
#include<stack>
#include "Exception.hpp"
class My_Stack: public std::stack<int>{
public:
    int& top_and_pop(){
        if (empty()) throw interpreter_error("extracting from an empty stack");
        int& r = top();
        pop();
        return r;
    }
    void print(){
        My_Stack tmp;
        while (!empty()){
            tmp.push(top());
            std::cout << top_and_pop() << " ";
        }
        while(!tmp.empty()){
            push(tmp.top_and_pop());
        }
    }
    int size(){
        int c = 0;
        while (!empty()){
            top_and_pop();
            c++;
        }
        return c;
    }
};