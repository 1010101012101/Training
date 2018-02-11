/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int merge(int *l, int nl, int *r, int nr, int* A)
{
   
    int i =0, j =0, k=0;
    while( i<nl && j<nr )
    {
        if(l[i] <= r[j])
        {
            A[k] = l[i];
            i = i+1;
            k= k+1;
            
        }
        else
        {
            A[k] = r[j];
            j = j+1;
            k= k+1;
        }
    }
    
    while(i<nl)
    {
        A[k] = l[i];
        i = i+1;
        k = k+1;
        
    }
    
    while( j<nr)
    {
        A[k] = r[j];
        j = j+1;
        k = k+1;
    
    }
    
}
 void mergesort(int *A, int n)
 {
     int mid, i, *left, * right;
    if(n <2)
     {
         return;
         
     }
     mid = n/2;
     left = (int*) malloc(mid * sizeof(int)); 
     right = (int*) malloc((n - mid) * sizeof(int));
     
     for( i=0; i< mid; i++)
     {
         left[i] = A[i];
     }
     
     for (i =mid; i <n; i++)
     {
         right[i-mid] = A[i];
     }
     
     mergesort(left, mid);
     mergesort(right, n-mid);
     merge(left, mid, right, n-mid, A);
     
     free(left);
     free(right);
     
     
 }
 
int main()
{
    int A[] = {6,2,3,1,9,10,15,13,12,17,88,44,77,8888};
    int n = sizeof(A)/sizeof(A[0]);
    printf( "Number of elements: %d\n", n);
   for(int i=0; i < n; i++)
    {
        printf( "Array elements Before: %d\n", A[i]);
        
    }
    mergesort(A, n);
    
    for(int k=0; k < n; k++)
    {
        printf( "Array elements After: %d\n", A[k]);
        
    }
    return 0;
}





