#ifndef _POINT_
#define _PoINT_
class Point{
	private :
		int x;
	protected :
		int y;
	public :
		int z;		
		
		Point(const int _x, const int _y, const int _z){x=_x;y=_y;z=_z;};
		Point(){x=-1;y=-1;z=-1;};
		~Point(){};
	
		void show();
};
#endif
