cmake_minimum_required(VERSION 3.21.2)
project(LAB1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(SRC main.cpp Header.hpp Value.hpp Value.cpp HashList.hpp HashList.cpp HashTable.hpp HashTable.cpp Entries.cpp Entries.hpp Test.cpp)

add_executable(LAB1 ${SRC})


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(
  HashTableTest
  Test.cpp
  HashTable.cpp
)
target_link_libraries(
  HashTableTest
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(HashTableTest)