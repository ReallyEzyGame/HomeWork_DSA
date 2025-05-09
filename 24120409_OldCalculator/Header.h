#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;
#define MemorySize 1

#define number '0'
#define bigNumber '1'
#define MaxSize 1024	// The Max char of a Calcution can handle( change if it's needed)
#define BigIntSize MaxSize/2	// the Limit of the char in a bigInt( can be changed if it's needed)

typedef struct
{
	char* digits;
	int tail;
}bigInt;

// Handle Big Int
bool IsBigInt(char* expression, int head);
void Addone(bigInt& big, int pos);
bigInt Plus2BigInt(bigInt bigOne, bigInt bigTwo);
bigInt plusBigInt(bigInt big, int pos, int add);
bigInt minusBigInt(bigInt big, int pos, int min);
bigInt minus2BigInt(bigInt beMinus, bigInt Minus);
bigInt mutiplyBigInt(bigInt big, int mul);
bigInt mutiply2BigInt(bigInt bigOne, bigInt bigTwo);
bigInt divideBigint(bigInt big, int div);
void clearArea(char* expression, int head, int tail);
void putBigInt(char* expression, bigInt& big, int pos);
bigInt getBigInit(char* expression, int& head);
void toNegative(bigInt& big);
void toPositive(bigInt& big);

// Handle Normal Int
double getNumber(char* expression, int& head);