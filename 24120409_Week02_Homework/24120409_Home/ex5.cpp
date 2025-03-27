#include <iostream>

/*
* INPUT: 6
*		2 3 1 2 4 3
*			7
* OUTPUT: 2
*INPUT: 6
*		2 3 1 2 4 3
*			100
* OUTPUT: 0
*/
int shortestSum(int array[], int size, int target)
{
	// Getitng the sum of the array
	int sum = 0;
	for (int i = 0; i < size; ++i)
		sum += array[i];
	if (sum < target) return 0;			// false cases


	// Shrink the array the the minimun size
	int len = size;
	int left = 0, right = size - 1;

	while (left < right)
	{
		if (array[left] > array[right])		// Limit the upper bound
			sum -= array[right--];
		else								// limit the  lower bound
			sum -= array[left++];
		

		if (sum < target) return len;		// Return for shortest len

		// decrease the len
		--len;
	}
	return len;
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

	std::cout << "The shortest len is " << shortestSum(array, size,target);
	delete[] array;
}