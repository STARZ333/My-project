#include <iostream>
using namespace std;
class Time
{
public:
    bool setTime(const int hour, const int min, const int sec);
    bool setDate(const int year, const int month, const int day);
    int whatDate;
    void input();
    void output();
    void outputROC();
    int seconds();
    bool isLeap(int x);

private:
    int phour, pmin, psec, pyear, pmonth, pday;
};

bool Time::setTime(const int hour, const int min, const int sec)
{
    if((hour>=0&&hour<25)&&(min>=0&&min<61)&&(sec>=0&&min<61))
    {
        phour = hour;
        pmin = min;
        psec = sec;
        return true;
    }
    else
        return false;
}

bool Time::setDate(const int year, const int month, const int day)
{
    if (year < 0 || month <= 0 || month > 12 || day <= 0 || day > 31)
        return false;

    if (1 == month || 3 == month || 5 == month || 7 == month || 8 == month || 10 == month || 12 == month)
    {
        pyear = year;
        pmonth = month;
        pday = day;
        return true;
    }
    if (isLeap(year))
    {
        if (2 == month && (day > 29))
        {
            return false;
        }
        else
        {

            pyear = year;
            pmonth = month;
            pday = day;
            return true;
        }
    }
    else
    {
        if (2 == month && (29 == day || 30 == day || 31 == day))
            return false;
        else
        {
            pyear = year;
            pmonth = month;
            pday = day;
            return true;
        }
    }
}

int Time::whatDate()

bool Time::isLeap(int x)
{
    if ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0))
        return 1;
    else
        return 0;
}

int main()
{
    Time x;
    cout << x.setDate(2000, 2, 29);
}
