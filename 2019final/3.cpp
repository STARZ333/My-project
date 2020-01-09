#include<iostream>
using namespace std;
int main()
{
    int x,s, n;
    cin >> s;
    cin >> n;
    int a[n];
    srand(s);
    for (int i = 0; i < n;i++)
    {
        a[i] = rand() %102 + 99;
    }
    while(cin>>x)
    {
        if(x<=0)
            break;
        cout << a[x - 1]<<endl;
    }
}