#include<iostream>
using namespace std;
int main()
{
    int a, b, c,m=0,max=0;
    cin >> a;
    cin >> b;
    max = a * b;
    if(a<1||b<1)
    {
        cout << "0 0" << endl;
    }
    else
    {
        while(b>0)
        {
            c = a % b;
            a = b;
            b = c;
        }
        m = max / a;
    }
    cout << a << " " << m<<endl;

}