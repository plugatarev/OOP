cmake_minimum_required(VERSION 3.21.2)
project(lab1)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest)
set(SRC)
include_directories(googletest/googletest/include)
add_executable(lab1 ${SRC})
target_link_libraries(lab1 gtest)