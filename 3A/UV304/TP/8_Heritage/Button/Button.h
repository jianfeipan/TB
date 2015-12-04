#ifndef _BUTTON_
#define _BUTTON_
#include "../Widget/Widget.h"
class Button: public Widget{
	public: 
		Button():Widget(0,0){};
		Button(int _x, int _y):Widget(_x,_y){};
		~Button(){} ;
		void draw() override;
	
};
#endif
