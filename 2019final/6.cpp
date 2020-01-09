#include <iostream>
using namespace std;
int main()
{
    int x, mon = 1, day = 0, week;
    cin >> x;
    week = x % 7;
    if (week == 0)
        week = 7;

    for (int i = 1; i <= 11; i++)
    {
        if (mon == 2)
        {
            if (x - 28 > 0)
            {
                x = x - 28;
                mon = mon + 1;
            }
            else
            {
                break;
            }
        }
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            {
                if (x - 31 > 0)
                {
                    x = x - 31;
                    mon += 1;
                }
                else
                {
                    break;
                }
            }
            else if (i == 4 || i == 6 || i == 9 || i == 11)
            {
                if (x - 30 > 0)
                {
                    x = x - 30;
                    mon += 1;
                }
                else
                {
                    break;
                }
            }
        
    }
    day = x;
    cout << mon << " " << day << " ";
    cout << week << endl;
}