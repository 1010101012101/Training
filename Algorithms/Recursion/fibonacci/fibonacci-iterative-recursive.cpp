/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, HTML, CSS, JS.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <cstdio>
#include<iostream>
using namespace std;

int fibonacci(int n)
{
    if(n <= 1)
    {
        return n;
    }
    
      /*  int F, F1, F2;
        F1=0;
        F2 = 1;
        for(int i= 2; i<= n; i++)
        {
            F = F1 + F2;
            F1= F2;
            F2 =F;
        }
        return F;*/
        return fibonacci( n-1 ) + fibonacci(n-2);
        
    
    
}

int main()
{
    int n=0;
    cout << "Enter a Number: ";
    cin>> n;
    
    int result = fibonacci(n);
    cout << result;

    return 0;
}
