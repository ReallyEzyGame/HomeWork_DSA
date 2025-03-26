#include <iostream>

// The Idea: Since our given array is sorted, we start from 2 position, 1 from the front, 1 front the last particle in the array
// If the sum of the two number less than the target => we need to increase our candidate => increase the left position by 1
// If the sum of the two number greater than the target => we need to decrease our candidate value => decrease the right position by 1
bool TwoPointer(int array[], int size, int target)
{
	int left = 0, right = size - 1;
	while (left < right)
	{
		if (array[left] + array[right] == target) return 1;
	}
	return 0;
}

void Solve_exp6()
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

	if (TwoPointer(array, size, target))
	{
		std::cout << "Exist Two value in the array that has the sum equal to " << target << std::endl;
	}
	delete[] array;
}