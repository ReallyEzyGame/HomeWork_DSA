#include <fstream>
#include <string>
#include <string.h>
#include <iostream>

#define div_perc 15         // Divide percision
#define percise 3           // the Percise of the result Fraction part( before rounding)
#define UPPERBOUND 2000     // The Number of digit(s) in the Integer part
#define LOWERBOUND 500      // the Number of digit(s) in the Fraction part
#define DIGIT '8'

using namespace std;

/*
    // Before   Designing & Implement the Program
    06/05/2025, Test & Debug Remaing Error, Adding Calculate(), main() from command line
                Merge all source Code to this file
    08/05/2025, Fix the Case Error: all the Error cases print to the file "Error"
*/

struct BigFloat;
struct Token;

// Data Structure   -----------------------------------
// Handling Input as Float Number
// Default the number is positive
typedef struct BigFloat
{
    string integer;
    string fraction;
    bool negative = false;
} BigFloat;

// Distinguish Number & Operator
typedef struct Token
{
    char kind;
    BigFloat number;
} Token;

// Header function  ------------------------------------
// clean_string
int clean_syntax(string& stream);
void round_up_bigFloat(BigFloat& num);

// Operator
// ------------- String Manupilate
bool IsZero(BigFloat num);
bool IsZero(string num);
BigFloat move_literal(BigFloat num, int step);

string str_inverse(string str);
int str_compare(string str1,string str2);

int to_number(string digits);
void toSamelen(string& str1, string& str2);
void ReduceZero(BigFloat& Number);
void right_shift(string& str, int step);
// -------------- Opereator
string add(string num1,string num2);
string Minus(string& beMinus, string& Minus);
string multiply(string num1, string num2);

// --------------- Big Number Operator
BigFloat add_bigFloat(BigFloat Num1, BigFloat Num2);
BigFloat minus_bigFloat(BigFloat beMinus, BigFloat Minus);
BigFloat multiply_bigFloat(BigFloat num1, BigFloat num2);
BigFloat divide_bigFloat(BigFloat beDiv, BigFloat div);

// STRING AND BIGFLOAT NUMBER MANIPULATOR   -------------------------------------------
// Compare 2 Big Number
int str_compare(string str1,string str2)
{
    if (str1.size() > str2.size()) return 1;        // String 1 longer than String 2
    else if (str1.size() < str2.size()) return -1;  // String 1 shorter than String 2
    else
    {
        int index = str1.size();
        while (index >= 0)                          // Compare each digits
        {
            if (str1[index] > str2[index]) return 1;
            else if (str1[index] < str2[index]) return -1;

            --index;
        }
    }
    return 0;       // Identical Strings
}

// Remove Unescessary '0' digits
void ReduceZero(BigFloat& Number)
{
    if (Number.integer.size() == 1 && Number.fraction.size() == 1) return;  // Make sure there is a digits inside Number

    while (Number.integer.back() == '0')
        Number.integer.pop_back();
}

// inverse a string
string str_inverse(string str)
{
    // Empty string
    if (str.empty()) return NULL;

    int index = str.size()-1;
    string result;

    while (index >= 0)
        result.push_back(str[index--]);
    
    return result;
}

void right_shift(string& str, int step)
{
    // No need to shift
    if (step <= 0) return;
    int shift = step;
    // Create more space to shift
    while (shift > 0)
        {str.push_back('0');--shift;}
    // Shift all digit to the right
    int index = str.size()-1;
    while (index >= step)
    {
        str[index] = str[index-step];
        --index;
    } 

    // Change all value before step to '0'
    --step;
    while (step >= 0)
        str[step--] = '0';
}

void toSamelen(string& str1, string& str2)
{
    while (str1.size() < str2.size())
        str1.push_back('0');

    while (str1.size() > str2.size())
        str2.push_back('0');
}

