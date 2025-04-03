#include "Header.h"

void Swap(int& X, int& Y)
{
	X = X ^ Y;
	Y = X ^ Y;
	X = X ^ Y;
}