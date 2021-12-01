#pragma once
#include "Commands.hpp"
#include "Interpreter.hpp"
#include<memory>
namespace {

    std::unique_ptr<Command> add_creator() {
        return std::make_unique<Command>(new Add());
    }
    bool add_cmd = Interpreter::getInstance().registerCreator("+", std::move(add_creator()));

    std::unique_ptr<Command> sub_creator() {
        return std::make_unique<Command>(new Sub());
    }
    bool sub_cmd = Interpreter::getInstance().registerCreator("-", std::move(sub_creator()));

    std::unique_ptr<Command> mod_creator() {
        return std::make_unique<Command>(new Mod());
    }
    bool mod_cmd = Interpreter::getInstance().registerCreator("mod", std::move(mod_creator()));

    std::unique_ptr<Command> div_creator() {
        return std::make_unique<Command>(new Div());
    }
    bool div_cmd = Interpreter::getInstance().registerCreator("/", std::move(div_creator()));

    std::unique_ptr<Command> equal_creator() {
        return std::make_unique<Command>(new Equal());
    }
     /*bool equal_cmd = Interpreter::getInstance().registerCreator("==", std::move(equal_creator()));

Command * more_creator() {
        return std::make_unique<Command>(new More());
    }
    bool more_cmd = Interpreter::getInstance().registerCreator(">", std::move(more_creator()));
*/
    std::unique_ptr<Command> less_creator() {
        return std::make_unique<Command>(new Less());
    }
    bool less_cmd = Interpreter::getInstance().registerCreator("<", std::move(less_creator()));

    std::unique_ptr<Command> write_creator() {
        return std::make_unique<Command>(new Write());
    }
    bool write_cmd = Interpreter::getInstance().registerCreator(".", std::move(write_creator()));

    std::unique_ptr<Command> mul_creator() {
        return std::make_unique<Command>(new Mul());
    }
    bool mul_cmd = Interpreter::getInstance().registerCreator("*", std::move(mul_creator()));

    std::unique_ptr<Command> dup_creator() {
        return std::make_unique<Command>(new Dup());
    }
    bool dup_cmd = Interpreter::getInstance().registerCreator("dup", std::move(dup_creator()));

    std::unique_ptr<Command> drop_creator() {
        return std::make_unique<Command>(new Drop());
    }
    bool drop_cmd = Interpreter::getInstance().registerCreator("drop", std::move(drop_creator()));

    std::unique_ptr<Command> swap_creator() {
        return std::make_unique<Command>(new Swap());
    }
    bool swap_cmd = Interpreter::getInstance().registerCreator("swap", std::move(swap_creator()));

    std::unique_ptr<Command> rot_creator() {
        return std::make_unique<Command>(new Rot());
    }
    bool rot_cmd = Interpreter::getInstance().registerCreator("rot", std::move(rot_creator()));

    std::unique_ptr<Command> over_creator() {
        return std::make_unique<Command>(new Over());
    }
    bool over_cmd = Interpreter::getInstance().registerCreator("over", std::move(over_creator()));

    std::unique_ptr<Command> cr_creator() {
        return std::make_unique<Command>(new Cr());
    }
    bool cr_cmd = Interpreter::getInstance().registerCreator("cr", std::move(cr_creator()));

    std::unique_ptr<Command> emit_creator() {
        return std::make_unique<Command>(new Emit());
    }
    bool emit_cmd = Interpreter::getInstance().registerCreator("Emit", std::move(emit_creator()));
}