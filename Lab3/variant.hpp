#include <iostream>
#include <utility>
#include <typeinfo>
#include <type_traits>
#include <string>
class variant_access_error: public std::runtime_error {
 public:
    explicit variant_access_error(const std::string& msg): std::runtime_error(msg) {}
};

namespace UtilsVariant{
    template<typename... Args>
    struct is_type;

    template<typename T, typename F, typename... Args>
    struct is_type<T, F, Args...>
    {
        static constexpr bool is(){
            if (std::is_same<T,F>::value) return true;
            else{
                is_type<T, Args...>::is();
            }
            return false;
        }
    };

    template<typename T, typename F> struct is_type<T,F>{
    constexpr static bool is() {
        return std::is_same<T,F>::value;
    }
    };


}

namespace MyVariant{
    template<typename... Args>
    class variant {
    public: 
        variant(){}

        //Makes a copy of value, so that the initial content of the new instance is equivalent in both type and value to value.
        template<typename T> variant(const T& value):data(new impl(value)){
            using utls = UtilsVariant::is_type<T, Args...>;
            static_assert(utls::is()); //fix is()
        }

        //Makes a copy of value, discarding previous content, so that the new content of is equivalent in both type and value to value.
        template<typename T> variant& operator=(const T& value){
            using utls = UtilsVariant::is_type<T, Args...>;
            static_assert(utls::is());
            delete data;
            data = new impl(value);
            return *this;
        }

        variant(const variant<Args...>& old){
            //static_assert(utls::copy(old,&data));
            //Check on equal templates
            data = new impl(old.get<T>()); // What type T?
        }

        variant(variant<Args...>&& old){
            //Check on equal templates
            data = new impl(old.get<T>()); // What type T?
        }

        // // Serves as both the move and the copy asignment operator.
        variant<Args...>& operator= (variant<Args...>&& old){
            //Check on equal templates
            std::swap(data, old.data);
            return *this;
        }
        
        template<typename T>
        T get(){
            using utls = UtilsVariant::is_type<T, Args...>;
            if (utls::is())
                return (dynamic_cast<impl<Args...>*>(data))->val;
            else 
                throw variant_access_error("bad cast error!");
        }
        
        template<typename T>
        T * get_if(){
            using utls = UtilsVariant::is_type<T, Args...>;
            if (utls::is())
                return dynamic_cast<impl<Args...>*>(data);
            else 
                return nullptr;
        }

        ~variant() {
            delete data;
        }

    private: 
        struct placeholder{
            virtual ~placeholder() {}
        };
        //mb Deleter?
        template < typename T >
        struct impl: placeholder{
            impl(){};
            impl(T const& t):val(t){}
            ~impl(){}
            T val;

        };
        placeholder* data;
    };
}