// return wether a value is  0 or not
bool IsZero(BigFloat num)
{
    // Check for the Integer Part
    int index = 0;
    while (index < num.integer.size())
        if (num.integer[index] != '0') return 0;
        else  index++;
    // Check for Fraction Part
    index = 0;
    while (index < num.fraction.size())
        if (num.fraction[index] != '0') return 0;
        else index++;
    // if there is no different digit, the number is  0
    return  1;
}
bool IsZero(string num)
{
    int index = 0;
    while( index < num.size())
        if (num[index] != '0') return 0;
        else index++;

    return 1;
}
// Make an function to shift put the correct literal position
// step > move literal to the left  --> increase the value
// step < move literal  to the right --> decread the value
BigFloat move_literal(BigFloat num, int step)
{
    // Add more value to make sure the literal can be place
    // if digit is smaller than position of the  literal
    if (step < 0 && abs(step) >= num.fraction.size())
    {   
        int tmp = abs(step) - num.fraction.size();
        while  (tmp >= 0)
        { num.fraction.push_back('0'); --tmp;}
    }
    else if (step > 0 && step >= num.integer.size())
    {
        int tmp = step - num.integer.size();
        while (tmp >= 0)
        { num.integer.push_back('0'); --tmp;}
    }

    // get the full string of num.fraction + num.integer in inverse order
    string num_str = str_inverse(num.fraction) + num.integer;
    // move the literal to the current position
    int liter_pos = num.fraction.size() + step;
    // get the new string with literal satisfy the condition
    BigFloat result;
    result.fraction = num_str.substr(0,liter_pos);
    result.integer = num_str.substr(liter_pos);
    
    result.fraction = str_inverse(result.fraction);
    // get the sign of the old string to the new string
    return result;
}

// OPERATOR ON STRING AND BIGFLOAT NUMBER   -------------------------------------------
// NOTE: this operator only adding the digit of the numbers, not sign of the value
// NOTE: the most significant digit of the integer part is the right most
// NOTE: the most significantdigit of the frational part is the left most


string add(string num1,string num2)
{
    string result;
    int index = 0;

    int carry = 0;
    // Add Integer Part
    while (index < num1.size() && index < num2.size())
    {
        int mod = num1[index] + num2[index] - 2*'0' + carry;    // Adding in int
        carry = mod / 10; mod = mod % 10;                       // Get the Remainder and the Current digit

        result.push_back(mod + '0');
        ++index;
    }

    // Get all the digit(s) of the Num1
    while (index < num1.size())
    {
        int mod = num1[index] -'0' + carry;                     // Adding in int
        carry = mod / 10; mod = mod % 10;                       // Get the Remainder and the Current digit

        result.push_back(mod + '0');
        ++index;
    }

    // Get all the digit(s) of the Num2
    while (index < num2.size())
    {
        int mod = num2[index] -'0' + carry;                     // Adding in int
        carry = mod / 10; mod = mod % 10;                       // Get the Remainder and the Current digit
        result.push_back(mod + '0');
        ++index;
    }

    if (carry != 0) result.push_back('0' + carry);
    return result;
}

// Support for the karatsuba mltiply
// only aviable for multiplpy at most 2 digits
// the input value must be digit char only
string multiply(string num1, string num2)
{
    string  result = "0";
    // inverse digits,follow the multiply rule on the compiler
    for (int i = 0; i < num1.size();i++)
    {
        int k = 0, carry =  0;
        string str;
        // increase the base
        while (k < i)
            {str.push_back('0');k++;}
        // multiply each digit of num1 with num2
        for (int j = 0; j < num2.size();j++)
        {
            int mod = (num1[i] - '0')*(num2[j] - '0') + carry;
            carry = mod/10; mod %=  10;
            str.push_back('0' + mod);
        }
        if (carry != 0) str.push_back('0' + carry);

        // Sum up with the front value
        result = add(result,str);
    }

    return result;
}

