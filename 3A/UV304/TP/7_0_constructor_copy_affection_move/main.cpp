#include "PointFactory.h"
#include "Polygon.h"
//#include "Compare.h"
#include <iostream>
using namespace std;

int main(){
	Point a;
	Point b(a);
	a.show();
	b.show();
	
	Point* points = new Point[2];
	points[1].show();
	points[0].moveTo(1,1);
	points[0].show();

	Polygon pol(points, 2);
	pol.show();
	pol.showMemory();

	cout<< "Polygon pol2 = pol:" <<endl;
	Polygon pol2=pol;
	pol2.show();
	pol2.showMemory();
	cout<< "modify pol:" <<endl;
	pol[1].moveTo(1,0);
	pol.show();
	pol.showMemory();
	
    cout<< "pol2 = pol:" <<endl;
	pol2=pol;// copy-constructor is called ????? why ??? 
	pol2.show();
	pol2.showMemory();

	cout<< "pol2 = pol2:" <<endl;
	pol2=pol2;
	
    cout<< "pol_Moved(move(pol)):" <<endl;
	Polygon pol_Moved(move(pol)); //only this way to call move constructor? ---> result is not right : 
	pol.show();
	pol.showMemory();
	pol_Moved.show();
	pol_Moved.showMemory();
		
	cout<< "pol_Moved(pol&&):" <<endl;
	Polygon pol_assigned(move(pol));
	pol.show();
	pol.showMemory();
	pol_assigned.show();
	pol_assigned.showMemory();

	
	
	return 0;
}
