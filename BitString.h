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

	BitString& operator<<=(std::size_t t)
	{
		if (t < 32) {
			unsigned long u = m_data[0] >> (32 - t);
			m_data[0] <<= t;
			m_data[1] <<= t;
			m_data[1] |= u;
		} else {
			m_data[1] = m_data[0] << (t - 32);
			m_data[0] = 0;
		}
		return *this;
	}

	BitString& operator>>=(std::size_t t)
	{
		if (t < 32) {
			unsigned long u = m_data[1] << (32 - t);
			m_data[1] >>= t;
			m_data[0] >>= t;
			m_data[0] |= u;
		} else {
			m_data[0] = m_data[1] >> (t - 32);
			m_data[1] = 0;
		}
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


	friend BitString operator <<(const BitString& x, std::size_t t)
	{
		BitString result(x);
		result <<= t;
		return result;
	}

	friend BitString operator >>(const BitString& x, std::size_t t)
	{
		BitString result(x);
		result >>= t;
		return result;
	}

	friend std::ostream& operator <<(std::ostream& out, const BitString& bstr);
};
