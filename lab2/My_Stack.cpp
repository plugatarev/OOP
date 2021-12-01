#include "My_Stack.hpp"
#include "Exception.hpp"

int& My_Stack::top_and_pop(){
    if (empty()) throw interpreter_error("extracting from an empty stack");
    int& r = top();
    pop();
    return r;
}

void My_Stack::print(){
    My_Stack tmp;
    while (!empty()){
        tmp.push(top());
        std::cout << top_and_pop() << " ";
    }
    while(!tmp.empty()){
        push(tmp.top_and_pop());
    }
}
int My_Stack::size(){
    int c = 0;
    while (!empty()){
        top_and_pop();
        c++;
    }
    return c;
}
