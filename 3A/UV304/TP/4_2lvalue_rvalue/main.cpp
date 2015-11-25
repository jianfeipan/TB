#include <iostream>
#include "incremental.h"
using namespace std;

int main(int argc, char* argv[]){
	Incremental a;
	cout<<a.add3(a.add2(a.add1(2)))<<endl;

	//int b = 10;
	//cout<<a.add3(a.add2(a.add1(b)))<<endl;
	
	return 0;
}
