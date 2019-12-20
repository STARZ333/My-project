#include<iostream>
#include<math.h>
#include <stdlib.h>
#include <stdio.h>
#include<string>
using namespace std;
int main()
{
    string out,stri,strsum;//储存输出结果
    int a, b,n,i,c,sum=0,j;
    cin >> n;
    
    //输入n组a，b
    for (i = 1; i <= n;i++)
    {
        sum = 0;
        cin >> a;
        cin >> b;
        //ab比大小，小的在a
        if(a>b)
    {
        c = a;
        a = b;
        b = c;
    }   
    //找出奇数并求和
    for (j = a; j <= b;j++)
    {
        //判断是否为奇数
        if(j%2==1)
        {
            sum = sum + j;
        }
    }
    std::string stri =  std::to_string(i);
    std::string strsum = std::to_string(sum);
    out =out+ "Case " +stri+ ":" + strsum+ "\n";

    }
    cout << out;
}