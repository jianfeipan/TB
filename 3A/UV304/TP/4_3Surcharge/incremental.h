#ifndef _INCREMENTAL_
#define _INCREMENTAL_
class Incremental{
	public :
		Incremental(){};
		~Incremental(){};

		//int add(int _v);
		//int add(int& _v) ;
		int add(const int& _v);
		//int add(int&& _v);
};
#endif

