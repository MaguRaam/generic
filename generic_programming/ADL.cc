
#include <iostream>
//The swap uses copy constructor and assignment operator of type T
namespace magu{
	
	template<typename T>
	inline
	void swap(T& x, T& y){
		T tmp(x); //copy constuctor:
		x = y;
		y = tmp;
	}

}


template<typename T>
struct vector{
	friend inline void swap(vector& x,vector& y){
		magu::swap(x.size,y.size);
		magu::swap(x.data,y.data);
	}
private:
	unsigned int size;
	T* data;
};

template<typename T>
inline void func(T& x,T& y){
	using std::swap;
	swap(x,y);       //involves ADL
}


int main(){

	return 0;
}

//Addedndum: More efficient swap
/*template<typename T>
inline
void swap(T& x , T& y){
	T tmp(std::move(x));
	x = std::move(y);
	y = std::move(tmp);
}*/











