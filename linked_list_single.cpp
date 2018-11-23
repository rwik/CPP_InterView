//============================================================================
// Name        : dynamic.cpp
// Author      : Rwik Mukhopadhyay
// Version     :
// Copyright   : You are free to copy
// Description :
//============================================================================

#include <iostream>
#include <stdlib.h>

using namespace std;



struct node
{
    struct node *next;
    int data;
};

void push(struct node **headref,int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = (*headref);
    (*headref) = newNode;

}

void deleteNode(struct node *head)
{
    struct node *temp = head->next;
      head->data    = temp->data;
      head->next    = temp->next;
      free(temp);

}
void display(struct node *head)
{
    struct node * current = head;
    cout<<endl;
    while(current != NULL)
    {
        cout<<" data = "<<current->data<<endl;
        current = current->next;

    }

}

int getNthNode(int n,struct node *headref)
{
    int counter = 0;
    struct node * current = headref;
    while(current)
    {
        if(counter == n)
        {
            return current->data ;
        }
        counter ++;
        current = current->next;
    }
    return -1;

}

struct node *getNthNodeFromBack(int n,struct node *head)
{
    // If list does not exist or if there are no elements in the list,return NULL
    if (head == NULL ) {
      return NULL;
    }

    // make pointers p1 and p2 point to the start of the list.
    struct node * p1 = head;
    struct node * p2 = head;

    // The key to this algorithm is to set p1 and p2 apart by n-1 nodes initially
    // so we want p2 to point to the (n-1)th node from the start of the list
    // then we move p2 till it reaches the last node of the list.
    // Once p2 reaches end of the list p1 will be pointing to the nth node
    // from the end of the list.

    // loop to move p2.
    for (int j = 0; j < n - 1; ++j) {
     // while moving p2 check if it becomes NULL, that is if it reaches the end
     // of the list. That would mean the list has less than n nodes, so its not
     // possible to find nth from last, so return NULL.
     if (p2 == NULL) {
         return NULL;
     }
     // move p2 forward.
     p2 = p2->next;
    }

    // at this point p2 is (n-1) nodes ahead of p1. Now keep moving both forward
    // till p2 reaches the last node in the list.
    while (p2->next != NULL) {
      p1 = p1->next;
      p2 = p2->next;
    }

     // at this point p2 has reached the last node in the list and p1 will be
     // pointing to the nth node from the last..so return it.
     return p1;


}




int main(void)
{
   struct node *head = NULL;
//   push(&head,1);
//   push(&head,10);
//   push(&head,16);
//   push(&head,10);
//   cout<<" 3rd value = "<<getNthNode(2,head);
//   display(head);
//   deleteNode(head);
   display(head);
   push(&head,15);
   push(&head,17);
   push(&head,18);
   push(&head,19);
   display(head);

   //nth node from back
   struct node *temp = getNthNodeFromBack(0,head);
   cout<<" nth value from back = "<<temp->data<<endl;





    return 0;
}