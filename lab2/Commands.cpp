#include<iostream>
#include "Interpreter.hpp"
#include "Exception.hpp"
#include "Command_Set.hpp"
void Add::apply(My_Stack & _value){
    int right = _value.top_and_pop();
    int left = _value.top_and_pop();
    int res = left + right;
    _value.push(res);
}   

void Sub::apply(My_Stack & _value){
    int right = _value.top_and_pop();
    int left = _value.top_and_pop();
    int res = left - right;
    _value.push(res);
}

void Div::apply(My_Stack & _value){
    if (_value.top() == 0) throw interpreter_error("Error: division by zero");
    int right = _value.top_and_pop();
    int left = _value.top_and_pop();
    int res = left / right;
    _value.push(res);
}

void Mod::apply(My_Stack & _value){
    if (_value.top() == 0) throw interpreter_error("Error: division by zero");
    int right = _value.top_and_pop();
    int left = _value.top_and_pop();
    int res = left % right;
    _value.push(res);
}

void Mul::apply(My_Stack & _value){
    int right = _value.top_and_pop();
    int left = _value.top_and_pop();
    int res = left * right;
    _value.push(res);
}

void More::apply(My_Stack & _value){
    int right = _value.top_and_pop();
    int left = _value.top_and_pop();
    _value.push(left > right);
}

void Less::apply(My_Stack & _value){
    int right = _value.top_and_pop();
    int left = _value.top_and_pop();
    _value.push(left < right);
}

void Write::apply(My_Stack & _value){
    std::cout << _value.top_and_pop();
}

void Dup::apply(My_Stack & _value){
    _value.push(_value.top());
}

void Drop::apply(My_Stack & _value){
    _value.pop();
}

void Swap::apply(My_Stack & _value){
    int first = _value.top_and_pop();
    int second = _value.top_and_pop();
    _value.push(first);
    _value.push(second);
}

void Equal::apply(My_Stack & _value){
    int first = _value.top_and_pop();
    int second = _value.top_and_pop();
    _value.push(first == second);
}

void Rot::apply(My_Stack & _value){
    int first = _value.top_and_pop();
    int second = _value.top_and_pop();
    int third = _value.top_and_pop();
    _value.push(second);
    _value.push(first);
    _value.push(third);
}

void Over::apply(My_Stack & _value){
    int first = _value.top_and_pop();
    int second = _value.top();
    _value.push(first);
    _value.push(second);    
}

void Emit::apply(My_Stack & _value){
    std::cout << char(_value.top_and_pop()) << std::endl;
}

void Cr::apply(My_Stack & _value){
    std::cout << "\n";
}

