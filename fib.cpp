
#include <iostream>
using namespace std;

int main()
{
    int a=0,b=1,c=0,n;
    cout<<" enter number ";
    cin>>n;

    if(n==0)
    {
        cout<<"  "<<c;
    }else
    {
        cout<<"  "<<0;
        cout<<"  "<<1;
        for(int i =0;i<n-2;i++)
        {
            c = a+b;
            a=b;
            b=c;
            cout<<"  "<<c;
        }

    }


    return 0;
}
