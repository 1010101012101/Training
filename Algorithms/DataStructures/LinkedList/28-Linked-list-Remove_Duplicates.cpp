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


void Insert_end(int x)
{
    struct Node* temp1 = (Node*) malloc (sizeof(Node));
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

void Remove_Duplicates(struct Node* temp_head)
{
    struct Node* ptr1, *ptr2, *dup;
    ptr1= temp_head;
    
    /*pick elements one by one*/
    while(ptr1!=NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        
        /* compare the picked element with rest of the elements*/
        while(ptr2->next!= NULL)
        {
            /*If duplicate then delete it*/
            if(ptr1->data == ptr2->next->data)   //core routine
            {
                /*sequence of steps importent here*/
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else
            {
                ptr2 = ptr2->next;
            }
            
        }
        ptr1 = ptr1->next;
    }
}



int main()
{
    head = NULL;
    
    Insert_end(2);
    Insert_end(4);
    Insert_end(6);
    Insert_end(6);
    Insert_end(8);
    Insert_end(10);
    printf("Print Forward: \n");
    Print();
    
    printf("\n");
   
   struct Node* temp_head = NULL;
   temp_head = head;
   Remove_Duplicates(temp_head);
   Print();
 
    return 0;
}

