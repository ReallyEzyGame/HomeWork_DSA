#include <iostream>

void Pointer()
{
	int A = 5;
	int* B = &A;

	std::cout << "The address of the A variable " << &A << " contains the value " << A << std::endl;
	std::cout << "The Address of the B's pointer " << &B << " which has the adress of the A variable " << B << " which is " << *B << std::endl;
}