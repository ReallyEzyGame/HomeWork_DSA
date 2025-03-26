#include <iostream>

// Input: 5
//			A
//			C
//			B
// Output:
/*
* Move disk 1 from peg A to peg C
Move disk 2 from peg A to peg B
Move disk 1 from peg C to peg B
Move disk 3 from peg A to peg C
Move disk 1 from peg B to peg A
Move disk 2 from peg B to peg C
Move disk 1 from peg A to peg C
Move disk 4 from peg A to peg B
Move disk 1 from peg C to peg B
Move disk 2 from peg C to peg A
Move disk 1 from peg B to peg A
Move disk 3 from peg C to peg B
Move disk 1 from peg A to peg C
Move disk 2 from peg A to peg B
Move disk 1 from peg C to peg B
Move disk 5 from peg A to peg C
Move disk 1 from peg B to peg A
Move disk 2 from peg B to peg C
Move disk 1 from peg A to peg C
Move disk 3 from peg B to peg A
Move disk 1 from peg C to peg B
Move disk 2 from peg C to peg A
Move disk 1 from peg B to peg A
Move disk 4 from peg B to peg C
Move disk 1 from peg A to peg C
Move disk 2 from peg A to peg B
Move disk 1 from peg C to peg B
Move disk 3 from peg A to peg C
Move disk 1 from peg B to peg A
Move disk 2 from peg B to peg C
Move disk 1 from peg A to peg C
*/

// the Main funtion to solve the TowerOfHaNoi
void TowerOfHaNoi(int disk, char from, char des, char aux)
{
	if (disk == 1)		// Stop when the disk from the fromPeg reach 1(out of disk)
	{
		std::cout << "Move disk " << disk << " from peg " << from << " to peg " << des << std::endl;
		return;
	}
	TowerOfHaNoi(disk - 1, from, aux, des);			// Moving disk from from_Peg to all posible position
	std::cout << "Move disk " << disk << " from peg " << from << " to peg " << des << std::endl;
	TowerOfHaNoi(disk - 1, aux, des, from);			// Stack all the valid disk
}

// using to create input variants to TowerOfHaNoi function
void TowerSolving()
{
	int num;
	char fromPeg, desPeg, auxPeg;
	std::cout << "Input the number of disk: ";
	std::cin >> num;
	if (num <= 0)
	{
		std::cout << "Invalid input\nthe number of the disk must be greater than 0\n";
		return;
	}

	std::cout << "Input the name of the From Peg: ";
	std::cin >> fromPeg;
	std::cout << "Input the name of the Destination Peg: ";
	std::cin >> desPeg;
	std::cout << "Input the name of the Auxiliary Peg: ";
	std::cin >> auxPeg;
	TowerOfHaNoi(num,fromPeg,desPeg,auxPeg);
}
