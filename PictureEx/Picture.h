#ifndef _PICTURE_H_
#define _PICTURE_H_

#include <iostream>
using namespace std;

class PictureNode;
class Picture
{
	friend ostream& operator<<(ostream&, const Picture&);
	friend Picture frame(const Picture&);
	friend Picture operator&(const Picture&, const Picture&);
	friend Picture operator|(const Picture&, const Picture&);
	friend class StringPicture;
	friend class FramePicture;
	friend class VCatPicture;
	friend class HCatPicture;
public:
	Picture();
	Picture(const char* const*, int);
	Picture(const Picture&);
	~Picture();
	
	Picture& operator=(const Picture&);
private:
	Picture(PictureNode*);
	int height()const;
	int width()const;
	void display(ostream&, int, int)const;
private:
	PictureNode* p;
};

#endif