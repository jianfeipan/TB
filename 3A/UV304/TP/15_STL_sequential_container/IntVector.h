#ifndef _INTVECTOR_
#define _INTVECTOR_
#include <vector>
class IntVector{
	private : 
		std::vector<int> v;
	public :
		IntVector():IntVector(1){};
		IntVector(int size){v=*(new std::vector<int>(size));};
		~IntVector(){};
		int& operator[] (int index);
};
#endif
