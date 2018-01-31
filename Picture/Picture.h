#ifndef _PICTURE_H_
#define _PICTURE_H_

#include <iostream>

using namespace std;

class Picture
{
	friend ostream& operator<<(ostream&, const Picture&);
	friend Picture frame(const Picture&);
	friend Picture operator&(const Picture&, const Picture&);
	friend Picture operator|(const Picture&, const Picture&);
public:
	Picture();
	Picture(const char* const*, int);
	Picture(const Picture &);
	~Picture();
	
	Picture& operator=(const Picture&);
	
private:
	void init(int, int);
	void clear(int, int, int, int);
	char& position(int, int);
	char position(int, int) const;
	void copyblock(int, int, const Picture&);
	static int max(int, int);
private:
	char *data;
	int width;
	int height;
};

#endif