#include<stdlib.h>
#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
    int h=0,m=0,s=0;
    do
    {
        s++;
        
if (s==60)
{
    s = 0;
    m++;
}
if (m==60)
{
    m = 0;
    h++;
}
cout << h << ":" << m << ":" << s  << endl;
Sleep(1000);
system("cls");

    } while (h < 99);
}