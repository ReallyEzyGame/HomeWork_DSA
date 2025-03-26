#include <string>
#include <iostream>

// Input: 6
// Output:
/*
000000
000001
000010
000011
000100
000101
000110
000111
001000
001001
001010
001011
001100
001101
001110
001111
010000
010001
010010
010011
010100
010101
010110
010111
011000
011001
011010
011011
011100
011101
011110
011111
100000
100001
100010
100011
100100
100101
100110
100111
101000
101001
101010
101011
101100
101101
101110
101111
110000
110001
110010
110011
110100
110101
110110
110111
111000
111001
111010
111011
111100
111101
111110
111111
*/

using namespace std;

bool check = 0;


void PreCondition(int n, string& str)
{
	while (n >= 0)
	{
		str.push_back('0');
		--n;
	}
}

// Idea: using the adding 1 similar to the bitwise operator, create the string in increasing-series
// the function main part: creating the first string of '0'(the first call), printing out the current string, adding 1 to the string
// when the string is string of '1' then stop
void generateBinaryStrings(int n, string str)
{
	// default the sring to string of '0'
	if (!check)
	{
		check = 1;
		PreCondition(n, str);
	}

	cout << str << endl;

	// flag: stop recursion when the string is string '1'
	bool flag = 1;
	// Increase the string by '1'
	for (int pos = str.size()-1; pos >= 0; --pos)
	{
		if (str[pos] == '0')
		{
			str[pos] = '1';
			flag = 0;
			break;
		}
		else	// if char is '1'
			str[pos] = '0';
	}

	// if the string is string of '1' then stop
	if (flag) return;
	else		// string is not string of '1', then continue to create more string
		generateBinaryStrings(n, str);
}

void BinaryString_Solve()
{
	string str; int len;

	cout << "the lenght of the binary string: ";
	cin >> len;
	if (len < 0)
	{
		cout << "The length of the string must greater than 0";
		return;
	}

	generateBinaryStrings(len-1, str);
}
