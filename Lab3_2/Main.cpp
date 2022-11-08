#include <iostream>
#include "List.h"

int main()
{
	List<int>a;
	a.pushList(10);
	a.pushList(20);
	a.pushList(1, 70);
	a.print();


	return 0;
}