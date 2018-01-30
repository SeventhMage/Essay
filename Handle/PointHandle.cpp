#include "PointHandle.h"

PointHandle::PointHandle()
	:up(new UPoint())
{
	
}

PointHandle::~PointHandle()
{
	if (--up->u == 0)
		delete up;
}

PointHandle::PointHandle(int x, int y)
	:up(new UPoint(x, y))
{
	
}

PointHandle::PointHandle(const Point& p)
	:up(new UPoint(p))
{
	
}

PointHandle::PointHandle(const PointHandle &h)
	:up(h.up)
{
	++up->u;
}

PointHandle& PointHandle::operator=(const PointHandle &h)
{
	if (this != &h)
	{
		if (--up->u == 0)
		{
			delete up;
		}
		
		up = h.up;
		++up->u;
	}
	
	// ++h.up->u;
	// if (--up->u == 0)
	// {
		// delete up;
	// }
	// up = h->up;
	
	return *this;
}

int PointHandle::x() const
{
	return up->p.x();
}

int PointHandle::y() const
{
	return up->p.y();
}


PointHandle& PointHandle::x(int x)
{
	//copy on write
	//this is the value copy, it's pointer copy if don't have this
	if (up->u != 1)
	{
		--up->u;
		up = new UPoint(up->p);
	}
	//
	
	up->p.x(x);
	return *this;
}

PointHandle& PointHandle::y(int y)
{
	//copy on write
	//this is the value copy
	if (up->u != 1)
	{
		--up->u;
		up = new UPoint(up->p);
	}
	
	up->p.y(y);
	return *this;
}
