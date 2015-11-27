#include "incremental.h"
#include <iostream>
using namespace std;
/*int Incremental::add(int value){
	cout<<"int value"<<endl;
	return 1+value;
}*/

/*int Incremental::add(int& value) {
	cout<<"int& value"<<endl;
	return 1+value;
}*/

int Incremental::add(const int& value){
	cout<<"const int& value"<<endl;
	return 1+value;
}


/*int Incremental::add(int&& value){
	cout<<"int&& value"<<endl;
	return 1+value;
}*/


