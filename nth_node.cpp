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




int main(void)
{
   struct node *head;
   push(&head,1);
   push(&head,10);
   push(&head,16);
   push(&head,10);
   cout<<" 3rd value = "<<getNthNode(2,head);


    return 0;
}
