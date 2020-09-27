#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main()
{
    string name[100];
    int count = 0, y = 0;
    while (cin.peek() != '0')
    {
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
    //找空格
    int pos[count];
    int max = 0;

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
    for (int i = 0; i < count; i++)
    {
        if (pos[i] < max)
        {
            for (int m = 0; m < max - pos[i]; m++)
            {
                cout << '\0';
            }
        }
        for (int j = 0; j < y; j++)
        {
            cout << data[i][j];
        }
        cout << endl;
    }
    //delete
    for (int i = 0; i < count; i++)
    {
        delete[] data[i];
    }
    delete[] data;
    return 0;
}