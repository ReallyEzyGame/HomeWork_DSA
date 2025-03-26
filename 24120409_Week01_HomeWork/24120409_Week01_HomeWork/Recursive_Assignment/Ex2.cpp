#include <iostream>


// Input: 10
// Output: the factorial of 10 is: 3628800
// Warning: due to the limit size of the 'int' type the value will be negative if the factorial is to large
// To increase the result, change from 'int' type to 'unsigned long long' can get the result with a greater value

// using: recursion( not recommend)
// for each recursive calculate the current n-th of the value multiply with the factorial(n-1), till n = 0 return 1
int factorial(int n)
{
	if (n == 0) return 1;
	return n * factorial(n - 1);
}

int get_Factorial()
{
	int num;

	// input
	std::cout << "Input the factorial: ";
	std::cin >> num;
	if (num < 0)
		std::cout << "Invalid input value\n the factorial number must greater than 0\n";

	// get the reuslt
	int result = factorial(num);
	std::cout << "the factorial of " << num << " is: " << result << std::endl;
	return result;
}
