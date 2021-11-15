#include <gtest/gtest.h>
#include "Interpreter.hpp"

Interpreter interpreter = Interpreter::getInstance();

TEST(InterpreterTest, AddingAnValueToTheStack){
    std::string cmds = "134";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().top(),134);

}

TEST(InterpreterTest, AddingSomeValuesToTheStack){
    std::string cmds = "134 12 21 43";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().top_and_pop(),134);
    ASSERT_EQ(interpreter.get_value().top_and_pop(),12);
    ASSERT_EQ(interpreter.get_value().top_and_pop(),21);
    ASSERT_EQ(interpreter.get_value().top_and_pop(),43);
}


