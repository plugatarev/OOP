#include "My_Stack.hpp"
#include "Exception.hpp"

int My_Stack::peek(){
    return stack.top();
}

int& My_Stack::pop(){
    if (stack.empty()) throw interpreter_error("extracting from an empty stack");
    int& r = stack.top();
    stack.pop();
    return r;
}

void My_Stack::print(){
    My_Stack tmp;
    while (!stack.empty()){
        tmp.push(peek());
        std::cout << pop() << " ";
    }
    while(!tmp.stack.empty()){
        push(tmp.pop());
    }
}

int My_Stack::size(){
    return stack.size();
}

void My_Stack::push(int value){
    stack.push(value);
}
