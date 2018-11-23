//============================================================================
// Name        : singleQ.cpp
// Author      : Rwik Mukhopadhay
// Version     :
// Copyright   : Do whatever
// Description : Hello World in C++, Ansi-style
//============================================================================
 
#include <iostream>
#include <cstdlib>
using namespace std;
 
class queue
{
    int maxSize;
        int *q ;
        int front;
        int rear;
public :
        queue(int m = 10)
        {
                this->maxSize = m;
                this->q = new int[maxSize];
                this->front =0;
                this->rear = -1;
        }
        void enq(int item)
        {
                if(isfull())
                {
                        cout<<"  Q Full "<<endl;
                        return;
                }
                q[++rear] =item;
                return;
 
        }
        void dq()
        {
                if(isempty())
                {
                        cout<<" q empty "<<endl;
                        return;
                }
                q[front++];
 
        }
        void display()
        {
                int i;
                if(isempty())
                {
                        cout<<" q empty "<<endl;
                        return;
                }
        for(i=front;i<=rear;i++)
        {
                cout<<" ~~ "<<q[i];
        }
 
        }
        bool isfull()
        {
                return (rear == maxSize -1) ? 1:0;
 
        }
        bool isempty()
        {
                return (front > rear) ? 1:0;
 
        }
        ~queue()
        {
                delete[] q;
        }
 
 
 
} ;
 
int main()
{
        queue *q;
        q = new queue[100];
        int choice = 0;
        int item = 0;
        for(;;)
        {
                cout<<" 1.insert 2.delete 3. display 4. exit"<<endl;
                cin>>choice;
                switch(choice)
                {
                case 1:
                        cout<<"enter the item to be inserted";
                        cin>>item;
                        q->enq(item);
                        break;
 
                case 2:
                        q->dq();
                        break;
 
                case 3:
                        q->display();
                        break;
                default :
                        q->~queue();
                        return 0;
                        break;
 
                }
        }
 
        return 0;
}