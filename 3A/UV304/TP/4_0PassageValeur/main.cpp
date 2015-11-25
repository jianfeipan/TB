 #include "Point.h"
#include <iostream>
using namespace std;

int main(){
	Point c;
	c.show();

	c.shift(1.1,1.2);
	c.show();

	Point d;
	d.moveTo(10,12);
	d.show();

	d.moveTo(c);
	d.show();

	Point* pa = new Point(2,1);
	pa->show();
	pa->shift(1,1);
	pa->show();
	(*pa).show();
	d.moveTo(pa);
	cout<<"d moves to: "<<endl;
	d.show();
	delete pa;

	Point& ra=c;
	cout<<"ra: "<<endl;
	ra.show();
	cout<<"c: "<<endl;
	c.show();

	c.shift(1.1,1.2);
	cout<<"after c shifted"<<endl;
	cout<<"ra: "<<endl;
	ra.show();
	cout<<"c: "<<endl;
	c.show();

	ra.shift(1.1,1.2);
	cout<<"after ra shifted"<<endl;
	cout<<"ra: "<<endl;
	ra.show();
	cout<<"c: "<<endl;
	c.show();

	d.moveTo(ra);
	cout<<"d moves to: "<<endl;
	d.show();

	Point a(0,0);
	d.copyTo(a);
	cout<<"a : "<<endl;
	a.show();
	return 0;
}
