#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List<int>a;
	a.pushList(10);
	a.pushList(20);
	a.pushList(2, 70);
	a.print();


	return 0;
}