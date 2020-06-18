#include "Set.h"

std::ostream& operator<< (std::ostream& out, const Set& s)
{
	out << "{";
	BitString bs(1);
	bool empty = true;
	for (int i = 0; i < 64; i++) {
		if ((s.m_data & bs) == bs) {
			if (!empty) {
				out << ",";
			}
			out << i;
			empty = false;
		}
		bs <<= 1;
	}
	out << "}";
	return out;
}
