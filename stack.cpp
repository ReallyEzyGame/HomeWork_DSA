#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Node of each key value
struct NODE
{
	int key;
	NODE* p_next;
	NODE() : p_next(nullptr) {};
};


// Stack contains the key value of the stack
struct Stack
{
	NODE* top;
	Stack() : top(nullptr) {};
	~Stack()
	{
		// Empty Stack
		if (top == nullptr) return;
		// Delete all the Node but the Tail Node
		NODE* tmp = top;
		while (tmp->p_next)
		{
			NODE* del = tmp;
			tmp = tmp->p_next;
			delete del;
		}
		// Delete the Tail Node
		delete tmp;
	}
};

Stack* initializeStack()
{
	Stack* stack = new Stack;
	// Out of Memory exception
	try {
		if (stack == nullptr)
		{
			throw(2);
		}
	}
	catch (...)
	{
		cout << "Error: Out of Memory\nUnable to Allocate a new Stack\n";
		exit(0);
	}
	return stack;
}


// Create a New Node contains the key value
NODE* createNode(Stack*& stack, int key)
{
	NODE* add = new NODE;
	// Out of memory Excpetion
	try 
	{
		if (add == nullptr)
			throw(3);
	}
	catch(...)
	{
		cout << "Error: Out of Memory for Allocation\nUnable to Allocate a new Node\n";
		exit(0);
	}

	add->key = key;

	return add;
}


// Push a new Key to a Stack
void push(Stack* &stack, int key)
{
	// List doesn't exist case
	if (stack == nullptr)
	{
		cout << "Add New Node to List Failed\nList doesn't Exist\n";
		return;
	}

	NODE* add = createNode(stack, key);

	// Add to Empty Stack
		if (stack->top == nullptr)
			stack->top = add;
		// Add to Normal Stack
		else
		{
			add->p_next = stack->top;
			stack->top = add;
		}
}


// Getting the top value
int pop(Stack*& stack)
{
	// Stack doesn';t exist
	if (stack == nullptr)
	{
		cout << "Stack doesn't Exist\n";
		return NULL;
	}
	// Pop to Empty Stack
	if (stack->top == nullptr)
	{
		cout << "Pop to an Empty Stack\n";
		return NULL;
	}
	// Get the Key value
	int key = stack->top->key;

	// Remove the top NODE
	NODE* del = stack->top;
	

	stack->top = del->p_next;
	delete del;
	return key;
}


// Get the Size of a Stack
int size(Stack*& stack)
{
	// Stack doesn't Exist
	if (stack == nullptr)
	{
		cout << "Stack doesn't Exist\n";
		return 0;
	}
	// Empty Stack
	if (stack->top == nullptr)
		return 0;

	// Normal Stack
	NODE* tmp = stack->top;
	int count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->p_next;
	}
	return count;
}


// Check whether the Stack is Empty or Not
bool isEmpty(Stack* &stack)
{
	// Stack doesn't eixst
	if (stack == nullptr) return false;
	// Stack is Empty
	if (stack->top == nullptr) return true;

	// Stack is not Empty
	return false;
}


void displays(Stack*& stack)
{
	// Stack doesn't exist
	if (stack == nullptr)
		return;

	NODE* tmp = stack->top;
	while (tmp)
	{
		cout << tmp->key << "  --->  ";
		tmp = tmp->p_next;
	}
	cout << "NULL\n";
}

// We only need to take the value in the string of "push x" as x is an integer value
int convStrtoInt(string str)
{
	int i = 5;
	int value = 0; bool negative = 0;

	// Getting the Negative value
	if (str[i] == '-')
	{
		++i;		// Approach the next digits
		negative = 1;
	}
	// Getting the Digits
	while (i < str.size() && str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	
	if (negative) value = -value;
	return value;
}
// Note: the input & output file must be the same directory as the .exe terminal
int main()
{
	// Open the Input file for reading command
	
	ifstream input(".\\input.txt"); 
	

	Stack* stack;
	string line;
	
	if (!input.good())
	{
		cout << "Not good\n";
		return 1;
	}
	// Open( create) a file for writting the result
	ofstream output(".\\output.txt");


	// init command
	getline(input, line);
	if (!line.compare(0, 4, "init"))
	{
		stack = initializeStack();
		output << "EMPTY\n";
	}
	// if there is no intit command
	else
	{
		cout << "Cannot Access Further Function due to the Stack hasn't been initialized\n";
		cout << "The Program has been Stopped\n";
		return 1;
	}

	while (getline(input, line))
	{
		cout << line << endl;
		// push command
		if (!line.compare(0, 4, "push"))
		{
			push(stack, convStrtoInt(line));

			// Print out the Stack to the output file
			NODE* tmp = stack->top;
			while (tmp)
			{
				output << tmp->key << " ";
				tmp = tmp->p_next;
			}
			output << "\n";
		}

		// Pop a Node out of the Stack
		if (!line.compare(0, 3, "pop"))
		{
			int key = pop(stack);
			// Print out the Stack key

			// Empty Stack
			if (stack->top == nullptr)
			{
				output << "EMPTY\n";
			}
			// Print out all the Key value in the Stack
			else
			{
				NODE* tmp = stack->top;
				while (tmp)
				{
					output << tmp->key << " ";
					tmp = tmp->p_next;
				}
				output << "\n";
			}
		}

		// Check if Stack is Empty
		if (!(line.compare(0, 7, "isEmpty")) || !(line.compare(0, 7, "isempty")))
		{
			bool empty = isEmpty(stack);
			output << "Is Empty: ";
			if (empty) output << "True\n";
			else output << "False\n";
		}

		// Get the size of the Stack
		if (!line.compare(0, 4, "size"))
		{
			int s = size(stack);
			output << "Stack's Size: " << s << endl;
		}
	}

	// close the input file
	// close the output file
	input.close();
	output.close();
}