#pragma once
#include "My_Stack.hpp"

//Base class of command
class Command {
 public:
    virtual void apply(My_Stack & it) = 0;
};


class Add: public Command {
    //Adding two values from the stack. 
    //The top of the stack is used as the right operand, and the second number on the stack is used as the left operand.
    //The result of the operation is put on the stack.
    //Exception of interpreter_error if there are not enough elements on the stack
    void apply(My_Stack & _value) override;
};

class Sub: public Command {
    //Subtraction two values from the stack. 
    //The top of the stack is used as the right operand, and the second number on the stack is used as the left operand.
    //The result of the operation is put on the stack.
    //Exception of interpreter_error if there are not enough elements on the stack
    void apply(My_Stack & _value) override;
};

class Div: public Command {
    //Division two values from the stack. 
    //The top of the stack is used as the right operand, and the second number on the stack is used as the left operand.
    //The result of the operation is put on the stack.
    //Exception of interpreter_error if there are not enough elements on the stack. Exception when dividing by zero
    void apply(My_Stack & _value) override;
};

class Mod: public Command {
    //Taking the remainder of the division.
    //The top of the stack is used as the right operand, and the second number on the stack is used as the left operand.
    //The result of the operation is put on the stack.
    //Exception of interpreter_error if there are not enough elements on the stack. Exception when dividing by zero
    void apply(My_Stack & _value) override;
};

class Mul: public Command {
    //Multiplication two values from the stack. 
    //The top of the stack is used as the right operand, and the second number on the stack is used as the left operand.
    //The result of the operation is put on the stack.
    //Exception of interpreter_error if there are not enough elements on the stack
    void apply(My_Stack & _value) override;
};

class More: public Command {
    //Compares two values from the stack(>).
    //The top of the stack is used as the right operand, and the second number on the stack is used as the left operand.
    //The result of the operation is put on the stack.
    //Exception of interpreter_error if there are not enough elements on the stack
    void apply(My_Stack & _value) override;
};

class Less: public Command {
    //Compares two values from the stack(<).
    //The top of the stack is used as the right operand, and the second number on the stack is used as the left operand.
    //The result of the operation is put on the stack.
    //Exception of interpreter_error if there are not enough elements on the stack
    void apply(My_Stack & _value) override;
};

class Equal: public Command {
    //Compares two values from the stack(==).
    //The top of the stack is used as the right operand, and the second number on the stack is used as the left operand.
    //The result of the operation is put on the stack.
    //Exception of interpreter_error if there are not enough elements on the stack
    void apply(My_Stack & _value) override;
};

class Write: public Command {
    //Printing the top of the stack
    //Exception of interpreter_error if there are not enough elements on the stack
    void apply(My_Stack & _value) override;
};

class Dup: public Command {
    //Copy the top of the stack and put it on the stack
    void apply(My_Stack & _value) override;
};

class Drop: public Command {
    //Remove the top number from the stack
    void apply(My_Stack & _value) override;
};

class Swap: public Command {
    //Swap the top and second numbers on the stack
    void apply(My_Stack & _value) override;
};

class Rot: public Command {
    //Cyclically shift the top three numbers on the stack
    void apply(My_Stack & _value) override;
};

class Over: public Command {
    //Copy the second number and put a copy over the top one
    void apply(My_Stack & _value) override;
};

class Emit: public Command {
    //Print the top number on the stack as an ascii code and remove it from the stack
    void apply(My_Stack & _value) override;
};

class Cr: public Command {
    //Print a line break
    void apply(My_Stack & _value) override;
};
