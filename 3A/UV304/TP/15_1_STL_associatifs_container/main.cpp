#include "Point.h"
#include "PointFactory.h"
#include "./Slider/Slider.h"
#include "./Button/Button.h"
#include "./Widget/Widget.h"
#include "./Window/Window.h"
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
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

struct classcomp{
	bool operator() (const int& a, const int& b){
		return a>b;
	}
};

int main(){
	PointFactory pf;

	set<int> myset;


	// set some initial values:
	for (int i=1; i<5; ++i) myset.insert(i*3);    // set: 3 6 9 12
	myset.erase(2);
	myset.erase(3);
	for (int i=0; i<20; ++i)
	{
		cout << i<<":";
		cout << myset.count(i)<<endl;
	}	
	cout<< "set size :"<<myset.size()<<endl;
	
	auto it = myset.find(12);
	cout<<"if 12 is the end ?:"<<(it==myset.end())<<endl;

	for_each(myset.begin(),myset.end(),[](int x){cout<<x<<endl;});
	myset.insert(3);
	for_each(myset.begin(),myset.end(),[](int x){cout<<x<<endl;});
	
	set<int,classcomp> myset2={1,2,3,4,5,0};
	for_each(myset2.begin(),myset2.end(),[](int x){cout<<x<<endl;});

	map<char,int> intmap;
	intmap['a'] = 1;
	intmap['à'] = 2;
	intmap['d'] = 3;

	
	
	return 0;
}
