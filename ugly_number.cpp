//============================================================================
// Name        : uly_number.cpp
// Author      : Rwik Mukhopadhyay
// Version     :
// Copyright   : You are free to copy
// Description : Number divisible by 1,2,3,5 . Ugly number (http://tech-queries.blogspot.in/2011/03/ugly-number.html)
//============================================================================

#include <iostream>
#include <stdlib.h>

using namespace std;




/*This function divides a by greatest divisible
  power of b*/
int maxDivide(int a, int b)
{
  while (a%b == 0)
   a = a/b;
  return a;
}

/* Function to check if a number is ugly or not */
int isUgly(int no)
{
  no = maxDivide(no, 2);
  no = maxDivide(no, 3);
  no = maxDivide(no, 5);

  return (no == 1)? 1 : 0;
}

/* Function to get the nth ugly number*/
int nthUglyNo(int n)
{
  int i = 1;
  int count = 1;   /* ugly number count */

  /*Check for all integers untill ugly count
    becomes n*/
  while (n > count)
  {
    i++;
    if (isUgly(i))
      count++;
  }
  return i;
}


int main(void)
{
    int no = nthUglyNo(100);
    cout<<"100th ugly no. is %d "<<no;

    return 0;
}
