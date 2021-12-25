// #pragma once
// #include <iostream>
// #include "Exception.hpp"
// #include "Is_Same.hpp"

// namespace UtilsVariant{
//     template<typename... Args>
//     struct is_type;

//     template<typename T, typename F, typename... Args>
//     struct is_type<T, F, Args...> {
//         static constexpr bool is(){
//             if (My::is_same<T,F>::value) return true;
//             else{
//                 if (is_type<T, Args...>::is()) return true;
//             }
//             return false;
//         }
//     };

//     template<typename T> struct is_type<T>{
//     constexpr static bool is() {
//         return false;
//     }
//     };

// }

// namespace MyVariant{
//     // at least one arg
//     template<typename F, typename... Args>
//     class variant{
//     public: 
//         variant(){}

//         //Makes a copy of value, so that the initial content of the new instance is equivalent in both type and value to value.
//         template<typename T> variant(const T& value):data(new impl(value)){
//             static_assert(UtilsVariant::is_type<T, F, Args...>::is());
//         }

//         //Makes a copy of value, discarding previous content, so that the new content of is equivalent in both type and value to value.
//         template<typename T>
//         variant& operator=(const T& value){
//             static_assert(UtilsVariant::is_type<T, F, Args...>::is());
//             delete data;
//             data = new impl(value);
//             return *this;
//         }
// //////////////////////////////////////////////////
//         variant(const variant<F,Args...>& old){
//             //placeholder* tmp = new impl(old.data);
//             data = new impl(old.data.val); // What type T?
//         }

//         variant(variant<F,Args...>&& old){
//             std::swap(data, old.data);
//         }

//         // // Serves as both the move and the copy asignment operator.
//         variant<F,Args...>& operator=(variant<F,Args...>&& old){ // - ok
//             std::swap(data, old.data);
//             return *this;
//         }

//         template<typename T>
//         T get(){
//             static_assert(UtilsVariant::is_type<T, F, Args...>::is());
//             return (dynamic_cast<impl<T>*>(data) != nullptr ? dynamic_cast<impl<T>*>(data)->val : throw variant_access_error("This type isn't stored in this variant"));
//         }
        
//         template<typename T>
//         T * get_if(){
//             static_assert(UtilsVariant::is_type<T, F, Args...>::is());
//             if (UtilsVariant::is_type<T, Args...>::is())
//                 return dynamic_cast<impl<T>*>(data);
//             else 
//                 return nullptr;
//         }

//         ~variant() {
//             if (data != nullptr) delete data;
//         }

//     private: 
//         struct placeholder{
//             virtual ~placeholder() {}
//         };

//         template < typename T >
//         struct impl: placeholder{
//             impl(){};
//             impl(T const& t):val(t){}
//             ~impl(){}
//             T val;

//         };
//         placeholder* data{nullptr};
//     };
// }
#pragma once
#include <iostream>
#include <memory>
#include "Exception.hpp"
#include "Is_Same.hpp"

namespace UtilsVariant{
    template<typename... Args>
    struct is_type;

    template<typename T, typename F, typename... Args>
    struct is_type<T, F, Args...> {
        static constexpr bool is(){
            if (My::is_same<T,F>::value) return true;
            else{
                if (is_type<T, Args...>::is()) return true;
            }
            return false;
        }
    };

    template<typename T> struct is_type<T>{
    constexpr static bool is() {
        return false;
    }
    };

}

namespace MyVariant{
    // At least one arg
    template<typename F, typename... Args>
    class variant{
    public: 
        variant():data(nullptr){}

        //Makes a copy of value, so that the initial content of the new instance is equivalent in both type and value to value.
        template<typename T> variant(const T& value):data(new impl(value)){
            static_assert(UtilsVariant::is_type<T, F, Args...>::is());
        }

        //Makes a copy of value, discarding previous content, so that the new content of is equivalent in both type and value to value.
        template<typename T>
        variant& operator=(const T& value){
            static_assert(UtilsVariant::is_type<T, F, Args...>::is());
            data = std::make_shared<impl<T>>(value);
            return *this;
        }

        //Default constructor. Constructs a variant with nullptr
        variant(const variant<F,Args...>& old):data(old.data){}

        variant(variant<F,Args...>&& old){
            std::swap(data, old.data);
        }

        //Serves as both the move and the copy asignment operator.
        variant<F,Args...>& operator=(variant<F,Args...>&& old){ // - ok
            std::swap(data, old.data);
            return *this;
        }

        template<typename T>
        T get(){
            static_assert(UtilsVariant::is_type<T, F, Args...>::is());
            return (dynamic_cast<impl<T>*>(data.get()) != nullptr ? dynamic_cast<impl<T>*>(data.get())->val : throw variant_access_error("This type isn't stored in this variant"));
        }
        
        template<typename T>
        T * get_if(){
            static_assert(UtilsVariant::is_type<T, F, Args...>::is());
            if (UtilsVariant::is_type<T, Args...>::is())
                return dynamic_cast<impl<T>*>(data);
            else 
                return nullptr;
        }

        ~variant(){}

    private: 
        struct placeholder{
            virtual ~placeholder() {}
        };

        template < typename T >
        struct impl: placeholder{
            impl(){};
            impl(T const& t):val(t){}
            ~impl(){}
            T val;

        };
        std::shared_ptr<placeholder> data;
    };
}