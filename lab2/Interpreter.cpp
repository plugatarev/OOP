#include "Interpreter.hpp"
#include <map>
#include<algorithm>
#include "Exception.hpp"
namespace{
    bool is_write_str(std::string& s, std::string::iterator & it, std::string::iterator & end){
        std::string k;
        bool flag = 0;
        it++;
        int count = 0;
        while (it != end && (*it) != '"' && (count++) < 10){
            k+=(*it);
            it++;
        }
        if ((*it) == '"') flag = 1;
        if (flag == 0){
            s = s + "\"" + k;
            return false;
        }
        s = k;
        return true;
    }

    bool is_number(const std::string& s){
        std::string::const_iterator it = s.begin();
        std::string::const_iterator end = s.end();
        return std::all_of(it, end, ::isdigit);
    }
}

Interpreter::Interpreter(Interpreter& other):_creators(other._creators),value(other.value){}

std::shared_ptr<Command> Interpreter::get_cmd(std::string::iterator & it, std::string::iterator & end) {

    std::string cmd;
    while (it != end && (*it) != ' ' && (*it) != '.'){
        cmd += (*it);
        it++;
    }
    if ((*it) == '.'){
        cmd+=(*it);
        it++;
    }
    if ((*it) == '"' && is_write_str(cmd,it,end)){
        ss << cmd;
        return nullptr;
    }
    if (cmd.length() == 0) return nullptr;


    if (is_number(cmd)){
        value.push(std::stoi(cmd.c_str()));
        return nullptr;
    }

    std::map<std::string, std::shared_ptr<Command>>::iterator creator_it = _creators.find(cmd);
    if (creator_it == _creators.end()) {
        ss << "no such command: '" << cmd << "'";
        throw interpreter_error(ss.str());
    }
    return creator_it->second;
}

void Interpreter::interpret(std::string & cmds) {
    std::string::iterator it = cmds.begin();
    std::string::iterator end = cmds.end();
    std::shared_ptr<Command> command;
    while (it != end) {
        try {
            command = get_cmd(it, end);
            if (command != nullptr){
                command->apply(value, ss);
                std::cout << ss.str() << " ";
            }
        }
        catch (interpreter_error & e) {
            std::cout << e.what() << std::endl;
        }
        if (it == end) break;
        ss.str("");
        it++;
    }
}

My_Stack& Interpreter::get_value(){
    return value;
}