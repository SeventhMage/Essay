#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>

using namespace std;

template<typename T>
class Array
{
public:
	Array():data(nullptr), size(0){}
	Array(unsigned size):data(new T[size]), sz(size) {}
	~Array(){ if (data) delete data; }
	
	const T& operator[](unsigned n)const
	{
		if (n >= sz || data == nullptr)
			throw "Array subscript out of range.";
		return data[n];
	}
	T& operator[](unsigned n)
	{
		if (n >= sz || data == nullptr)
			throw "Array subscript out of range.";
		return data[n];	
	}
	
	unsigned size() const { return sz; }
	
	
	friend ostream& operator<<(ostream& os, const Array<T>& array)
	{
		unsigned sz = array.size();
		for (unsigned i=0; i<sz; ++i)
		{
			os << array[i];
			if (i < sz - 1)
				os << ",";
		}
		return os;
	}
private:
	Array(const Array&);
	Array& operator=(const Array&);
	T* data;
	unsigned sz;
};


#endif