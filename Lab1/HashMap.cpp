#include "HashMap.hpp"

HashMap::HashMap(){};

HashMap::HashMap(Key& k, Value& v):key(k),value(v){};

HashMap::HashMap(const HashMap& other):key(other.key), value(other.value){};

HashMap::HashMap(Key& k, Value& v, HashMap* next):key(k), value(v), next(next){};

HashMap::~HashMap(){};

bool HashMap::operator==(const HashMap& p){
    if (key == p.key && value == p.value) return true;
    return false;
}

