#ifndef _DOUBLEPOINT_
#define _DOUBLEPOINT_
#include "Point.h"
template <int N=1>
class DoublePoint:public Point<double,N>{
};

template <int N>
bool operator< (const DoublePoint<N>& p, const DoublePoint<N>& q) {
	double a=0;
	double b=0;
	for(int i=0; i<N; i++){
		a+=(p[i])*(p[i]);
		b+=(q[i])*(q[i]);
	}
	return a<b;
}
#endif
