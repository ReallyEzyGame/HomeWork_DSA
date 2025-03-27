#include <iostream>
#include <vector>
using namespace std;
// Idea: using the two Pointer Notation as the lower bound and upper bound of the array, we try to find the value in the middle which has the sum with the 2 bounds as 0
/*
* Input: 6
*		-1 0 1 2 -1 -4
* Output:  
* Triplet -1  2  -1
* Triplet 0  1  -1
* 
* Input: 7
*		-1 -2 -3 0 1 2 3
*/
// This part a used chatgpt for solving: findTriplet()
void swap(int& X, int& Y)
{
	int tmp = X;
	X = Y;
	Y = tmp;
}

void heapify(std::vector<int>& array, int n, int root)
{
	int largest = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;

	if (left < n)
		if (array[left] > array[largest])
			largest = left;

	if (right < n)
		if (array[right] > array[largest])
			largest = right;


	if (largest != root)
	{
		swap(array[largest], array[root]);
		heapify(array, n, largest);
	}
}

void heapSort(std::vector<int>& array, int size)
{
	for (int i = size / 2 - 1; i >= 0; --i)
		heapify(array, size, i);

	for (int i = size - 1; i > 0; --i)
	{
		swap(array[0], array[i]);
		heapify(array, i, 0);
	}
}	

vector<vector<int>> findTriplet(vector<int>&nums) {
		// Invalid cases
		if (nums.size() <= 2) return {};

		heapSort(nums, nums.size());		// Sorting the input vector

		vector<vector<int>> result;
		int n = nums.size();


		for (int left = 0; left < n - 2; left++) { // Ensure we have at least 3 elements left
			if (left > 0 && nums[left] == nums[left - 1]) continue; // Skip duplicates

			int middle =  left+ 1, right = n - 1;
			while (middle < right) {
				int sum = nums[left] + nums[middle] + nums[right];

				if (sum == 0) {
					result.push_back({ nums[left], nums[middle], nums[right] });

					// Move left and right pointers while avoiding duplicates
					while (middle < right && nums[middle] == nums[middle + 1]) middle++;
					while (middle < right && nums[right] == nums[right - 1]) right--;

					middle++;
					right--;
				}
				else if (sum < 0) {
					middle++;  // Increase sum
				}
				else {
					right--; // Decrease sum
				}
			}
		}
		return result;
	}

void Solve_exp7()
{
	std::cout << "Input the size of the array: ";

	int size;
	std::cin >> size;
	std::vector<int> list;
	for (int in = 0; in < size; ++in)
	{
		int tmp;
		std::cin >> tmp;
		list.push_back(tmp);
	}

	std::vector<std::vector<int>> result = findTriplet(list);

	for (auto triplet : result)
	{
		std::cout << triplet[0] << "   " << triplet[1] << "   " << triplet[2] << std::endl;
	}
}