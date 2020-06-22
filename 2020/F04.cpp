#include <iostream>
using namespace std;
template <typename T>
void add(T &a, T &b)
{
    T add = a + b;
    b = add;
}
int main()
{
    int x;
    while (cin >> x)
    {
        if (x == 0)
            break;
        if (x == 1)
        {
            int b, c;
            cin >> b >> c;
            add(b, c);
            cout << c << endl;
        }
        if (x == 2)
        {
            char a, b;
            cin >> a >> b;
            add(a, b);
            cout << b<< endl;
        }
        if (x == 3)
        {
            double a, b;
            cin >> a >> b;
            add(a, b);
            cout << b << endl;
        }
    }
}