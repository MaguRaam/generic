//Variadic Templates:
#include <iostream>

template <typename T>
inline T sum(T t){return t;}

template<typename T,typename ...P>
inline T sum(T t, P ...p){
    return t + sum(p...);
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
