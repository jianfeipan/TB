 #include "Point.h"
#include <iostream>
using namespace std;

int main(){
	Point c;
	c.show();

	cout<<"cout in main:"<<c.z<<endl;
	c.z = 2;
	cout<<"change z to 2, cout in main:"<<c.z<<endl;

	c.show();
	return 0;
}
