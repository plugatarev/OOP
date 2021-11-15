#pragma once
#include "My_Stack.hpp"

class Command {
 public:
    virtual void apply(My_Stack & it) = 0;
};

class Add: public Command {
    void apply(My_Stack & _value) override;
};

class Sub: public Command {
    void apply(My_Stack & _value) override;
};

class Div: public Command {
    void apply(My_Stack & _value) override;
};

class Mod: public Command {
    void apply(My_Stack & _value) override;
};

class Mul: public Command {
    void apply(My_Stack & _value) override;
};

class More: public Command {
    void apply(My_Stack & _value) override;
};

class Less: public Command {
    void apply(My_Stack & _value) override;
};

class Equal: public Command {
public:
    void apply(My_Stack & _value) override;
};

class Write: public Command {
    void apply(My_Stack & _value) override;
};

class Dup: public Command {
    void apply(My_Stack & _value) override;
};

class Drop: public Command {
    void apply(My_Stack & _value) override;
};

class Swap: public Command {
    void apply(My_Stack & _value) override;
};

class Rot: public Command {
    void apply(My_Stack & _value) override;
};

class Over: public Command {
    void apply(My_Stack & _value) override;
};

class Emit: public Command {
    void apply(My_Stack & _value) override;
};

class Cr: public Command {
    void apply(My_Stack & _value) override;
};

class EmptyCommand: public Command {
    void apply(My_Stack & _value) override;
};
