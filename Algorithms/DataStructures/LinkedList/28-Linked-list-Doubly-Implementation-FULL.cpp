/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;  //global variable pointer to head Node

struct Node* GetNewNode(int x)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    return newNode;
    
}

void Print()
{
    struct Node* temp = head;
    printf("Print Forward: ");
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
    printf("\n");
    
    return;
}

void ReversePrint()
{
     struct Node* temp = head;
    if(temp == NULL) return;
    //Go to the end of the list
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    
    printf("Reverse Print: ");
    
       while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    
    
    printf("\n");
    
    return;
    
}

void InsertAtHead(int x)
{
    struct Node* newNode = GetNewNode(x);
    
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void InsertAtEnd(int x)
{
    struct Node* newNode = GetNewNode(x);
    
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    
    struct Node* temp = head;
    
    while(temp->next!= NULL)
    {
        temp = temp->next;
    }
     temp->next = newNode;
     newNode->prev=temp;
    
}

int main()
{
    head = NULL;
    InsertAtHead(2); Print(); 
     InsertAtHead(4); Print(); 
      InsertAtHead(6); Print();
      
      InsertAtEnd(500); Print();
      InsertAtEnd(700); Print();
      ReversePrint();

    return 0;
}



