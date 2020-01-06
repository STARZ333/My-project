#include<iostream>
using namespace std;
int main()
{
    
    int i,a[15];
    cin >> i;
    for (int j = 0; j < 15;j++)
    {
        a[j] = rand() % 9901 + 100;
        cout << a[j]<<endl;
    }
    cout << a[i - 1];

}
