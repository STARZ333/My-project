#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i;
    int k = 0;
    for (i = 2; i <= n; i++)
    {
        if (k == 0 && n % i == 0)
        {
            cout <<" "<< i;
            n /= i;
            k = 1;
        }
        while (n % i == 0)
        {
            cout << " " << i;
            n /= i;
        }
    }    
}