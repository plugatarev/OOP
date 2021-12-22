#include "variant.hpp"
#include <variant>
class A{};
int main(){

    // std::variant<int, double, A, int&> v;
    // std::variant<int, double, A, int&> g(v);
    //v = 1.21;
    //v = new A();
    //int* b = new int;
    int a2 = 1;
    //MyVariant::variant<double, int> a(a2);
    // UtilsVariant::utils<int, double, int> ac;
    // int* b;
    // int* b_0;
    // std::cout << ac.move(b,b_0);
    //My::variant<char> b(a);
    //a = "df";
    // std::cout << "size is " << sizeof(a) << "   value is " << a.get<int>() << std::endl;
    // a = 23432423432.3434;
    // std::cout << "size is " << sizeof(a) << "   value is " << a.get<double>() << std::endl;
    //MyVariant::variant<int,char> b(a);
    //std::cout << "size is " << sizeof(a) << "   value is " << a.get<int>() << std::endl;
    //variant<> v;
    // int* v = new int(3);
    // a = v;
    // std::cout << "size is " << sizeof(a) << "   value is " << *(a.get<int*>()) << std::endl;
    return 0;
}