#include <iostream>
#include <memory>
#include <algorithm>
#include <initializer_list>

template <typename T>
class vector
{
public:
	//constructor:
	explicit vector(int size) : my_size(size), data(new T[my_size]) {}

	//initializer list constructor:
	vector(std::initializer_list<T> values) : my_size(values.size()), data(new T[my_size])
	{
		std::move(std::begin(values), std::end(values), &data[0]);
	}

	//copy constructor:
	vector(const vector &that) : my_size(that.my_size), data(new T[my_size])
	{
		std::copy(&that.data[0], &that.data[that.my_size], &data[0]);
	}

	//assignment operator: takes arbirtary vector type:
	template <typename Src>
	vector &operator=(const Src &that)
	{
		for (int i = 0; i < my_size; ++i)
		{
			data[i] = that[i];
		}
		return *this;
	}

	//size
	int size() const { return my_size; }

	//read only access operator []
	const T &operator[](int i) const { return data[i]; }

	//access opeartor []
	T &operator[](int i) { return data[i]; }

	friend std::ostream &operator<<(std::ostream &os, const vector &v)
	{
		for (int i = 0; i < v.my_size; ++i)
			os << v[i] << " ";
		return os;
	}

private:
	int my_size;
	std::unique_ptr<T[]> data;
};

//Expression templates:

//sum_vector stores reference to two input vectors:
template <typename V1, typename V2>
class vector_sum
{
public:
	vector_sum(const V1 &v1, const V2 &v2) : v1(v1), v2(v2) {}

	//access operator returns sum of elements:
	auto operator[](int i) const
	{
		return v1[i] + v2[i];
	}

private:
	const V1 &v1;
	const V2 &v2;
};

//addition operator returns sum_vector:
template <typename V1, typename V2>
vector_sum<V1, V2> operator+(const V1 &v1, const V2 &v2)
{
	return {v1, v2};
}

//stores reference to scalar and a vector:
template <typename Scalar, typename Vector>
class scalar_product
{
public:
	scalar_product(const Scalar &a, const Vector &v) : a(a), v(v) {}

	//access operator returns sum of elements:
	auto operator[](int i) const
	{
		return a * v[i];
	}

private:
	const Scalar &a;
	const Vector &v;
};

//The scalar product operator:
template <typename Scalar, typename Vector>
scalar_product<Scalar, Vector> operator*(const Scalar &a, const Vector &v)
{
	return {a, v};
}

//Assignment Operator:



int main()
{
	vector<int> x{1, 2, 2, 3}, y(x), z(x);
	vector<int> ans{0, 0, 0, 0};
	ans = x + 100*y + z;

	std::cout << ans << std::endl;

	return 0;
}