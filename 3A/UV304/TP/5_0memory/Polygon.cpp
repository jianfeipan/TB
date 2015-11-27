#include "Polygon.h"
#include <iostream>

using namespace std;

void Polygon::show(){
	cout<<"polygon :"<<endl;
	for(int i=0;i<size;i++){
		cout<<i<<" ";
		pointTable[i].show();
	}
}

void Polygon::setVertex(int index, const Point& pointDest){
	pointTable[index].moveTo(pointDest);
}


void Polygon::setVertex(int index, int x, int y){
	pointTable[index].moveTo(x,y);
}

Point& Polygon::getVertex1(int index){
	return pointTable[index];
}

Point Polygon::getVertex(int index){
	return pointTable[index];
}
