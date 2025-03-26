#include <iostream>

void doWhileLoop()
{
	int round = 0;
	do
	{
		std::cout << "round " << round << std::endl;
		++round;
	} while (round <= 5);
}