#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int k = 1; k <= n; k++)
    {
        //空白
        for (int i = k; i < n; i++)
        {
            cout << " ";
        }
        //*
        for (int j = 1; j <= 2 * k - 1; j++)
            cout << "*";
        cout << endl;
    }
    for (int k = 1; k < n; k++)
    {   //空白again
        for (int i = 1; i <= k; i++)
            cout << " ";
        //* again
        for (int j = 1; j <= 2 * (n - k) - 1; j++)
            cout << "*";
        cout << endl;
    }
}