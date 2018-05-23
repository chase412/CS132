// My Tran
// This is resource file for problem 5

#include <iostream>
#include "LinkList_pb5.h"
using namespace std;

LinkList::LinkList () {
    head = nullptr;
}

LinkList::~LinkList () {
    ListNode *traverse = new ListNode;   // To traverse the list.
    ListNode *nextNode = new ListNode; // To point to the next node.
    
    // Position T at the head of the list.
    traverse = head;
    
    // While T is not at the end of the list.
    while (traverse != NULL ) {
        // Save a pointer to the next node.
        traverse = traverse ->next;
        
        // Delete the current node.
        delete traverse;
        
        // Position T at the next node.
        traverse = nextNode;
    }
}

void LinkList::appendNode (int a) {
    // create pointer pointing to new node, give value, bc it's the last one, null at the end
    ListNode *newNode = new ListNode;
    newNode->data = a;
    newNode->next = nullptr;
    
    // if there are no nodes in the list
    if (!head)
        head = newNode;
    else   // create ANOTHER pointer which goes through the list
    {
        ListNode *traverse = new ListNode;
        traverse = head;  // set it up go from the head to the end to add a node at the end
        while (traverse->next)  //until the end of the original list
            traverse = traverse->next;
        
        // add the last node at the end of the list
        traverse->next = newNode;
    }
}

void LinkList::insertNode (int a) {
    ListNode *newNode = new ListNode;
    newNode->data = a;
    
    if (!head) {
        head = newNode;
        newNode -> next = NULL;
    }
    
    else {
        ListNode *traverse = new ListNode;
        ListNode *before = new ListNode;
        traverse = head;
        before = NULL;
        
        // Find the right location by examing value of each node
        while (traverse != NULL && a > traverse->data) {
            before = traverse;
            traverse = traverse -> next; }
        
        // now insert between the before and the traverse
        // if the inserted one is 1st in the list
        if (before == NULL) {
            head = newNode;
            newNode->next = traverse; }
        else {
            before -> next = newNode;
            newNode -> next = traverse;  }
    }
}

void LinkList::deleteNode (int a) {
    if (!head) {
        cout << "\nList is empty. Fail to delete node!\n";
        return;
    }
    else {
        ListNode *traverse = new ListNode;
        ListNode *before = new ListNode;
        
        
        if (head->data == a) {   // if 1st one is the one to be deleted
            traverse = head->next;
            delete head;
            head = traverse; }
        else   {
            // Initialize T to head of list.
            traverse = head;
            
            // Skip all nodes whose value member is not equal to num.
            while (traverse != NULL && traverse->data != a)
            {
                before = traverse;
                traverse = traverse->next;
            }
            
            // If traverse is not at the end of the list,
            // link the beforeNode to the node after traverse, then delete T.
            if (traverse)
            {
                before->next = traverse->next;
                delete traverse;
            }
            else
                cout << "\n\tFailed to delete as " << a
                << " not found in the list.";
        }    //    end else-if
        
        display();
    }
    
}

void LinkList::reverse()
{
    ListNode *traverse = new ListNode;
    ListNode *next = new ListNode;
    ListNode *result= NULL;
    
    if ( !head )
    {
        cout << "\n\tThe list is empty.";
        return;
    }
    else {
        traverse = head;
        while (traverse != NULL) {
            next = traverse->next;
            traverse->next = result;
            result = traverse;
            traverse = next;
        }
        head = result;
        display();
    }
}

int LinkList::search(int a)
{
    ListNode *traverse; // To move through the list.
    int position = -1;
    if (!head)
    {
        cout << "\n\tThe list is empty.\n";
        return -1;
    }
    else {
    // Position at the head of the list.
    traverse  = head;
    while (traverse) {
        position++;
        if(traverse->data == a)
            return position;
        else
            traverse = traverse-> next; }
    }
    return -1;
}


void LinkList::display() const
{
    ListNode *traverse = new ListNode; // To move through the list
    
    if ( !head )
    {
        cout << "\n\tThe list is empty.";
        return;
    }
    
    // Position T at the head of the list.
    traverse = head;
    
    cout << "\n\n\tThe elements in the list are:\n\t";
    // While T points to a node, traverse the list.
    
    while (traverse)
    {
        // Display the value in this node.
        cout << traverse->data<< " -> ";
        
        // Move to the next node.
        traverse = traverse->next;
    }
    cout << "Null";
}

