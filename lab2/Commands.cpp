#include<iostream>
#include <functional>
#include "Interpreter.hpp"
#include "Exception.hpp"
#include "Command_Set.hpp"
void Add::apply(My_Stack & _value){
    int right = _value.pop();
    int left = _value.pop();
    int res = left + right;
    _value.push(res);
}   

void Sub::apply(My_Stack & _value){
    int right = _value.pop();
    int left = _value.pop();
    int res = left - right;
    _value.push(res);
}

std::function<int, int> Div::op() {
    return std::divides<int, int>();
}

void Div::apply(My_Stack & _value){
    if (_value.peek() == 0) throw interpreter_error("Error: division by zero");
    int right = _value.pop();
    int left = _value.pop();
    int res = left / right;
    _value.push(res);
}

void Mod::apply(My_Stack & _value){
    if (_value.peek() == 0) throw interpreter_error("Error: division by zero");
    int right = _value.pop();
    int left = _value.pop();
    int res = left % right;
    _value.push(res);
}

void Mul::apply(My_Stack & _value){
    int right = _value.pop();
    int left = _value.pop();
    int res = left * right;
    _value.push(res);
}

void More::apply(My_Stack & _value){
    int right = _value.pop();
    int left = _value.pop();
    _value.push(left > right);
}

void Less::apply(My_Stack & _value){
    int right = _value.pop();
    int left = _value.pop();
    _value.push(left < right);
}

void Write::apply(My_Stack & _value){
    std::cout << _value.pop();
}

void Dup::apply(My_Stack & _value){
    _value.push(_value.peek());
}

void Drop::apply(My_Stack & _value){
    _value.pop();
}

void Swap::apply(My_Stack & _value){
    int first = _value.pop();
    int second = _value.pop();
    _value.push(first);
    _value.push(second);
}

void Equal::apply(My_Stack & _value){
    int first = _value.pop();
    int second = _value.pop();
    _value.push(first == second);
}

void Rot::apply(My_Stack & _value){
    int first = _value.pop();
    int second = _value.pop();
    int third = _value.pop();
    _value.push(second);
    _value.push(first);
    _value.push(third);
}

void Over::apply(My_Stack & _value){
    int first = _value.pop();
    int second = _value.peek();
    _value.push(first);
    _value.push(second);    
}

void Emit::apply(My_Stack & _value){
    std::cout << char(_value.pop()) << std::endl;
}

void Cr::apply(My_Stack & _value){
    std::cout << "\n";
}

