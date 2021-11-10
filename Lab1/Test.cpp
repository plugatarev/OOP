#include <gtest/gtest.h>
#include "HashTable.hpp"
#include <ctime> 
#include "Header.hpp"
bool operator==(const Value& a,const Value& b);
Key* gen_random(int len) {
    Key s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    Key* key = new std::string(s); 

    return key;
}

void fill_table(HashTable& a, int n = 5){
    
    for (size_t i = 0; i < n; i++){
    	Key* name = gen_random(5);
        Value* v = new Value(*name, i + 2);
        Key* k = gen_random(5);
        a.insert(*k,*v);
    }
}

TEST(HashTableTest, CheckingMethodSize){
    HashTable a(17);
    fill_table(a,6);
    ASSERT_EQ(a.size(), 6);
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
    ASSERT_EQ(a.at(k),v);
    a.insert("wrew",Value("erw",23));
    a.insert("wre2332w",Value("erw2",33));
    a.insert("fafasc",Value("git12",1));
    ASSERT_EQ(a.size(),4);
}

TEST(HashTableTest, InsertInHashtableWithEqualKeys){
    HashTable a(100);
    Key k = "1234";
    Key name = "abrac";
    Value v(name,22);
    Key k2 = "1234";
    Key name2 = "qqeq";
    Value v2(name,22);

    a.insert(k,v);
    a.insert(k2, v2);
    ASSERT_EQ(a.size(),1);
    ASSERT_EQ(a.at(k),v2);
}

TEST(HashTableTest, InsertInHashtableWithOverflowHashTable){
    HashTable a(10);
    Key k = "1234";
    Key name = "abrac";

    Value v(name,22);
    for (int i = 65; i < 74; i++){
        Key k = std::to_string(i) + std::to_string(i + 2) + std::to_string(i + 3);
        a.insert(k,Value("erw2",33));
    }
    ASSERT_EQ(a.capacity(),20);
    ASSERT_EQ(a.size(),9);
}

TEST(Test_HashTable, OriginalHashTableIsNotChangedOnOperatorAssign){
    HashTable a(12);
    Key k = "1234";
    Key name = "abrac";

    Value v(name,22);
    a.insert(k,v);
    ASSERT_EQ(a.size(), 1);
    ASSERT_EQ(a.at(k),v);
    HashTable b;
    b = a;
    ASSERT_EQ(b.size(), 1);
    ASSERT_EQ(a.at(k),v);
  
    Key name2 = "hey";

    Value v2(name2,34);
    b.insert(name2, v2);
    ASSERT_EQ(a.size(), 1);
    ASSERT_EQ(a.at(k),v);
    ASSERT_EQ(b.size(), 2);
    ASSERT_EQ(b.at(k),v);
    ASSERT_EQ(b.at(name2),v2);
}

TEST(Test_HashTable, OperatorAssignForEmpryHashTable){
    HashTable a(12);
    HashTable b;
    b = a;
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(b.size(), 0);
    ASSERT_EQ(a.capacity(),12);
    ASSERT_EQ(b.capacity(), 12);
}

TEST(Test_HashTable, NewHashTableDoesNotChangeWhenTheOlIsChanged){
    HashTable a(12);
    a.insert("wrew",Value("erw",23));
    a.insert("wre2332w",Value("erw2",33));
    a.insert("fafasc",Value("git12",1));
    HashTable b;
    b = a;
    ASSERT_EQ(a.size(), 3);
    ASSERT_EQ(b.size(), 3);
    Key k = "1234";
    Key name = "abrac";
    Value v(name,22);
    a.insert(k,v);
    ASSERT_EQ(a.size(), 4);
    ASSERT_EQ(b.size(), 3);
}

TEST(Test_HashTable, OriginalHashTableIsNotChangedOnCopyChangeOperatorAssign){
    HashTable a(12);
    Key k = "1234";
    Key name = "abrac";

    Value v(name,22);
    a.insert(k,v);
    ASSERT_EQ(a.size(), 1);
    ASSERT_EQ(a.at(k),v);
    HashTable b(a);
    ASSERT_EQ(b.size(), 1);
    ASSERT_EQ(a.at(k),v);
    Key name2 = "hey";

    Value v2(name2,34);
    b.insert(name2, v2);
    ASSERT_EQ(a.size(), 1);
    ASSERT_EQ(a.at(k),v);
    ASSERT_EQ(b.size(), 2);
    ASSERT_EQ(b.at(k),v);
}

TEST(Test_HashTable, NewHashTableDoesNotChangeWhenTheOlIsChangedCopyConstructor){
    HashTable a(12);
    a.insert("wrew",Value("erw",23));
    a.insert("wre2332w",Value("erw2",33));
    a.insert("fafasc",Value("git12",1));
    HashTable b(a);
    ASSERT_EQ(a.size(), 3);
    ASSERT_EQ(b.size(), 3);
    Key k = "1234";
    Key name = "abrac";
    Value v(name,22);
    a.insert(k,v);
    ASSERT_EQ(a.size(), 4);
    ASSERT_EQ(b.size(), 3);
}

