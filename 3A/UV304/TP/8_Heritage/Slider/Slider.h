#ifndef _SLIDER_
#define _SLIDER_
#include "../Widget/Widget.h"
class Slider: public Widget{
	private: 
		int n;
	public: 
		Slider():Widget(0,0),n(0){};
		Slider(int _x, int _y, int _n):Widget(_x,_y),n(_n){};
		~Slider(){};
		int getN();
		void draw() override; 
		void draw(int i);
};
#endif
