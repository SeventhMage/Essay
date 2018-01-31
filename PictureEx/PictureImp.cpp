#include "PictureImp.h"

static int max(int x, int y) { return (x < y ? y : x); }

static void pad(ostream& os, int begin, int end)
{
	for (int i=begin; i< end; ++i)
	{
		os << " ";
	}
}

PictureNode::PictureNode()
	:use(1)
{
	
}

StringPicture::StringPicture(const char* const* array, int n)
	:data(new char*[n]), size(n)
{
	for (int i=0; i<n; ++i)
	{
		data[i] = new char[strlen(array[i]) + 1];
		strcpy(data[i], array[i]);
	}
}

StringPicture::~StringPicture()
{
	for (int i=0; i<size; ++i)
	{
		delete[]data[i];
	}
	delete[]data;
}

int StringPicture::width()const
{
	int n = 0;
	for (int i=0; i<size; ++i)
	{
		n = max(n, strlen(data[i]));
	}
	return n;
}

int StringPicture::height()const
{
	return size;
}

void StringPicture::display(ostream& os, int row, int width) const
{
	int start = 0;
	if (row >= 0 && row < height())
	{
		os << data[row];
		start = strlen(data[row]);
	}
	pad(os, start, width);
}

FramePicture::FramePicture(const Picture& pic)
	:p(pic)
{
	
}

int FramePicture::width()const
{
	return p.width() + 2;
}

int FramePicture::height() const
{
	return p.height() + 2;
}

void FramePicture::display(ostream& os, int row, int width) const
{
	if (row < 0 || row > height())
	{
		pad(os, 0, width);
	}
	else
	{
		if (row == 0 || row == height() - 1)
		{
			os << "+";
			int i = p.width();
			while(--i >= 0)
				os << "-";
			os << "+";
		}
		else
		{
			os << "|";
			p.display(os, row - 1, p.width());
			os << "|";
		}
		pad(os, this->width(), width);
	}
}

VCatPicture::VCatPicture(const Picture& t, const Picture& b)
	:top(t), bottom(b)
{
	
}

int VCatPicture::width()const
{
	return max(top.width(), bottom.width());
}

int VCatPicture::height()const
{
	return (top.height() + bottom.height());
}

void VCatPicture::display(ostream& os, int row, int width) const
{
	if (row >= 0 && row <top.height())
	{
		top.display(os, row, width);
	}
	else if (row < this->height())
	{
		bottom.display(os, row - top.height(), width);
	}
	else
	{
		pad(os, 0, width);
	}
}

HCatPicture::HCatPicture(const Picture& l, const Picture& r)
	:left(l), right(r)
{
	
}

int HCatPicture::width()const
{
	return left.width() + right.width();
}

int HCatPicture::height()const
{
	return max(left.height(), right.height());
}

void HCatPicture::display(ostream& os, int row, int width) const
{
	left.display(os, row, left.width());
	right.display(os, row, right.width());
	pad(os, this->width(), width);
}