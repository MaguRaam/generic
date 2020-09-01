#include <iostream>

//Value parameters:
template<typename TPara>
void f1(TPara p){}

//Lvalue-Reference parameter:
template<typename TPara>
void f2(const TPara& p){}

//mutable reference:
template<typename TPara>
void f3(TPara& p){}

//forward reference:
template<typename TPara>
void f4(TPara&& p){}

//perfect forwarding:
template<typename TPara>
void f5(TPara&& p){
    f4(std::forward<TPara>(p));
}

int main()
{
    int i = 0;
    int& j = i;
    const int& k = i;

    f1(3);
    f1(i);
    f1(j);
    f1(k);

    f2(3);
    f2(i);
    f2(j);
    f2(k);

    //f3(3); it rejects temporaries and literals
    f3(i);
    f3(j);
    f3(k);

    f4(3);
    f4(i);
    int l = 3;
    f4(std::move(l));
    f4(j);
    f4(k);

    return 0;
}

