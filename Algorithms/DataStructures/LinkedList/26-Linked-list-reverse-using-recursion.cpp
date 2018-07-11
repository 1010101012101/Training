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

void Reverse_Print(Node* temp_head);


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

void Reverse_Print(Node* temp_head)
{
    if(temp_head == NULL) return;
    
    Reverse_Print(temp_head->next);
    printf("%d ", temp_head->data);
    
}

void Reverse(struct Node* p)
{
	if(p->next == NULL)
	{
		head = p;
		return;
	}
	Reverse(p->next);
	struct Node* q = p->next;
	q->next = p;
	p->next = NULL;

}

int main()
{
    head = NULL;
    
    Insert_end(2);
    Insert_end(4);
    Insert_end(6);
    Insert_end(8);
    Insert_end(10);
    printf("Print Forward: \n");
    Print();
    
    printf("\n Print Reverse the list: ");
   
   struct Node* temp_head = NULL;
   temp_head = head;
   Reverse_Print(temp_head);
 
    return 0;
}









