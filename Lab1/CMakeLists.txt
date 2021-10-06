cmake_minimum_required(VERSION 3.20.5)
project(LAB1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(SRC main.cpp Value.cpp HashList.cpp HashTable.cpp Entries.cpp)

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
  Value.cpp
  HashList.cpp
  HashTable.cpp
  Entries.cpp
)
target_link_libraries(
  HashTableTest
  gtest_main
)
include(GoogleTest)
gtest_discover_tests(HashTableTest)