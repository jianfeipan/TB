#include "Matrix.h"

#include <iostream>
using namespace std;

Matrix::Matrix(int a, int b){
	nbRow = a;
	nbColumn = b;
	data = new double*[nbRow];
	for (int i = 0; i < nbRow; i++){
		data[i] = new double[nbColumn];
		for(int j = 0; j< nbColumn;j++){
			data[i][j] = 0;
		}
	}
}

Matrix::~Matrix(){
	for (int i = 0; i < nbRow; i++){
		delete [] data[i];
	}
	delete [] data;
}

void Matrix::print() const{
	for(int i=0; i<nbRow;i++){
		for(int j = 0; j<nbColumn;j++){
			cout<<setfill (' ') << std::setw (10)<<data[i][j]<<" ";
		}
		cout<<endl;
	}	
}

double* Matrix::operator() (int x, int y){
	if(x<nbRow && y<nbColumn){
		return &data[x][y];
	}else{
		return NULL;
	}
}
