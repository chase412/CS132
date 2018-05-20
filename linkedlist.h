//Ayaka Nishihori
//CS132 Homework 17
//Question 4
//Day: 05/18/2018
//Time spend: 3hr 30 min


#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<iostream>
using namespace std;

template <class T>
class MyLinkedList
{
private:
	struct ListNode
	{
		T data;       //Integer Number
		struct ListNode *next; //pointer poit to next Node
	};
	ListNode *head;     //signal for the first Node
	//int size;
public:
	MyLinkedList();     //defalt constructor 
	~MyLinkedList();    //destructor
	void appending(T);
	void inserting(T);
	void deleteNode(T);
	void reverse();//Question4 Revers method 
	void display();
	int search(T);
};
#endif
