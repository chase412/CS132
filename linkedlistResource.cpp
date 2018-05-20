//Ayaka Nishihori
//CS132 Homework 17
//Question 4
//Day: 05/18/2018
//Time spend: 3hr 30 min

#include "linkedlist.h"
#include<iostream>
using namespace std;

template <class T>
MyLinkedList<T>::MyLinkedList()        //defalt constructor 
{
	head = nullptr;
}

template <class T>
MyLinkedList<T>::~MyLinkedList()       //destructor
{
	ListNode *traverse = new ListNode; //Traversing list
	ListNode *nextNode;
	traverse = head;
	while (traverse != nullptr)
	{
		nextNode = traverse->next;//Save the pointer to next Node
		delete traverse;          //delete current Node
		traverse = nextNode;      // Position nodePtr at the next node. 
	}
	cout << "Destroys list" << endl;
}

template <class T>
void MyLinkedList<T>::appending(T n)
{
	ListNode *newNode = new ListNode;//Point a new Node 
	ListNode *traverse = new ListNode; //Traversing pointer 
	traverse = head;

	newNode->data = n;
	newNode->next = nullptr;

	if (head == nullptr)//If there is no Node on the list, then make first Node
	{
		head = newNode; //Creat new Node
	}
	///////////////////////////////////////////////////
	//Find the Last Node and add the newNode to last.//
	///////////////////////////////////////////////////
	else
	{
		while (traverse->next != nullptr)//If pointer is pointing Node
		{
			traverse = traverse->next;  //Find the last Node in the list
		}
		traverse->next = newNode;       //Insert new Node. point newNode 
	}
	//size++;
}

template <class T>
void MyLinkedList<T>::inserting(T n)
{
	ListNode *newNode = new ListNode; //New Node 
	ListNode *traverse = new ListNode;//Traversing
	ListNode *preNode = nullptr;      //Previouse Node
	traverse = head;
	newNode->data = n; //Point the numebr 

	///////////////////////////////////////////
	//If there is no Node, then creat new one//
	///////////////////////////////////////////
	if (head == nullptr)//If there is no Node on the list, then make first Node
	{
		head = newNode; //Creat new Node
		newNode->next = nullptr;
	}
	///////////////
	//Insert Node//
	///////////////
	else
	{
		//While loop until traverse find the Node that less than n
		while (traverse != nullptr && traverse->data < n)
		{
			preNode = traverse;
			traverse = traverse->next;
		}
		///////////////////////////////////////
		//If newNode need to be the first one//
		///////////////////////////////////////
		if (preNode == nullptr)
		{
			head = newNode;
			newNode->next = traverse;
		}
		/////////////////////////////
		//Insert after then preNode//
		/////////////////////////////
		else
		{
			preNode->next = newNode;
			newNode->next = traverse;
		}
	}
	//size++;
}
template <class T>
void MyLinkedList<T>::deleteNode(T n)
{
	ListNode *traverse; //For traverse the list
	ListNode *preNode = new ListNode;  //pointer for the previouse Node

	//////////////////////////////////////
	//If list is empty, then do nothing //
	//////////////////////////////////////
	if (head == nullptr) { return; }

	if (head->data == n)//Finding whether the first one is the one
	{
		traverse = head->next;
		delete head;
		head = traverse;
	}
	else
	{
		traverse = head;//intialize traverse to head of list
		/////////////////////////////////////////////////
		//While loop until the Node is same number as n//
		/////////////////////////////////////////////////

		while (traverse != nullptr && traverse->data != n)
		{
			preNode = traverse;
			traverse = traverse->next;
		}
		//If the traverse is not the end of the list
		if (traverse)
		{
			preNode->next = traverse->next;
			delete traverse;
		}
	}
	//size--;
}

template <class T>
void MyLinkedList<T>::display()
{
	ListNode *traverse = new ListNode;
	traverse = head;
	if (head == nullptr)
	{
		return;
	}
	while (traverse != nullptr)
	{
		cout << traverse->data << ", ";
		traverse = traverse->next;
	}
}
template <class T>
void MyLinkedList<T>::reverse()
{
	ListNode *traverse;
	ListNode *lastOne;

	traverse = head;
	lastOne = nullptr;

	while (traverse != nullptr)
	{
		ListNode *nextOne = traverse->next; //Save the first element to temp1
		traverse->next = lastOne;//next element point previouse element
		lastOne = traverse;
		traverse = nextOne;//swap temp1 and traverse
	}
	head = lastOne;
}
template <class T>
int MyLinkedList<T>::search(T n)
{
	int count = -1;
	ListNode *traverse;
	traverse = head;

	while (traverse != nullptr && traverse->data != n)//increase count until the number
	{
		//cout << count << endl;
		count++;
		traverse = traverse->next;
	}
	if (traverse != nullptr)//If the the pointer is nuber not nullptr then increment 1
	{
		//cout << "!!" <<count<< endl;
		count++;
		traverse = traverse->next;
	}
	else//If there is no number
	{
		return -1;
	}
	return count;

}