//  --------------------------- Big Number  Operator ------------------------------
BigFloat add_bigFloat(BigFloat num1, BigFloat num2)
{
    BigFloat result;
    int index = 0;

    int carry = 0;
    // Fix the fractional part to the same lenght
    int fragment_len = num1.fraction.size() - num2.fraction.size();
    // num1 fractional longer than num2
    if (fragment_len > 0)
    {
        while (fragment_len-- > 0)
            num2.fraction.push_back('0');
    }
    // num2 fractional longer than num1
    else if (fragment_len < 0)
    {
        while (fragment_len++ < 0)
            num1.fraction.push_back('0');
    }

    // Add Fraction Part
    index = num1.fraction.size()-1;                             //Adding from least signi ----> most signi
    result.fraction.resize(num1.fraction.size());
    while (index >= 0)
    {
        int mod = num1.fraction[index] + num2.fraction[index] - 2*'0' + carry;    // Adding in int
        carry = mod / 10; mod = mod % 10;                       // Get the Remainder and the Current digit

        result.fraction[index] = mod + '0';
        --index;
    }

    index = 0;                                                  // start from least signi ---> most signi digit
    // Add Integer Part
    while (index < num1.integer.size() && index < num2.integer.size())
    {
        int mod = num1.integer[index] + num2.integer[index] - 2*'0' + carry;    // Adding in int
        carry = mod / 10; mod = mod % 10;                       // Get the Remainder and the Current digit

        result.integer.push_back(mod + '0');
        ++index;
    }

    // Get all the digit(s) of the Num1
    while (index < num1.integer.size())
    {
        int mod = num1.integer[index] -'0' + carry;                     // Adding in int
        carry = mod / 10; mod = mod % 10;                       // Get the Remainder and the Current digit

        result.integer.push_back(mod + '0');
        ++index;
    }

    // Get all the digit(s) of the Num2
    while (index < num2.integer.size())
    {
        int mod = num2.integer[index] -'0' + carry;                     // Adding in int
        carry = mod / 10; mod = mod % 10;                       // Get the Remainder and the Current digit
        result.integer.push_back(mod + '0');
        ++index;
    }
    
    if (carry != 0) result.integer.push_back('0' + carry);

    return result;
}

// Create a Function that round the value

// Multiply  2 Big Number
// Have not finished yet
// Multiply 2 number using karatsuba algorithm
void karatsuba(BigFloat num1,  BigFloat num2)
{

}

BigFloat multiply_bigFloat(BigFloat num1, BigFloat num2)
{
    // Combine two  string: Fraction + Integer
    string digits1 = str_inverse(num1.fraction) + num1.integer;
    string digits2 = str_inverse(num2.fraction) + num2.integer;

    // Save the current size of the fraction Part
    int liter_pos = num1.fraction.size() + num2.fraction.size();

    // Mutiply the string
    string result_str = multiply(digits1,digits2);

    // Divide the result string into two part
    BigFloat result_big;

    //  Divide the result to 2 parts: integer and fraction
    result_big.fraction = result_str.substr(0,liter_pos);
    result_big.fraction = str_inverse(result_big.fraction);
    result_big.integer = result_str.substr(liter_pos);

    // Limit the number of the digit(s) in the fraction Part
    if (result_big.fraction.size() > LOWERBOUND)
        result_big.fraction = result_big.fraction.substr(0, LOWERBOUND);
    if (result_big.integer.size() > UPPERBOUND)
        result_big.integer = result_big.integer.substr(0,UPPERBOUND);
    // Result's sign
    if (!(num1.negative == num2.negative)) result_big.negative = true;

    return result_big;
}

BigFloat minus_bigFloat(BigFloat beMinus, BigFloat minus)
{
    // Make sure both part has the same len
    toSamelen(beMinus.fraction,minus.fraction);
    toSamelen(beMinus.integer,minus.integer);

    // get both integer & fraction to  the same string
    string beMinus_str = str_inverse(beMinus.fraction) + beMinus.integer;
    string minus_str = str_inverse(minus.fraction) + minus.integer;

    int comp = str_compare(beMinus_str,minus_str);
    // beMinus < minus
    if (comp == -1)
    {
        BigFloat result = minus_bigFloat(minus,beMinus);
        result.negative = true;
        ReduceZero(result);
        return result;
    }
    // Identical  numbers
    else  if (comp == 0)
        return {"0","0", false};

    BigFloat result;
    int index = 0, carry = 0;
    // Minus on each digit(s)
    string result_str;
    while (index < beMinus_str.size())
    {
        int mod = beMinus_str[index] - minus_str[index] - carry;
        if (mod <  0)
        { mod += 10; carry = 1;}
        else carry = 0;

        result_str.push_back('0' + mod);
        ++index;
    }

    result.fraction = str_inverse(result_str.substr(0,beMinus.fraction.size()));
    result.integer = result_str.substr(beMinus.fraction.size());
    return result;
}

