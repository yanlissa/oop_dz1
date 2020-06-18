#pragma once
#include <iostream>

class BitString
{
private:
	unsigned long m_data[2];
public:
	BitString(unsigned long low = 0, unsigned long high = 0)
	{
		m_data[0] = low;
		m_data[1] = high;
	}

	BitString(const BitString& bstr)
	{
		m_data[0] = bstr.m_data[0];
		m_data[1] = bstr.m_data[1];
	}

	BitString& operator=(const BitString& bstr)
	{
		m_data[0] = bstr.m_data[0];
		m_data[1] = bstr.m_data[1];
		return *this;
	}

	BitString& operator&=(const BitString& bstr)
	{
		m_data[0] &= bstr.m_data[0];
		m_data[1] &= bstr.m_data[1];
		return *this;
	}

	BitString& operator|=(const BitString& bstr)
	{
		m_data[0] |= bstr.m_data[0];
		m_data[1] |= bstr.m_data[1];
		return *this;
	}

	BitString& operator^=(const BitString& bstr)
	{
		m_data[0] ^= bstr.m_data[0];
		m_data[1] ^= bstr.m_data[1];
		return *this;
	}

	BitString operator~()
	{
		BitString result;
		result.m_data[0] = ~m_data[0];
		result.m_data[1] = ~m_data[1];
		return result;
	}

	friend BitString operator &(const BitString& x, const BitString& y)
	{
		BitString result(x);
		result &= y;
		return result;
	}

	friend BitString operator |(const BitString& x, const BitString& y)
	{
		BitString result(x);
		result |= y;
		return result;
	}

	friend BitString operator ^(const BitString& x, const BitString& y)
	{
		BitString result(x);
		result ^= y;
		return result;
	}

	friend std::ostream& operator <<(std::ostream& out, const BitString& bstr);
};
