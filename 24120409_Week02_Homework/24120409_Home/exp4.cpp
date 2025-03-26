#include <iostream>
/*
* Idea: we need an extra array has the same size, the array contains the sum of all front particle infront
* In that array, we need to find the smallest value in that array satisfy one rule: array[x]* days >= sum
* That's means: the max load of the ship is above( but least in all the posible weight) the average weight per day
* => the ship can always carry the wieght that near average most => the number of days is near the requires most
*/
int LeastWeight(int array[],int size, int days)
{
	// Temporary contain the sum of all the front weight
	int* weight = new int [size];

	int sum = 0, index = 0;

	// Getting the sum of all weight in front to the array
	while (index < size)
	{
		sum += array[index];
		weight[index] = sum;
		++index;
	}

	// finding the smallest sum
	index = 0;
	while (index < size && weight[index]*5 < sum)
		++index;

	int minWeight = weight[index];
	delete[] weight;

	std::cout << "The Smallest weigt for the ship to carry in " << days << " days is " << minWeight << std::endl;
	return minWeight;
}

// Note: the input array must be an Increase array
void Solve_exp4()
{
	std::cout << "Input the size of the array: ";

	int size;
	std::cin >> size;
	int* array = new int[size];

	for (int in = 0; in < size; ++in)
	{
		std::cin >> array[in];
	}
	int days;
	std::cout << "Input the number of day(s): ";
	std::cin >> days;


	int weight = LeastWeight(array, size, days);
	std::cout << "We can use the ship with the minimum weight is " << weight;
	delete[] array;
}