#include <cmath>
#include <iostream>
using namespace std;
int prime(int a)
{
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int x, count = 0;
    cin >> x;
    while (count < 5)
    {
        x++;
        if (prime(x))
        {
            cout << x << " ";
            count++;
        }
    }
    cout << endl;
}