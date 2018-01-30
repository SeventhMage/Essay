#ifndef _HANDLE_H_
#define _HANDLE_H_

#include "UseCount.h"

template<typename T>
class Handle
{
public:
	Handle(T *t);
	Handle(const Handle&);
	~Handle();
	Handle& operator=(const Handle&);
	T* operator->();
private:
	T *p;
	UseCount c;
};

template<typename T>
Handle<T>::Handle(T *t)
	:p(t)
{
	
}

template<typename T>
Handle<T>::Handle(const Handle& h)
	:p(h.p), c(h.c)
{
	
}

template<typename T>
Handle<T>::~Handle()
{
	if (c.Only())
	{
		delete p;
	}
}

template<typename T>
Handle<T>& Handle<T>::operator=(const Handle<T>& h)
{
	if (c.Reattach(h.c)) //this use count equal 0
	{
		delete p;
	}
	
	p = h.p;
	
	return *this;
}

template<typename T>
T* Handle<T>::operator->()
{
	return p;
}

#endif