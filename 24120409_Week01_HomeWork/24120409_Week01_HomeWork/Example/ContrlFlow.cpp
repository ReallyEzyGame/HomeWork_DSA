#include <iostream>

void ControlFlow()
{
	int num;
	std::cout << "Enter a number: ";
	std::cin >> num;

	if (num % 2 == 0) {
		std::cout << num << " is even." << std::endl;
	}
}