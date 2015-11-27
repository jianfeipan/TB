#include "Point.h"
#ifndef _POLYGON_
#define _POLYGON_
using namespace std;
class Polygon{
	private :
		Point* pointTable;	
		int size;	
	public :
		Polygon(Point* _pointTable,int _size){
			size = _size;
			pointTable = new Point[size];
			for(int i = 0; i<size; i++){
				pointTable[i] = _pointTable[i];
			}
		};
		~Polygon(){delete[] pointTable; };
		void show();
		void setVertex(int _index, const Point& _pointDest);	
		void setVertex(int _index, int _x, int _y);	
		Point& getVertex1(int _index);
		Point getVertex(int _index)
};
#endif
