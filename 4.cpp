#include<iostream>
using namespace std;
int main()
{
    int s, a, b, c,k;
    cin >> s >> a >> b >> c;
    srand(s);
    for (int i = 0; i < c;i++)
    {
        k=rand() % (b - a+1) + a;
        cout << k << " ";
    }
}