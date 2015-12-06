#ifndef _WINDOW_
#define _WINDOW_
#include "..//Widget/Widget.h"
#include "..//Button/Button.h"
#include "..//Slider/Slider.h"
#include <iostream>

using namespace std;
class Window{
	private :
		Widget** widgets;
		int size;
	public :
		Window();
		Window(int n);
		~Window();

		int getSize();
		void init();
		void draw();
};
#endif
