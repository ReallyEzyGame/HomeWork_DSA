#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Each Node in a Queue
struct NODE
{
	int key;
	NODE* p_next;
	NODE() : p_next(nullptr) {};
};

// Queue List
struct Queue
{
	NODE* head;
	NODE* tail;
	Queue() : head(nullptr), tail(nullptr) {};
	~Queue()
	{
		// Empty List
		if (head == nullptr)
			return;
		// Delete all the Node in the Queue but the Tail node
		NODE* tmp = head;
		while (tmp->p_next)
		{
			NODE* del = tmp;
			tmp = tmp->p_next;
			delete del;
		}
		// Delete the tail node
		delete tmp;
	}
};


Queue* initializeQueue()
{
	Queue* queue = new Queue;

	// Out of Memory for allocation
	try
	{
		if (queue == nullptr)
			throw(1);
	}
	catch (...)
	{
		cout << "Error: Allocation for Queue Failed due to the Lack of Memory for Allocation\nThe Program has been Stop\n";
		exit(1);
	}

	return queue;
}


// Create new Node for Queue
NODE* createNode(int key)
{
	NODE* add = new NODE;
	// Out of Memory
	try
	{
		if (add == nullptr)
			throw(1);
	}
	catch (...)
	{
		cout << "Error: Allocation for Node Failed due to the Lack of Memory for Allocation\nThe Program has been Stop\n";
		exit(1);
	}

	add->key = key;
	return add;

}


// Adding a new key value to a Queue
void enqueue(Queue* &queue, int key)
{
	// Queue doen't Exist
	if (queue == nullptr)
	{
		cout << "Queue does not Exist\n";
		return;
	}

	NODE* add = createNode(key);
	// Add to an Empty Queue
	if (queue->head == nullptr)
	{
		queue->head = queue->tail = add;
	}
	// Add to a Normal Queue
	else
	{
		add->p_next = nullptr;
		queue->tail->p_next = add;
		queue->tail = add;
	}
}


// Remove a Node in a Queue( FIFO rule)
int dequeue(Queue*& queue)
{
	// Queue Doesn't Exist
	if (queue == nullptr)
	{
		cout << "Queue Doesn't exist\n";
	}
	// Empty Queue
	if (queue->head == nullptr)
	{
		cout << "Dequeue from an Empty Queue\n";
		return NULL;
	}

	// remove the head & get the key value
	NODE* pop = queue->head;
	queue->head = pop->p_next;

	int key = pop->key;
	delete pop;

	return key;
}


// Get the Size of a Queue
int size(Queue*& queue)
{
	//  List doesn't Exist
	if (queue == nullptr)
	{
		cout << "List doesn't exist\n";
		return -1;
	}
	// Empty List
	if (queue->head == nullptr)
		return 0;

	// Count all the Node in the List
	NODE* tmp = queue->head;
	int count = 0;
	while (tmp)
	{
		++count;
		tmp = tmp->p_next;
	}

	return count;
}


// Check if the Queue is Empty
bool isEmpty(Queue* &queue)
{
	// List doesn't exist
	if (queue == nullptr)
	{
		cout << "Queue doesn't exist\n";
		return false;
	}
	// Empty List
	if (queue->head == nullptr)
		return true;

	// OtherWise
	return false;
}


void displays(Queue*& queue)
{
	// queue doesn't exist
	if (queue == nullptr)
		return;

	NODE* tmp = queue->head;
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
	// i = 8 since the first char of the number is 8
	int i = 8;
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


	Queue* queue;
	string line;

	if (!input.good())
	{
		cout << "Unable to Open the File for Reading\nThe File may not be Exist";
		return 1;
	}

	// Open( create) a file for writting the result
	ofstream output(".\\output.txt");


	// init command
	getline(input, line);
	if (!line.compare(0, 4, "init"))
	{
		queue = initializeQueue();
		output << "EMPTY\n";
	}
	// if there is no intit command
	else
	{
		cout << "Cannot Access Further Function due to the Queue hasn't been initialized\n";
		cout << "The Program has been Stopped\n";

		output << "Cannot Access Further Function due to the Queue hasn't been initialized\n";
		output << "The Program has been Stopped\n";

		input.close();
		output.close();
		return 1;
	}

	while (getline(input, line))
	{
		cout << line << endl;
		// push command
		if (!line.compare(0, 7, "enqueue"))
		{
			enqueue(queue, convStrtoInt(line));

			// Print out the Stack to the output file
			NODE* tmp = queue->head;
			while (tmp)
			{
				output << tmp->key << " ";
				tmp = tmp->p_next;
			}
			output << "\n";
		}

		// Pop a Node out of the Stack
		if (!line.compare(0, 7, "dequeue"))
		{
			int key = dequeue(queue);
			// Print out the Stack key

			// Empty Stack
			if (queue->head == nullptr)
			{
				output << "EMPTY\n";
			}
			// Print out all the Key value in the Stack
			else
			{
				NODE* tmp = queue->head;
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
			output << "Is Empty: ";
			if (isEmpty(queue)) output << "True\n";
			else output << "False\n";
		}

		// Get the size of the Stack
		if (!line.compare(0, 4, "size"))
		{
			output << "Queue's Size: " << size(queue) << endl;
		}
	}

	// close the input file
	// close the output file
	input.close();
	output.close();
}