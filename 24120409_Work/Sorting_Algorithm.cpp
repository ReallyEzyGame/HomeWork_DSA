#include "Header.h"

// Sorting Max to Right
void SelectionSort(int array[], int size)
{
	// Invalid array
	if (size <= 0) return;

	// Sorting from the right side of the array
	for (int i = size-1;++loopCount && i >= 0; --i)
	{
		int max = array[i];
		// Finding the max value
		for (int j = size-1;++loopCount && j >= i;--j)
			if (array[j] > max) max = array[j];

		Swap(max, array[i]);
	}
}


void BubbleSort(int array[], int size)
{
	int swapped = 0;
	for (int i = 0; ++loopCount && i < size - 1; ++i)
	{
		for (int j = 0; ++loopCount && j < size-1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				Swap(array[j], array[j + 1]);
				swapped = 1;
			}
		}


		if (!swapped) break;
	}
}

void Merge(int array[], int left, int middle, int right)
{}

void MergeSort(int array[], int left, int right)
{
	// Divide Part
	if (left < right)
	{
		int middle = left + (right - left) / 2;

		MergeSort(array, left, middle);
		MergeSort(array, middle + 1, right);

		Merge(array, left, middle, right);
	}
}