#include "Picture.h"

Picture::Picture()
	:data(nullptr), width(0), height(0)
{
	
}

Picture::Picture(const char* const* array, int n)
{
	int w = 0;
	
	for (int i=0; i<n; ++i)
	{
		w = max(w, strlen(array[i]));
	}
	init(w, n);
	
	for (int i=0; i<n; ++i)
	{
		const char* src = array[i];
		int len = strlen(src);
		int j = 0;
		while(j < len)
		{
			position(i, j) = src[j];
			++j;
		}
		while(j < width)
		{
			position(i, j) = ' ';
			++j;
		}
	}
}

Picture::Picture(const Picture& pic)
	:width(pic.width), height(pic.height), data(new char[pic.width * pic.height])
{
	copyblock(0, 0, pic);
}

Picture::~Picture()
{
	if (data)
	{
		delete[]data;
	}
}

Picture& Picture::operator=(const Picture& pic)
{
	if (this != &pic)
	{
		if (data)
			delete[]data;
		init(pic.width, pic.height);
		copyblock(0, 0, pic);
	}
	
	return *this;
}

void Picture::init(int w, int h)
{
	width = w;
	height = h;
	data = new char[w * h];
}

void Picture::clear(int r1, int c1, int r2, int c2)
{
	for (int i = r1; i<=r2; ++i)
	{
		for (int j=c1; j<=c2; ++j)
		{
			position(i, j) = ' ';
		}
	}
}

char& Picture::position(int row, int col)
{
	if (row < height && row >=0 && col < width && col >=0)
		return data[row * width + col];
	else
		throw "Error Picture.position";
}

char Picture::position(int row, int col) const
{
	if (row < height && row >=0 && col < width && col >=0)
		return data[row * width + col];
	else
		throw "Error Picture.position";	
}

void Picture::copyblock(int row, int col, const Picture& pic)
{
	for (int i=0; i<pic.height; ++i)
	{
		for (int j=0; j<pic.width; ++j)
		{
			position(i + row, j + col) = pic.position(i, j);
		}
	}
}

int Picture::max(int a, int b)
{
	return (a < b ? b : a);
}

ostream& operator<<(ostream& o, const Picture& pic)
{
	for (int i=0; i<pic.height; ++i)
	{
		for (int j=0; j<pic.width; ++j)
		{
			o << pic.position(i, j);
		}
		o << endl;
	}
	return o;
}

Picture frame(const Picture& pic)
{
	Picture r;
	r.init(pic.width + 2, pic.height + 2);
	for (int i=1; i<r.height-1; ++i)
	{
		r.position(i, 0) = '|';
		r.position(i, r.width - 1) = '|';
	}
	
	for (int i=1; i<r.width - 1; ++i)
	{
		r.position(0, i) = '-';
		r.position(r.height - 1, i) = '-';
	}
	
	r.position(0, 0) = '+';
	r.position(r.height - 1, 0) = '+';
	r.position(0, r.width - 1) = '+';
	r.position(r.height - 1, r.width - 1) = '+';
	
	r.copyblock(1, 1, pic);
	return r;
}

Picture operator&(const Picture& p1, const Picture& p2)
{
	Picture p3;
	p3.init(Picture::max(p1.width, p2.width), p1.height + p2.height);
	if (p1.width < p2.width)
		p3.clear(0, p1.width, p1.height - 1, p3.width - 1);
	else
		p3.clear(p1.height, p2.width, p3.height - 1, p3.width - 1);
	
	p3.copyblock(0, 0, p1);
	p3.copyblock(p1.height, 0, p2);
	
	return p3;
}

Picture operator|(const Picture& p1, const Picture& p2)
{
	Picture p3;
	p3.init(p1.width + p2.width, Picture::max(p1.height, p2.height));
	if (p1.height < p2.height)
		p3.clear(p1.height, 0, p3.height - 1, p1.width - 1);
	else
		p3.clear(p2.height, p1.width, p3.height - 1, p3.width - 1);
	p3.copyblock(0, 0, p1);
	p3.copyblock(0, p1.width, p2);
	
	return p3;
}
