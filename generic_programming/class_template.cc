#include <memory>
#include <algorithm>

struct row_major{};
struct col_major{};
struct heap{};
struct stack{};

template<typename T = double,typename Orientation = row_major,typename Memory = heap>
class vector{
public:
	
	explicit vector(int size) : my_size(size), data(new T[my_size]){}
	
	vector(const vector& that) : my_size(that.size), data(new T[my_size]){
		std::copy(&that[0],&that[my_size],data);
	}

	const T& operator[](int i) const{
		return data[i];
	}

	int size() const {
		return my_size;
	}

private:
	int my_size;
	std::unique_ptr<T[]> data;
};

template<typename T,typename U = T>
struct pair{};


int main(){

	vector<int,col_major,stack> v(10);
	vector<int,col_major> w(5);
	vector<>   x(5);
	pair<int,float> p;
	pair<int> q;
	return 0;
}