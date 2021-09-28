//#include <gtest/gtest.h>
#include "HashTable.hpp"

using namespace std;

int main() {
    //return RUN_ALL_TESTS();
    std::string s = "espetr";
    std::string str1 = "hello"; std::string str2 = "gggv"; std::string str3 = "Yoap"; std::string str4 = "Abracadabra";
    Value v(s,12);
    HashMap a1(str1,v);
    HashMap a2(str2,v);
    HashMap a3(str3,v);
    HashMap a4(str4,v);
    HashList a;
    a.insert(str1,v); a.insert(str2,v); a.insert(str3,v); a.insert(str4,v);

    a.printList();

    HashList b(a);
    //b.remove(a1);
    b.printList();

    return 0;
}