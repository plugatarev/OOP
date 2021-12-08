#pragma once
#include <sstream>
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
   bool registerCreator(const std::string& c, std::unique_ptr<Command> && command) {
       _creators[c] = std::move(command);
//      _creators.insert(std::make_pair(c,std::move(command)));
      return true;
   }

   //Gets value of stack
   My_Stack& get_value();
   Interpreter(Interpreter& other);
   std::stringstream ss;
private:
   Interpreter() = default;
   std::map<std::string, std::unique_ptr<Command>> _creators;
   std::shared_ptr<Command> get_cmd(std::string::iterator & it, std::string::iterator & end);
   My_Stack value;
};
