//============================================================================
// Name        : dynamic.cpp
// Author      : Rwik Mukhopadhyay
// Version     :
// Copyright   : You are free to copy
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>

using namespace std;



void print_sequence(int n)
{
  if(n >0)
  {
    print_sequence(n-1);
	  cout<<endl<<n<<endl;
  }
}


int main(void)
{
    cout<<"sequence is"<<endl;
    print_sequence(100);

    return 0;
}
