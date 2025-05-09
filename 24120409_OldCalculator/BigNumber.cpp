#include "Header.h"

// Handling supper lagre Interger Number

bool IsBigInt(char* expression,int head)
{
	int length = 0;
	while (expression[head] >= '0' && expression[head] <= '9')
	{
		++length; ++head;
	}
	if (length > 6) return 1;
	return 0;
}

bool compare2BigInt(bigInt bigOne, bigInt bigTwo)
{
	int tailOne =(int) strlen(bigOne.digits) - 1;
	int tailTwo =(int) strlen(bigTwo.digits) - 1;

	if (bigOne.digits[0] == '-' && bigTwo.digits[0] == '-')
	{
		if (strlen(bigOne.digits) > strlen(bigTwo.digits)) return 0;
		else if (strlen(bigOne.digits) < strlen(bigTwo.digits)) return 1;
	}
	else if (bigOne.digits[0] != '-' && bigTwo.digits[0] != '-')
	{
		if (strlen(bigOne.digits) < strlen(bigTwo.digits)) return 0;
		else if (strlen(bigOne.digits) > strlen(bigTwo.digits)) return 1;
	}
	else if (bigOne.digits[0] != '-' && bigTwo.digits[0] == '-') return 1;
	else if (bigOne.digits[0] == '-' && bigTwo.digits[0] != '-') return 0;
	else
	{
		for (int i = 0; i < tailOne; ++i)
		{
			if (bigOne.digits[i] < bigTwo.digits[i]) return 0;
		}
		return 1;
	}
}

// Only apply for Adding remain
void Addone(bigInt& big, int pos)
{
	if (big.digits[pos] == '9') { big.digits[pos] = '0'; Addone(big, pos - 1); }
	else { big.digits[pos] = big.digits[pos] + 1; return;}
}
// Adding in BigInt
bigInt plusBigInt(bigInt big,int pos, int add)
{
	if (add < 0)
	{
		big = minusBigInt(big, pos, abs(add));
		return big;
	}

	while (add >= 1 && pos >= 0)
	{
		for (int i = 0; i <= 9; ++i)
		{
			if ((add - i) % 10 == 0)
			{
				if (big.digits[pos] + i > '9')
				{
					big.digits[pos] = big.digits[pos] + i - ('9'+1) + '0';
					Addone(big, pos - 1);
				}
				else big.digits[pos] = big.digits[pos] + i;
				add /= 10;
				--pos;
			}
		}
	}
	return big;
}

bigInt Plus2BigInt(bigInt bigOne, bigInt bigTwo)
{
	if ((bigOne.digits[0] == '-'))		// Minus Cases
	{
		toPositive(bigOne);
		bigInt otcCase = minus2BigInt(bigTwo, bigOne);
		return otcCase;
	}   

	int bigpos1 =(int) strlen(bigOne.digits) - 1;
	int bigpos2 =(int) strlen(bigTwo.digits) - 1;
	int limit = abs((bigpos1 < bigpos2) * (bigpos1 + bigpos2) - bigpos2);
	int contain = limit;

	void* temp;
	if (bigOne.digits[0] + bigTwo.digits[0] - 2 * '0' > 9)
	{
		if (bigOne.digits[0] == '-' && bigTwo.digits[0] == '-')
		{
			temp = malloc((bigpos1 + bigpos2 - limit + 2) + 2);		// 1 byte for minus character, 1 for remain
		}
		else
			temp = malloc((bigpos1 + bigpos2 - limit + 2) + 1);

	}
	else
		temp = malloc(bigpos1 + bigpos2 - limit + 2);

	if (temp == nullptr)
	{
		cout << "Error: Allocate Memory for Array Failed\n";
		exit(8);
	}

	bigInt result; result.digits = (char*)temp;
	memset(result.digits, '0', strlen(result.digits));			// Default all members to 0

	int respos =(int) strlen(result.digits)- 1;						// Result position
	while (limit >= 0)											// Adding Two BigInt
	{
		result = plusBigInt(result, respos, bigOne.digits[bigpos1] + bigTwo.digits[bigpos2] - 2 * '0');
		--respos; --bigpos1; --bigpos2; --limit;
	}

	if (bigpos1 >= bigpos2)										// Copy the Remain from bigger Int to
	{
		if (result.digits[respos-1] == '0') Addone(result,respos -1);
		for (int i = bigpos1; i >= 0; --i)
		{
			result.digits[respos] = bigOne.digits[i];
			--respos;
		}
	}
	else
	{
		if (result.digits[respos - 1] == '0') Addone(result, respos - 1);
		for (int i = bigpos2; i >= 0; --i)
		{
			result.digits[respos] = bigTwo.digits[i];
			--respos;
		}
	}
	if (bigOne.digits[0] == '-' && bigTwo.digits[0] == '-') toNegative(result);	// plus Two Negative
	result.tail = bigTwo.tail;
	return result;
}

