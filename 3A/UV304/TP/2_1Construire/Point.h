#ifndef _POINT_
#define _PoINT_
class Point{
	private :
		int x;
	public :
		Point(int _x){x=_x;};
		Point(){x=-1;};
		~Point(){};
	
		void show();
};
#endif
