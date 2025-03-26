#include <iostream>

int ForLoop()
{
	int round = 0;
	while (round <= 5)
	{
		std::cout << "Round " << round << std::endl;
		round++;
	}
	return 0;
}