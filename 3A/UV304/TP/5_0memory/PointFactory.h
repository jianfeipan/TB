#include "Point.h"
#ifndef _POINTFACTORY_
#define _POINTFACTORY_
#include <time.h>
#include <cstdlib>
class PointFactory{
	private :
		int random();//-10 ~ 10
	public :

		PointFactory(){	srand ( time(NULL) );};
		~PointFactory(){};

		Point createPoint1();
};
#endif
