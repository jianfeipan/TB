#include <iostream>
#include "incremental.h"
using namespace std;

int main(int argc, char* argv[]){
	Incremental a;
	cout<<" add rvalue "<<a.add(2)<<endl;
	int i =1;	
	int& ri = i;
	cout<<" add rvalue ref ri : "<<a.add(ri)<<endl;
	const int ci = 3;
	cout<<" add rvalue ref ri: "<<a.add(ci)<<endl;
}
