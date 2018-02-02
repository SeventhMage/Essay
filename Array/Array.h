#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>

using namespace std;

template<typename T>
class ArrayData
{
	friend class Array;
	
	ArrayData():use(1), data(nullptr), sz(0){}
	ArrayData(unsigned size):use(1), data(new T[size]), sz(size) {}
	ArrayData(const ArrayData& ad)
		:use(1), data(new T[ad.sz]), sz(ad.sz)
	{	
		strcpy(data, ad.data);
	}
	~ArrayData(){ if (data) delete data; }
	
	T& operator[](unsigned n)
	{
		if (data == nullptr || n >= sz)
			throw "Out of Range";
		return data[n];
	}
	
	const T& operator[](unsigned n) const
	{
		if (data == nullptr || n >= sz)
			throw "Out of Range";
		return data[n];		
	}
	
	ArrayData& operator=(const ArrayData&);
	
	T* data;
	unsigned sz;
	unsigned use;
}

template<typename T>
class Array
{
public:
	Array():data(nullptr){}
	Array(unsigned size):data(new ArrayData(size){}
	Array(const Array& array)
		:data(array.data)
	{
		if (data)
		{
			++data.use;
		}
	}
	~Array()
	{
		if (data && --data.use == 0)
		{
			delete data;
		}
	}
	
	Array& operator=(const Array& array)
	{
		if (&array != this)
		{
			if (array.data)
			{
				++array.data;
			}
			
			if (data && --data.use == 0)
			{
				delete data;
			}
			
			data = array.data;
		}
		
		return *this;
	}
	
	T& operator[](unsigned n)
	{
		if (!data)
			throw "Out of range";
		return data[n];
	}
	
	const T& operator[](unsigned n) const
	{
		if (!data)
			throw "Out of range";
		return data[n];		
	}
	
private:
	ArrayData *data;
};

template<typename T>
class Pointer
{
public:
	Pointer(const Array<T> &array, unsigned n = 0) : array(array), sub(n){}
private:
	Array<T> array;
	unsigned sub;
	
}


#endif