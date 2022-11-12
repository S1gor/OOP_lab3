#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List<int>a;

	a.PushPos(20, 1);
	a.PushHead(90);
	a.PushTail(120);

	a.PrintList();
	a.PrintElem(2);

	return 0;
}