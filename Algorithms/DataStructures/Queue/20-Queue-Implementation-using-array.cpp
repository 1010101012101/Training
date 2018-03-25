
#include <stdio.h>
#include<stdlib.h>
using namespace std;

#define SIZE 12
 int A[SIZE];
 int front =-1, rear =-1;
 
 int isFull()
{
    if( (front == rear + 1) || (front == 0 && rear == SIZE-1)) return 1;
    return 0;
}

int isEmpty()
{
    if(front == -1) return 1;
    return 0;
}

void Enqueue( int x)
{
    if(isFull())
    {
        printf("\n Queue is full!! \n");
        return;
    }
    else if(isEmpty())
    {
       front = rear =0; 
    }
    else
    {
        rear = rear +1;
        
    }
  
  A[rear] = x;
    
}

int Dequeue()
{
    int x = A[front];
    front = front+1;
    return x;
}

void Print()
{
    int i = front;
    
    while( i<rear)
    {
        i= i+1;
        printf("%d: ", A[i]);
        
    }
    printf("\n");
    
}
main ()
{

  Enqueue (5);
  Print();
  Enqueue (10);
  Print();
  Enqueue (15);
  Print();
  Enqueue (20);
  Print();
  Enqueue (25);
  Print();
  Enqueue (30);
  Print();
   Enqueue (35);
  Print();
  Enqueue (40);
  Print();
  Enqueue (45);
  Print();
   Enqueue (50);
  Print();
  Enqueue (55);
  Print();
  Enqueue (60);
  Print();
  Enqueue (65);
  Dequeue();
  Print();
  Dequeue();
  Print();
   Dequeue();
  Print();
  Dequeue();
  Print();
   Dequeue();
  Print();
  Dequeue();
  Print();

  return 0;
}



