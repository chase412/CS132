// My Tran
// This is the header file for problem 5


#include <iostream>
using namespace std;

#ifndef LINKLIST_H
#define LINKLIST_H
class LinkList {
private:
    struct ListNode {
        int data;
        ListNode *next; };
    ListNode *head;
public:
    LinkList ();
    ~LinkList ();        // include function to delete the list
    void appendNode (int);
    void insertNode (int);
    void deleteNode (int);
    void reverse ();
    int search (int);
    void display () const ;
};
#endif
