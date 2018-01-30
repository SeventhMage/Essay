#include "UseCount.h"

UseCount::UseCount()
	:p(new int(1))
{
	
}

UseCount::UseCount(const UseCount &c)
	:p(c.p)
{
	++*p;
}

UseCount::~UseCount()
{
	if (--*p == 0)
	{
		delete p;
	}
}

bool UseCount::Reattach(const UseCount& c)
{
	++*c.p;
	if (--*p == 0)
	{
		delete p;
		p = c.p;
		return true;
	}
	
	p = c.p;
	return false;
}

UseCount& UseCount::operator=(const UseCount &c)
{	
	return *this;
}