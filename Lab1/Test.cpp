#include <gtest/gtest.h>
#include "HashTable.hpp"
#include <ctime> 
#include "Header.hpp"

Key gen_random(int len) {
    Key s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return s;
}
TEST(HashTableTest,DefaultConstructor){
    HashTable a;
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(a.capacity(), _DEFAULT_HASHTABLE_SIZE);
}

TEST(HashTableTest,SizeConstructor){
    HashTable a(12);
    ASSERT_EQ(a.capacity(), 12);
    ASSERT_EQ(a.size(), 0);
}

TEST(HashTableTest, InsertInHashtable){
    HashTable a(100);
    Key k = "1234";
    Key name = "abrac";

    Value v(name,22);
    a.insert(k,v);
    ASSERT_EQ(a.size(),1);
    ASSERT_EQ(a.at(k),&v);
    for (int i = 0 ; i < 10; i++){
        k = gen_random(3);
        v.name = gen_random(4);
        v.age = i;
        a.insert(k,v);
    }
    ASSERT_EQ(a.size(),10);
}

TEST(HashTableTest, InsertInHashtableWithOverflowHashTable){
    HashTable a(10);
    Key k = "1234";
    Key name = "abrac";

    Value v(name,22);
    for (int i = 0 ; i < 6; i++){
        k = gen_random( i);
        v.name = gen_random(4);
        v.age = i;
        a.insert(k,v);
    }
    ASSERT_EQ(a.capacity(),20);
    ASSERT_EQ(a.capacity(),6);
}

TEST(Test_HashTable, OriginalHashTableIsNotChangedOnCopyChange){
    HashTable a(12);
    Key k = "1234";
    Key name = "abrac";

    Value v(name,22);
    a.insert(k,v);
    ASSERT_EQ(a.size(), 1);
    ASSERT_EQ(a.at(k), &v);
    HashTable b;
    b = a;
    ASSERT_EQ(b.size(), 1);
    ASSERT_EQ(a.at(k), &v);
    Key name2 = "hey";

    Value v2(name2,34);
    b.insert(name2, v2);
    ASSERT_EQ(a.size(), 1);
    ASSERT_EQ(a.at(k), &v);
    ASSERT_EQ(b.size(), 2);
    ASSERT_EQ(b.at(k), &v);
}

TEST(Test_HashTable, WorkOfTheOperatorGettingByKeyWhenTheElementExists){
    Key k = gen_random(4);
    Value v;
    v.name = gen_random(4);
    v.age = 54;
    HashTable a;
    a.insert(k,v);
    a.insert(gen_random(3), Value(gen_random(3),23));
    ASSERT_EQ(a[k],&v);    
}

TEST(Test_HashTable, WorkOfTheOperatorGettingByKeyWhenTheElementNotExists){
    Key k = gen_random(4);
    Value v;
    v.name = gen_random(4);
    v.age = 54;
    HashTable a;
    a.insert(k,v);
    a.insert(gen_random(3), Value(gen_random(3),23));
    ASSERT_EQ(a.size(),2);
    a[k];
    ASSERT_EQ(a.size(),3);
}