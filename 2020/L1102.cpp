#include<iostream>
using namespace std;
int GCD(int a ,int b)
{
    if(b==0)
        return a;
    else
        return GCD(b, a % b);
}

int main()
{
    int x, y;
    while(cin>>x>>y)
    {
        if(x<=0||y<=0)
            break;
        cout << GCD(x, y) << endl;
    }
}