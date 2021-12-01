#pragma once
#include <stack>
class My_Stack{
public:
  //Returns top of the stack and remove from the stack
  int& pop();

  //Prints the stack 
  void print();

  //Returns number of elements on the stack
  int size();

  int peek();

  void push(int value);
private:
  std::stack<int> stack;
};