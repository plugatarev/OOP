#include"Interpreter.hpp"
#include <iostream>
int main(){
    Interpreter interpreter = Interpreter::getInstance();
    std::string cmds;

    while (true){   
        // CR: my stack shouldn't be accessed from anywhere except interpreter -ok
        // CR: also it's better to return top value instead of printing inside of print() - ok
        // CR: (it might be helpful if we'll start to print to some other stream, e.g. file)
        std::cout << std::endl;
        std::cout << "> ";
        std::getline(std::cin, cmds);
        std::cout << interpreter.interpret(cmds).str();
    }
    return 0;
}
