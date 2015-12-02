#include "PointFactory.h"
#include "Polygon.h"
//#include "Compare.h"
#include <iostream>
using namespace std;

struct Compare{

  bool operator()(const int &a, const int &b) const
  {
    return a < b;
  }
};



int main(){
	PointFactory factory;
	Point* points;	
	points = new Point[10];
	for (int i=0;i<10;i++){
		points[i] = factory.createPoint1();
		points[i].show();
	}
	Polygon ply(points,10);
	delete [] points;
	ply.show();

	ply.setVertex(1,factory.createPoint1());
	ply.show();

	ply.setVertex(2,0,0);
	ply.show();

	ply.shift(20,30);
	ply.show();
	
	ply+= (Point(20,30));
	ply.show();

	Point a(0,3);
	Point b(2,0);
	(a+b).show();
	cout<<a<<endl;

	points = new Point[2];
	points[0] = factory.createPoint1();
	points[1] = factory.createPoint1();

	cout<<"[] operator"<<endl;
	Polygon p2(points,2);
	p2.show();
	p2[0].show();
	p2[0].shift(1,1);
	p2.show();
	p2.getVertex_copie(0).show();
	p2.getVertex_copie(0).shift(1,1);	
    p2.show();
	auto compare = [] (int a, int b){return a<b;};
	cout<<compare(1,2)<<endl;
	cout<<compare(2,2)<<endl;
	return 0;
}
