#include "PointFactory.h"

using namespace std;


Point PointFactory::createPoint1(){
	Point p(random(),random());
	return p;
}

int PointFactory::random(){
	return rand()%20-10;
}

