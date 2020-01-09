#include <iostream>
using namespace std;
int main()
{
    int sum = 0, a[11] = {1, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1}, k = 0;
    char x;

    for (int i = 1; i <= 10; i++)
    {
        cin >> x;
        if (i == 1)
        {
            if (x == 'I')
                sum += (3 + 4 * 9);
            else if (x == 'O')
                sum += (3 + 5 * 9);
            else if (x <= 'H')
            {
                k = (x - 'A') +10;
                sum += ((k % 10) * 9 + (k / 10));
            }
            else if (x <= 'N')
            {
                k = x - 'J' + 18;
                sum += ((k % 10) * 9 + (k / 10));
            }
            else if (x <= 'Z')
            {
                k = x - 'P' + 23;
                sum += ((k % 10) * 9 + (k / 10));
            }
        }
        else
        {
            sum += (x - '0') * a[i];
        }
    }
    
    if ((sum % 10) == 0)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}