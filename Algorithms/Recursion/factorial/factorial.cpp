/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;



int
factorial (int n)
{
  if (n == 0)
    {
      return 1;
    }
  else
    {
      int f = n * factorial (n - 1);
      return f;
    }

}

int
main ()
{
  int n = 0;

  cout << "Enter the number: ";
  cin >> n;

  int f = factorial (n);

  cout << "Factorial of: " << n << " is: " << f;

  return 0;
}
