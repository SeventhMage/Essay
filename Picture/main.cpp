#include "Picture.h"

int main(int argc, char *argv[])
{
	char* init[] = {"Hi", "World", "Hahaha"};
	Picture pic1(init, 3);
	cout << pic1 << endl;
	Picture pic2 = frame(pic1);
	
	Picture pic3 = pic1&pic2;
	Picture pic4 = frame(pic3|pic1|pic2&pic2);
	
	cout << pic3 << endl;
	cout << pic4 << endl;
	return 0;
}