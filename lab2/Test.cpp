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

TEST(InterpreterTest, CheckingDivisionElements){
    std::string cmds = "24 8 /";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().pop(),3);
}

TEST(InterpreterTest, CheckingDivisionByZero){
    std::string cmds = "24 0 /";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.ss.str(),"Error: division by zero");  
    interpreter.ss.str("");
}

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

TEST(InterpreterTest, WritingToTheConsoleTopTheStack){
    std::string cmds = "12 1214 .";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.ss.str(), "1214"); 
    interpreter.ss.str("");
}

TEST(InterpreterTest, CheckingWorkOfMethodEmit){
    std::string cmds = "43 emit";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.ss.str(), "+"); 
    interpreter.ss.str("");
}

TEST(InterpreterTest, CheckingWorkOfMethodCr){
    std::string cmds = "1 cr";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.ss.str(), "\n"); 
    interpreter.ss.str("");
}

TEST(InterpreterTest, TestNoSuchCommand){
    std::string cmds = "GHrot";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.ss.str(),"no such command: 'GHrot'");  
    interpreter.ss.str("");
}

TEST(InterpreterTest, TestNoSuchCommandWithDot){
    std::string cmds = ".\"";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.ss.str(),"no such command: '.\"'");  
    interpreter.ss.str("");
}

TEST(InterpreterTest, TestPrintingStringWithSpace){
    std::string cmds = ".\"  sdf  *\"";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.ss.str(),"  sdf  *");  
    interpreter.ss.str("");
}

TEST(InterpreterTest, TestWithPrintingEmptyString){
    std::string cmds = ".\"\"";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.ss.str(),"");  
    interpreter.ss.str("");
}

TEST(InterpreterTest, TestWithThreeQuotesInARow){
    std::string cmds = ".\"\"\"";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.ss.str(),"no such command: '\"'");  
    interpreter.ss.str("");
}