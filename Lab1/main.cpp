//#include <gtest/gtest.h>
#include "HashTable.hpp"

using namespace std;

int main() {
    //return RUN_ALL_TESTS();
    Value a1; a1.age = 10;
    Value a2; a2.age = 10;
    Value a3; a3.age = 123;
    Value a4; a4.age = 34;
    Value a5; a5.age = 56;
    HashList a;
    a.insert(a1); a.insert(a2); a.insert(a3); a.insert(a4); a.insert(a5);

    a.printList();

    HashList b(a);
    b.remove(a1);
    b.printList();

    return 0;
}