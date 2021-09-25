cmake_minimum_required(VERSION 3.21.2)
project(LAB1)

set(CMAKE_CXX_STANDARD 17)
include_directories(.)
set(SRC main.cpp Header.hpp Value.hpp Value.cpp HashList.hpp HashList.cpp HashTable.hpp HashTable.cpp)
add_executable(LAB1 ${SRC})
