#include "Day2.h"

#include "Day.h"

#include <array>
#include <fstream>
#include <string>
#include <vector>


namespace Day2
{
	int64_t part1()
	{
		Day::get().setDayAndPart(2, 1);

		std::array<uint8_t, 26> letterCount;
		uint8_t twoTimes = 0;
		uint8_t threeTimes = 0;

		std::ifstream infile("Day2.txt");
		std::string line;

		while (getline(infile, line))
		{
			letterCount.fill(0);
			
			for (const auto& ch : line)
			{
				++letterCount[ch - 'a'];
			}

			for (const auto& count : letterCount)
			{
				if (count == 2)
				{
					++twoTimes;
					break;
				}
			}

			for (const auto& count : letterCount)
			{
				if (count == 3)
				{
					++threeTimes;
					break;
				}
			}
		}

		return twoTimes * threeTimes;
	}

	std::string part2()
	{
		Day::get().setDayAndPart(2, 2);

		std::vector<std::string> ids;

		std::ifstream infile("Day2.txt");
		std::string line;

		while (getline(infile, line))
		{
			ids.emplace_back(line);
		}

		for (auto it1 = ids.cbegin(); it1 != ids.cend(); ++it1)
		{
			for (auto it2 = std::next(it1, 1); it2 != ids.cend(); ++it2)
			{
				if (it1->size() != it2->size())
				{
					throw std::exception("Wrong size");
				}

				uint8_t diffs = 0;
				size_t pos = -1;

				for (size_t i = 0; i < it1->size(); ++i)
				{
					if ((*it1)[i] != (*it2)[i])
					{
						++diffs;

						if (diffs > 1)
						{
							break;
						}

						pos = i;
					}
				}

				if (diffs == 1)
				{
					return it1->substr(0, pos) + it1->substr(pos + 1);
				}
			}
		}

		return "";
	}
}