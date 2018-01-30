#include <iostream>
#include "Automobile.h"


Vehicle* Automobile::Copy() const
{
	std::cout << "Automobile.Copy()" << std::endl;
	return new Automobile();
}

double Automobile::Weight() const
{
	return .0;
}

void Automobile::Start()
{
	std::cout << "Automobile.Start()" << std::endl;
}
