#ifndef _MATRIX_
#define _MATRIX_
#include <iostream>
#include <iomanip>
using namespace std;
class Matrix{
	private :		
		int nbRow;
		int nbColumn;
		double** data;

	public :
		Matrix():Matrix(1,1){};
		Matrix(int a, int b);
		~Matrix();
		void print() const;
		double* operator() (int x, int y);//return null if index is wrong
};

#endif
