#include "IntVector.h"
int& IntVector::operator[] (int index){
	return v[index];
}
