#ifndef _POLYGON_
#define _POLYGON_
#include "Point.h"
#include <iostream>
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
		Polygon(const Polygon& _poly ):Polygon(_poly.pointTable,_poly.size){cout<< "by polygon's copy-constructor" <<endl;};
		Polygon(Polygon&& other):pointTable(move(other.pointTable)),size(move(other.size)){cout<< "by polygon's move-constructor" <<endl;};
		~Polygon(){delete[] pointTable; };
		void show();
		void setVertex(int _index, const Point& _pointDest);	
		void setVertex(int _index, int _x, int _y);	
		Point& getVertex_ref(int _index);
		Point getVertex_copie(int _index);
		void shift(double x, double y);
		void shift(const Point& point);
		void operator+= (const Point& point);
		void showMemory();
		Point& operator[] (int index);
		void operator= (const Polygon& p);
		/*Polygon(Polygon&& other){
			std::swap(pointTable, other.pointTable);
       		std::swap(size, other.size);
			cout<< "by polygon's assignment-constructor" <<endl;
        	return *this;
		};*/

};
#endif
