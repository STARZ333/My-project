#include <iostream>
using namespace std;
int main()
{
    int x, y; //x個字串，Y長度

    int j;
    cin >> x >> y;
    char **data;
    data = new char *[x];
    for (int i = 0; i < x; i++)
    {
        data[i] = new char[y];
        for (int j = 0; j < y; j++)
            data[i][j] = ' ';
    }

    for (int i = 0; i < x; i++)
    {
        j = 0;
        while (cin.peek() != '\n' || (j == 0)) //enter則下一個字符
        {
            cin >> data[i][j];
            j++;
        }
    }

    //sort
    char temp;
    for (int i = 0; i < x - 1; i++)
    {
        for (int k = 0; k < x - 1 - i; k++)
        {
            if (data[k][0] < data[k + 1][0])
            {
                for (int j = 0; j < y; j++)
                {
                    temp = data[k][j];
                    data[k][j] = data[k + 1][j];
                    data[k + 1][j] = temp;
                }
            }
        }
    }

    //out
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << data[i][j];
        }
        cout << endl;
    }
    //delete
    for (int i = 0; i < x; i++)
    {
        delete[] data[i];
    }
    delete[] data;
    return 0;
}
