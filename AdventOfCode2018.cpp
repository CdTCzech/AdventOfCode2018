#include "Day1.h"

#include "Test.h"

#include <cstdint>
#include <iostream>
#include <string>


int main(int /*argc*/, char** /*argv*/)
{
	try
	{
		Test::test<int64_t>(Day1::part1, 543);
		Test::test<int64_t>(Day1::part2, 621);
	}
	catch (std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
	}

	system("pause");
	return 0;
}