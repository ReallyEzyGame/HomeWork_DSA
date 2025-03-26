#include <iostream>

// Idea: using the two Pointer Notation as the lower bound and upper bound of the array, we try to find the value in the middle which has the sum with the 2 bounds as 0
void findTriplet(int array[], int size)
{
	// Invalid cases
	if (!array || size < 0) return;

	// the index value: left for the left bound, right for the right bound, mid can run in the left and right bound
	int left = 0, right = size - 1;
	bool shift = 1;			// 1: right bound decrease, 0: left bound decrease
	while (left < right)
	{
		for (int mid = left; mid < right; ++mid)
			if (array[left] + array[right] + array[mid] == 0)
				std::cout << "Triplet " << array[left] << "  " << array[mid] << "  " << array[right] << std::endl;

		if (shift)
			right--;
		else
			left++;
		shift = !shift;
	}
}

void Solve_exp7()
{
	std::cout << "Input the size of the array: ";

	int size;
	std::cin >> size;
	int* array = new int[size];

	for (int in = 0; in < size; ++in)
	{
		std::cin >> array[in];
	}

	findTriplet(array, size);
	delete[] array;
}