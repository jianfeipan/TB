#ifndef _POINT_
#define _POINT_
class Point{
	private :
		int x;
		int y;

	public :

		Point(int _x, int _y){x=_x;y=_y;};
		Point(const Point& _p){x=_p.getx();y=_p.gety();};
		Point(){x=-1;y=-1;};
		~Point(){};

		int getx() const;
		int gety() const;

		void show() const;
		void shift(int _x, int _y);
		void moveTo(int _x, int _y);
		//void moveTo(Point _destination);
		void moveTo(Point* _destinationPointer);
		void moveTo(const Point& _destinationReference);
		void copyTo(Point& _target);
};
#endif
