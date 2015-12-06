#include "IntVector.h"
#include "Point.h"
#include "PointFactory.h"
#include "./Slider/Slider.h"
#include "./Button/Button.h"
#include "./Widget/Widget.h"
#include "./Window/Window.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void remplit(vector<int>& v){
	int i=0;
	for(vector<int>::iterator it=v.begin(); it!=v.end();++it){
		*it=i++;
	}

}

vector<int>::iterator select(vector<int>& v){
	return remove_if(v.begin(),v.end(),[] (int x){return x%5!=0;});
}

void compter(vector<int>& v){
	for(int i=0;i<=110;i++)
		cout<< v[i]<<endl;
}

int main(){
	PointFactory pf;
	IntVector a;
	cout<<a[0]<<endl;
	
	std::vector<Point> pvector {std::move(pf.createPoint1()),std::move(pf.createPoint1()),std::move(pf.createPoint1())};
	for(vector<Point>::iterator it=pvector.begin(); it!=pvector.end();++it)
		it->show();
	pvector.push_back(std::move(pf.createPoint1()));
	for(vector<Point>::iterator it=pvector.begin(); it!=pvector.end();++it)
		it->show();

	Button b;
	Slider s;
	b.draw();
	s.draw();
	std::vector<Widget*> widgets {&b,&s};//can not use Widget variable because it's an abstract class. so we use printor or ref (we cannot have list of ref, so we use pointer) 
	for(vector<Widget*>::iterator it=widgets.begin(); it!=widgets.end();++it)
		(*it)->draw();

	for(auto it=widgets.begin(); it!=widgets.end();++it)
		(*it)->draw();

	for(const auto& it:widgets)
		it->draw();

	std::vector<int> v(100); 
	remplit(v);
	auto end =select(v);
	for(vector<int>::iterator it=v.begin(); it!=end;++it){
		cout<<*it<<endl;
	}
	vector<int> myvector (7);
    copy ( v.begin(), v.begin()+7, myvector.begin() );

	for(vector<int>::iterator it=myvector.begin(); it!=myvector.end();++it){
		cout<<*it;
	}
	cout<<endl;

	for_each(myvector.begin(),myvector.end(),[] (int x){cout<< x; });

	cout <<*find_if(myvector.begin(),myvector.end(),[] (int x){return x>12;} );

	
	return 0;
}
