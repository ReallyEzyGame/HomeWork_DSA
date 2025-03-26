#include <iostream>

// Checking from the last partical of the array to the first
// Because the array is sorted ==> each cell will contain a value smaller than the value to the right, bigger than the value to the left( except for the first and last value)
// so in rule if there is no value in the array agisnt this rule then the array is sorted and if not the array is not sorted
bool IsSorted(int array[], int index)
{
	// getting to the first article of the array
	if (index == 0) return 1;

	// there is unsorted part
	if (array[index-1] > array[index]) return 0;

	// Continue to Check the next parrt of the Array( to the left)
	return IsSorted(array, index - 1);
}

void Check()
{
	// Get the size of the Array
	int size = 0;
	std::cout << "Input the size of the Array\n";
	std::cin >> size;
	int* array = new int[size];
	
	// Input value to the Array
	std::cout << "Input value(s) " << size << "to the Array\n";
	for (int in = 0; in < size; ++in)
		std::cin >> array[in];

	// Getting the result
	if (IsSorted(array, size-1))
		std::cout << "the array is Sorted\n";
	else
		std::cout << "the array is not sorted\n";
}