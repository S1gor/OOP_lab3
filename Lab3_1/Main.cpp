#include <iostream>
#include "Vector.h"

using namespace std;
	
int main()
{
	Vector<float> v1(9, 15, 20);
	cout << v1 << endl;

	Vector<float> v2(10.3, 20.8, 17.5);
	cout << v2 << endl;

	cout << v1 + v2 << endl;


	return 0;
}