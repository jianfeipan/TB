#ifndef _INCREMENTAL_
#define _INCREMENTAL_
class Incremental{
	public :
		Incremental(){};
		~Incremental(){};

		int add1(int _v);
		int add2(int& _v);
		int add3(const int& _v);
};
#endif

