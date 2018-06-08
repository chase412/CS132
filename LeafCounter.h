//Ayaka Nishihori
//HW20
//CS 132 Question 3
//Leaf Counter 
//Day: 06/06
//Time spend:1hr 

#ifndef LEAFCOUNTER_H
#define LEAFCOUNTER_H
#include<iostream>
using namespace std;


#include<iostream>
using namespace std;

template<class T>
class BinaryTreeTemplate
{
private:
	struct TreeNode
	{
		T data;
		TreeNode *left;
		TreeNode *right;
	};
	TreeNode *root;
	int numberNode;

	void insert(TreeNode *&, TreeNode  *&);
	void destorySubTree(TreeNode *);
	void deleteNode(T, TreeNode *&);
	void makeDeletion(TreeNode *&);
	void displayInOrder(TreeNode *)const;
	void displayPreOrder(TreeNode *)const;
	void displayPostOrder(TreeNode *)const;
	int countNode(TreeNode *);//Count number of Node in the Binary Tree
public:
	BinaryTreeTemplate() { root = NULL; }
	~BinaryTreeTemplate() { destorySubTree(root); }
	void insertNode(T);
	bool serarchNode(T);
	void remove(T);
	void displayInOrder()const { displayInOrder(root); }
	void displayPrOrder()const { displayPreOrder(root); }
	void displayPostOrder()const { displayPostOrder(root); }
	int countNode() { return countNode(root); }  //Count number of Node in the Binary Tree
	
};

template<class T>
int BinaryTreeTemplate<T>::countNode(TreeNode *traverse)//Count Node function
{
	numberNode++;
	if (traverse)
	{
		if (traverse->left)//if there are Node in left side 
			countNode(traverse->left);
		if (traverse->right)
			countNode(traverse->right);
	}
	return numberNode;
}
template<class T>
void BinaryTreeTemplate<T>::insert(TreeNode *&traverse, TreeNode *&newNode)
{
	if (traverse == NULL)
		traverse = newNode;
	else if (newNode->data < traverse->data)
		insert(traverse->left, newNode);
	else if (newNode->data > traverse->data)
		insert(traverse->right, newNode);
}

template<class T>
void BinaryTreeTemplate<T>::insertNode(T n)
{
	TreeNode *newNode = NULL;
	newNode = new TreeNode;
	newNode->data = n;
	newNode->left = newNode->right = NULL;
	insert(root, newNode);
}
template<class T>
void BinaryTreeTemplate<T>::destorySubTree(TreeNode *traverse)
{
	if (traverse)
	{
		if (traverse->left)
			destorySubTree(traverse->left);
		if (traverse->right)
			destorySubTree(traverse->right);
		delete traverse;
	}
}
template<class T>
bool BinaryTreeTemplate<T>::serarchNode(T n)
{
	TreeNode *traverse = root;
	while (traverse)
	{
		if (traverse->data == n)
			return true;
		else if (n < traverse->data)
			traverse = traverse->left;
		else
			traverse = traverse->right;
	}
	return false;
}
template<class T>
void BinaryTreeTemplate<T>::remove(T n)
{
	deleteNode(n, root);
}
template<class T>
void BinaryTreeTemplate<T>::deleteNode(T n, TreeNode *&traverse)
{
	if (n < traverse->data)
		deleteNode(n, traverse->left);
	else if (n > traverse->data)
		deleteNode(n, traverse->right);
	else
		makeDeletion(traverse);
}
template<class T>
void BinaryTreeTemplate<T>::makeDeletion(TreeNode *&traverse)
{
	TreeNode *temp = NULL;
	if (traverse == NULL)
		cout << "Cannot delete empty node." << endl;
	else if (traverse->right == NULL)
	{
		temp = traverse;
		traverse = traverse->left;
		delete temp;
	}
	else if (traverse->left == NULL)
	{
		temp = traverse;
		traverse = traverse->right;
		delete temp;
	}
	else
	{
		temp = traverse->right;
		while (temp->left)
		{
			temp = temp->left;
		}
		temp->left = traverse->left;
		temp = traverse;
		traverse = traverse->right;
		delete temp;
	}
}

template<class T>
void BinaryTreeTemplate<T>::displayInOrder(TreeNode *traverse)const
{
	if (traverse)
	{
		displayInOrder(traverse->left);
		cout << traverse->data << endl;
		displayInOrder(traverse->right);
	}
}
template<class T>
void BinaryTreeTemplate<T>::displayPreOrder(TreeNode *traverse)const
{
	if (traverse)
	{
		cout << traverse->data << endl;
		displayPreOrder(traverse->left);
		displayPreOrder(traverse->right);
	}
}
template<class T>
void BinaryTreeTemplate<T>::displayPostOrder(TreeNode *traverse)const
{
	if (traverse)
	{
		displayPostOrder(traverse->left);
		displayPostOrder(traverse->right);
		cout << traverse->data << endl;
	}
}

#endif
