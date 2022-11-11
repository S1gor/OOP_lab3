#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List<int>a;

	a.pushPos(20, 1);
	a.pushHead(90);
	a.pushTail(120);

	a.print();

	cout << a.getElement(2) << endl;


	return 0;
}