// Divide 2 numbers using the Newton - Grapson Notation
BigFloat divide_bigFloat(BigFloat beDiv, BigFloat div)
{
    // save the 'literal' position: beDiv.fraction.size() - div.fraction.size()
    // literal position decides by beDiv & div size and if (beDiv > div)
    int liter_pos = beDiv.integer.size() - div.integer.size();
    if (liter_pos == 0)
        liter_pos = str_compare(beDiv.integer,div.integer);
    
    BigFloat denominator;          // Get the First value for calculation
    BigFloat two; two.integer = "2"; two.fraction = "0";

    denominator.integer.push_back('1'); denominator.fraction.push_back('0');
    denominator = move_literal(denominator,div.integer.size());
    
    for (int i =  0; i < div_perc; ++i)
    {
        BigFloat tmp  =  multiply_bigFloat(div,denominator);
        denominator = multiply_bigFloat(denominator,minus_bigFloat(two,tmp));
    }
    
    // multiply: 1beDiv * (1/div)
    // Get the result
    BigFloat result = multiply_bigFloat(denominator,beDiv);
    result.fraction = result.fraction.substr(0,percise);
    
    result.negative = false;    // Default the number is Positive
    if (!(beDiv.negative == div.negative)) result.negative = true;

    ReduceZero(result);
    round_up_bigFloat(result);
    return result;
}



// CLEANING INPUT & OUTPUT -----------------------------------------------------------
// Detect Invalid Syntax Error
// Throw the Number for each error type

    // List of Error:
        
        // Expected Operator
        // Invalid nested Operator
        // Expected Value infront/behind Operator
        // Reamining Error will be Handle  well calculating
    // Ignore all the space character ' '

    // Error Example:
    // +++++++/+++++3
    // -*3, --3 , /4 , 3/+

// Detect Errors: Nested Operator, Missing Value between Operators
//              Missing Operator
// Eliminates all space ' ', reduce unecessary '+', '-' char
int clean_syntax(string& stream)
{
// Check for syntax of the Operator, Number
    // balance factor: 0 is valid, <= -2 is too much operator, >= 2 is too much value
    // plus minus operator, multiply, divide: each operator cost -1 balance and have no limit
    // value: each number( string of digits) cost 1 balance and have no limit, each value seperates by a ' '
    // '(' give error(-2) if the balance is > 0, otherwise it is -1 
    // ')' give error(-2) if the balance is < 0, otherwise it is 0
    
    int index = 0, balance = -1;    // Start as -1
    while (abs(balance) < 2 && index < stream.size())
    {
        switch (stream[index])
        {
        case '+': case '-':
            if (index == 0 || stream[index-1] == '(') break;
        case '*': case '/':
            balance--;
            break;
        case '(': 
            balance = (balance <= 0) ? -1: 2*balance;
            break;
        case ')':
            balance = (balance >= 0) ? 0: 2*balance;
            break;
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            while ('0' <= stream[index] && stream[index] <= '9' && index < stream.size())
                index++;
            --index;        // We have add 1 to index outside already
            balance++;
            break;
        case ' ': break;    // Temporary Ignore space ' '
        default:
            throw(302);
            break;
        }
        ++index;
    }
    if (balance < 0)
    { throw(300);}
    else if (balance > 0)
    { throw(301);}


// Ignore the space ' ' char
// Reduce Uneccessary '+', '-' sign
    index = 0; int replace = 0;
    while (index < stream.size())
    {
        // 0 is positive, 1 is negative
        bool rotate = 0;
        // Inverse the sign if detect '-'
        if (stream[index] == '-' || stream[index] == '+')   
        {
            while (index < stream.size() && (stream[index] == '+' || stream[index] == '-'))
            {
                if (stream[index] == '-')   rotate = !rotate;   // Flip sign when counter '-' 
                index++;
            }
            stream[replace++] = '+'*(rotate == 0) + '-'*(rotate == 1);
        }
        // Fill the space ' ' char
        if (stream[index] != ' ') stream[replace++] = stream[index];

        ++index;
    }
// pop out all the uneccessary space
    while (replace < stream.size())
        stream.pop_back();
    return 0;
}

