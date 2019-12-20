#include<iostream>
#include<math.h>
#include<string>
using namespace std;
int main()
{
    string total,out;
    int n,i,j,k,max=0,min=100000,a;
    cin >> n;//n组测资
    for (i = 1; i <= n;i++)//
    {
        cin >>  j;//输入店数
        max = 0;
        min = 100000;

        for (k = 1; k <= j; k++)
        {
            cin >> a;
            if(a<min)
            {
                min = a;
            }
            if(a>max)
            {
                max = a;
            }
        }
        std::string total =  std::to_string((max-min)*2);
        out = out + total + "\n";
    }
    cout << out;
}