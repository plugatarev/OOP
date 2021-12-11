#include "Interpreter.hpp"
#include <map>
#include<algorithm>
#include "Interpreter_error.hpp"
namespace{
    bool is_number(const std::string& s){
        std::string::const_iterator it = s.begin();
        std::string::const_iterator end = s.end();
        return std::all_of(it, end, ::isdigit);
    }
}

Interpreter::Interpreter(Interpreter& other):_creators(std::move(other._creators)),value(other.value){}

std::unique_ptr<Command>* Interpreter::get_cmd(std::string::iterator & it, std::string::iterator & end, std::stringstream& s) {
    std::string cmd;
    std::string::iterator tmp = it;
    char balance = 0;
    while (it != end && (*it != ' ' || (cmd[0] == '.' && cmd[1] == '\"'))){
        if (*it == '"'){
            if (++balance == 2){
                cmd += (*it);
                break;
            } 
        }
        cmd += (*it);
        it++;
    }

    if (cmd.length() == 0) return nullptr;

    if (cmd.size() >= 3 && cmd[0] == '.' && cmd[1] == '\"' && cmd[cmd.size() - 1] == '\"') {
        s << cmd.substr(2, cmd.size() - 3) << "\n";
        return nullptr;
    }


    if (cmd[0] == '-' && cmd.size() > 1){
        cmd = cmd.substr(1,cmd.size());
        if (is_number(cmd)){
            value.push(std::stoi(cmd) * -1);
            return nullptr;
        }
    }
    else if (is_number(cmd)){
        value.push(std::stoi(cmd));
        return nullptr;
    }

    auto creator_it = _creators.find(cmd);
    if (creator_it == _creators.end()) {
        std::stringstream s;
        s << "no such command: '" << cmd << "'";
        throw interpreter_error(s.str());
    }
    return &(creator_it->second);
}

std::stringstream Interpreter::interpret(std::string & cmds) {
    std::stringstream s;
    std::string::iterator it = cmds.begin();
    std::string::iterator end = cmds.end();
    std::unique_ptr<Command>* command;
    while (it != end) {
        try {
            command = get_cmd(it, end,s);
            if (command != nullptr){
                (*command)->apply(value, s);
                s << "\n";
            }
        }
        catch (interpreter_error & e){
            s << e.what() << "\n";
        }
        if (it == end) break;
        it++;
    }
    return s;
}

My_Stack& Interpreter::get_value(){
    return value;
}