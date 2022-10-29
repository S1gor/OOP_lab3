#include <iostream>

using namespace std;

template <class T>

T sum(T x, T y)
{
	return x + y;
}

int main()
{
	int a = 10, b = 15;

	cout << "Sum = " << sum(a, b) << endl;

	return 0;
}