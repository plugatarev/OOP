#include <gtest/gtest.h>
#include "HashTable.hpp"
TEST(HashTableTest,DefaultConstructor){
    HashTable a;
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(a.capacity(), _DEFAULT_HASHTABLE_SIZE);
}

// TEST(HashTableTest,SizeConstructor){
//     HashTable a(12);
//     ASSERT_EQ(0, a.size());
// }

// TEST(Test_HashTable, OriginalHashTableIsNotChangedOnCopyChange){
//     HashTable a(12);
//     Key k = "1234";
//     Key name = "abrac";

//     Value v(name,22);
//     a.insert(k,v);
//     ASSERT_EQ(1, a.size());
//     ASSERT_EQ(&v, a.at(k));
//     HashTable b;
//     b = a;
//     ASSERT_EQ(1, b.size());
//     ASSERT_EQ(&v, b.at(k));
//     Key name2 = "hey";

//     Value v2(name2,34);
//     b.insert(name2, v2);
//     ASSERT_EQ(1, a.size());
//     ASSERT_EQ(&v, a.at(k));
//     ASSERT_EQ(2, b.size());
//     ASSERT_EQ(&v2, b.at(k));
// }
