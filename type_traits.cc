#include <complex>
#include <iostream>
#include <vector>
//true for all intrinsic type:
template<typename T>
struct Magnitude{
    using type = T;
};

//patial template specialization for complex types:
template<typename T>
struct Magnitude<std::complex<T> >
{
    using type = T;
};

template<typename T>
T inline min_magnitude(const T& x, const T& y){

    using std::abs;
    typename Magnitude<T>::type ax = abs(x), ay = abs(y);
    return ax < ay ? x : y;
}

//simple view implementation of matrix:
template<typename Matrix>
//concept:
//requiremnt on Matrix type
// needed a value_type and size_type for the Matrix type
//required an opertor() taking arguments i,j to return the matix element a(i,j)
class transposed_view
{
    public:
        using value_type = typename Matrix::value_type;
        using size_type  = typename Matrix::size_type;

        explicit transposed_view(Matrix& A) : ref(A){}
        value_type& operator()(size_type r, size_type c)
        {
            return ref(c,r);
        }
        const value_type& operator()(size_type r, size_type c) const 
        {
            return ref(c,r);
        }
    private:
        Matrix& ref;
};

template<typename Matrix>
inline transposed_view<Matrix> trans(Matrix& A){
    return transposed_view<Matrix>(A);
}

int main(){

    return 0;
}