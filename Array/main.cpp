#include "Array.h"

#include<cmath>
#include<ctime>

int main(int argc, char *argv[])
{
	int n = 10;
	srand(time(0));
	Array<int>a(n);
	for (int i=0; i<n; ++i)
		a[i] = rand() % n;
	
	cout << a << endl;
	
	
	return 0;
}