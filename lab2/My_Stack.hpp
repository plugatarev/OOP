#pragma once
#include <stack>
class My_Stack: public std::stack<int>{
public:
  //Returns top of the stack and remove from the stack
  int& top_and_pop();

  //Prints the stack 
  void print();

  //Returns number of elements on the stack
  int size();
};