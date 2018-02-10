#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>

using namespace std;

template<typename T>
class ConstPointer;

template<typename T>
class Pointer;

template<typename T>
class Array;

template<typename T>
class ArrayData
{
	friend class Array<T>;
	friend class ConstPointer<T>;
	friend class Pointer<T>;
	friend ostream& operator<<(ostream& os, const Array<T>& array);
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
	
	void resize(unsigned n)
	{
		if (n == sz) return;
		T* ndata = new T[n];
		memcpy(ndata, data, n * sizeof(T));
		delete data;
		data = ndata;
		sz = n;
	}
	
	void grow(unsigned newSize)
	{
		unsigned nsz = sz;
		if (nsz == 0)
			nsz = 1;
		while (nsz < newSize)
			nsz *= 1.5f;
		resize(nsz);
	}
	
	ArrayData& operator=(const ArrayData&);
	
	T* data;
	unsigned sz;
	unsigned use;
};

template<typename T>
class Array
{
	friend class ConstPointer<T>;
public:
	Array():data(0){}
	Array(unsigned size):data(new ArrayData<T>(size)){}
	Array(const Array<T>& array)
		:data(array.data)
	{
		if (data)
		{
			++data->use;
		}
	}
	~Array()
	{
		if (data && --data->use == 0)
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
			
			if (data && --data->use == 0)
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
		return (*data)[n];
	}
	
	const T& operator[](unsigned n) const
	{
		if (!data)
			throw "Out of range";
		return data[n];		
	}
	
	void resize(unsigned n)
	{
		if (data)
			data->resize(n);
		else
			data = new ArrayData<T>(n);
	}
	
	void reserve(unsigned newSize)
	{
		if (newSize >= data->sz)
			data->grow(newSize);
	}
	
	friend ostream& operator<<(ostream& os, const Array<T>& array)
	{
		if (array.data)
		{
			for (unsigned i=0; i<array.data->sz; ++i)
			{	
				os << (*array.data)[i];
				if (i != array.data->sz - 1)
					os << ",";
			}				
		}
		
		return os;
	}
	
private:
	ArrayData<T> *data;
};

template<typename T>
class ConstPointer
{
public:
	ConstPointer(const Array<T>& array, unsigned n = 0)
		:data(array.data), sub(n)
	{
		++data->use;
	}
	ConstPointer():data(nullptr), sub(0){}
	ConstPointer(const ConstPointer<T>& ptr)
		:data(ptr.data), sub(ptr.sub)
	{
		if (data)
			++data->use;
	}
	~ConstPointer()
	{
		if (data && --data->use == 0)
		{
			delete data;
		}
	}
	
	ConstPointer& operator=(const ConstPointer<T>& ptr)
	{
		if (ptr.data)
			++ptr.data->use;
		if (data && --data->use)
			delete data;
		data = ptr.data;
		sub = ptr.sub;
		
		return *this;
	}
	
	const T& operator*() const
	{
		if (data == nullptr)
			throw "Out of Range";
		return (*data)[sub];
	}
	
	ConstPointer& operator++()
	{
		++sub;
		return *this;
	}
	
	ConstPointer operator++(int)
	{
		ConstPointer pt = *this;
		++sub;
		return pt;
	}
	
	ConstPointer& operator--()
	{
		--sub;
		return *this;
	}
	
	ConstPointer operator--(int)
	{
		ConstPointer pt = *this;
		--sub;
		return pt;
	}
	
	ConstPointer& operator+=(int n)
	{
		sub += n;
		return *this;
	}
	
	ConstPointer& operator-=(int n)
	{
		sub -= n;
		return *this;
	}
	
	friend int operator-(const ConstPointer<T>& op1, const ConstPointer<T>& op2)
	{
		return (op1.sub - op2.sub);
	}
	
protected:
	ArrayData<T>* data;
	unsigned sub;
};

template<typename T>
class Pointer : public ConstPointer<T>
{
public:
	Pointer(const Array<T> &array, unsigned n = 0) : ConstPointer(array, n){}
	Pointer(){}
	T& operator*() const
	{
		if (data == nullptr)
			throw "Out of Range";
		return (*data)[sub];
	}
	
	Pointer& operator++()
	{
		++sub;
		return *this;
	}
	
	Pointer operator++(int)
	{
		Pointer pt = *this;
		++sub;
		return pt;
	}
	
	Pointer& operator--()
	{
		--sub;
		return *this;
	}
	
	Pointer operator--(int)
	{
		Pointer pt = *this;
		--sub;
		return pt;
	}
	
	Pointer& operator+=(int n)
	{
		sub += n;
		return *this;
	}
	
	Pointer& operator-=(int n)
	{
		sub -= n;
		return *this;
	}
	
	friend Pointer<T> operator+(int n, const Pointer<T>& p)
	{
		Pointer<T> ret = p;
		return (ret += n);
	}
	
	friend Pointer<T> operator+(const Pointer<T>& p, int n)
	{
		Pointer<T> ret = p;
		return (ret += n);
	}
};


#endif