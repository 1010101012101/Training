/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, Perl, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};

struct Node* top = NULL;

void Push(int x)
{
    struct Node * temp = (struct Node*) malloc(sizeof(struct Node*));
    temp->data = x;
    temp ->link = top;
    top = temp;
    return;
    
}

void Pop()
{
    struct Node* temp;
    if(top == NULL) return;
    temp = top;
    top = top->link;
    free(temp);
    
}

void Top()
{
    printf("\n Top %d :", top->data);
}

int main()
{
    Push(10);
    Push(20);
    Push(30);
    Push(40);
    Pop();
    Top();
    
    Push(100);
    Push(200);
    Push(300);
    Push(400);
    Pop();
    Top();
    Pop();
    Top();


    return 0;
}

