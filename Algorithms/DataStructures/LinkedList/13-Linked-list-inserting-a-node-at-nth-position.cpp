/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;  //Global pointer
//void Insert_Beginning(int x);
void Insert(int x);
void Print();

/*void Insert_Beginning(int x)
{
    Node * temp = (Node*) malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    if(head != NULL)
        temp->next = head;
    head = temp;
    
    return;
}
*/

void Insert(int x, int n)
{
    Node * temp1 = (Node*) malloc(sizeof(Node));
    temp1->data = x;
    temp1->next = NULL;
    if(n == 1)
    {
       temp1->next = head;
        head = temp1;
        return;
    }
    
    Node* temp2 = head;
    for(int i=0; i< n-2; i++)
    {
        temp2= temp2->next;
        
    }
    temp1->next = temp2->next;
    temp2->next= temp1;
    
    
}

void Print()
{
    Node* temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return;
}

int main()
{
    head = NULL;   
    Insert(10,1);
    Insert(20,2);
    Insert(30,3);
    Insert(40,4);
    Insert(90,1);
    Print();

    return 0;
}


