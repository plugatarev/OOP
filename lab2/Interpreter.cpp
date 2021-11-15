#include "Interpreter.hpp"
#include <map>
#include <sstream>
#include "Exception.hpp"
#include "Function_for_string.hpp"

Command * Interpreter::get_cmd(std::string::iterator & it, std::string::iterator & end) {

    std::string cmd;
    while (it != end && (*it) != ' '){
        cmd += (*it);
        it++;
    }
    if (cmd[0] == '.' && is_write_str(cmd)){
        std::cout << cmd;
        return new EmptyCommand;
    }
    if (cmd.length() == 0) return new EmptyCommand;


    if (is_number(cmd)){
        value.push(atoi(cmd.c_str()));
        return new EmptyCommand;
    }

    std::map<std::string, creator_t>::iterator creator_it = _creators.find(cmd);
    if (creator_it == _creators.end()) {
        std::stringstream ss;
        ss << " no such command: '" << cmd << "'";

        throw interpreter_error(ss.str().c_str());
    }
    creator_t creator = (*creator_it).second;
    return creator();
}


// Command * Interpreter::get_cmd(std::string::iterator & it, std::string::iterator & end) {
//     std::string cmd;
//     while (it != end && (*it) != ' '){
//         cmd += (*it);
//         it++;
//     }
//     if (is_number(cmd)){
//         value.push(atoi(cmd.c_str()));
//         return new EmptyCommand;
// }
//     if (cmd == "+") return new Add();
//     if (cmd == "-") return new Sub();
//     if (cmd == "/") return new Div();
//     if (cmd == "*") return new Mul();
//     if (cmd == "mod") return new Mod();
//     if (cmd == "=") return new Equal();
//     if (cmd == ">") return new More();
//     if (cmd == "<") return new Less();
//     if (cmd == "dup") return new Dup();
//     if (cmd == "drop") return new Drop();
//     if (cmd == "swap") return new Swap();
//     if (cmd == "rot") return new Rot();
//     if (cmd == "over") return new Over();
//     if (cmd == "emit") return new Emit();
//     if (cmd == "cr") return new Cr();
//     if (cmd[0] == '.') {
//         if (cmd.length() == 1) std::cout << value.top_and_pop() << std::endl;
//         if (is_write_str(cmd)) std::cout << cmd << std::endl;
//     }

//     return new EmptyCommand;
// }

void Interpreter::interpret(std::string & cmds) {
    std::string::iterator it = cmds.begin();
    std::string::iterator end = cmds.end();
    while (it != end) {
        try {
            Command * command = get_cmd(it, end);
            command->apply(value);
            delete command;
        } catch (interpreter_error & e) {
            std::cout << e.what() << std::endl;
        }
        if (it == end) break;
        it++;
    }
}

My_Stack& Interpreter::get_value(){
    return value;
}