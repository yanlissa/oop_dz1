#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
	BitString b;
	BitString b0(1);
	BitString b31(0, 1);
	cout << b << endl;
	cout << b0 << endl;
	cout << b31 << endl;
	cout << ~b << endl;
	cout << ~b0 << endl;
	cout << (~b0 & b0) << endl;
	cout << (b31 | b0) << endl;
	return 0;
}
