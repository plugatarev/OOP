#pragma once
#include "Commands.hpp"
#include "Interpreter.hpp"

namespace {

    Command * add_creator() {
        return new Add();
    }
    bool add_cmd = Interpreter::getInstance().registerCreator("+", add_creator);

    Command * sub_creator() {
        return new Sub();
    }
    bool sub_cmd = Interpreter::getInstance().registerCreator("-", sub_creator);

    Command * mod_creator() {
        return new Mod();
    }
    bool mod_cmd = Interpreter::getInstance().registerCreator("mod", mod_creator);

    Command * div_creator() {
        return new Div();
    }
    bool div_cmd = Interpreter::getInstance().registerCreator("/", div_creator);

    Command * equal_creator() {
        return new Equal();
    }
    bool aequal_cmd = Interpreter::getInstance().registerCreator("==", equal_creator);

    Command * more_creator() {
        return new More();
    }
    bool more_cmd = Interpreter::getInstance().registerCreator(">", more_creator);

    Command * less_creator() {
        return new Less();
    }
    bool less_cmd = Interpreter::getInstance().registerCreator("<", less_creator);

    Command * write_creator() {
        return new Write();
    }
    bool write_cmd = Interpreter::getInstance().registerCreator(".", write_creator);

    Command * mul_creator() {
        return new Mul();
    }
    bool mul_cmd = Interpreter::getInstance().registerCreator("*", mul_creator);

    Command * dup_creator() {
        return new Dup();
    }
    bool dup_cmd = Interpreter::getInstance().registerCreator("dup", dup_creator);

    Command * drop_creator() {
        return new Drop();
    }
    bool drop_cmd = Interpreter::getInstance().registerCreator("drop", drop_creator);

    Command * swap_creator() {
        return new Swap();
    }
    bool swap_cmd = Interpreter::getInstance().registerCreator("swap", swap_creator);

    Command * rot_creator() {
        return new Rot();
    }
    bool rot_cmd = Interpreter::getInstance().registerCreator("rot", rot_creator);

    Command * over_creator() {
        return new Over();
    }
    bool over_cmd = Interpreter::getInstance().registerCreator("over", over_creator);

    Command * cr_creator() {
        return new Cr();
    }
    bool cr_cmd = Interpreter::getInstance().registerCreator("cr", cr_creator);

    Command * emit_creator() {
        return new Emit();
    }
    bool emit_cmd = Interpreter::getInstance().registerCreator("Emit", emit_creator);
}