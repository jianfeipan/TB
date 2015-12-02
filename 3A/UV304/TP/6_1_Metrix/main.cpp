#include "Matrix.h"
#include <iostream>

using namespace std;

int main(){
	Matrix m;
	m.print();	

	Matrix m1(2,3);
	m1.print();
	
	*m1(0,0) = 1;
	*m1(1,0) = 2;
	*m1(0,1) = 3;
	m1.print();

	const Matrix mc;
	//mc(0,0)++;
	mc.print();
	return 0;
}
