#include "IntVector.h"
#include "Point.h"
#include "PointFactory.h"
#include "./Slider/Slider.h"
#include "./Button/Button.h"
#include "./Widget/Widget.h"
#include "./Window/Window.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
	PointFactory pf;
	IntVector a;
	cout<<a[0]<<endl;
	
	std::vector<Point> pvector {std::move(pf.createPoint1()),std::move(pf.createPoint1()),std::move(pf.createPoint1())};
	for(vector<Point>::iterator it=pvector.begin(); it!=pvector.end();++it)
		it->show();
	pvector.push_back(std::move(pf.createPoint1()));
	for(vector<Point>::iterator it=pvector.begin(); it!=pvector.end();++it)
		it->show();

	Button b;
	Slider s;
	b.draw();
	s.draw();
	std::vector<Widget*> widgets {&b,&s};//can not use Widget variable because it's an abstract class. so we use printor or ref (we cannot have list of ref, so we use pointer) 
	for(vector<Widget*>::iterator it=widgets.begin(); it!=widgets.end();++it)
		(*it)->draw();

	return 0;
}
