/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, Perl, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define MAX_SIZE 100
int stack[MAX_SIZE];
int top =-1;

void push(int x)
{
    if(top == MAX_SIZE-1)
    {
        printf("Error stack overflow\n");
        return;
        
    }
    top++;
    stack[top] = x;
 
}

void pop()
{
    if(top ==-1)
    {
        printf("No Elements to pop\n");
        return;
    }
    top--;
}

void print()
{
    for(int i=0; i <=top; i++)
    printf("%d ", stack[i]);
    printf("\n");
}

int Top()
{
    return stack[top];
}
int main()
{
    push(2); print();
    push(4); print();
    push(6); print();
    pop();
    push(8); print();
    pop();
    pop();
    pop();
    pop();
    push(10); print();
    push(12); print();
    
    int temp = Top();
    printf("Top: %d\n", temp);
    return 0;
}
