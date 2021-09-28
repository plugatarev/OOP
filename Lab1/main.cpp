//#include <gtest/gtest.h>
#include "HashTable.hpp"

using namespace std;

int main() {
    //return RUN_ALL_TESTS();
    std::string s = "espetr";
    Value v(s,12);
    HashMap a1("123",v);
    HashMap a2("Hello",v);
    HashMap a3("Yoap",v);
    HashMap a4("Abracadabra",v);
    HashList a;
    a.insert(a1); a.insert(a2); a.insert(a3); a.insert(a4);

    a.printList();

    HashList b(a);
    b.remove(a1);
    b.printList();

    return 0;
}