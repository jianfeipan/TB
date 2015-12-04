#include "Widget.h"

Widget::Widget(int _x=0,int _y=0){
	this->x=_x;
	this->y=_y;
}

void Widget::draw(){
	cout<< "Draw !" <<endl;
}

double Widget::getX() const{
	return x;	
}

double Widget::getY() const{
	return y;	
}

std::ostream& operator<< (std::ostream& flot, const Widget& w){
	flot<<"widget:("<<w.getX()<<","<<w.getY()<<")";
	return flot;
}
