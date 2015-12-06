#include "Point.h"

#include <iostream>
using namespace std;

int Point::getx() const{
	return x;
}

int Point::gety() const{
	return y;
}

void Point::show() const{
	cout<<"("<<this->x<<","<<this->y<<")"<<endl;
}

void Point::shift(int _x,int _y){
	this->x += _x;
	this->y += _y;
}

void Point::moveTo(int _x,int _y){
	this->x = _x;
	this->y = _y;
}
/*
void Point::moveTo(Point dest){
	this->x = dest.getx();
	this->y = dest.gety();
}*/

void Point::moveTo(Point* destPointer){
	this->x = destPointer->getx();
	this->y = destPointer->gety();
}

void Point::moveTo(const Point& destReference){
	this->x = destReference.getx();
	this->y = destReference.gety();
}

void Point::copyTo(Point& target){//don't work beacause the target is a copy of original target instance 
	target.moveTo(this);
}

Point Point::operator+ (const Point& point){
	Point result(x+point.x,y+point.y);
	return result;
}

std::ostream& operator<< (std::ostream& flot, const Point& p){
	flot<<"("<<p.x<<","<<p.y<<")";
	return flot;
}
