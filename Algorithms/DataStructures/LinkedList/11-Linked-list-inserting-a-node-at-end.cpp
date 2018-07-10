/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdlib.h>
#include <stdio.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;  // global variable, can be accessed anywhere
void Insert(int x);
void Print();

void Insert_end(int x)
{
    Node* temp = (Node*) malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    

    Node( temp1 = A;
    while(temp1->link != NULL)
    {
		temp1 = temp1->link;
    }
    temp1->link = temp;
    
    return;
    
}

void Print()
{
    Node * temp = head;
    while(temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return;
    
}

int main()
{
    head = NULL;  //empty list;
    printf("How many numbers? \n");
    int n, i,x;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("Enter the number \n");
        scanf("%d", &x);
        Insert_end(x);
        Print();
    
    }
    

    return 0;
}



