#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    double sum = 0.0,av,sd=0.0;
    int s, x;
    cin >> s >> x;
    srand(s);
    int *p[1024];
    for (int i = 0; i < x; i++)
    {
        p[i] = new int;
        *(p[i]) = rand() % 201 - 100;
        sum += *(p[i]);
    }
    av = sum / x;
    for (int i = 0; i < x;i++)
    {
        sd += pow(*(p[i]) - av,2);
    }
    sd = sqrt(sd/x);
    cout << av << endl;
    cout << sd << endl;
}