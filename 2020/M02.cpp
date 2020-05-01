#include <cmath>
#include <iostream>
using namespace std;
class primeNumber
{
private:
    int pri;

public:
    primeNumber();
    primeNumber(int n);
    bool setPrime(int n);
    int getPrime();
    int prime(int a);
    primeNumber operator+(const primeNumber &b)
    {
        pri = pri + b.pri;
        for (int i = pri;; i++)
        {
            if (prime(i))
            {
                pri = i;
                break;
            }
        }
        return primeNumber();
    }
    primeNumber operator-(const primeNumber &b)
    {
        pri = abs(pri - b.pri);
        for (int i = pri;; i++)
        {
            if (prime(i))
            {
                pri = i;
                break;
            }
        }
        return primeNumber();
    }
    primeNumber operator+(const int n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = pri+1;; j++)
            {
                if (prime(j))
                {
                    pri = j;
                    break;
                }
            }
        }
        return primeNumber();
    }
};
int primeNumber::getPrime()
{
    cout << pri << endl;
    return 0;
}
bool primeNumber::setPrime(int n)
{
    for (int i = n;; i++)
    {
        if (prime(i))
        {
            pri = i;
            break;
        }
    }
    return 0;
}

primeNumber::primeNumber()
{
    int y;
    y = rand() % 9001 + 1000;
    for (int i = y;; i++)
    {
        if (prime(i))
        {
            pri = i;
            break;
        }
    }
}
primeNumber::primeNumber(int n)
{
    for (int i = n;; i++)
    {
        if (prime(i))
        {
            pri = i;
            break;
        }
    }
}

int primeNumber::prime(int a)
{
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int s;
    cin >> s;
    srand(s);
    int a, b, c;

    while(cin >> a >> b >> c)
    {
    if (a == 0)
    {
        if (b == 0)
        {
            primeNumber x;
            if (c == 0)
            {
                primeNumber y;
                x + y;
                x.getPrime();
            }
            else
            {
                primeNumber y(c);
                x + y;
                x.getPrime();
            }
        }
        else
        {
            primeNumber x(b);
            if (c == 0)
            {
                primeNumber y;
                x + y;
                x.getPrime();
            }
            else
            {
                primeNumber y(c);
                x + y;
                x.getPrime();
            }
        }
    }
    else if(a==1)
    {
        if (b == 0)
        {
            primeNumber x;
            if (c == 0)
            {
                primeNumber y;
                x - y;
                x.getPrime();
            }
            else
            {
                primeNumber y(c);
                x - y;
                x.getPrime();
            }
        }
        else
        {
            primeNumber x(b);
            if (c == 0)
            {
                primeNumber y;
                x - y;
                x.getPrime();
            }
            else
            {
                primeNumber y(c);
                x - y;
                x.getPrime();
            }
        }
    }
    else if(a==2)
    {
        if (b == 0)
        {
            primeNumber x;
            x + c;
            x.getPrime();
        }
        else
        {
            primeNumber x(b);
            x + c;
            x.getPrime();
        }
    }
    else if (a==3)
        break;
    }
}