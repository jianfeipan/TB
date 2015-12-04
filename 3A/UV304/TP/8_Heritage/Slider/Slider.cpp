#include "Slider.h"
#include <iostream>
using namespace std;
int Slider::getN(){
	return n;
}

void Slider::draw(){
	cout<< "slider : ";
	Widget::draw();
}

void Slider::draw(int i){
	cout<< i<<"#";
	draw();
}
