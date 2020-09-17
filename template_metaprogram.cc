#include <iostream>

namespace meta
{

	//Constexpr function:
	constexpr int absolute(int N) 
	{
		return (N < 0) ? -N : N;
	}

	//Metafunction:
	template<int N>
	struct abs
	{ 
		static constexpr int value = (N < 0) ? -N : N; 
	};

	//compile time recursion:
	template<unsigned M, unsigned N>
	struct gcd
	{
		static constexpr int value = gcd<N,M%N>::value;
	};

	//specialization
	template<unsigned M>
	struct gcd<M,0>
	{
		static_assert(M != 0);
		static int constexpr value = M;
	};

	//Metafunction can take type as a parameter:
	template<typename T>
	struct rank
	{
		static constexpr size_t value = 0;
	};

	//partial specialzation:
	template<typename U, size_t N>
	struct rank<U[N]>
	{
		static constexpr size_t value = 1 + rank<U>::value;	
	};

	//Metafunction can give type as its results:
	template<typename T>
	struct remove_const
	{
		using type = T;
	};

	//Identity metafunction:
	template<typename T>
	struct type_is
	{
		using type = T;
	};

	template<typename T>
	struct remove_volatile : type_is<T>
	{
		
	};

}

	using namespace meta;

	int main()
	{
		remove_volatile<const int>::type a = 5;
		a = 6;

		return 0;
	}