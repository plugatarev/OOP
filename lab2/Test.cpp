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

TEST(InterpreterTest, CheckingPutNegativValueToTheStack){
    std::string cmds = "-134";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().pop(),-134);
}

TEST(InterpreterTest, OperationWithNegativValues){
    std::string cmds = "-134 -2 -";
    interpreter.interpret(cmds);
    ASSERT_EQ(interpreter.get_value().pop(),-132);
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
    std::string out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out, "Error: division by zero\n");  
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
    std::string out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out, "1214\n"); 
}

TEST(InterpreterTest, CheckingWorkOfMethodEmit){
    std::string cmds = "43 emit";
    std::string out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out, "+\n"); 
}

TEST(InterpreterTest, CheckingWorkOfMethodCr){
    std::string cmds = "1 cr";
    std::string out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out, "\n\n"); 
}

TEST(InterpreterTest, TestNoSuchCommand){
    std::string cmds = "GHrot";
    std::string out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"no such command: 'GHrot'\n");  
}

TEST(InterpreterTest, TestNoSuchCommandWithDot){
    std::string cmds = ".\"";
    std::string out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out, "no such command: '.\"'\n");  
}

TEST(InterpreterTest, TestPrintingStringWithSpace){
    std::string cmds = ".\"  sdf  *\"";
    std::string out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out ,"  sdf  *\n");  
}

TEST(InterpreterTest, TestWithPrintingEmptyString){
    std::string cmds = ".\"\"";
    std::string out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"\n");  
}

TEST(InterpreterTest, TestWithThreeQuotesInARow){
    std::string cmds = ".\"\"\"";
    std::string out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"\nno such command: '\"'\n");  
}

TEST(InterpreterTest, TestWithStringAndTwoQuotesInTheEnd){
    std::string cmds = ".\"wer\"\"";
    std::string out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"wer\nno such command: '\"'\n");  
}

TEST(InterpreterTest, TestWithTwoQuotesInTheBeginning){
    std::string cmds = ".\"\"werew\"";
    std::string out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"\nno such command: 'werew\"'\n");  
}

TEST(InterpreterTest, TestWithOnlySpaceInString){
    std::string cmds = ".\"   \"";
    std::string out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"   \n");  
}

TEST(InterpreterTest, TestWithPrintingStringAndIncorrectString){
    std::string cmds = ".\"ds\"f\"";
    std::string out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"ds\nno such command: 'f\"'\n");  
}

TEST(InterpreterTest, TestWithSomeStrings){
    std::string cmds = ".\"dfdfd\" \"dsfsd\" sdwe";
    std::string out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"dfdfd\nno such command: '\"dsfsd\"'\nno such command: 'sdwe'\n");  
}

TEST(InterpreterTest, TestWithArithmeticOperationWhenTHereIsNotEnoughtOnElementTheStack){
    std::string cmds = "1 +";
    std::string out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n");

    cmds = "+";
    out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n"); 

    cmds = "1 -";
    out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n"); 

    cmds = "-";
    out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n"); 

    cmds = "1 /";
    out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n"); 

    cmds = "/";
    out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n"); 

    cmds = "1 mod";
    out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n"); 

    cmds = "mod";
    out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n"); 

    cmds = "1 *";
    out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n"); 

    cmds = "*";
    out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n"); 

    cmds = "1 ==";
    out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n"); 

    cmds = "==";
    out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n"); 

    cmds = "1 <";
    out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n"); 

    cmds = "<";
    out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n"); 

    cmds = "1 >";
    out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n"); 

    cmds = ">";
    out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n"); 

    cmds = ".";
    out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n"); 

    cmds = "-";
    out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n"); 

    cmds = "emit";
    out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n"); 

    cmds = "1 2 rot";
    out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n"); 

    cmds = "swap";
    out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n"); 

    cmds = "over";
    out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n"); 

    cmds = "dup";
    out = interpreter.interpret(cmds).str();
    ASSERT_EQ(out,"extracting from an empty stack\n"); 
}
