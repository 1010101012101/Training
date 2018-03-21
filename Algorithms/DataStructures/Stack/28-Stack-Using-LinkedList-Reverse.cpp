#include <stdio.h>
#include<stdlib.h>
#include<stack>
using namespace std;

struct Node
{
    char data;
    struct Node* link;
};

struct Node* top = NULL;

void Push(char x)
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

void Reverse()
{
    stack<struct Node*> S;
    if(top == NULL) return;
    Node* temp = top;
    
    while(temp!= NULL)
    {
        S.push(temp);
        temp = temp->link;
        
    }
    
    temp = S.top(); top = temp;
    S.pop();
    while(!S.empty())
    {
        temp->link = S.top();
        S.pop();
        temp = temp->link;
        
    }
    temp->link = NULL;
}

void Print()
{
    Node * temp = top;
    while(temp!= NULL)
    {
        printf("%c ", temp->data);
        temp = temp->link;
    }
    return;
    
}

void Top()
{
    printf("\n Top %c :", top->data);
}

int main()
{
    Push('S');
    Push('R');
    Push('E');
    Push('E');
    Print();
    Reverse();
    printf("\n");
    Print();
  


    return 0;
}
