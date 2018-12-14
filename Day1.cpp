#include "Day1.h"

#include "Day.h"

#include <fstream>
#include <set>
#include <string>


namespace Day1
{
	int64_t part1()
	{
		Day::get().setDayAndPart(1, 1);

		int64_t result = 0;

		std::ifstream infile("Day1.txt");
		std::string line;

		while (getline(infile, line))
		{
			result += std::stoll(line);
		}

		return result;
	}

	int64_t part2()
	{
		Day::get().setDayAndPart(1, 2);

		int64_t current = 0;
		std::set<int64_t> frequencies;
		std::string line;

		while (true)
		{
			std::ifstream infile("Day1.txt");

			while (getline(infile, line))
			{
				current += std::stoll(line);
				if (!frequencies.insert(current).second)
				{
					return current;
				}
			}
		}
	}
}