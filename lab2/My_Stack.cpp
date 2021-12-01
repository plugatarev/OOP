#include "My_Stack.hpp"
#include "Exception.hpp"

int My_Stack::peek(){
    return stack.top();
}

int& My_Stack::pop(){
    if (stack.empty()) throw interpreter_error("extracting from an empty stack");
    int& r = stack.top();
    pop();
    return r;
}

void My_Stack::print(){
    My_Stack tmp;
    while (!stack.empty()){
        tmp.push(stack.top());
        std::cout << pop() << " ";
    }
    while(!tmp.stack.empty()){
        push(tmp.pop());
    }
}

int My_Stack::size(){
    int c = 0;
    while (!stack.empty()){
        pop();
        c++;
    }
    return c;
}

void My_Stack::push(int value){
    stack.push(value);
}
