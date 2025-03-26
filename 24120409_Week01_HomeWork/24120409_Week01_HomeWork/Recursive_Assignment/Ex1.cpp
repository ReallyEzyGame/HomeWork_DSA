#include <iostream>
#define MaxSize 100		// the Max Number limits the n-th fibonacci number
// Input: 10
// Output:
/*
* the fibonacci list to the 10 is:
0   1   1   2   3   5   8   13   21   34
*/

// Warning: due to the limit size of the  usigned long long type, the value can be type casting when the n-th of the Fibonacci number get too large
unsigned long long fibo_List[MaxSize];		// Contains the fibonacci List

int fibonacci(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	
	if (fibo_List[n - 1] == -1) fibo_List[n - 1] = fibonacci(n - 1);
	if (fibo_List[n - 2] == -1) fibo_List[n - 2] = fibonacci(n - 2);

	unsigned long long sum = fibo_List[n-1] + fibo_List[n-2];
	fibo_List[n] = sum;						// Save the Fibonacci number
	return sum;
}


// Printing out the Fibonacci series
void fibonacci_List()
{

	int n;
	std::cout << "input the n-th of the Fibonacci number: ";
	std::cin >> n;
	if (n >= MaxSize)		// Out of Range computing
	{
		std::cout << "n-th is out of range of MaxSize\n";
		std::cout << "Please Increase the MaxSize on the head of the source code\n";
	}

	// define fibo-List as: -1, assusming that the position that is -1 is still empty
	for (int i = 0; i < n; ++i)
		fibo_List[i] = -1;

	fibonacci(n);

	// Print out the result( in the array fibo_List
	std::cout << "the fibonacci list to the " << n << " is:\n";
	for (int i = 0; i < n; ++i)
		std::cout << fibo_List[i] << "   ";
}