TEST(Test_HashTable, WorkOfTheOperatorGettingByKeyWhenTheElementExists){
    Key k = "SDFSD";
    Value v;
    v.name = "Obeme";
    v.age = 54;
    HashTable a;
    a.insert(k,v);
    a.insert("wewq", Value("324",23));
    ASSERT_EQ(a[k],v);   
}

TEST(Test_HashTable, WorkOfTheOperatorGettingByKeyWhenTheElementNotExists){
    Key k = "SDFSD";
    Value v;
    v.name = "Obeme";
    v.age = 54;
    HashTable a;
    a.insert(k,v);
    a.insert("wewq", Value("324",23));
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

TEST(Test_HashTable, WorkOfTheOperatorEqualForEqualHashTable){
    HashTable a;
    for (size_t i = 0; i < 5; i++){
        Value* v = new Value(*gen_random(5), i + 2);
        a.insert(*gen_random(5),*v);
    }
    HashTable b(a);
    ASSERT_EQ(a == b, 1);
}

TEST(Test_HashTable, WorkOfTheOperatorEqualForNotEqualHashTable){
    HashTable a;
    for (size_t i = 0; i < 5; i++){
        Value* v = new Value(*gen_random(5), i + 2);
        a.insert(*gen_random(5),*v);
    }
    HashTable b(a);
    b.insert(*gen_random(4),Value());
    ASSERT_EQ(a == b, 0);
}

TEST(Test_HashTable, WorkOfTheOperatorEqualOneHashTableIsEmpty){
    HashTable a;
    for (size_t i = 0; i < 5; i++){
        Value* v = new Value(*gen_random(5), i + 2);
        a.insert(*gen_random(5),*v);
    }
    HashTable b;
    ASSERT_EQ(a == b, 0);
}
////////////////////////////////////////////////////////////////////////////////////
TEST(Test_HashTable, WorkOfTheOperatorNotEqualForEmptyHashTable){
    HashTable a;
    HashTable b;
    ASSERT_EQ(a != b, 0);
}

TEST(Test_HashTable, WorkOfTheOperatorNotEqualForEqualHashTable){
    HashTable a;
    for (size_t i = 0; i < 5; i++){
        Value* v = new Value(*gen_random(5), i + 2);
        a.insert(*gen_random(5),*v);
    }
    HashTable b(a);
    ASSERT_EQ(a != b, 0);
}

TEST(Test_HashTable, WorkOfTheOperatorNotEqualForNotEqualHashTable){
    HashTable a;
    for (size_t i = 0; i < 5; i++){
        Value* v = new Value(*gen_random(5), i + 2);
        a.insert(*gen_random(5),*v);
    }
    HashTable b(a);
    b.insert(*gen_random(4),Value());
    ASSERT_EQ(a != b, 1);
}

TEST(Test_HashTable, WorkOfTheOperatorNotEqualOneHashTableIsEmpty){
    HashTable a;
    for (size_t i = 0; i < 5; i++){
        Value* v = new Value(*gen_random(5), i + 2);
        a.insert(*gen_random(5),*v);
    }
    HashTable b;
    ASSERT_EQ(a != b, 1);
}

TEST(Test_HashTable, WorkOfTheSwapForRandomNotEmptyHashTables){
    HashTable a;
    HashTable b;
    for (int i = 65; i < 78; i++){
        Key k = std::to_string(i) + std::to_string(i + 2) + std::to_string(i + 3);
        a.insert(k,Value("erw2",33 + i));
    }
    for (int i = 65; i < 74; i++){
        Key k = std::to_string(i + 4) + std::to_string(i + 5) + std::to_string(i + 6);
        a.insert(k,Value("erw2" + i, 10 + i));
    }
    HashTable tmp_a(a);
    HashTable tmp_b(b);
    a.swap(b);
    ASSERT_EQ(a == tmp_b,1);
    ASSERT_EQ(b == tmp_a,1);
}   

TEST(Test_HashTable, WorkOfTheSwapOneHashTableIsEmpty){
    HashTable a;
    HashTable b;
    for (int i = 65; i < 78; i++){
        Key k = std::to_string(i) + std::to_string(i + 2) + std::to_string(i + 3);
        a.insert(k,Value("erw2",33 + i));
    }
    HashTable tmp_a(a);
    HashTable tmp_b(b);
    a.swap(b);
    ASSERT_EQ(a == tmp_b,1);
    ASSERT_EQ(b == tmp_a,1);
}   

TEST(Test_HashTable, WorkOfTheSwapHashTablesAreEmpty){
    HashTable a;
    HashTable b;
    HashTable tmp_a(a);
    HashTable tmp_b(b);
    a.swap(b);
    ASSERT_EQ(a == tmp_b,1);
    ASSERT_EQ(b == tmp_a,1);
} 

TEST(Test_HashTable, WorkOfTheSwapHashTablesFor){
    HashTable a;
    HashTable b;
    HashTable tmp_a(a);
    HashTable tmp_b(b);
    a.swap(b);
    ASSERT_EQ(a == tmp_b,1);
    ASSERT_EQ(b == tmp_a,1);
} 


TEST(Test_HashTable, WorkOfTheSwapHashTablesCheckingForChangesHashTables){
    HashTable a;
    HashTable b;
    a.insert(";io;6", Value("324",23));
    a.insert("12wewq", Value("sds",2));
    a.insert("19wewq", Value("sdf",56));
    b.insert("qazqa", Value("asd",223));
    b.insert("aqtg", Value("jhk",11));
    b.insert("nm,n", Value("zxcds",99));
    HashTable tmp_a(a);
    HashTable tmp_b(b);
    a.swap(b);
    ASSERT_EQ(a == tmp_b,1);
    ASSERT_EQ(b == tmp_a,1);
    Key k = "1234";
    Key name = "abrac";
    Value v(name,22);
    a.insert(k,v);
    ASSERT_EQ(a.size(),6);
    ASSERT_EQ(b.size(),5);
    ASSERT_EQ(a.contains(k),1);
    ASSERT_EQ(b.contains(k),0);
} 

TEST(Test_HashTable,CheckingOnTableEmptiness){
    HashTable a;
    ASSERT_EQ(a.empty(),1);
    a.insert("wewq", Value("324",23));
    ASSERT_EQ(a.empty(),0);
}

TEST(Test_HashTable,CheckinGMethodContaintsTheTable){
    HashTable a(12);
    Key k = "1234";
    Key name = "abrac";

    Value v(name,22);
    a.insert(k,v);
    a.insert("wewq", Value("324",23));
    ASSERT_EQ(a.contains(k),1);
    Key n = "!";
    ASSERT_EQ(a.contains(n),0);
}

TEST(Test_HashTable,CheckinGMethodContaintsTheTableForSomeKeys){
    HashTable a(12);
    Key k = "1234";
    Key name = "abrac";
    Key kt = k;
    Key namet = name;
    Value v(name,22);
    for (int i = 0; i < 6; i++){
        k+=1;
        name+=1;
        a.insert(k,v);
    }

    for (int i = 0; i < 6; i++){
        kt+=1;
        namet+=1;
        ASSERT_EQ(a.contains(k),1);
    } 
}

TEST(Test_HashTable,CheckinGMethodContaintsForEmptyTable){
    HashTable a(12);
    Key k = "1234";
    ASSERT_EQ(a.contains(k),0);
}

TEST(Test_HashTable,CheckingMethodClearTheTable){
    HashTable a(12);
    Key k = "1234";
    Key name = "abrac";

    Value v(name,22);
    a.insert(k,v);
    a.insert("wewq", Value("324",23));
    a.insert("wewerq", Value("324",23));
    a.clear();
    ASSERT_EQ(a.capacity(),12);
    ASSERT_EQ(a.size(),0);
    ASSERT_EQ(a.contains(k),0);
}

TEST(Test_HashTable,CheckingMethodClearForEmptyTable){
    HashTable a(12);
    a.clear();
    ASSERT_EQ(a.capacity(),12);
    ASSERT_EQ(a.size(),0);
}

TEST(Test_HashTable,CheckingMethodEraseTheTable){
    HashTable a;
    Key k = "!@#";
    Key name = "abrac";

    Value v(name,22);
    a.insert(k,v);
    a.insert("wewq", Value("324",23));
    a.insert("wf23", Value("324",23));
    a.insert(";io;6", Value("324",23));
    ASSERT_EQ(a.contains(k),1);
    a.erase(k);
    ASSERT_EQ(a.size(),3);
    ASSERT_EQ(a.contains(k),0);
}

TEST(Test_HashTable,CheckingMethodEraseForEmptyTable){
    HashTable a;
    Key k = "erase";
    a.erase(k);
    ASSERT_EQ(a.size(),0);
}

TEST(Test_HashTale,CheckingMethodAtTheTableWhenTheElementIsNotExists){
    HashTable a;
    a.insert("wewq", Value("324",23));
    Key k = "!@#$#";
    try{
    	a.at(k);
    }
    catch (std::exception  &e) {
        EXPECT_EQ(e.what(), (std::string )"no such element exists");
    }

}

TEST(Test_HashTable,CheckingMethodAtForEmptyTableWhenTheElementIsNotExists){
    HashTable a;
    Key k = "abrac";
    try{
    	a.at(k);
    }
    catch (std::exception  &e) {
        EXPECT_EQ(e.what(), (std::string )"no such element exists");
    }

}

TEST(Test_HashTable,CheckingMethodAtTheTableWhenTheElementExists){
    HashTable a;
    a.insert(";io;6", Value("324",23));
    Key k = "1234";
    Key name = "abrac";
    Value v(name,22);
    a.insert(k,v);
    ASSERT_EQ(a.at(k),v);
}
