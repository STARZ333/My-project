#include <iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;

const int m = 5, n = 4;//m为行，n为列
void Outputup(int arr[m][n]);


void print(int a[][n])//输出二维数组
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
}

void Outputup(int arr[][n])//对数组第一列进行升序排序，后面的数字随第一行排序
{
    int temp, k = 0;
    for (int i = 0; i < m - 1; i++)
        for (int j = 0; j < m - 1-i; j++)
        {
            if (arr[j][0] > arr[j + 1][0])
            {
                for (k = 0; k < n; k++)
                {
                    temp = arr[j][k];
                    arr[j][k] = arr[j + 1][k];
                    arr[j + 1][k] = temp;
                }
            }
        }
}

void linedown(int arr[][n])//对数组进行按行升序
{
    int temp;
    for (int i = 0; i < m;i++)
        for (int j = 0; j < n - 1;j++)
        {
            for (int k = 0; k < n - 1 - j;k++)
            {
                if (arr[i][k] > arr[i][k + 1])
                {
                    temp = arr[i][k];
                    arr[i][k] = arr[i][k + 1];
                    arr[i][k + 1] = temp;
                }
            }
        }
}

int main()
{

    int score[m][n];
    srand(time(0));
    //给数组赋值，产生随机数
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            score[i][j] =rand() % 100 + 1;
        }
    
    print(score);//输出原数组
    cout << endl;

    Outputup(score);//按第一列升序排列
    print(score);//输出排序后数组
    cout << endl;

    linedown(score);//按行升序排列
    print(score);//输出
}