#include <gtest/gtest.h>
#include "Interpreter.hpp"
#include "Command_Set.hpp"
Interpreter interpreter = Interpreter::getInstance();

TEST(InterpreterTest, CheckingPutAnValueToTheStack){
    std::string cmds = "134";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().peek(),134);

}

TEST(InterpreterTest, CheckingPutSomeValuesToTheStack){
    std::string cmds = "134 12 21 43";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().pop(),43);
    ASSERT_EQ(interpreter.get_value().pop(),21);
    ASSERT_EQ(interpreter.get_value().pop(),12);
    ASSERT_EQ(interpreter.get_value().pop(),134);
}

TEST(InterpreterTest, CheckingAddingElements){
    std::string cmds = "21 43 +";
    interpreter.interpret(cmds);

    ASSERT_EQ(interpreter.get_value().pop(),64);
}

TEST(InterpreterTest, CheckingSubtractionElements){
    std::string cmds = "134 12 -";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().pop(),122);
}

TEST(InterpreterTest, CheckingMultiplicationElements){
    std::string cmds = "2 35 *";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().pop(),70);
}

//Tests with overflow int work of arithmetic

TEST(InterpreterTest, CheckingDivisionElements){
    std::string cmds = "24 8 /";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().pop(),3);
}

//Test for division on 0

TEST(InterpreterTest, CheckingModElements){
    std::string cmds = "24 8 mod";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().pop(),0);
}

TEST(InterpreterTest, CheckingOperatorMoreForElements){
    std::string cmds = "24 8 >";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().pop(),1);
    cmds = "5 8 >";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().pop(),0);
}

TEST(InterpreterTest, CheckingOperatorLessForElements){
    std::string cmds = "24 8 <";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().pop(),0);
    cmds = "5 8 <";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().pop(),1);
}

TEST(InterpreterTest, CheckingOperatorEqualForElements){
    std::string cmds = "24 8 ==";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().pop(),0);
    cmds = "5 5 ==";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().pop(),1);
}

TEST(InterpreterTest, CheckingWritingElementOfConsole){
    std::string cmds = "12321";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().pop(),12321);
    
}

TEST(InterpreterTest, CheckingDupMethod){
    std::string cmds = "11 dup";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().pop(),11);
    ASSERT_EQ(interpreter.get_value().pop(),11);    
}

TEST(InterpreterTest, CheckingDropMethod){
    std::string cmds = "11 123 drop";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().pop(),11);    
}

TEST(InterpreterTest, CheckingSwapMethod){
    std::string cmds = "11 4 swap";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().pop(),11);
    ASSERT_EQ(interpreter.get_value().pop(),4);    
}

TEST(InterpreterTest, CheckingRotMethod){
    std::string cmds = "1 2 3 rot";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().pop(),1);
    ASSERT_EQ(interpreter.get_value().pop(),3);
    ASSERT_EQ(interpreter.get_value().pop(),2);    
}
/*
TEST(InterpreterTest, CheckingOverMethod){
    std::string cmds = "1 2 3 rot";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().pop(),1);
    ASSERT_EQ(interpreter.get_value().pop(),2);
    ASSERT_EQ(interpreter.get_value().pop(),3);    
}*/
