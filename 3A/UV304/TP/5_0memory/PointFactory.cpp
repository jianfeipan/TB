#include "PointFactory.h"
#include <cstdlib>
#include <time.h>

using namespace std;


Point PointFactory::createPoint1(){
	srand ( time(NULL) );
	Point p(random(),random());
	return p;
}

int PointFactory::random(){
	return rand()%20-10;
}

