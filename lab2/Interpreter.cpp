#include "Interpreter.hpp"
#include <map>
#include<algorithm>
#include "Exception.hpp"
namespace{
    bool is_write_str(std::string& s, std::string::iterator it, std::string::iterator & end){
        std::string k;
        if ((*it) != '.' || it == end) return false;
        it++;
        if ((*it) != '"' || it == end) return false;   
        it++; 
        int count = 0;
        while (it != end && (*it) != '"' && (count++) < 10){
            k+=(*it);
            it++;
        }
        if ((*it) == '"'){
            s = k;
            return true;
        }
        return false;
    }

    bool is_number(const std::string& s){
        // -344
        std::string::const_iterator it = s.begin();
        std::string::const_iterator end = s.end();
        return std::all_of(it, end, ::isdigit);
    }
}

Interpreter::Interpreter(Interpreter& other):_creators(other._creators),value(other.value){}

std::shared_ptr<Command> Interpreter::get_cmd(std::string::iterator & it, std::string::iterator & end) {
    std::string cmd;
    std::string::iterator tmp = it;
    char balance = 0;
    while (it != end && (*it != ' ' || (cmd[0] == '.' && cmd[1] == '\"'))){
        // ." fff"    " bar
        if (*it == '"'){
            if (++balance == 2) break;
        }
        cmd += (*it);
        it++;
    }

    if (cmd.length() == 0) return nullptr;

    if (cmd.size() > 3 && cmd[0] == '.' && cmd[1] == '\"' && cmd[cmd.size() - 1]) {
        std::cout << cmd.substr(2, cmd.size() - 1) << std::endl;
        return nullptr;
    }


    if (is_number(cmd)){
        value.push(std::stoi(cmd));
        return nullptr;
    }

    auto creator_it = _creators.find(cmd);
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

std::string interpret(std::string & cmds) {
    ss;
    return ss.str();
}

My_Stack& Interpreter::get_value(){
    return value;
}