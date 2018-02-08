#include "Array.h"

#include<cmath>
#include<ctime>

int main(int argc, char *argv[])
{
	int n = 10;
	srand(time(0));
	Array<int> *a = new Array<int>(n);
	for (int i=0; i<n; ++i)
		(*a)[i] = rand() % n;
	
	cout << (*a) << endl;
	
	
	a->reserve(20);
	(*a)[20] = 20;
	
	Pointer<int>pointer(*a, 20);
	
	
	cout << *pointer << endl;
	delete a;
	*pointer = 4;
	cout << *pointer << endl;
	
	return 0;
}