/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, HTML, CSS, JS.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<iostream>
using namespace std;

int BinarySearch(int A[], int low,int high, int x)
{
    if(low > high) return -1;
    int mid = (low+high)/2;  //low + (high-low)/2   to avaid upper limit 2**31 limits
    
    if(A[mid] == x) return mid;
    else if( x < A[mid]) return BinarySearch( A,low, mid-1, x );
    else if(x > A[mid])  return BinarySearch(A, mid+1, high, x);


}
int main()
{
    //printf("Hello World");
    int A[] = { 2,4,5,6,12,34,55,55,55,66,99,777,6767};  //sorted array
    int n = sizeof(A)/A[0];
    int low = 0, high =n-1;
    int x; //Element to be searched
    cout << "Enter the search(recursively) element : "  ;
    cin>>x;
    
    int bIndex = BinarySearch( A, low, high, x );
    cout<< "The Index of " << x <<" is: " <<bIndex;

    return 0;
}