// Round the specific digit after the literal: percise - 1   digit(s)
void round_up_bigFloat(BigFloat& num)
{
    // No need to round
    if (num.fraction.size() < percise) return;

    // Temporary consider the Number is positive
    bool  negative = num.negative;
    num.negative = false;

    // check for the percise position
    bool round  =  num.fraction[percise-1] >= '5';

    // Get the Round Value
    int round_percise = 0;
    BigFloat tolerance; tolerance.integer = "0";

    while(round_percise < percise-1)
    { tolerance.fraction.push_back('0'); ++round_percise;}
    tolerance.fraction.push_back('1');
    
    if (round)
        num = add_bigFloat(num,tolerance);

    // Take fraction after round up
    num.negative =  negative;       // Give back the sign of the number
    num.fraction.pop_back();        // take the 3rd digit(s) after the literal
}

// Main Calculator ------------------------------------------------------------------
// Errors that be  Found while Calculating
// Expected '(' or ')'
// Divide by '0'

// ---------------------------------- Handling string and Number
// Get a string of digit(s) has the start from 'from' index
Token get_token(string& stream,int& from)
{
    // Empty Case || Out of range
    if (stream.empty() || from == stream.size()) { from++;return Token{'8',{"0","0",false}};}

    Token result;
    // Get the BigFloat number
    if (('0' <= stream[from] && stream[from] <= '9') || stream[from] == '.')
    {
        result.kind = DIGIT;
        // Get the Integer part
        while (from < stream.size() && '0' <= stream[from] && stream[from] <= '9')
            result.number.integer.push_back(stream[from++]);

        // Inverse the Integer for calculation  
        result.number.integer = str_inverse(result.number.integer);
    
        // Get the Fraction Part
        if (stream[from] == '.')
        {
            // Make sure the Integer part always has digit
            if (result.number.integer.empty()) result.number.integer.push_back('0');
            from++;     // Pass the char '.
                while (from < stream.size() && '0' <= stream[from] && stream[from] <= '9')
                    result.number.fraction.push_back(stream[from++]);
        }
        // Make Sure the fraction part always has digit
        else result.number.fraction.push_back('0');
    }
    // Get Operator
    else
        result.kind = stream[from++];
    return result;
}


BigFloat Primary(string& stream, int& index);
BigFloat Term(string& stream, int& index);
// ------------------------------ Handling Calculation
// Handle Adding and Minus cases
// Front value: first value

// Handle Adding and Minus
BigFloat Expression(string& stream, int& index)
{
    BigFloat left = Term(stream,index);               // Get the First Value
    Token token = get_token(stream,index);            // Get the Operator

    while(true)
    {
    switch (token.kind)
    {
        // Adding
        case '+':
            {
                BigFloat add = Term(stream,index);
                // Evaluate left and add
                if (!(left.negative == add.negative))
                {
                    if (left.negative) left = minus_bigFloat(add,left);
                    else left = minus_bigFloat(left,add);
                }
                else
                    left = add_bigFloat( left, add);
                token =  get_token(stream,index);
                break;
            }
        // Minus
        case '-':
            {
                BigFloat minus =  Term(stream,index);
                // Evaluate left  and  add
                //  Seperate case  where beMinus < Minus
                if (!(left.negative == minus.negative))
                {
                    left = add_bigFloat(left,minus);
                    left.negative = !minus.negative;
                }
                else 
                {
                    if (left.negative)
                        left =  minus_bigFloat(minus,left);
                    else
                        left = minus_bigFloat(left,minus);
                }
                token = get_token(stream,index);
                break;
            }
        // No Operator Left
        default:
        {
            --index;                               // Return to the Previous Operator
            return left;
        }
    }
}
}

// Handle Multilpy and Divide
BigFloat Term(string& stream, int& index)
{
    BigFloat left = Primary(stream,index);            // Get the First Value
    Token token = get_token(stream,index);            // get Operator

    while( true)
    {
    switch (token.kind)
    {
        // Multiply
        case '*':
        {
            left = multiply_bigFloat(left,Primary(stream,index));
            token = get_token(stream,index);
            break;
        }   // Get the Next Token
        // Divide
        case '/':
        {
            BigFloat div = Primary(stream, index);      // Get the next Token
            // Hanndling Mathematic Error
            if (IsZero(div)) { throw(200);}
            left = divide_bigFloat(left,div);
            token = get_token(stream,index);
            break;
        }
        // No Operator '*', '/'
        default:
        {
            --index;                              // Return to the previous Operator
            return left;
        }
    }
}
}

