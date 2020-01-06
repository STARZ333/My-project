#include <iostream>
using namespace std;
bool fourDigitTen(int x)
{
    int sum = 0;
    bool number = false, ten = false;
    //判断是否为4位数
    if (x - 1000 >= 0 && x - 10000 < 0)
        number = true;
    
    //求出各位数字之和
    if (number)
    {
        for (int j = 1; j < 5; j++)
        {
            sum += x % 10;
            x = x / 10;
        }
    }

    if (sum == 10)
    {
        ten = true;
    }
    return (ten);
}

bool prime(int x)//判断是否为质数
{
    int i;
  
    for (i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            return (false);
            break;
        }
    }
    if (x == i)
        return (true);
}

int main()
{
    int i;
    for (i = 1000; i < 10000;i++)
    {
        if(prime(i)&&fourDigitTen(i))
            cout << i << endl;
    }
}