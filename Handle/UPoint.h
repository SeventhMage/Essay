#ifndef _UPOINT_H_
#define _UPOINT_H_

#include "Point.h"

class UPoint
{
	friend class PointHandle;
	Point p;
	int u;
	
	UPoint():u(1){}
	UPoint(int x, int y):p(x, y), u(1){}
	UPoint(const Point &p):p(p), u(1){}
};

#endif