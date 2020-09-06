#include <iostream>
#include <fstream>

using namespace std;

struct cannot_open_file{};

//Throwing:
void read_matrix(const char* fname){
	fstream f(fname);
	if (!f.is_open()) throw cannot_open_file{};
}




int main(int argc, char const *argv[])
{
	//Catching:
	try{
		read_matrix("file.dat");
	} catch (cannot_open_file& e){
		cerr<<"your file doesnot exists! I am out\n";
		throw e;
	}

	return 0;
}
