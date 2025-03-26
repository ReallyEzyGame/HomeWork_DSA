#include <iostream>
// the naive seearching algorithm

int LinearSearch(int array[], int size, int target)
{
	// invalid size
	if (size < 0) return -1;

	// finding the target in the array by searching from left to right

	int in = 0;
	while (in < size)
	{
		// return the value if the value is in the array
		if (array[in] == target) return in;
	}
	// no such value exist in the array
	return -1;
}

void Sovle_exp1()
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

	int index = LinearSearch(array, size, target);

	if (index == -1) std::cout << "No such value was found in the array\n";
	else	std::cout << "The value " << target << " has the index " << index << " in the array\n";

	delete[] array;
}