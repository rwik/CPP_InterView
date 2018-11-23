//============================================================================
// Name        : kadane_array.cpp
// Author      : Rwik Mukhopadhyay
// Version     :
// Copyright   : You are free to copy
// Description : Largest Sum Contiguous Subarray (http://en.wikipedia.org/wiki/Kadane%27s_Algorithm)
//============================================================================

#include <iostream>
#include <stdlib.h>

using namespace std;

int maxArraySum(int a[],int size)
{
  int max_so_far = a[0], max_ending_here = a[0];
	for(int i =1;i<size;i++)
	{
		cout<<" i = "<<i<<" max_ending = "<<max_ending_here<<" max_so_far = "<<max_so_far<<endl;
		if(max_ending_here < 0)
		{
			max_ending_here = a[i];
		}else
		{
			max_ending_here = max_ending_here + a[i];
		}
		if(max_ending_here> max_so_far)
		{
			max_so_far = max_ending_here;
		}

	}
	return max_so_far;

}



int main(void) {
	int a[] ={-2,-3,4,-1,-2,1,5,-3};
	int n = sizeof(a)/sizeof(a[0]);
	int sum = maxArraySum(a,n);
	cout<<"The Sum Is = "<<sum<<endl;
	return 0;

}
