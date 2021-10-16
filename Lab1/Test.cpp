#include <gtest/gtest.h>
#include "HashTable.hpp"
#include <ctime> 
#include "Header.hpp"
bool operator==(const Value& a,const Value& b);
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

void fill_table(HashTable& a, int n = 5){
    Value v;
    for (size_t i = 0; i < n; i++){
        v.age = i + 2;
        v.name = gen_random(5); 
        a.insert(gen_random(5),v);
    }
}

TEST(HashTableTest,DefaultConstructor){
    HashTable a;
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(a.capacity(), 16);
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
    bool flag = (a.at(k) == v);
    ASSERT_EQ(flag,1);
    fill_table(a,10);
    ASSERT_EQ(a.size(),10);
}

TEST(HashTableTest, InsertInHashtableWithOverflowHashTable){
    HashTable a(10);
    Key k = "1234";
    Key name = "abrac";

    Value v(name,22);
    fill_table(a,7);
    ASSERT_EQ(a.capacity(),20);
    ASSERT_EQ(a.size(),6);
}

TEST(Test_HashTable, OriginalHashTableIsNotChangedOnOperatorAssign){
    HashTable a(12);
    Key k = "1234";
    Key name = "abrac";

    Value v(name,22);
    a.insert(k,v);
    ASSERT_EQ(a.size(), 1);
    bool flag = (a.at(k) == v);
    ASSERT_EQ(flag,1);
    HashTable b;
    b = a;
    ASSERT_EQ(b.size(), 1);
    flag = (a.at(k) == v);
    ASSERT_EQ(flag,1);
    Key name2 = "hey";

    Value v2(name2,34);
    b.insert(name2, v2);
    ASSERT_EQ(a.size(), 1);
    flag = (a.at(k) == v);
    ASSERT_EQ(flag,1);
    ASSERT_EQ(b.size(), 2);
    flag = (b.at(k) == v);
    ASSERT_EQ(flag,1);
}

TEST(Test_HashTable, OriginalHashTableIsNotChangedOnCopyChange){
    HashTable a(12);
    Key k = "1234";
    Key name = "abrac";

    Value v(name,22);
    a.insert(k,v);
    ASSERT_EQ(a.size(), 1);
    bool flag = (a.at(k) == v);
    ASSERT_EQ(flag,1);
    HashTable b(a);
    ASSERT_EQ(b.size(), 1);
    flag = (a.at(k) == v);
    ASSERT_EQ(flag,1);
    Key name2 = "hey";

    Value v2(name2,34);
    b.insert(name2, v2);
    ASSERT_EQ(a.size(), 1);
    flag = (a.at(k) == v);
    ASSERT_EQ(flag,1);
    ASSERT_EQ(b.size(), 2);
    flag = (b.at(k) == v);
    ASSERT_EQ(flag,1);
}

TEST(Test_HashTable, WorkOfTheOperatorGettingByKeyWhenTheElementExists){
    Key k = gen_random(4);
    Value v;
    v.name = gen_random(4);
    v.age = 54;
    HashTable a;
    a.insert(k,v);
    a.insert(gen_random(3), Value(gen_random(3),23));
    bool flag = (a[k] == v);
    ASSERT_EQ(flag,1);   
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
    Key newk = "!@$%";
    a[newk];
    ASSERT_EQ(a.size(),3);
}

TEST(Test_HashTable, WorkOfTheOperatorEqualForEmptyHashTable){
    HashTable a;
    HashTable b;
    ASSERT_EQ(a == b, 1);
}

TEST(Test_HashTable, WorkOfTheOperatorEqualForNotEmptyHashTable){
    HashTable a;
    HashTable b(a);
    fill_table(a);
    ASSERT_EQ(a == b, 1);

    b.insert(gen_random(4),Value());
    ASSERT_EQ(a == b, 0);
}


TEST(Test_HashTable, WorkOfTheSwap){
    HashTable a;
    HashTable b;
    fill_table(a,17);
    fill_table(b);
    HashTable tmp_a(a);
    HashTable tmp_b(b);
    a.swap(b);
    ASSERT_EQ(a == tmp_b,1);
    ASSERT_EQ(b == tmp_a,1);
}   

TEST(Test_HashTable,CheckingOnTableEmptiness){
    HashTable a;
    ASSERT_EQ(a.empty(),0);
    fill_table(a,1);
    ASSERT_EQ(a.empty(),1);
}

TEST(Test_HashTable,CheckinGMethodContaintsTheTable){
    HashTable a(12);
    Key k = "1234";
    Key name = "abrac";

    Value v(name,22);
    a.insert(k,v);
    fill_table(a);
    ASSERT_EQ(a.contains(k),1);
    Key n = "!";
    ASSERT_EQ(a.contains(n),0);
}

TEST(Test_HashTable,CheckingMethodClearTheTable){
    HashTable a(12);
    Key k = "1234";
    Key name = "abrac";

    Value v(name,22);
    a.insert(k,v);
    a.clear();
    ASSERT_EQ(a.capacity(),16);
    ASSERT_EQ(a.size(),0);
    ASSERT_EQ(a.contains(k),0);
}

TEST(Test_HashTable,CheckingMethodEraseTheTable){
    HashTable a;
    Key k = "1234";
    Key name = "abrac";

    Value v(name,22);
    a.insert(k,v);
    fill_table(a,10);
    ASSERT_EQ(a.contains(k),1);
    a.erase(k);
    ASSERT_EQ(a.size(),10);
    ASSERT_EQ(a.contains(k),0);
}