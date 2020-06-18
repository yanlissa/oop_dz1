#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
	BitString b;
	BitString b0(1);
	BitString b32(0, 1);
	cout << b << endl;
	cout << b0 << endl;
	cout << b32 << endl;
	cout << ~b << endl;
	cout << ~b0 << endl;
	cout << (~b0 & b0) << endl;
	cout << (b32 | b0) << endl;
	cout << (b0 << 32) << endl;
	cout << (b0 << 32 == b32) << endl;

	Set s;
	cout << s << endl;
	s.add(1);
	cout << s << endl;
	s.add(5);
	s.add(3);
	cout << s << endl;
	s.remove(1);
	cout << s << endl;
	return 0;
}
