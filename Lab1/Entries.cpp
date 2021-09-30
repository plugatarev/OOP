#include "Entries.hpp"

Entries::Entries(){};

Entries::Entries(Key& k, Value& v):key(k),value(v){};

Entries::Entries(const Entries& other):key(other.key), value(other.value){};

Entries::Entries(Key& k, Value& v, Entries* next):key(k), value(v), next(next){};

Entries::~Entries(){};

bool Entries::operator==(const Entries& p){
    if (key == p.key && value == p.value) return true;
    return false;
}

