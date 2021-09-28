#include "HashMap.hpp"

HashMap::HashMap(){};

HashMap::HashMap(Key k, Value& v):key(k),value(v){};

HashMap::HashMap(const HashMap& other):key(other.key), value(other.value){};

HashMap::HashMap(const HashMap & other, HashMap* v):key(other.key), value(other.value), next(v){};

HashMap::~HashMap(){};

bool HashMap::operator==(const HashMap& p){
    if (key == p.key && value == p.value) return true;
    return false;
}

