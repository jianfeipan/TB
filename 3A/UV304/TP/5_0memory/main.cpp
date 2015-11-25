#include "PointFactory.h"
#include <iostream>
using namespace std;

int main(){
	PointFactory factory;
	Point c = factory.createPoint1();
	c.show();
	return 0;
}
