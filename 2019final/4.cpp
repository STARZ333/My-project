#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int s,a[200];
    cin >> s;
    srand(s);
    for (int i = 0; i < 200;i++)
    {
        a[i] = rand() % 200 + 1;
    }
    sort(a,a+200);
    for (int j = 0; j < 200;j++)
    {   
        if(a[j]%2==0)
        cout << j+1<<endl;
    }
}