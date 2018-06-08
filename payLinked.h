/*
Taesoo Lee
Linked list header and resource file for groupProject
Group Project
5/23/2018
Spent 20 minutes?
*/

#ifndef PAYLINKED_h
#define PAYLINKED_h

#include <iostream>
#include <string>
using namespace std;

template <class T>
class LinkedList {
private:
	struct ListNode {
		T value;
		ListNode *next;
	};
	ListNode *head;

public:
	LinkedList();
	~LinkedList();
	void insert(T);
	void display();
	void deleteNode(T);
	void appendNode(T);
	void reverse();
	int search(T);
};

template <class T>
LinkedList<T>::LinkedList() {
	head = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {
	ListNode *traverse = head;
	if (head == nullptr) {
		delete head;
		return;
	}
	ListNode *after = head->next;
	while (after != nullptr) {
		delete traverse;
		traverse = after;
		after = after->next;
	}

}

template <class T>
void LinkedList<T>::insert(T x) {
	ListNode *temp2 = new ListNode;
	ListNode *temp;
	temp2->value = x;
	temp2->next = nullptr;

	if (head == nullptr) {
		head = temp2;
	}
	else {
		if (head->value > x) {
			temp2->next = head;
			head = temp2;
			return;
		}

		temp = head;

		while (temp->next != nullptr && (temp->next->value) < x) {
			temp = temp->next;
		}
		if (temp->next == nullptr) {
			temp->next = temp2;
		}
		else {
			temp2->next = temp->next;
			temp->next = temp2;
		}
	}
}

template <class T>
void LinkedList<T>::deleteNode(T x) {
	ListNode *before = head;
	ListNode *current = head;
	if (head == nullptr)
		return;
	current = head->next;

	while (current != nullptr&&current->value != x) {
		current = current->next;
		before = before->next;
	}
	if (current == nullptr)
		return;
	if (current->value == x) {
		before->next = current->next;
		delete current;
	}

}

template <class T>
void LinkedList<T>::display() {
	ListNode *temp = head;
	while (temp != nullptr) {
		cout << "Name : " << (temp->value).getName() << endl;
		temp = temp->next;
	}
}

template <class T>
void LinkedList<T>::appendNode(T x) {
	ListNode *newNode = new ListNode;
	newNode->value = x;
	newNode->next = nullptr;
	ListNode *traverse = head;
	if (head == nullptr) {
		head = newNode;
		return;
	}
	while (traverse->next != nullptr) {
		traverse = traverse->next;
	}
	traverse->next = newNode;
}

template <class T>
void LinkedList<T>::reverse() {
	if (head == nullptr || head->next == nullptr)
		return;


	ListNode* before = head;
	ListNode* current = head->next;
	ListNode* after = head->next->next;
	before->next = nullptr;

	while (after != nullptr) {
		current->next = before;
		before = current;
		current = after;
		after = after->next;
	}
	current->next = before;
	head = current;
}

template <class T>
int LinkedList<T>::search(T x) {
	ListNode* traverse = head;
	int count = 0;
	while (traverse != nullptr) {
		if (traverse->value == x)
			return count;
		count++;
		traverse = traverse->next;
	}
	return -1;
}

#endif