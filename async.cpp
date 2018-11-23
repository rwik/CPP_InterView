#include <iostream>
#include <string>
#include <thread>
#include <future>



using namespace std;
//thread 1

int func1()
{
    int i = 1;
    int result =0;
    while(result != 10000)
        result += i;
    return result;
}
int func2()
{
    int i = 1;
    int result =0;
    while(result != 10)
        result += i;
    return result;

}
int main()
{

    future<int> res1 = async(func1);
    int res2 = func2();
    int res = res1.get()+res2;
    cout<<"Result = "<<res<<endl;

    return 0;
}