#include "Handle.h"
#include "Point.h"

#include <iostream>

int main(int argc, char *argv[])
{
	Handle<Point>h1;
	Handle<Point>h2 = h1;
	h2->x(3);
	
	std::cout << h1->x() << std::endl;
	std::cout << h2->x() << std::endl;
	return 0;
}