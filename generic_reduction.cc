//reduction
#include <vector>

template<typename Iter, typename T, typename BinaryFunction>
T accumulate(Iter it, Iter end, T init, BinaryFunction op){
    for (; it != end; ++it)
        init = op(init,*it);
    return init;
}

template<typename T>
struct add
{
    T operator()(const T& x, const T& y){return x+y;}
};



int main(int argc, char const *argv[])
{
    std::vector<double> vec{1.0,2.0,3.0,4.0,5.0};

    accumulate(vec.begin(),vec.end(),0.0,add<double>());
    return 0;
}
