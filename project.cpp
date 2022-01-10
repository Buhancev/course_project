#include <iostream>
#include "fract_num.h"

int main()
{
	fract_num a(10, 14);
	fract_num b(67, 84);

	fract_num c;

	c = b;
	std::cout << c;

	c = a + b;
	std::cout << c;

	c = a - b;
	std::cout << c;

	c = a * b;
	std::cout << c;

	c = a / b;
	std::cout << c;

	c = 2 + b;
	std::cout << c;

	c = a - 3;
	std::cout << c;

	c = a * 3;
	std::cout << c;

	c = 7 / b;
	std::cout << c;

	c += b;
	std::cout << c;

	c -= b;
	std::cout << c;

	c++;
	std::cout << c;

	--c;
	std::cout << c;

	if (a == b)
	{
		std::cout << "a = b" << std::endl;
	}

	if (a != b)
	{
		std::cout << "a != b" << std::endl;
	}

	if (a > b)
	{
		std::cout << "a > b" << std::endl;
	}

	if (a < b);
	{
		std::cout << "a < b" << std::endl;
	}
}