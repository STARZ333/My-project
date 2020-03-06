#include<iostream>
using namespace std;
void max(int&a,int&b,int&c)
{
    int m;
    if(a<b)
    {
        m = a;
        a = b;
        b = m;
    }
    if(a<c)
    {
        m = a;
        a = c;
        c = m;
    }
    if(b<c)
    {
        m = b;
        b = c;
        c = m;
    }
    cout << a << " " << b << " " << c << endl;
}
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    max(a, b, c);
}