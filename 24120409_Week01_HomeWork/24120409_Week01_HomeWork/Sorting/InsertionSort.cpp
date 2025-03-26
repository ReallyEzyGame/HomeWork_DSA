#include <iostream>

void InsertionSort(int array[], int size)
{
	int in = 1;
	while (in < size)
	{
		for (int i = 0; i < size; ++i)
			std::cout << array[i] << "   ";
		std::cout << std::endl;
		int i = in-1;
		int tmp = array[in];

		while (i >= 0 && tmp <= array[i])
		{
			array[i+1] = array[i];
			--i;
		}
		array[i+1] = tmp;
		++in;
	}
}

