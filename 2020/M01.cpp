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
    int x;

    cin >> x;

    if (x == 0)
    {
        primeNumber lks;
        lks.getPrime();
        while (cin >> x)
        {
            if (x < 2)
                break;
            else
            {
                primeNumber lks(x);
                lks.getPrime();
            }
        }
    }
    else if (x == 1)
    {
        cout << 2 << endl;
        while (cin >> x)
        {
            if (x < 2)
                break;
            else
            {
                primeNumber lks(x);
                lks.getPrime();
            }
        }
    }

    else
    {
        while (x >= 2)
        {
            if (x < 2)
                break;
            else
            {
                primeNumber lks(x);
                lks.getPrime();
                cin >> x;
            }
        }
    }
}