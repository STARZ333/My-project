#include<iostream>
using namespace std;
int main()
{
    int a[5] = {3, 2, 5, 4, 1},temp;
    for (int i = 0; i < 4;i++)
    {
        for (int j = 0; j < 4 - i;j++)
        {
            if (a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 5;i++)
        cout << a[i] << endl;
}