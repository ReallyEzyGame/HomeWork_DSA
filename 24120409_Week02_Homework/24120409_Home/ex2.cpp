#include <iostream>

/*
* Input: 6
*			1 2 3 4 5 6
*			6
* Output:	5
*
* Input: 6
*			1 2 3 4 5 6
*			7
* Output: -1
*/
// A modified Linear Search, using a dummy head to replace for the last place to reduce 1 'if' condition in the loop
int SentinalSearch(int array[], int size, int target)
{
	// Invavid size case
	if (size < 0) return -1;

	int in = 0;		// the index in the array

	// using the last position in the array as the sentinal
	if (array[size - 1] == target) return size - 1;

	// tempoprary using the last position in the array for the sentinal
	int tmp = array[size - 1];
	array[size - 1] = target;

	// using linear searching notation
	while (array[in] != target)
		++in;

	// if the target is the sentinal then return no such value in the array
	if (in == size - 1) return -1;
	// exist a value in the array
	array[size - 1] = tmp;		// return back the last postion as the old array
	return in;
}


void Sovle_exp2()
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

	int index = SentinalSearch(array, size, target);

	if (index == -1) std::cout << "No such value was found in the array\n";
	else	std::cout << "The value " << target << " has the index " << index << " in the array\n";

 	delete[] array;
}