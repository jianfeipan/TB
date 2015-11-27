#include "incremental.h"

int Incremental::add1(int value){
	
	return 1+value;
} //rvalue ou lvalue

int Incremental::add2(int& value) {
	return 1+value;
} //lvalue

int Incremental::add3(const int& value){
	return 1+value;
}//rvalue ou lvalue (no modification)

int Incremental::add4(int&& value){
	return 1+value;
}//rvalue

int Incremental::add2_const(int& value) const{
	return 1+value;
};//lvalue
