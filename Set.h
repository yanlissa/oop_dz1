#pragma once
#include <ostream>

#include "BitString.h"

class Set
{
private:
	BitString m_data;
public:
	Set()
		:m_data(0, 0)
	{}

	Set(const Set& s)
		:m_data(s.m_data)
	{}

	Set& operator=(const Set& s)
	{
		m_data = s.m_data;
		return *this;
	}

	Set& add(unsigned int e)
	{
		if ((e) >= 64) {
			throw std::out_of_range("Set::add");
		}
		BitString bs1 = BitString(1, 0);
		m_data |= bs1 << e;

		return *this;
	}

	Set& remove(unsigned int e)
	{
		if ((e) >= 64) {
			throw std::out_of_range("Set::remove");
		}
		BitString bs1 = BitString(1, 0);
		m_data &= ~(bs1 << e);

		return *this;
	}

	Set& merge(const Set& s)
	{
		m_data |= s.m_data;
		return *this;
	}

	Set& intersect(const Set& s)
	{
		m_data &= s.m_data;
		return *this;
	}

	Set& subtract(const Set& s)
	{
		m_data &= ~(s.m_data);
		return *this;
	}

	std::size_t power() const
	{
		BitString bs(1);
		std::size_t power = 0;
		for (int i = 0; i < 64; i++) {
			if ((m_data & bs) == bs) {
				power++;
			}
			bs <<= 1;
		}
		return power;
	}

	bool is_empty() const
	{
		BitString bs(1);
		for (int i = 0; i < 64; i++) {
			if ((m_data & bs) == bs) {
				return false;
			}
			bs <<= 1;
		}
		return true;
	}

	friend std::ostream& operator <<(std::ostream& out, const Set& s);
};
