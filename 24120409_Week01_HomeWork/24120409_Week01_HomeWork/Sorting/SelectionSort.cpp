#include <iostream>
void swap(int& X, int& Y)
{
	int tmp = X;
	X = Y;
	Y = tmp;
}
void SelectionSort(int array[], int size)
{
	int in = 0;
	while (in < size)
	{
		for (int i = 0; i < size; ++i)
			std::cout << array[i] << "\t";
		std::cout << std::endl;
		int i = in;
		int min = i;
		while (i < size)
		{
			if (array[i] < array[min]) min = i;
			++i;
		}
		swap(array[min], array[in]);
		++in;
	}
}

int main()
{
	int array[10] = { 5,10,8,2,1,9,11,6,3,5 };
	SelectionSort(array, 10);

	std::cout << std::endl;
	for (int i = 0; i < 10; ++i)
		std::cout << array[i] << "   ";
}