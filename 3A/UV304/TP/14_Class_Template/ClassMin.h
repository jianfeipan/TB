#ifndef _CLASSMIN_
#define _CLASSMIN_
#include "Point.h"
template <typename T>
class ClassMin{
	public:
		static T min(T a, T b);
};
#include "ClassMin.tpp"
#endif
