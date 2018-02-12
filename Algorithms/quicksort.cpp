/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, HTML, CSS, JS.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*#Time Complexity
Best case: O(n log n)
Worst case: O(n**2)
# Space complexity
Best case: O(log n)
Worst case: O(n)
*/
   
#include <stdio.h>
#include <iostream>
using namespace std;

/*int RandomizedPartition( int *A, int start, ind end)
{
    int pIndex = random(start, end);
    swap(A[pIndex], A[end]);
    pIndex = PartitionIndex(A, start, end);
    return pIndex;         
}
*/

int PartitionIndex( int *A, int start, int end)
{
    int pivot = A[end];
    int pIndex = start;
    for(int i=start; i < end ; i++)
    {
        if(A[i] <= pivot)
        {
            swap(A[i], A[pIndex]);
            pIndex = pIndex+1;
        }
    }
    swap(A[pIndex], A[end]);
    return pIndex;
}

void quicksort(int *A, int start, int end)
{
    if (start< end)
    {
        int pIndex = PartitionIndex(A, start, end);
        quicksort(A, start, pIndex-1);
        quicksort(A, pIndex+1, end);
    }
    
}

int main()
{
    int A[] = {55,7,2,12,1,6,8,5,56,3,4,55};
    
    int n = sizeof(A)/sizeof(A[0]);
    for(int i = 0; i < n; i++)
    {
        printf("Quick Sort Before %d\n", A[i]);
        
    }
    int start = 0;
    int end = n-1;
    
    quicksort(A, start, end);
    
    for(int j = 0; j < n; j++)
    {
        printf("Quick Sort After %d\n", A[j]);
        
    }
    
    return 0;
}

