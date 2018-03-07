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


struct Node* Insert_end(struct Node* head_list1, int x);
void Print();

struct Node* Insert_end(struct Node* head_list1, int x)
{
    Node* newNode = (Node*) malloc (sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    
    if(head_list1 == NULL)
    {
        head_list1= newNode;
        return head_list1;
    }
    
    Node* temp1 = head_list1;
    while(temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = newNode;
    
    return head_list1;
}

void Print(struct Node* head_list)
{
    Node* temp = head_list;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}


int main()
{
    struct Node* head_list1 = NULL;
    head_list1 = Insert_end(head_list1,2);
    head_list1= Insert_end(head_list1,4);
    head_list1= Insert_end(head_list1, 6);
    head_list1 = Insert_end(head_list1, 8);
    head_list1=Insert_end(head_list1, 10);
    printf("Print List1: \n");
    Print(head_list1);
    
    struct Node* head_list2 = NULL;
    head_list2 = Insert_end(head_list2,100);
    head_list2= Insert_end(head_list2,200);
    head_list2= Insert_end(head_list2, 300);
    head_list2 = Insert_end(head_list2, 400);
    head_list2=Insert_end(head_list2, 500);
    printf("Print List2: \n");
    Print(head_list2);
    
    struct Node* head_list3 = NULL;
    
    struct Node* temp1 = NULL;
    temp1 = head_list1;
    while(temp1!=NULL)
    {
        head_list3 = Insert_end(head_list3, temp1->data);
        temp1= temp1->next;
        
    }
    
    struct Node* temp2 = NULL;
    temp2 = head_list2;
    while(temp2!=NULL)
    {
        head_list3 = Insert_end(head_list3, temp2->data);
        temp2= temp2->next;
        
    }
   
   printf("Print List3: \n");
    Print(head_list3);
    
     return 0;
}











