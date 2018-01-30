#include <iostream>

#include "PointHandle.h"

int main(int argc, char *argv[])
{
	PointHandle h1(1, 2);
	PointHandle h2 = h1;
	h2.x(3);
	std::cout << h1.x() << std::endl;
	std::cout << h2.x() << std::endl;
	return 0;
}