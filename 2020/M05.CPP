#include <iostream>
#include <cmath>
using namespace std;
class myTime
{
public:
    myTime();
    myTime(int hr, int mn, int sc);
    int getHour() const;
    int getMin() const;
    int getSec() const;
    void output();
    myTime operator+(const myTime &b)
    {
        int sum;
        sum = (hour + b.hour) * 3600 + (min + b.min) * 60 + sec + b.sec;
        hour = sum / 3600;
        min = sum % 3600 / 60;

        sec = sum -min*60-hour*3600;
        
        return myTime();
    }
    myTime operator-(const myTime &b)
    {
        int minus;
        minus = abs(3600 * hour + 60 * min + sec - b.hour * 3600 - b.min * 60 - b.sec);
        hour = minus / 3600;
        min = minus % 3600 / 60;

        sec = minus -min*60-hour*3600;
        return myTime();
    }
    myTime operator+(const int n)
    {
        int pmin, phour;
        if(sec+n<60)
            sec += n;
        else if (sec+n>60)
        {
            pmin = (sec + 60) / 60;
            min += pmin;
            sec = (sec + n) % 60;
            if(min>=60)
            {
                phour = min / 60;
                hour += phour;
                hour = hour % 60;
            }
        }
        return myTime();
    }

private:
    int hour;
    int min;
    int sec;
};
myTime::myTime(int hr, int mn, int sc)
{
    hour = hr;
    min = mn;
    sec = sc;
}
myTime::myTime()
{
    hour = 0;
    min = 0;
    sec = 0;
}
int myTime::getHour() const
{
    return hour;
}
int myTime::getMin() const
{
    return min;
}
int myTime::getSec() const
{
    return sec;
}
void myTime::output()
{

    cout << "hr:" << hour << " min:" << min << " sec:" << sec << endl;
}
int main()
{
    int a, b, c, d, e, f, g;
    while(cin>>a)
    {
        if(a==0)
            break;
        else if(a==1)
        {
            cin >> b >> c >> d >> e >> f >> g;
            myTime time1(b, c, d),time2(e, f, g);
            time1 + time2;
            time1.output();
        }
        else if (a==2)
        {
            cin >> b >> c >> d >> e >> f >> g;
            myTime time1(b, c, d),time2(e, f, g);
            time1 - time2;
            time1.output();
        }
        else if (a==3)
        {
            cin >> b >> c >> d;
            myTime time1(b, c, d);
            time1 + d;
            time1.output();
        }
    }
}