#pragma once

#include <cstdint>
#include <string>
#include <utility>


class Day
{
public:

	static Day& get()
	{
		static Day instance;
		return instance;
	}

	Day(const Day& day) = delete;
	void operator=(const Day& day) = delete;

	std::pair<uint8_t, uint8_t> getDayAndPart()
	{
		return { m_day, m_part };
	}

	void setDayAndPart(uint8_t day, uint8_t part)
	{
		m_day = day;
		m_part = part;
	}

private:
	Day() {}

	uint8_t m_day;
	uint8_t m_part;
};