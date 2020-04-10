#include <iostream>
using namespace std;
class Time
{
public:
    bool setTime(const int hour, const int min, const int sec);
    bool setDate(const int year, const int month, const int day);
    int whatDate();
    void output();
    void outputROC();
    void weeks();
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

int Time::whatDate(void)
{
    int m = pmonth;
    int y = pyear,d=pday;

    if (m == 1 || m == 2) //把一月和二月换算成上一年的十三月和是四月
    {
        m+=12;
        y--;
    }
    int Week=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    switch(Week)
    {
        case 0:  return 1; break;
        case 1:  return 2; break;
        case 2:  return 3; break;
        case 3:  return 4; break;
        case 4:  return 5; break;
        case 5:  return 6; break;
        case 6:  return 7; break;
    }
}

void Time::output()
{
    if(pyear>999)
        cout << pyear<<"-";
    else
        cout << "0" << pyear << "-";
    if(pmonth<10)
        cout << "0" << pmonth << "-";
    else
        cout << pmonth<<"-";
    if(pday<10)
        cout << "0" << pday << " ";
    else
        cout << pday<<" ";
    if(phour<13)
    {
        if(phour<10)
            cout << "0" << phour<<":";
        if(phour>9)
            cout << phour << ":";
    }
    else
    {
        if(phour<22)
            cout << "0" << phour - 12 << ":";
        else
            cout << phour - 12 << ":";
    }
    if(pmin<10)
        cout << "0" << pmin<<":";
    else
        cout << pmin << ":";
    if(psec<10)
        cout << "0" << psec;
    else
        cout << psec;
    if(phour<12)
        cout << " am" << endl;
    else
        cout << " pm" << endl;
}

void Time::outputROC(void)
{
    cout << "中華民國";
    cout << pyear - 1911 << "年";
    if(pmonth<10)
        cout << "0" << pmonth<<"月";
    else
        cout << pmonth << "月";
    if(pday<10)
        cout << "0" << pday<<"日";
    else
        cout << pday << "日";
    if(phour<12)
        cout << "上午";
    else
        cout << "下午";
    if(phour<10)
        cout << "0" << phour<<"點";
    else if(phour<13)
        cout << phour << "點";
    else if(phour<22)
    cout << "0" << phour - 12 << "點";
    else
        cout << phour - 12 << "點";
    if(pmin<10)
        cout << "0" << pmin << "分";
    else
        cout << pmin << "分";
    if(psec<10)
        cout << "0" << psec << "秒"<<endl;
    else
        cout << psec << "秒"<<endl;
}
void Time::weeks()
{
    cout << isLeap(pyear);
    switch(whatDate())
    {
        case 1:  cout<<"Monday"; break;
        case 2:  cout<<"Tuesday"; break;
        case 3:  cout<<"Wednesday"; break;
        case 4:  cout<<"Thurday"; break;
        case 5:  cout<<"Friday"; break;
        case 6:  cout<<"Saturday"; break;
        case 7:  cout<< "Sunday";break;
    }

}
int Time::seconds()
{
    return (phour * 3600 + pmin * 60 + psec);
}
bool Time::isLeap(int x)
{
    if ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0))
        return 1;
    else
        return 0;
}

int main()
{
    Time trans;
    int year, mon, day, hour, min, sec;
    while(cin>>year>>mon>>day>>hour>>min>>sec)
    {
        if(year==0&&mon==0&&day==0&&hour==0&&min==0&&sec==0)
            break;
        trans.setDate(year, mon, day);
        trans.setTime(hour,min , sec);
        trans.output();
        trans.outputROC();
        trans.weeks();
        cout << endl;
        cout << trans.seconds()<<endl;
    }

}
