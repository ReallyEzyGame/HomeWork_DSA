#include "Header.h"


// Contain Data
struct Token
{
	char ch;			// For containg symbol
	double value;		// For containg number (if it is number)
	bigInt big;	// For containg number as string
	int position;
};
struct TokenStream
{
	Token buffer{NULL,NULL};		// Temporary Contain a Value
	bool full = false;				// The Status of the Buffer
};

// Put a Token into the buffer
void putback(TokenStream& stream, Token token)
{
	if (stream.full)
	{
		cout << "putback into a Full Buffer\n";
		return;
	}
	stream.buffer = token;
	stream.full = true;
}

// Get a Token
Token getToken(TokenStream& stream,char* expression)
{
	static int move;


	// If the Buffer is Full then return the Data in the buffer
	if (stream.full)
	{
		stream.full = false;
		return stream.buffer;
	}

	// If the Buffer is Empty then return the Data from the stream
	char ch;
	ch = expression[move];
	switch (ch)
	{
		// Let each symbol Represent it Self
	case 0: case 10:
		return Token{ 0 };
	case'+': case '-': case '*': case '/': case ':':
	case '(': case ')': case '%':
		++move;
		cout << ch;
		return Token{ ch };
		// Taking the number if the ch is a char of number or '.'
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	case '.':
	{
		bigInt big; double value;
		if (IsBigInt(expression, move))
		{
			big = getBigInit(expression, move); cout << big.digits;
			return Token{ bigNumber,pow(2,32),bigInt{big.digits,move-1},move-1 };
		}
		else
		{
			value = getNumber(expression, move); cout << value;	// this can sometimes print the end of result ( Error??)
			return Token{ number, value,bigInt{nullptr},move-1 };
		}
	}
	default:
		cout << "\nUnexpected Input '" << ch << "' in the Prompting\n";
		break;
	}
	return Token{ 0};
}


// Function Decleration
Token Level3(TokenStream& stream,char* expresion);
Token Level2(TokenStream& stream,char* expression);
Token Level1(TokenStream& stream,char* expression);

// Handle Operant +,- and Level2()
Token Level3(TokenStream& stream,char* expression)
{
	Token left;
	left = Level2(stream,expression); // Start with the left operand
	Token token = getToken(stream,expression);
	while (true)
	{
		switch (token.ch)
		{
		case '+': {
			Token add = Level2(stream, expression);
			if (left.big.digits != nullptr && add.big.digits != nullptr)
			{
				clearArea(expression, left.big.tail - strlen(left.big.digits) + 1, add.big.tail-1);
				left.big = Plus2BigInt(left.big, add.big);
				putBigInt(expression, left.big, add.big.tail);
			}
			else if (left.big.digits != nullptr)
			{
				clearArea(expression, left.big.tail - strlen(left.big.digits) + 1, add.position - 1);
				left.big = plusBigInt(left.big, strlen(left.big.digits)-1, add.value);
				add.value = 0;
				putBigInt(expression, left.big, add.position);
			}
			else if (add.big.digits != nullptr)
			{
				clearArea(expression, left.position + 1, add.big.tail - 1);
				left.big = plusBigInt(add.big, strlen(add.big.digits) - 1, left.value);
				left.value = 0;
				putBigInt(expression, left.big, add.big.tail);
			}
			else left.value += add.value; // Normal addition
			token = getToken(stream, expression);
			break;
		}
		case '-': 
		{
			Token min = Level2(stream, expression);
			if (left.big.digits != nullptr && min.big.digits != nullptr)
			{
				clearArea(expression, left.big.tail - strlen(left.big.digits) + 1, min.big.tail - 1);
				left.big = minus2BigInt(left.big, min.big);
				putBigInt(expression,left.big, min.big.tail);
			}
			else if (left.big.digits != nullptr)
			{
				clearArea(expression, left.big.tail - strlen(left.big.digits) + 1, min.position - 1);
				left.big = minusBigInt(left.big, strlen(left.big.digits) - 1, min.value);
				min.value = 0;
				putBigInt(expression, left.big,min.big.tail);
			}
			else if (min.big.digits != nullptr)
			{
				clearArea(expression, left.position + 1, min.big.tail - 1);
				left.big = minusBigInt(min.big, strlen(min.big.digits) - 1, left.value);
				left.value = 0;
				toNegative(left.big);
				putBigInt(expression, left.big, min.big.tail);
			}
			else left.value -= min.value; // Normal addition
			token = getToken(stream, expression);
			break;
		}
		default:
			putback(stream, token); // Put back unused token
			return left;
		}
	}
}

