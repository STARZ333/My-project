#include <iostream>
using namespace std;

int main()
{
    int m, n, num,k;
    
    k = 1;
    
    while (cin>>m>>n)
    {
    int totle[m], back[n];
    //阵列初始化
    for (int i = 0; i < m; i++)
    {
        totle[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        back[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        back[i] = num;
    }

    for (int i = 0; i < n; i++)
    {
        totle[back[i]-1] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        if (m == n)
        {
            cout << "*";
            break;
        }
        if (totle[i] == 0)
            cout << i + 1 <<" ";
    }
    cout << endl;
    }
}