#include <iostream>
#include <math.h>
using namespace std;
class myDate
{

private:
    int year;
    int month;
    int day;
    int week;

public:
    myDate(const int y, const int m, const int d);
    int getYear();
    int getMonth();
    int getDay();
    int getWeek(); //0~6 蔡勒公式
    bool setDate(const int y, const int m, const int d);
    void output(); //輸出 year-month-day (week)
    bool isLeap(int x);
    myDate operator+(int n)
    {
        day += n;
        while (day <= 0)
        {
            month--;
            if (month < 1)
            {
                year--;
                month = 12;
            }
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            {
                day += 31;
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11)
            {
                day += 30;
            }
            else
            {
                if (isLeap(year) == true)
                {
                    day += 29;
                }
                else
                {
                    day += 28;
                }
            }
        }
        while (day > 28)
        {
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            {
                if (day > 31)
                {
                    day -= 31;
                    month++;
                }
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11)
            {
                if (day > 30)
                {
                    day -= 30;
                    month++;
                }
            }
            else if (month == 2)
            {
                if (isLeap(year) == true)
                {
                    if (day > 29)
                    {
                        day -= 29;
                        month++;
                    }
                    else
                        return myDate(year, month, day);
                }
                else
                {
                    if (day > 28)
                    {
                        day -= 28;
                        month++;
                    }
                }
            }
            if (month > 12)
            {
                year++;
                month = 1;
            }
        }
        return myDate(year, month, day);
    }
};
bool myDate::isLeap(int x)
{

    if ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0))
        return 1;
    else
        return 0;
}
myDate::myDate(const int y, const int m, const int d)
{
    setDate(y, m, d);
}
void myDate::output()
{
    cout << getYear() << "-" << getMonth() << "-" << getDay() << " (" << getWeek() << ")" << endl;
}
int myDate::getYear()
{
    return year;
}
int myDate::getMonth()
{
    return month;
}
int myDate::getDay()
{
    return day;
}
bool myDate::setDate(const int y, const int m, const int d)
{
    year = y;
    month = m;
    day = d;
    return 0;
}
int myDate::getWeek(void)
{
    int m = month;
    int y = year, d = day;

    if (m == 1 || m == 2) //
    {
        m += 12;
        y--;
    }
    int Week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    week = Week + 1;
    if (week == 7)
        week = 0;
    return week;
}
class myDateTime : public myDate
{
private:
    int hour;
    int minute;
    int second;

public:
    myDateTime(const int y, const int m, const int d, const int h, const int min, const int s);
    int getHour();
    int getMinute();
    int getSecond();
    bool setDateTime(const int y, const int m, const int d, const int h, const int min, const int s);
    void output(); //輸出 year-month-day (week) hour:minute:second
    myDateTime operator+(int n)
    {
        int pday;
        second += n;
        if (second < 60)
            return myDateTime(myDate::getYear(), myDate::getMonth(), myDate::getDay(), hour, minute, second);
        else
        {
            minute += second / 60;
            second = second % 60;
        }
        if (minute < 60)
            return myDateTime(myDate::getYear(), myDate::getMonth(), myDate::getDay(), hour, minute, second);
        else
        {
            hour += minute / 60;
            minute %= 60;
        }
        if (hour < 24)
            return myDateTime(myDate::getYear(), myDate::getMonth(), myDate::getDay(), hour, minute, second);
        else
        {
            pday = hour / 24;
            hour %= 24;
        }
        myDate::operator+(pday);
        return myDateTime(myDate::getYear(), myDate::getMonth(), myDate::getDay(), hour, minute, second);
    }
    myDateTime operator-(int n)
    {
        int pday=0;
        second -= n;
        
        while (second < 0)
        {
            second = 60 + second;
            minute -= 1;
        }
        while (minute < 0)
        {
            minute += 60;
            hour -= 1;
        }
        while (hour < 0)
        {
            hour += 24;
            pday -= 1;
        }
        myDate::operator+(pday);
        return myDateTime(myDate::getYear(), myDate::getMonth(), myDate::getDay(), hour, minute, second);
    }
};
myDateTime::myDateTime(const int y, const int m, const int d, const int h, const int min, const int s) : myDate(y, m, d)
{
    setDateTime(y, m, d, h, min, s);
}

void myDateTime::output()
{
    cout << getYear() << "-" << getMonth() << "-" << getDay() << " (" << getWeek() << ") " << hour << ":" << minute << ":" << second << endl;
}
int myDateTime::getHour()
{
    return hour;
}
int myDateTime::getMinute()
{
    return minute;
}
int myDateTime::getSecond()
{
    return second;
}
bool myDateTime::setDateTime(const int y, const int m, const int d, const int h, const int min, const int s)
{
    myDate::setDate(y, m, d);
    hour = h;
    minute = min;
    second = s;
    return 0;
}

int main()
{
    int y,m,d,h,min,s,x;
    cin >> y >> m >> d >> h >> min >> s;
    myDateTime kkk(y, m, d, h, min, s);
    while(cin>>x)
    {
        if(x==0)
            break;
        if(x>0)
        {    kkk + x;
            kkk.output();
        }
        else if(x<0)
        {
            kkk - (-x);
            kkk.output();
        }
    }
    
}