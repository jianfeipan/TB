#include "Point.h"
#include "DoublePoint.h"
#include "DoubleQuadrilater.h"
#include "ClassMin.h"
#include <iostream>
using namespace std;

int main(){
	Point<int> a;
	a[0] = 3;//[]ref
	cout<<a<<endl;//[]const
	Point<double> b;
	b[0] = 0.3;//[]ref
	cout<<b<<endl;//[]const
	b.add(a);//[]const
	cout<<a<<endl;//[]const
	a.add(b);//[]const
	cout<<a<<endl;//[]const

	Point<char> c;
	c[0] = 'A';
	cout<<c<<endl;
	cout<<a<<endl;
	c.add(a);
	cout<<c<<endl;

	Point<> d;
	cout<<d<<endl;


	DoublePoint<2> e;
	cout<<e<<endl;

	DoublePoint<> f;
	cout<<f<<endl;

	DoubleQuadrilater dq;
	cout<<dq<<endl;
	
	cout<< ClassMin<double>::min(1.9,2) <<endl;

	DoublePoint<> dp1;
	dp1[0] = 0.3;
	cout<<dp1<<endl;

	DoublePoint<> dp2;
	dp2[0] = 0.6;
	cout<<dp2<<endl;
	cout<<"comparation"<<endl;
	cout<< ClassMin<DoublePoint<>>::min(dp1,dp2) <<endl;
	
	return 0;
}
