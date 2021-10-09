//#include <gtest/gtest.h>
#include "HashTable.hpp"

using namespace std;

int main(int argc, char ** argv) {
    // testing::InitGoogleTest(&argc, argv);
    // return RUN_ALL_TESTS();
    std::string s = "espetr";
    std::string str1 = "hello"; std::string str2 = "gggv"; std::string str3 = "Yoap"; std::string str4 = "Abracadabra";
    Value v(s,12);
    //if (v == v) std::cout << "sdf";
    Entry a1(str1,v);
    Entry a2(str2,v);
    Entry a3(str3,v);
    Entry a4(str4,v);
    HashTable a;
    a.insert(str1,v); a.insert(str2,v); a.insert(str3,v); a.insert(str4,v);
    HashTable b(a);
    b.insert(str1,v);
    cout << "A: ";
    a.print_HashTable();
    cout << "B: ";
    b.print_HashTable();
    cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\a" << endl;
    a.swap(b);
    cout << "A: ";
    a.print_HashTable();
    cout << "B: ";
    b.print_HashTable();

   // cout << (a == b) << endl;

}