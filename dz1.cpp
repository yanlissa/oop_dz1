#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
	BitString bx;
	BitString b0(1);
	BitString b32(0, 1);
	cout << bx << endl;
	cout << b0 << endl;
	cout << b32 << endl;
	cout << ~bx << endl;
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

	Set a, b;
	a.add(1);
	a.add(11);
	a.add(21);
	a.add(31);
	cout << "a = " << a << endl;
	b.add(7);
	b.add(14);
	b.add(21);
	b.add(28);
	cout << "b = " << b << endl;

	s = a;
	s.merge(b);
	cout << " a ∪ b = " << s << endl;
	cout << "|a ∪ b|= " << s.power() << endl;

	s = a;
	s.intersect(b);
	cout << " a ∩ b = " << s << endl;
	cout << "|a ∩ b|= " << s.power()<< endl;

	s = a;
	s.subtract(b);
	cout << " a - b = " << s << endl;
	cout << "|a - b|= " << s.power() << endl;

	cout << "a " << (a.is_empty() ? "=" : "≠") << " ∅ \n";
	s = a;
	s.subtract(s);
	cout << "a - a " << (s.is_empty() ? "=" : "≠") << " ∅ \n";
	return 0;
}
