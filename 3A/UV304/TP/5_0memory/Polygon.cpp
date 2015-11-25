#include "Polygon.h"


using namespace std;


Point Polygon::createPoint1(){
	srand ( time(NULL) );
	Point p(random(),random());
	return p;
}

int Polygon::random(){
	return rand()%20-10;
}

