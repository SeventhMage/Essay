#include "Picture.h"

int main(int argc, char *argv[])
{
	char *str[] = {"Hi", "Hello", "How are you", "Haha"};
	Picture p1(str, 4);
	Picture p2 = frame(p1)&p1;
	
	cout << frame((p1&frame(p1))|p2) << endl;
	return 0;
}