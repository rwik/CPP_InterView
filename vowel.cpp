#include <iostream>

using namespace std;

int main()
{
    char *text;
    text = new char[10];
    cout << "Enter the string : " << endl;
    cin>>text;
    for(int i = 0;text[i] != '\0'; i++)
    {
        if(text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' )
        {
            text[i] = ' ';

        }

    }
    cout<<text;
    return 0;
}