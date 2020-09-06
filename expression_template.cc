#include <iostream>
#include <vector>


template<typename T>
inline
void print(const std::vector<T>& x){
	for (const auto& e : x) std::cout<<e<<" ";
	std::cout<<"\n";
}

template<typename T>
inline
int size(const std::vector<T>& vec){
	return vec.size();
}


template<typename T>
class vector_sum
{
public:
	vector_sum(const std::vector<T>& v1, const std::vector<T>& v2) : v1(v1), v2(v2){}
	friend int size(const vector_sum<T>& x){return size(x.v1);}
	T operator[](int i) const {return v1[i] + v2[i];}

private:
	const std::vector<T> &v1, &v2;	
};

template<typename T>
vector_sum<T> operator+(const std::vector<T>& x, const std::vector<T>& y){
	return {x,y};
}

int main(int argc, char const *argv[])
{
	std::vector<int> x{1,2,3,4,5,6}, y{1,2,3,4,5,6}, z{1,2,3,4,5,6};

	auto sum = x+y;
	for (int i = 0; i < 6; i++) std::cout<<sum[i]<<" ";

	return 0;
}
