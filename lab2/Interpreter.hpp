#pragma once
#include <sstream>
#include "Commands.hpp"
#include <map>
#include "My_Stack.hpp"
#include<memory>
#include<iostream> //delete

class Interpreter {
public:
   //Creates Interpreter
   static Interpreter & getInstance() {
      static Interpreter i;
      return i;
   }
   //Runs Interpreter
   std::stringstream interpret(std::string & cmds);

   //Adds new command
   bool registerCreator(const std::string& c, std::unique_ptr<Command> && command) {
      _creators[c] = std::move(command);
      return true;
   }

   //Gets value of stack
   My_Stack& get_value();
   Interpreter(Interpreter& other);
   std::stringstream ss;
private:
   Interpreter() = default;
   std::map<std::string, std::unique_ptr<Command>> _creators;
   std::unique_ptr<Command>* get_cmd(std::string::iterator & it, std::string::iterator & end);
   My_Stack value;
};
