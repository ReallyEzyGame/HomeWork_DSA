#include <string>
#include <iostream>

void stringMani()
{
	std::string str = "Le_Thanh_Phong";
	std::cout << "The string before appending is " << str << std::endl;

	str.append("_Loves_DSA");
	std::cout << "The string after appending is " << str << std::endl;
}