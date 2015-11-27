#include "PointFactory.h"
#include "Polygon.h"
#include <iostream>
using namespace std;

int main(){
	PointFactory factory;
	Point* points;	
	points = new Point[10];
	for (int i=0;i<10;i++){
		points[i] = factory.createPoint1();
		points[i].show();
	}
	Polygon ply(points,10);
	delete [] points;
	ply.show();

	ply.setVertex(1,factory.createPoint1());
	ply.show();

	ply.setVertex(2,0,0);
	ply.show();
	return 0;
}
