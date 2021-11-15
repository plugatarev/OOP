#include "Function_for_string.hpp"
bool is_number(const std::string& s){
    std::string::const_iterator it = s.begin();
    std::string::const_iterator end = s.end();
    while (it != end && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool is_write_str(std::string& s){
    std::string k;
    std::string::iterator it = s.begin();
    std::string::iterator end = s.end();
    bool flag = 0;
    it++;
    if ((*it) != '"') return false;
    it++;
    while (it != end){
        if ((*it) == '"') {
            flag = 1;
            break;
        }
        k+=(*it);
        it++;
    }
    if (flag = 0 || (++it) != end) return false;
    s = k;
    return true;
}