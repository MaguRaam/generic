//generic array summation:
template<typename InputIter,typename T>
inline T accumulate(InputIter it, InputIter end, T init){
	for (;it != end; ++it)
		init += *it;
	return init;
}		

//list class:
template<typename T>
struct list_entry{

	T value;
	list_entry<T>* next;	
};	


int main(){

	return 0;
}