#include "Picture.h"
#include "PictureImp.h"

Picture::Picture()
{
	
}

Picture::Picture(const char* const* array, int n)
	:p(new StringPicture(array, n))
{
	
}

Picture::Picture(PictureNode* node)
	:p(node)
{
	
}

Picture::Picture(const Picture& pic)
	:p(pic.p)
{
	++pic.p->use;
}

Picture::~Picture()
{
	if (--p->use == 0)
	{
		delete p;
	}
}

Picture& Picture::operator=(const Picture& pic)
{
	++pic.p->use;
	if (--p->use == 0)
		delete p;
	p = pic.p;
	return *this;
}

int Picture::height()const
{
	return p->height();
}

int Picture::width()const
{
	return p->width();
}

void Picture::display(ostream& o, int row, int width)const
{
	p->display(o, row, width);
}

Picture frame(const Picture& pic)
{
	return new FramePicture(pic);
}

ostream& operator<<(ostream& os, const Picture& pic)
{
	int ht = pic.height();
	for (int i=0; i<ht; ++i)
	{
		pic.display(os, i, 0);
		os << endl;
	}
	return os;
}

Picture operator&(const Picture& t, const Picture& b)
{
	return new VCatPicture(t, b);
}

Picture operator|(const Picture& l, const Picture& r)
{
	return new HCatPicture(l, r);
}