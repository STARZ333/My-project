#include <ctime>
#include <iostream>
using namespace std;
int main()
{
    int arr[14], num;
    string flower[] = {"S", "H", "D", "C"}, stnum[14];
    stnum[1] = 'A';
    stnum[11] = 'J';
    stnum[12] = 'Q';
    stnum[13] = 'K';

    srand(time(0));
    //产生不重复随机数
    for (int i = 0; i < 13; i++)
    {

        arr[i] = rand() % 52 + 1;
        for (int k = 0; k < i; k++)
        {
            if (arr[i] == arr[k])
            {
                i--;
                break;
            }
        }
    }
    //对随机数处理，输出花色和数字
    for (int i = 0; i < 13; i++)
    {
        cout << flower[(arr[i] - 1) / 13];
        num = arr[i] % 13 + 1;
        if ((num == 1) || (num >= 11))
        {
            cout << stnum[num];
        }
        else
        {
            cout << num;
        }
        cout << endl;
    }
}
