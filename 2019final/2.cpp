#include <iostream>
using namespace std;
int main()
{
    int n,i,k=0;
    cin >> n;
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