#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main()
{
    cout << "Please enter the number of names:" << endl;
    int x;
    cin >> x;
    cout << "Please enter names:" << endl;
    string *name = new string[x];
    int count = 0, y = 0;
    fflush(stdin); //清除緩存
    while (1)
    {
        if (count == x)
            break;
        getline(cin, name[count]);
        if (size(name[count]) > y)
            y = size(name[count]); //找最長
        count++;
    }

    //創建陣列
    char **data;
    data = new char *[count];
    for (int i = 0; i < count; i++)
    {
        data[i] = new char[y];
        for (int j = 0; j < y; j++)
            data[i][j] = ' ';
    }

    //string to char
    for (int i = 0; i < count; i++)
    {
        strcpy(data[i], name[i].c_str());
    }

    //找第一個最遠的空格
    int pos[count]; //每個名字第一個空格的位置
    int max = 0;    //最遠的空格

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (data[i][j] == ' ')
            {
                pos[i] = j;
                if (j > max)
                    max = j;
                break;
            }
        }
    }

    //輸出
    cout << "Result output:" << endl;
    for (int i = 0; i < count; i++)
    {
        if (pos[i] < max)
        {
            for (int m = 0; m < max - pos[i]; m++)
            {
                cout << ' ';
            }
        }
        for (int j = 0; j < y; j++)
        {
            cout << data[i][j];
        }
        cout << endl;
    }
    cout << max;
    //delete
    for (int i = 0; i < count; i++)
    {
        delete[] data[i];
    }
    delete[] data;
    delete[] name;
    return 0;
}
