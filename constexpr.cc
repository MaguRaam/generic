#include <iostream>
#include <cmath>


//compile time containers:
template<typename T, std::size_t N>
class array{
private:
	constexpr static std::size_t size_ = N;
	T data_[N]{};
public:
	constexpr std::size_t size() const {return N;}
	constexpr T& operator[](std::size_t i){return data_[i];}
	constexpr const T& operator[](std::size_t i) const {return data_[i];}

	//iterator:
	using iterator = T*;
	constexpr iterator begin() {return &data_[0];}
	constexpr iterator end()   {return &data_[N];}
 	
};

template<typename T>
constexpr auto constexpr_sin(T value){
	return sin(value);
}

template<typename T, std::size_t N>
constexpr auto generate_sine()
{
	array<T,N> ret;
	constexpr T pi = 3.14;
	for (int i = 0; i<N; i+=1){
		T f = i;
		ret[i] = constexpr_sin(f*2*pi/N);	
	}
	return ret;
}

constexpr float sine_lookup(std::size_t i)
{
	constexpr auto table = generate_sine<float,256>();
	if (i >= table.size()){
		throw std::out_of_range("Index too big");	
	}
	return table[i];
}



int main()
{	 
		constexpr float f2 = sine_lookup(200);
		
		return 0;
}
