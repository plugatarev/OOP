#pragma once
#include "Commands.hpp"
#include "Interpreter.hpp"
#include<memory>
namespace {

    std::shared_ptr<Command> add_creator() {
        return std::shared_ptr<Command>(new Add());
    }
    bool add_cmd = Interpreter::getInstance().registerCreator("+", add_creator());

    std::shared_ptr<Command> sub_creator() {
        return std::shared_ptr<Command>(new Sub());
    }
    bool sub_cmd = Interpreter::getInstance().registerCreator("-", sub_creator());

    std::shared_ptr<Command> mod_creator() {
        return std::shared_ptr<Command>(new Mod());
    }
    bool mod_cmd = Interpreter::getInstance().registerCreator("mod", mod_creator());

    std::shared_ptr<Command> div_creator() {
        return std::shared_ptr<Command>(new Div());
    }
    bool div_cmd = Interpreter::getInstance().registerCreator("/", div_creator());

    std::shared_ptr<Command> equal_creator() {
        return std::shared_ptr<Command>(new Equal());
    }
    bool equal_cmd = Interpreter::getInstance().registerCreator("==", equal_creator());

    std::shared_ptr<Command> more_creator() {
        return std::shared_ptr<Command>(new More());
    }
    bool more_cmd = Interpreter::getInstance().registerCreator(">", more_creator());

    std::shared_ptr<Command> less_creator() {
        return std::shared_ptr<Command>(new Less());
    }
    bool less_cmd = Interpreter::getInstance().registerCreator("<", less_creator());

    std::shared_ptr<Command> write_creator() {
        return std::shared_ptr<Command>(new Write());
    }
    bool write_cmd = Interpreter::getInstance().registerCreator(".", write_creator());

    std::shared_ptr<Command> mul_creator() {
        return std::shared_ptr<Command>(new Mul());
    }
    bool mul_cmd = Interpreter::getInstance().registerCreator("*", mul_creator());

    std::shared_ptr<Command> dup_creator() {
        return std::shared_ptr<Command>(new Dup());
    }
    bool dup_cmd = Interpreter::getInstance().registerCreator("dup", dup_creator());

    std::shared_ptr<Command> drop_creator() {
        return std::shared_ptr<Command>(new Drop());
    }
    bool drop_cmd = Interpreter::getInstance().registerCreator("drop", drop_creator());

    std::shared_ptr<Command> swap_creator() {
        return std::shared_ptr<Command>(new Swap());
    }
    bool swap_cmd = Interpreter::getInstance().registerCreator("swap", swap_creator());

    std::shared_ptr<Command> rot_creator() {
        return std::shared_ptr<Command>(new Rot());
    }
    bool rot_cmd = Interpreter::getInstance().registerCreator("rot", rot_creator());

    std::shared_ptr<Command> over_creator() {
        return std::shared_ptr<Command>(new Over());
    }
    bool over_cmd = Interpreter::getInstance().registerCreator("over", over_creator());

    std::shared_ptr<Command> cr_creator() {
        return std::shared_ptr<Command>(new Cr());
    }
    bool cr_cmd = Interpreter::getInstance().registerCreator("cr", cr_creator());

    std::shared_ptr<Command> emit_creator() {
        return std::shared_ptr<Command>(new Emit());
    }
    bool emit_cmd = Interpreter::getInstance().registerCreator("emit", emit_creator());
}