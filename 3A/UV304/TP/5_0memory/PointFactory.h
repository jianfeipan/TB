#include "Point.h"
#ifndef _POINTFACTORY_
#define _POINTFACTORY_
class PointFactory{
	private :
		int random();//-10 ~ 10
	public :

		PointFactory(){};
		~PointFactory(){};

		Point createPoint1();
};
#endif
