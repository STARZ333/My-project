#include<iostream>
using namespace std;
int FFF(int n)
{
    if(n==1)
        return 1;
    if(n==2)
        return 1;
    if(n==3)
        return 1;
    if(n>3)
        return FFF(n - 3) + FFF(n - 2) + FFF(n - 1);
}
int main()
{
    int x;
    while(cin>>x)
    {
        if(x==0)
            break;
        if(x>0)
            cout << FFF(x)<<endl;
    }
}