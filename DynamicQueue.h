#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H
#include<iostream>
#include<string>
using namespace std;

///////////////////////////////
//HW18 Using Dynamic queue   //
//instead of array           //
///////////////////////////////
template<class T>
class DynamicQueue
{
public:
	struct QueueNode
	{
		T data;
		QueueNode *next;
	};
	QueueNode *front;
	QueueNode *rear;
	int numElement;
public:
	DynamicQueue();
	~DynamicQueue();
	void enqueue(T);
	void dequeue(T &);
	bool isEmpty();
	void clear();
	void display();

};

template <class T>
DynamicQueue<T>::DynamicQueue()
{
	front = NULL;
	rear = NULL;
	numElement = 0;
}

template <class T>
DynamicQueue<T>::~DynamicQueue()
{
	clear();
}

template <class T>
void DynamicQueue<T>::enqueue(T n)
{
	QueueNode *newNode = new QueueNode;

	newNode->data = n;
	newNode->next = NULL;

	if (isEmpty())//If there are no Node 
	{
		front = newNode;
		rear = newNode;
	}
	else//Add to the last Node 
	{
		rear->next = newNode;
		rear = newNode;
	}
	numElement++;//increment size
}

template <class T>
void DynamicQueue<T>::dequeue(T &n)//FIFO
{
	QueueNode *temp = NULL;

	if (isEmpty())
	{
		cout << "The queue is EMPTY" << endl;
	}
	else
	{
		n = front->data;
		temp = front;       //Get first Node
		front = front->next;//front becase first one's next
		delete temp;        //Delete the first Node
		numElement--;
	}
}

template <class T>
bool DynamicQueue<T>::isEmpty()
{
	bool result;
	if (numElement > 0)
		result = false;
	else
		result = true;

	return result;
}

template <class T>
void DynamicQueue<T>::clear()
{
	T n;
	while (isEmpty() == true)
	{
		dequeue(n);
	}
}

template <class T>
void DynamicQueue<T>::display()
{
	QueueNode *temp = front;
	while (temp != nullptr) {
		cout << "Name : " << (temp->data).getName() << endl;
		temp = temp->next;
	}
}


#endif