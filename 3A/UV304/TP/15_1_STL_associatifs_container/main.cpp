#include "Point.h"
#include "PointFactory.h"
#include "./Slider/Slider.h"
#include "./Button/Button.h"
#include "./Widget/Widget.h"
#include "./Window/Window.h"
#include <iostream>
#include <algorithm>
#include <set>
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

	set<int> myset;

	// set some initial values:
	for (int i=1; i<5; ++i) myset.insert(i*3);    // set: 3 6 9 12
	myset.erase(2);
	myset.erase(3);
	for (int i=0; i<10; ++i)
	{
		cout << i<<":";
		cout << myset.count(i)<<endl;
	}	
	cout<< myset.size()<<endl;
	
	auto it = myset.find(9);
	cout<<(it==myset.end())<<endl;

	for_each(myset.begin(),myset.end(),[](int x){cout<<x<<endl;});
	myset.insert(1);
	for_each(myset.begin(),myset.end(),[](int x){cout<<x<<endl;});
	return 0;
}
