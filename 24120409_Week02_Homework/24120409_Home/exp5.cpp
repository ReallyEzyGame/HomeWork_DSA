#include <iostream>

// O(n)
int shortest = 0;
void shortestSum(int array[], int left, int size, int target, int len)
{
	if (target == 0)
		if (len < shortest || shortest == 0) shortest = len;

	while (left < size)
	{
		shortestSum(array, left + 1, size, target - array[left], len + 1);
		++left;
	}
}

void Solve_exp5()
{
	std::cout << "Input the size of the array: ";

	int size;
	std::cin >> size;
	int* array = new int[size];

	for (int in = 0; in < size; ++in)
	{
		std::cin >> array[in];
	}
	int target;
	std::cout << "Input the target: ";
	std::cin >> target;

	shortestSum(array, 0, size, target, 0);
	std::cout << "The shortest len is " << shortest;
	delete[] array;
}