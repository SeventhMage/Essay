#ifndef _PICTURE_IMP_H_
#define _PICTURE_IMP_H_

#include "Picture.h"

class PictureNode
{
	friend class Picture;
protected:
	PictureNode();
	virtual~PictureNode(){}
	virtual int height() const = 0;
	virtual int width() const = 0;
	virtual void display(ostream&, int, int) const = 0;
	
private:
	int use;
};

class StringPicture : public PictureNode
{
	friend class Picture;
	friend class Picture;
	StringPicture(const char* const*, int);
	~StringPicture();
	int height() const;
	int width() const;
	void display(ostream&, int, int) const;
	char **data;
	int size;
};

class FramePicture : public PictureNode
{	
	friend class Picture;
	friend Picture frame(const Picture&);
	FramePicture(const Picture&);
	int height() const;
	int width() const;
	void display(ostream&, int, int) const;
	Picture p;
};

class VCatPicture : public PictureNode
{
	friend class Picture;
	friend Picture operator&(const Picture&, const Picture&);
	VCatPicture(const Picture&, const Picture&);
	int height() const;
	int width() const;
	void display(ostream&, int, int) const;
	Picture top;
	Picture bottom;
};

class HCatPicture : public PictureNode
{
	friend class Picture;
	friend Picture operator|(const Picture&, const Picture&);
	HCatPicture(const Picture&, const Picture&);
	virtual int height() const;
	virtual int width() const;
	virtual void display(ostream&, int, int) const;
	Picture left;
	Picture right;
};

#endif