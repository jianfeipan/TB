#ifndef _WIDGET_
#define _WIDGET_
#include <iostream>
using namespace std;
class Widget{
	private :
		double x;
		double y;
	public :
		Widget(int x,int y);
	 	virtual ~Widget(){};	
		virtual void draw()=0;
		double getX() const;
		double getY() const;
};
std::ostream& operator<< (std::ostream& flotn, const Widget& w);
#endif
