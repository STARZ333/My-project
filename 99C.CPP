#include<iostream>

using namespace std;
int main()
{
    int i=1, j=1;
    while(i<=9)
    {
        j = 1;
        while (j<=i)
        {
            cout << j << "*" << i << "="<<i * j<<" ";
            j++;
        }
        cout << endl;
        i++;
    }
    
    return 0;
}
