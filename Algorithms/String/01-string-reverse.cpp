/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;


void reverse( string &str)
{
    int len= str.length();
    
    for(int i=0; i < len/2; i++)
    {
        std::swap(str[i], str[len-i-1]);
    }
    
    std::cout<<"\n"<<"After Reverse:"<< str;
   
    
}
int main()
{
    string str = "California";
    std::cout<<"Before Reverse:"<< str;
   
 
    reverse(str);
    
    

    return 0;
}


