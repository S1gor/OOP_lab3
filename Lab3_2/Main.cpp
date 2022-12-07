#include <iostream>
#include "List.h"

using namespace std;

struct X
{
	int x;
	float y;
	char z;

	friend std::ostream& operator<<(std::ostream& out, X const& X)
	{
		out << X.x << " " << X.y << " " << X.z;
		return out;
	}
};

int main()
{
	List<int> a;
	List<X> b;

	a.PushPos(20, 1);
	a.PushHead(90);
	a.PushTail(120);
	cout << a << endl;
	
	b.PushHead({ 1,2.7,'f' });
	cout << b;

	return 0;
}