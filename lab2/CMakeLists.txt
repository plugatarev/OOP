cmake_minimum_required(VERSION 3.21.2)
project(Interpreter VERSION 0.1)
 
set(SRC main.cpp Interpreter.cpp Commands.cpp Function_for_string.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Interpreter ${SRC})