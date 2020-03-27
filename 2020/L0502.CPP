#include <iostream>
using namespace std;

int main()
{
    // creat the array and cin
    int n, **pptrArray, i, j, money = 0, count = 0, k = 0, temp;
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
    //sort
    for (i = 0; i < n + 1; i++)
    {
        for (j = 0; j < 5; j++)
        {
            for (int k = 0; k < 4 - j; k++)
            {
                if (pptrArray[i][k] > pptrArray[i][k + 1])
                {
                    temp = pptrArray[i][k];
                    pptrArray[i][k] = pptrArray[i][k + 1];
                    pptrArray[i][k + 1] = temp;
                }
            }
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
            if (pptrArray[i][j] == pptrArray[n][k])
            {
                count++;
                j++;
                k++;
            }
            else if (pptrArray[i][j] > pptrArray[n][k])
                k++;
            else if (pptrArray[i][j] < pptrArray[n][k])
            {
                j++;
            }
        }
        if (count == 2)
        {
            money += 50;
            cout << "50";
            for (int m = 0; m < 5; m++)
                cout << " " << pptrArray[i][m];
            cout << endl;
        }
        else if (count == 3)
        {
            money += 300;
            cout << "300";
            for (int m = 0; m < 5; m++)
                cout << " " << pptrArray[i][m];
            cout << endl;
        }
        else if (count == 4)
        {
            money += 20000;
            cout << "20000";
            for (int m = 0; m < 5; m++)
                cout << " " << pptrArray[i][m];
            cout << endl;
        }
        else if (count == 5)
        {
            money += 8000000;
            cout << "8000000";
            for (int m = 0; m < 5; m++)
                cout << " " << pptrArray[i][m];
            cout << endl;
        }
    }
    cout << money << endl;
}