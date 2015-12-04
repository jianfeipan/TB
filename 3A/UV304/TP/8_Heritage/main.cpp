#include "./Slider/Slider.h"
#include "./Button/Button.h"
#include "./Widget/Widget.h"
#include "./Window/Window.h"
#include <iostream>
using namespace std;

int main(){

	Button b;
	b.draw();

	Slider s;
	s.draw();
	s.draw(2);
	

	Widget* w2=&s;
	w2->draw();//Slider: Draw !

	Widget& w1=s;
	w1.draw();//Slider: Draw ! 
	
	cout<<s<<endl;
	
	Window a(3);
	a.init();
	a.draw();
}