void Minusone(bigInt& big, int pos)
{
	if (big.digits[pos] == '0') { big.digits[pos] = '9'; Addone(big, pos - 1); }
	else { big.digits[pos] = big.digits[pos] - 1; return; }
}

bigInt minusBigInt(bigInt big, int pos, int min)
{
	while (min >= 1 && pos >= 0)
	{
		for (int i = 0; i <= 9; ++i)
		{
			if ((min - i) % 10 == 0)
			{
				if (big.digits[pos] - i < '0')
				{
					big.digits[pos] =  '9' +big.digits[pos] - (i + '0') + 1;
					Minusone(big, pos - 1);
				}
				else big.digits[pos] = big.digits[pos] - i;
				min /= 10;
				--pos;
			}
		}
	}
	return big;
}

bigInt minus2BigInt(bigInt beMinus, bigInt Minus)
{
	if (beMinus.digits[0] == '-')
	{
		bigInt result = Plus2BigInt(beMinus,Minus);
		toNegative(result);
		return result;
	}
	
	int bigPos1 =(int) strlen(beMinus.digits) - 1;
	int bigPos2 =(int) strlen(Minus.digits) - 1;

	int limit = abs((bigPos1 > bigPos2) * (bigPos1 - bigPos2) - bigPos2);
	int contain = limit;

	void* temp;
	if (beMinus.digits[0] - Minus.digits[0] - 2 * '0' < 0)
		temp = malloc((bigPos1 + bigPos2 - limit + 2) + 1);		// 1 byte for minus character
	else
		temp = malloc(bigPos1 + bigPos2 - limit + 2);

	if (temp == nullptr)
	{
		cout << "Error: Allocate Memory for Array Failed\n";
		exit(8);
	}

	bigInt result; result.digits = (char*)temp;
	int resPos =(int) strlen(result.digits) - 1;
	result.tail = Minus.tail;

	if (compare2BigInt(beMinus, Minus))
	{
		while (limit >= 0)
		{
			beMinus = minusBigInt(beMinus, bigPos1, Minus.digits[bigPos2] - '0');
			--limit; --bigPos1; --bigPos2;
		}
		return beMinus;
	}
	else
	{

		while (limit >= 0)
		{
			Minus = minusBigInt(Minus, bigPos2, beMinus.digits[bigPos1] - '0');
			--limit; --bigPos1; --bigPos2;
		}
		toNegative(Minus);
		return Minus;
	}
}

bigInt mutiplyBigInt(bigInt big, int fmul)
{
	int mul = abs(fmul);						// Handle Negative Cases
	bigInt result;
	result.digits = (char*)malloc((int)strlen(big.digits) +(int) round((int)log10(abs(mul)))); // The Array of the result

	memset(result.digits, '0', strlen(result.digits));		// Default all member is '0'

	int bigpos = 0;								// start adding from the head
	int resultpos =(int) round(log10(mul))+1;			// get the result from the head

	int temp = 0;
	if (big.digits[0] == '-') ++bigpos;			// Passing the minus '-'

	while (bigpos < strlen(big.digits))
	{
		temp = (big.digits[bigpos] - '0') * mul;
		result = plusBigInt(result, resultpos, temp);
		++bigpos; ++resultpos;
	}
	result.digits[resultpos+1] = '\0';

	if ((fmul < 0) != (big.digits[0] == '-')) toNegative(result);
	return result;
}

// Assit for the function multiply 2 Big Interger
bigInt mutiplyBigInt(bigInt result,bigInt big, int mul, int pos)
{
	int bigpos = 0;									// start adding from the head
	int resultpos =(int) 1+pos;	// get the result from the head

	int temp = 0;
	if (big.digits[0] == '-') ++bigpos;				// Passing the minus '-'

	while (bigpos < strlen(big.digits))
	{
		temp = (big.digits[bigpos] - '0') * mul;
		result = plusBigInt(result, resultpos , temp);
		++bigpos; ++resultpos;
	}
	return result;
}

