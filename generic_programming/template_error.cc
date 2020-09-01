#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>


int main(){

    std::complex<double> z1(2,3),z2(4,5);
    std::max(z1,z2);

    std::vector<std::complex<double> > vec{{1.0,2.0},{2.0,3.0},{4.0,5.0}};
    std::sort(vec.begin(),vec.end());
    std::cout<<z1<<std::endl;

    return 0;
}