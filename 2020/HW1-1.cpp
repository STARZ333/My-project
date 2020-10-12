#include <iostream>
using namespace std;
int main()
{
    int x, y; //x個字串，Y長度
    int j;
    cout << "Please enter number(x) and length(y):" << endl;
    cin >> x >> y;
    char **data;
    data = new char *[x];
    for (int i = 0; i < x; i++)
    {
        data[i] = (char *)malloc(sizeof(char) * y);
        for (int j = 0; j < y; j++)
            data[i][j] = ' ';
    }

    cout << "please enter words:" << endl;
    //輸入字符
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
    char **a=data;
    char temp;
    for (int i = 0; i < x - 1; i++)
    {
        for (int k = 0; k < x - 1 - i; k++)
        {
            if (a[k][0] < a[k + 1][0])
            {
                for (int j = 0; j < y; j++)
                {
                    temp = a[k][j];
                    a[k][j] = a[k + 1][j];
                    a[k + 1][j] = temp;
                }
            }
        }
    }

    //out
    cout << "Result output:" << endl;
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
        free (data[i]);
    }
    delete[] data;
    return 0;
}
