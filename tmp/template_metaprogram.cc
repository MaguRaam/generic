#include <iostream>

template <typename T>
inline T sum(T t) { return t; }

template <typename T, typename... P>
inline T sum(T t, P... p)
{
    return t + sum(p...);
}

//meta functions:
template <int n>
struct factorial
{
    static constexpr int value = n * factorial<n - 1>::value;
};

template <>
struct factorial<0>
{
    static constexpr int value = 1;
};

template <typename T>
struct isPtr
{
    static constexpr bool value = false;
};

template <typename U>
struct isPtr<U *>
{
    static constexpr bool value = true;
};

template <typename U>
struct isPtr<U *const>
{
    static constexpr bool value = true;
};

//count:
template <typename... list>
struct count;

template <>
struct count<>
{
    static const int value = 0;
};

template<typename head, typename ...tail>
struct count<head, tail...>
{
    static constexpr int value = 1 + count<tail...>::value;
};




int main()
{
    static_assert(count<int,double,float>::value == 3, "Oops");

    return 0;
}
