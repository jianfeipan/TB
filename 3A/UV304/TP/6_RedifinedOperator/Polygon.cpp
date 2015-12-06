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

Point& Polygon::getVertex_ref(int index){
	return pointTable[index];
}

Point Polygon::getVertex_copie(int index){
	return pointTable[index];
}

void Polygon::shift(double x, double y){
	for(int i=0;i<size;i++){
		pointTable[i].shift(x,y);
	}
}

void Polygon::shift(const Point& point){
	shift(point.getx(),point.gety());
}

void Polygon::operator+= (const Point& point){
	shift(point);
}

Point& Polygon::operator[] (int index){
	return getVertex_ref(index);
}