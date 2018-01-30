#ifndef _POINT_H_
#define _POINT_H_

class Point
{
public:
	Point():_x(0), _y(0){}
	Point(int x, int y):_x(x), _y(y){}
	int x() const {return _x;}
	int y() const {return _y;}
	Point& x(int x) {_x = x; return *this;}
	Point& y(int y) {_y = y; return *this;}
private:
	int _x;
	int _y;
};

#endif