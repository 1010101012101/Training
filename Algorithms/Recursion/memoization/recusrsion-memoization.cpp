/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, HTML, CSS, JS.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <cstdio>
#include<iostream>
using namespace std;

int F[51];

int fibonacci(int n)
{
    if(n <= 1)
    {
        return n;
    }
    
    if(F[n] != -1)
    {
        return F[n];
    }
    
    F[n] = fibonacci( n-1 ) + fibonacci(n-2);
    return F[n];
        
    
    
}

int main()
{
    for(int i =0; i< 51; i++)
    F[i] = -1;
    int n=0;
    cout << "Enter a Number: ";
    cin>> n;
    
    int result = fibonacci(n);
    cout << result;

    return 0;
}