bigInt mutiply2BigInt(bigInt bigOne, bigInt bigTwo)
{
	int bigPos1 = 0, bigPos2 = 0;

	void* temp = malloc((strlen(bigOne.digits) + strlen(bigTwo.digits)));		// Already Included the '-' character

	if (temp == nullptr)
	{
		cout << "Error: Cannot Allocate Memory for Array\n";
		exit(9);
	}
	
	bigInt result; result.digits = (char*)temp;
	memset(result.digits, '0', strlen(result.digits));							// Default all member is '0'
	result.digits[(strlen(bigOne.digits) + strlen(bigTwo.digits))] = '\0';		// end string

	if (bigTwo.digits[0] == '-') ++bigPos2;										// Pass the '-' character
	if (bigOne.digits[0] == '-') ++bigPos1;										// Pass the '-' character

	int resPos = 0;			// Multiply from the head

	while (bigPos2 < strlen(bigTwo.digits))
	{
		result = mutiplyBigInt(result,bigOne, bigTwo.digits[bigPos2] - '0',resPos);
		++bigPos2; ++resPos;
	}

	if ((bigOne.digits[0] == '-') != (bigTwo.digits[0] == '-')) toNegative(result);
	result.tail = bigTwo.tail;
	return result;
}

bigInt divideBigint(bigInt big, int fdiv)
{
	int div = (int)abs(fdiv);		//Handle minus cases
	bigInt result;
	result.digits = (char*)calloc(strlen(big.digits) -(int) round((int)log10(div)) + 1,1); // The Array of the result

	int bigpos = 0;		// start divide from the head
	int resultpos = 0;	// take the result from the head

	int temp = 0;		// Contain the remaining value
	int divresult = 0;	// result of the divide
	if (big.digits[0] == '-') ++bigpos;

	while (bigpos < strlen(big.digits))
	{
		temp = temp*10 + big.digits[bigpos] - '0';		// Taking number for divide
		divresult = temp / div;					// Divide
		if (divresult != 0)						// if numerator greater than 
		{
			result.digits[resultpos] = divresult + '0';
			temp -= divresult * div;			// taking out the already divide
			++resultpos;
		}
		++bigpos;
	}
	if (!(fdiv < 0) != !(big.digits[0] == '-')) toNegative(result);
	result.digits[strlen(big.digits)] = '\0';
	return result;
}

// Put the final result to the Array to continue calculating
// The pos is stand for position of the tail of the bigInt in the Array
void putBigInt(char* expression, bigInt& big, int pos)
{
	if (pos > strlen(expression) - 1 || pos < 0)
	{
		printf("Error: Out of Range Error\nThe value must smaller than the Array's length\n");
		exit(0);
	}
	big.tail = pos;
	int bigpos =(int) strlen(big.digits) - 1;
	while (bigpos >= 0)
	{
		expression[pos] = big.digits[bigpos];
		--pos; --bigpos;
	}
}

bigInt getBigInit(char* expression, int& head)
{
	bigInt big;
	big.digits = (char*)calloc(BigIntSize, 1);

	int bigpos = 0;
	while (isdigit(expression[head]))
	{
		big.digits[bigpos] = expression[head];
		++bigpos; ++head;
	}
	return big;
}

void toNegative(bigInt& big)
{
	if (big.digits[0] == '-') return;
	int end =(int) strlen(big.digits) + 1;
	void* temp = malloc(end);

	if (temp == nullptr) { printf("Error: Cannot Allocate for Array\n"); exit(6); }
	char* string = (char*)temp;
	string[end] = '\0';

	string[0] = '-';
	for (int i = 0; i < end; ++i)
	{
		string[i+1] = big.digits[i];
	}
	big.digits = string;
}

void toPositive(bigInt& big)
{
	if (big.digits[0] != '-') return;
	int end = (int)strlen(big.digits);
	void* temp = calloc(end, 1);

	if (temp == nullptr) { printf("Error: Cannot Allocate for Array\n"); exit(6); }
	char* string = (char*)temp;

	for (int i = 0; i < strlen(big.digits); ++i)
	{
		string[i] = big.digits[i];
	}
	string[end] = '\0';
	big.digits = string;
}
// Converte from char to number in the Array
double getNumber(char* expression,int& head)
{
	double result = 0;
	for (head; expression[head] >= '0' && expression[head] <='9';++head)
	{
		result = result*10 + (expression[head] - '0');
	}
	return result;
}

// Default positions in Array to '0' character
void clearArea(char* expression, int head, int tail)
{
	if (head < 0 || tail < 0 || head > strlen(expression) || tail > strlen(expression) || head > tail)
	{
		cout << "Error: Invalid Array Range\n";
		exit(5);
	}
	for (int i = head; i < tail; ++i) expression[i] = '0';
}