#ifndef _POINT_HANDLE_H_
#define _POINT_HANDLE_H_

#include "UPoint.h"

class PointHandle
{
public:
	PointHandle();
	~PointHandle();
	PointHandle(int x, int y);
	PointHandle(const Point&);
	PointHandle(const PointHandle&);
	PointHandle& operator=(const PointHandle&);
	
	int x() const;
	PointHandle& x(int);
	int y() const;
	PointHandle& y(int);
private:
	UPoint* up;
};

#endif