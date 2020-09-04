//Functors:
#include <iostream>
#include <cmath>

//sin + cos functor
struct psc_f
{
    psc_f(const double alpha) : alpha(alpha) {}
    double operator()(double x) const
    {
        return sin(alpha * x) + cos(x);
    }

private:
    double alpha;
};

//finite difference
template <typename F, typename T>
/*
requirements:
Let f be of type F
Let x be of type T, where T is the argument type of F
f(x) calls f with one argument and returns an object of the result type
The return type of f is T as well ?
*/
inline T fin_diff(F f, const T &x, const T &h)
{
    return (f(x + h) - f(x)) / h;
}

//composing functors:

//derivative functor:
template <typename F, typename T>
struct derivative
{
    derivative(const F &f, const T &h) : f(f), h(h) {}

    T operator()(const T &x) const
    {
        return (f(x + h) - f(x)) / h;
    }

private:
    const F &f;
    T h;
};

//second derivative:
template <typename F, typename T>
struct second_derivative
{
    second_derivative(const F &f, const T &h) : h(h), fp(f, h)
    {
    }

    T operator()(const T &x) const
    {
        return (fp(x + h) - fp(x)) / h;
    }

private:
    T h;
    derivative<F, T> fp;
};

//nth derivative using recursion:
template<typename F, typename T, unsigned N>
struct nth_derivative
{
    using prev_derivative = nth_derivative<F,T,N-1>;

    nth_derivative(const F& f, const T& h) : h(h), fp(f,h){}

    T operator()(const T& x) const
    {
        return (fp(x+h) - fp(x))/h;
    }
private:
    T h;
    prev_derivative fp;
};

//template specialization to stop recursion:
template<typename F, typename T>
struct nth_derivative<F,T,1>
{
    nth_derivative(const F& f, const T& h) : h(h), f(f){}

    T operator()(const T& x) const
    {
        return (f(x+h) - f(x))/h;
    }
private:
    T h;
    const F& f;
};


using d_psc_f = derivative<psc_f, double>;
using dd_psc_f = derivative<d_psc_f, double>;

int main()
{
    psc_f psc_o(1.0);
    d_psc_f d_psc_o(psc_o, 0.001);
    dd_psc_f dd_psc_o(d_psc_o, 0.001);

    std::cout << "2nd der of sin(0) + cos(0) is " << dd_psc_o(0.0) << "\n";

    return 0;
}
