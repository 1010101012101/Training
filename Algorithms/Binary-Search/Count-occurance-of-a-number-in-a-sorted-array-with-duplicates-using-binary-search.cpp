/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, HTML, CSS, JS.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<iostream>
using namespace std;

int BinarySearch(int A[], int n, int x, bool SearchFirst)
{
    int low =0, high = n-1, result= -1;
    while(low <= high)
    {
        int mid = (low + high)/2; //To avoid 2**31 overflow mid = low + (high-low)/2;
        if(A[mid] == x) 
        {
            result= mid;
            if(SearchFirst)
            {
                //FIRST OCCURRANCE
                 high = mid-1;  //Found X return and exit
            }
            else
            {
                //LAST OCCURRANCE
                 low = mid+1;  //Found X return and exit
            }
            
        }
        else if(x > A[mid]) low = mid+1;  //x lies after mid
        else if (x< A[mid]) high = mid -1;  // x lies before mid
    }
    return result;

}
int main()
{
    //printf("Hello World");
    int A[] = { 2,4,5,6,12,34,55,55,55,66,66,66,66,66};  //sorted array
    int n = sizeof(A)/A[0];
    int x; //Element to be searched
    cout << "Enter the search element: "  ;
    cin>>x;
    bool SearchFirst = true;
    int count =0;
    int bIndexFirst = BinarySearch( A,n,x, SearchFirst );
    if (bIndexFirst == -1)
    {
        cout<< "Count of an element  " << x <<" is: " <<count;
    }
    else
    {
        SearchFirst = false;
        int bIndexLast = BinarySearch( A,n,x, SearchFirst );
        count = (bIndexLast - bIndexFirst) + 1;
        cout<< "Count of an element  " << x <<" is: " <<count;
    }

    return 0;
}




