namespace My{
    
template<typename T, typename U>
struct is_same {
    static const bool value = false; 
};

template<typename T>
struct is_same<T,T>{ 
   static const bool value = true; 
};

}