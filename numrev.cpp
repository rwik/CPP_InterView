#include<iostream>

using namespace std;

int main()
{
    int num =0,rev=0,m;
    cout<<" enter a number to reverse : ";
    cin>>num;
    while(num>0)
    {
    m=num%10;
    rev=rev*10+m;
    num=num/10;
    }
    cout<<"  reveresed "<<rev;
    return 0;
}