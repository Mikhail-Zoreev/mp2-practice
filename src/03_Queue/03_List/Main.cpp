#include "TList.h"

int main()
{
	TList<int, int> test;
	int* a = new int;
	*a = 100;
	test.InsertBackward(20, a);
	test.InsertBackward(10, a);
	test.InsertAfter(10, 5, a);
	test.Remove(5);
	return 0;
}