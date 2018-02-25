/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, HTML, CSS, JS.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

Node* head;

void Insert_end(int x);
void Print();
void Delete(int n);

void Insert_end(int x)
{
    Node* temp1 = (Node*) malloc (sizeof(Node));
    temp1->data = x;
    temp1->next = NULL;
    
    if(head == NULL)
    {
        head= temp1;
        return;
    }
    
    Node* temp2 = head;
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
    
    return;
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

void Delete(int n)
{
    
   Node* temp1 = head;
   
   if( n==1)
   {
       head= temp1->next;
       free(temp1);
       return;
   }
    
   for(int i =0; i < n-2; i++)
   {
       temp1=temp1->next;
   }
   
   Node* temp2;
   
   temp2 = temp1->next;
   temp1->next = temp2->next;
   free(temp2);
    
}


int main()
{
    head = NULL;
    
    Insert_end(2);
    Insert_end(4);
    Insert_end(6);
    Insert_end(8);
    Insert_end(10);
    printf("Print List before delete: \n");
    Print();
    
    int n = 0;
    printf("\nEnter the position of the Item to be deleted: ");
    scanf("%d", &n);
    Delete(n);
    printf("\nPrint List after delete: ");
    Print();
    

    return 0;
}
