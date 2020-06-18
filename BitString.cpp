#include <bitset>
#include "BitString.h"

std::ostream& operator<< (std::ostream& out, const BitString& bs)
{
	out << std::bitset<32>(bs.m_data[1]) << std::bitset<32>(bs.m_data[0]);
	return out;
}
