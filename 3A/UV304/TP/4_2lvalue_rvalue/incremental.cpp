#include "incremental.h"

int Incremental::add1(int value){
	
	return 1+value;
}

int Incremental::add2(int& value){
	return 1+value;
}

int Incremental::add3(const int& value){
	return 1+value;
}

