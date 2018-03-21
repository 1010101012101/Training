//string reversal using std::stack<T> ;


#include <iostream>
#include<string.h>
#include<stack>
using namespace std;


void swap1(char *s1, char *s2)
{
    char temp;
    temp =*s1;
    *s1 = *s2;
    *s2 = temp;
}

void Reverse_string( char c[], int len)
{
    for(int i = 0, j= (len -1); i<j ;i++, j--)
    {
        swap1(&c[i], &c[j]);
    }
    
}


void Reverse( char c[], int len)
{
    stack<char>S;
    
    //loop for push
    for(int i=0; i < len; i++)
    S.push(c[i]);
    
    
    //loop for pop
    for(int i=0; i < len; i++)
    {
        c[i] = S.top();
        S.pop();
    }
    
    
    return;
    
}

int main()
{
    char c[100];
    printf("Enter a String: ");
    gets(c);
    
    Reverse_string(c, strlen(c));
   // Reverse(c, strlen(c));
    puts(c);
    printf("Output %s:", c);
    
    return 0;
}
