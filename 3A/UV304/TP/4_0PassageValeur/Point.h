#ifndef _POINT_
#define _PoINT_
class Point{
	private :
		float x;
		float y;

	public :

		Point(const float _x, const float _y){x=_x;y=_y;};
		Point(){x=-1;y=-1;};
		~Point(){};

		float getx() const;
		float gety() const;

		void show() const;
		void shift(float _x, float _y);
		void moveTo(float _x, float _y);
		//void moveTo(Point _destination);
		void moveTo(Point* _destinationPointer);
		void moveTo(const Point& _destinationReference);
		void copyTo(Point& _target);
};
#endif