// Handle Openrant *, / and Level1()
Token Level2(TokenStream& stream,char* expression)
{
	Token left = Level1(stream,expression);
	Token token = getToken(stream,expression);
	Token div;
	while(true)
	{
		switch (token.ch)
		{
		case '*':
		{
			Token mul = Level1(stream, expression);
			if (left.big.digits != nullptr && mul.big.digits != nullptr)
			{
				clearArea(expression, left.big.tail - strlen(left.big.digits) + 1, mul.big.tail);
				left.big = mutiply2BigInt(left.big, mul.big);
				putBigInt(expression,left.big, mul.big.tail);
				left.value = 0;
			}
			else if (left.big.digits != nullptr)
			{
				clearArea(expression, left.big.tail - strlen(left.big.digits) +  1, mul.position);
				left.big = mutiplyBigInt(left.big, mul.value);
				mul.value = 0;
				putBigInt(expression, left.big, mul.position);
			}
			else if (mul.big.digits != nullptr)
			{
				clearArea(expression, left.position + 1, mul.big.tail);
				left.big = mutiplyBigInt(mul.big, left.value);
				left.value = 0;
				putBigInt(expression, left.big, mul.position);
			}
			else left.value *= mul.value;

			token = getToken(stream, expression);
			break;
		}
		case '/': case ':':
			div = Level1(stream,expression);
			if (div.value == 0)
			{
				cerr << "Unable to Divide by 0\n";
				exit(104);
			}
			if (left.big.digits != nullptr)
			{
				clearArea(expression, left.big.tail - strlen(left.big.digits) +1, div.position);
				left.big = divideBigint(left.big, div.value);
				left.value = 0;
				putBigInt(expression, left.big, div.position);
			}
			else if (div.big.digits != nullptr)
			{
				clearArea(expression, left.position + 1, div.big.tail);
				left.value = 0;
			}
			else left.value /= div.value;

			token = getToken(stream,expression);
			break;
		case '%':
			div = Level1(stream,expression);
			if (div.value == 0)
			{
				cerr << "Unable to Divide by 0\n";
				exit(104);
			}
			left.value =(int)left.value%(int)div.value;
			token = getToken(stream,expression);
			break;
		default:
			putback(stream, token);
			return left;
		}
	}
}

// Handle  '(',')' and Number()
Token Level1(TokenStream& stream, char* expression)
{
	Token middle;
	middle.value = 0;
	Token token = getToken(stream, expression);
	while(true)
	{
		switch (token.ch)
		{
		case '(':
			middle = Level3(stream, expression);
			token = getToken(stream,expression);
			try { if (token.ch != ')') throw (0); }
			catch (...)
			{
				cout << "\nError: Expected ')'\n";
				exit(0);
			}
			return middle;
		case number:
			return token;
		case bigNumber:			// Do we Really need this?
			return token;
		case '+':
			return Level1(stream,expression);
		case '-':
			middle = Level1(stream, expression);
			middle.value = -middle.value;
			if (middle.big.digits != nullptr) toNegative(middle.big);
			return middle;
		default:
			cerr << "\nExpected Number\n";
			exit(131);
		}
	}
}
	
// Print out the List of the Calculation Assigment
int List(FILE* file)
{
	rewind(file);

	char ch = 10;
	int count = 1;
	while (!feof(file))
	{
		if (ch == 10) { cout << count << ".   "; ++count; }
		fscanf_s(file, "%c", &ch, (unsigned int)sizeof(ch));
		printf("%c", ch);
	}
	rewind(file);
	return count;
}

char* getOperation(FILE* Input)
{
	// Allocate Array for Caluculation
	void* temp = calloc(MaxSize, 1);
	if (temp == nullptr) { cout << "Error: Unable to Allocate the Array\n"; exit(5); }
	char* string = (char*)temp;

	// Get the Information from File

	int limit = List(Input);

	cout << "\nChoose an Assignment in you favor\n";
	int lineNum; cin >> lineNum;
	if (lineNum >= limit - 1 || lineNum <= 0)
	{
		cout << "Exit the Calculation Programm\nGoodbye\n";
		exit(5);
	}

	char ch;
	int count = 1;
	while (count < lineNum && !feof(Input))	// Passing the Not Necessary line
	{
		fscanf_s(Input, "%c", &ch, (unsigned int)sizeof(ch));
		if (ch == 10) ++count;
	}

	ch = '0';				// Decleare the Variable for the Next loop
	int pos = 0;
	while (ch != '\n')		// Get the Calculation
	{
		fscanf_s(Input, "%c", &ch, (unsigned int)sizeof(ch));
		if (ch == ' ') continue;
		string[pos] = ch;
		++pos;
	}
	string[pos] = '\0';
	rewind(Input);
	return string;
}

void Calculate()
{
	FILE* Input; errno_t err1 = fopen_s(&Input, "Input.txt", "r");
	if (Input == nullptr) { cout << "Unable to Open the File\n"; exit(0); }

	char* expression;
	expression = getOperation(Input);

	cout << ">> ";

	TokenStream stream;
	Token token = getToken(stream, expression);

	while (token.ch == 10) token = getToken(stream, expression);
	if (token.ch == 0) return;


	putback(stream, token);
	Token result = Level3(stream, expression);

	if (result.big.digits == nullptr)  cout << "\n= " << result.value << endl;
	else cout << "\n= " << result.big.digits << endl;

	token = getToken(stream, expression);

	fclose(Input);
	return;
}

int main()
{
	try 
	{
			Calculate();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
		return 0;
	}
}
// Need to Solve for Big Number 24  –9 – (129 + 90 – 1788877888778788887877)