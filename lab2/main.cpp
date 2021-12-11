#include"Interpreter.hpp"
#include <iostream>
int main(){
    Interpreter interpreter = Interpreter::getInstance();
    std::string cmds;
    
    while (true){   
        std::cout << "Top -> ";
        interpreter.get_value().print();
        std::cout << std::endl;
        std::cout << "> ";
        std::getline(std::cin, cmds);
        std::cout << interpreter.interpret(cmds).str();;
        interpreter.ss.str("");
    }
    return 0;
}
