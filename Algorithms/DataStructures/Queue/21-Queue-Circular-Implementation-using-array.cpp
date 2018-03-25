
//https://www.programiz.com/dsa/circular-queue

#include <stdio.h>
#include<stdlib.h>
using namespace std;

#define SIZE 4
 int items[SIZE];
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

void Enqueue(int element)
{
    if(isFull()) printf("\n Queue is full!! \n");
    else
    {
        if(front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\n Inserted -> %d ", element);
    }
}


int Dequeue()
{
    int element;
    if(isEmpty()) {
        printf("\n Queue is empty !! \n");
        return(-1);
    } else {
        element = items[front];
        if (front == rear){
            front = -1;
            rear = -1;
        } /* Q has only one element, so we reset the queue after dequeing it. ? */
        else {
            front = (front + 1) % SIZE;
            
        }
        printf("\n Deleted element -> %d \n", element);
        return(element);
    }
}

void display()
{
    int i;
    if(isEmpty()) printf(" \n Empty Queue\n");
    else
    {
        printf("\n Front -> %d ",front);
        printf("\n Items -> ");
        for( i = front; i!=rear; i=(i+1)%SIZE) {
            printf("%d ",items[i]);
        }
        printf("%d ",items[i]);
        printf("\n Rear -> %d \n",rear);
    }
}


main ()
{

// Fails because front = -1
   
    
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    
    // Fails to enqueue because front == 0 && rear == SIZE - 1
    Enqueue(6);
    
    display();
    Dequeue();
    
    display();
    
    Enqueue(7);
    display();
    
    // Fails to enqueue because front == rear + 1
    Enqueue(8);


  return 0;
}




