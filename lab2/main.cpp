#include"Interpreter.hpp"
#include <iostream>
int main(){
    Interpreter interpreter = Interpreter::getInstance();
    std::string cmds;
    while (true){   
        std::cout << std::endl;
        std::cout << "Top -> ";
        interpreter.get_value().print();
        std::cout << std::endl;
        std::cout << "> ";
        std::getline(std::cin, cmds);
        interpreter.interpret(cmds);
        
        interpreter.ss.str("");
    }

    return 0;
}
