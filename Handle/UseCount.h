#ifndef _USE_COUNT_H_
#define _USE_COUNT_H_

class UseCount
{
public:
	UseCount();
	UseCount(const UseCount &c);
	~UseCount();
	
	bool Reattach(const UseCount&);
	bool Only(){return (*p == 1);}
	int  Count() {return *p;}
private:
	UseCount& operator=(const UseCount &c);
private:
	int *p;
};

#endif