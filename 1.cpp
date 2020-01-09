#include<iostream>
using namespace std;
void spacestar(int space, int star);
void spacestar(int space, int star)
{
    for (int i = 1; i <= space;i++)
    {
        cout << " ";
    }
    for (int i = 1; i <= star;i++)
        cout << "*";
    cout << endl;
}

int main()
{
    int n,i;
    cin >> n;
    for ( i = 1; i <= n;i++)
    {
        spacestar(n - i, 2 * i - 1);
    }
    for (i = 1; i < n;i++)
    {
        spacestar(i, 2 * (n - i) - 1);
    }
}