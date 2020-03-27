#include <iostream>
using namespace std;

int main()
{
    // creat the array and cin
    int n, **pptrArray, i, j, money = 0, count = 0, k = 0;
    cin >> n;
    pptrArray = new int *[n + 1];
    for (i = 0; i < n + 1; i++)
        pptrArray[i] = new int[5];
    for (i = 0; i < n + 1; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cin >> pptrArray[i][j];
        }
    }
    //compare and get the money
    for (i = 0; i < n; i++)
    {
        count = 0;
        k = 0;
        j = 0;
        money -= 50;
        while (j < 5 && k < 5)
        {
            if (pptrArray[i][j] == pptrArray[n ][k])
            {
                count++;
                j++;
                k++;
            }
            else if (pptrArray[i][j] > pptrArray[n ][k])
                k++;
            else if (pptrArray[i][j] < pptrArray[n ][k])
            {
                j++;
            }
        }
        if (count == 2)
            money += 50;
        else if (count == 3)
            money += 300;
        else if (count == 4)
            money += 20000;
        else if (count == 5)
            money += 8000000;
    }
    cout << money << endl;
}