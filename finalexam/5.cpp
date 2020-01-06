#include <iostream>
using namespace std;
int main()
{
    int x, hour, min, sec;
    cin >> x;
    //计算时间
    hour = x / 3600;
    x = x % 3600;
    min = x / 60;
    x = x % 60;
    sec = x;
    //输出AM情况
    if (hour < 12)
    {
        cout << "AM " << hour;
        if (min < 10)
            cout  <<":0" << min ;
        if (min >= 10)
            cout << ":" << min ;
        if (sec<10)
            cout << ":0" << sec;
        if(sec>10)
            cout << ":" << sec;
    }
    if(hour==12)
    {
        cout << "PM " << hour;
        if (min < 10)
            cout  <<":0" << min ;
        if (min >= 10)
            cout << ":" << min ;
        if (sec<10)
            cout << ":0" << sec;
        if(sec>10)
            cout << ":" << sec;
    }   
    //输出PM情况
    if(hour>12)
    {
        cout << "PM " << hour-12;
        if (min < 10)
            cout  <<":0" << min ;
        if (min >= 10)
            cout << ":" << min ;
        if (sec<10)
            cout << ":0" << sec;
        if(sec>10)
            cout << ":" << sec;
    }
}