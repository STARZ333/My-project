#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int len;
string s;
char arr[30];
void Per(int k)
{
    if (k == len)
    {
        for (int j = 0; j < len; j++)
            cout << arr[j];
        cout << endl;
    }
    else
    {
        for (int i = k; i < len; i++) //第i个数分别与它后面的数字交换就能得到新的排列
        {
            swap(arr[i], arr[k]);

            sort(arr + 1 + k, arr + len);

            Per(k + 1);

            sort(arr + k, arr + len);
        }
    }
}
int main()
{
    cin >> s;
    len = s.size();
    for (int i = 0; i < len; i++)
        arr[i] = s[i];
    sort(arr, arr + len);
    Per(0);
    return 0;
}
