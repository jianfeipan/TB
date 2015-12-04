#include <iostream>
#include <string>
using namespace std;

template <typename T>
T mini(T a, T b){
	return a>b?b:a;
}

int main(){
	cout<< "min(1,2)"<<mini(1,2) <<endl;
	cout<< "min(1.2,2.3)"<<mini(1.2,2.3) <<endl;
	cout<< "min(1.2,2)"<<mini<double>(1.2,2) <<endl;
	cout<< "min(\"Z\",\"TITITI\")"<<min<string>("Z","TITITI") <<endl;
	return 0;
}

