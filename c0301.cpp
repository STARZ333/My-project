#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str1,str;
    int number, i, tou=0, er=0, san=0, si=0,money=0; //number存发票数量
    cin >> number;

    //将输入的x张发票存在str中
    for (i = 1; i <= number; i = i + 1)
    {
        cin >> str1;
        str = str + str1 ;
    }
    i = 1;
    //str1 = str1.assign(str, (i - 1) * 8, 2);
    //cout << str1<<endl;
    //cout << str << endl;

    for (i = 1; i <= number; i = i + 1)
    {
    
        if ((str1.assign(str, (i - 1) * 8, 8)) == "20379435")
        {
        cout << "頭獎" << endl;
        tou = tou + 1;
        }
        else if((str1.assign(str, (i - 1) * 8, 8))=="47438762")
        {cout << "二獎" << endl;
            er = er + 1;
        }
        else if (((str1.assign(str, (i - 1) * 8+3, 5)=="79435")||(str1.assign(str, (i - 1) * 8+3, 5)=="38762")))
        {cout << "三獎" << endl;
            san = san + 1;}
        else if (((str1.assign(str, (i - 1) * 8+5, 3)=="435"))||((str1.assign(str, (i - 1) * 8+5, 3)=="762"))||((str1.assign(str, (i - 1) * 8+5, 3)=="693"))||((str1.assign(str, (i - 1) * 8+5, 3)=="504"))||((str1.assign(str, (i - 1) * 8+5, 3)=="425"))||((str1.assign(str, (i - 1) * 8+5, 3)=="878")))
        {
            cout << "四獎" << endl;
            si = si + 1;
        }
        else 
        {
            cout << "無" << endl;
        }
    }
    money = tou * 200000 + er * 40000 + san * 10000 + si * 200;
    cout << money << endl;

    return 0;
}