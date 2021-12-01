#pragma once
#include <iostream>
#include "Commands.hpp"
#include <map>
#include "My_Stack.hpp"
#include<memory>
class Interpreter {
public:
   //Creates Interpreter
   static Interpreter & getInstance() {
      static Interpreter i;
      return i;
   }
   //Runs Interpreter
   void interpret(std::string & cmds);
   typedef Command * (*creator_t)();

   //Adds new command
   bool registerCreator(std::string c, std::unique_ptr<Command> command) {
      _creators.insert(std::make_pair(c,std::move(command)));
      return true;
   }

   //Gets value of stack
   My_Stack& get_value();
private:
   Interpreter() = default;
   std::map<std::string, std::unique_ptr<Command>> _creators;
   std::unique_ptr<Command> get_cmd(std::string::iterator & it, std::string::iterator & end);
   My_Stack value;
};
