#ifndef _POINT_
#define _POINT_
#include <iostream>
using namespace std;
template <typename T=double, int N=1>
class Point{
	private:
		T v[N];
	public:
		Point();
		Point(const Point<T,N>& p);

		template <typename S> void add(const Point<S,N>& s);
		T& operator[] (int index);
		T operator[] (int index) const;			
};
#include "Point.tpp"
#endif

