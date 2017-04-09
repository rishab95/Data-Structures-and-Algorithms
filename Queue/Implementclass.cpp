#include <iostream>
#define size 101
using namespace std;
// Current Position = i
// Next Position  = (i+1)%n
//Prev Position = (i+n-1)%n
class Queue
{
	int arr[size];
	int front, rear;
public:
	Queue()
	{
		front = -1;
		rear = -1;
	}
	bool isEmpty()
	{
		return (front == -1 && rear == -1);
	}

	bool isFull()
	{
		return (rear + 1) % size == front ? true : false;
	}

	void enqueue()
	{
		int x;
		if (isFull())
		{
			cout << "Queue is Full\n";
			return;
		}
		else
		{
			
			cout << "Enter the element: \n";
			cin >> x;
			if (isEmpty())
			{
				front = rear = 0;
			}
			else
			{
				rear = (rear + 1) % size;
			}
				arr[rear] = x;
		}
	}

	void dequeue()
	{
		if (isEmpty())
		{
			cout << "Queue is Empty\n";
			return;
		}
		else if (front == rear)
		{
			front = rear = -1;
		}
		else
		{
			front = (front + 1) % size;
		}
	}

	int Front()
	{
		if (front == -1)
		{
			cout << "Error Try again\n";
			return -1;
		}
		return arr[front];
	}

	void print()
	{
		int count = (size - front + rear) % size + 1;
		int p;
		cout << "Queue \n";
		for (int i = 0; i<count; i++)
		{
			p = (front + i) % size;
			cout << arr[p] << " ";
		}
		cout << "\n";
	}

};

int main()
{
	Queue q;
	cout << "Queue Operations \n";
	cout << "1.Insert\n" << "2.Delete\n" << "3.Exit\n";
	int ch;
	do
	{
		cout << "Your Choice: ";
		cin >> ch;
		switch (ch);
		{
		case 1:	q.enqueue();
				q.print();
				break;
		case 2: q.dequeue();
				q.print();
				break;
		case 3: exit();
		default: cout << "Invalid \n";
		}
		cout << "Do u want to continue (1/0)\n";
		cin >> ch;
	} while (1);
	return 0;
}