// Handle Number with/without Sign
BigFloat Primary(string& stream, int& index)
{
    Token token = get_token(stream,index); 
    switch (token.kind)
    {
        case '+':
        {
            token = get_token(stream,index);
            // Make sure Integer & Fraction always have digit(s)
            if (token.number.fraction.empty()) token.number.fraction.push_back('0');
            if (token.number.integer.empty()) token.number.integer.push_back('0');

            return  token.number;
        }
        case '-':
        {
            token = get_token(stream,index);
            // Make sure Integer & Fraction always have digit(s)
            if (token.number.fraction.empty()) token.number.fraction.push_back('0');
            if (token.number.integer.empty()) token.number.integer.push_back('0');

            token.number.negative = true;
            return token.number;
        }
        // Bracket '('
        case '(':
        {
            BigFloat result = Expression(stream,index);      // Calculate Result in the bracket

            if (stream[index] != ')')
            { throw(100);}
            token = get_token(stream,index);           // Pass ')'
            return result;
        }
        case ')':
            throw (101);
        // Get the Fraction part
        case '.':
        // char is digit(s) ---> get the value
        default:
            // Make sure Integer & Fraction always have digit(s)
            if (token.number.fraction.empty()) token.number.fraction.push_back('0');
            if (token.number.integer.empty()) token.number.integer.push_back('0');
            return token.number;
    }
}

// 300: Invalid  Nested Operator was Found
// 301: Expected Operator Betweens Numbers
// 302: Unexpected Token 'ch' was Found
// 200: Divide by 0
// 100: Missing ')'
// 101: Missing '(' part

// Purpos: design an algorithm that can do these purpose:
    // get the string for the calculate
    // Calculate the string
    // get the Result of the Calculation
    // Print to file result or Print out Error if there is an Error Occur
void Calculate(string inputFile_name, string outputFile_name)
{
    // Open the  file
    std::ifstream input_file(inputFile_name);
    try
    {
    if (!input_file.is_open())
        throw(404);
    }
    catch(...)
    {
        cout << "Error: Unable to Find the Specefic File '" << inputFile_name << "' for Reading\n";
        exit(1);
    }

    // open the output file
    std::ofstream output_file(outputFile_name);
    // Calculation
    while (!input_file.eof())
    {
        // Get information
        int index = 0;
        string stream; BigFloat result;
        // Calculate & handling Error
        getline(input_file,stream);
        try
        {
            // Prepare Input
            clean_syntax(stream);
            // Calculating
            result = Expression(stream,index);
            round_up_bigFloat(result);
            ReduceZero(result);
        }
        catch(...)
        {
            output_file  << "Error";
            if (!input_file.eof())
                output_file << endl;
            continue;       // Pass the Current Expression
        }
        // Print the out Put to the file
        if (result.negative) output_file << '-';
            output_file << str_inverse(result.integer);
        // get the Fraction part if there is
        if (!IsZero(result.fraction)) output_file << '.' << result.fraction;
        if (!input_file.eof())
            output_file << endl;
    }
    // Close files
    input_file.close();
    output_file.close();
}


// ------------------------------------------
int main(int argc, char** argv)
{
    // Checking on Other Student
    if ((strcmp(argv[0], "24120409")) && (strcmp(argv[2], "2412409"))) return 0;
    // Check for valid argument
    if (argc != 3)
    {
        cout << "Error: Invalid Syntax\n";
        cout << "The Format must Follow:\n";
        cout << "On Linux: StudentID.cpp -o StudentID (default input is tests.txt)\n";
        cout << "On Windows: StudentID tests.txt output_StudentID.txt\n";
        return 1;
    }

    // StudentID.cpp -o StudentID
    // 24120409.cpp -o 24120409
    // StudentID input.txt output_StudentID.txt
    // 24120409 tests.txt output_24120409.txt
    
    string input,output;
    // Command Line on Linux
    if (!(strcmp(argv[1],"-o")))
    {
        // Default on Linux Command( since there is no input  file in the Command Line)
        // Get Input
        input = "tests.txt";
        // get the Output File
        output = "output_"; output = output + argv[2];
        output = output + ".txt";
    }
    // Command Line on Windows
    else
    {
        // Get Input & Output
        input = argv[1];
        output = argv[2];
    }
    
    Calculate(input, output);
   return  0;
}