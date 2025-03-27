#include <iostream>
/*
* Input: 6
*			1 2 3 4 5 6
*
* Output:	1
*
* Input: 7
*			5 6 0 1 2 3 4 
*			
* Output:	0
*/
// Since the given array is Increase array but got rotated x times
// Idea: if the value on the left great than the right => the smallest value is between right and left
// Otherwise: the smallest vaue is on the right side
int findMin(int array[], int left, int right)
{
	// Only the Smallest value left
	if (left == right) return array[left];


	int mid = left + right / 2;
	if (array[mid] > array[right])
		return findMin(array, mid + 1, right);
	return findMin(array, left, mid);
}

// Note: the input array must be an accesendend order array that had been rotate clockwise x time(s)
void Sovle_exp3()
{
	std::cout << "Input the size of the array: ";

	int size;
	std::cin >> size;
	int* array = new int[size];

	for (int in = 0; in < size; ++in)
	{
		std::cin >> array[in];
	}

	int min = findMin(array, 0, size - 1);
	std::cout << "The value smallest value in the array is " << min << std::endl;

	delete[] array;
}