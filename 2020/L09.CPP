#include <iostream>
using namespace std;
class powerDate
{
private:
    int year = 2020;
    int month = 1, day = 1;

public:
    powerDate(const int y, const int m, const int d);
    bool isLeap(int x);
    int getWeek();
    bool set(const int y, const int m, const int d);
    int getYear();
    int getMonth();
    int getDay();
    void weeks();
    friend ostream &operator<<(ostream &out, powerDate &A);
    friend istream &operator>>(istream &in, powerDate &A);
    powerDate operator [](int n)
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
                    day +=  29;
                }
                else
                {
                    day +=  28;
                }
            }
        }
        while (day > 28)
        {
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            {
                if (day > 31)
                {
                    day -=  31;
                    month++;
                }
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11)
            {
                if (day > 30)
                {
                    day -=  30;
                    month++;
                }
            }
            else
            {
                if (isLeap(year) == true)
                {
                    if (day > 29)
                    {
                        day -=  29;
                        month++;
                    }
                }
                else
                {
                    if (day > 28)
                    {
                        day -=  28;
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
        return powerDate(year, month, day);
    }
};

powerDate::powerDate(const int y, const int m, const int d)
{
    set(y, m, d);
}

istream &operator>>(istream &in, powerDate &A)
{
    int y, m, d;
    in >> y >> m >> d;
    A.set(y, m, d);
    return in;
}

ostream &operator<<(ostream &out, powerDate &A)
{

    out << A.year << "-";
    if (A.month < 10)
        out << "0" << A.month;
    else
        out << A.month;
    out << "-";
    if (A.day < 10)
        out << "0" << A.day;
    else
        out << A.day;
    if (A.isLeap(A.year))
        out << "L ";
    else
        out << "l ";
    A.weeks();
    return out;
}
int powerDate::getWeek(void)
{
    int m = month;
    int y = year, d = day;

    if (m == 1 || m == 2) //
    {
        m += 12;
        y--;
    }
    int Week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    switch (Week)
    {
    case 0:
        return 1;
        break;
    case 1:
        return 2;
        break;
    case 2:
        return 3;
        break;
    case 3:
        return 4;
        break;
    case 4:
        return 5;
        break;
    case 5:
        return 6;
        break;
    case 6:
        return 7;
        break;
    }
}
void powerDate::weeks()
{

    switch (getWeek())
    {
    case 1:
        cout << "Monday";
        break;
    case 2:
        cout << "Tuesday";
        break;
    case 3:
        cout << "Wednesday";
        break;
    case 4:
        cout << "Thurday";
        break;
    case 5:
        cout << "Friday";
        break;
    case 6:
        cout << "Saturday";
        break;
    case 7:
        cout << "Sunday";
        break;
    }
}
int powerDate::getYear()
{
    cout << year;
    return year;
}
int powerDate::getMonth()
{
    cout << month;
    return month;
}
int powerDate::getDay()
{
    cout << day;
    return day;
}
bool powerDate::isLeap(int x)
{

    if ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0))
        return 1;
    else
        return 0;
}
bool powerDate::set(const int y, const int m, const int d)
{
    if (y < 0 || m <= 0 || m > 12 || d <= 0 || d > 31)
    {
        year = 1900;
        month = 1;
        day = 1;
        return false;
    }
    if (1 == m || 3 == m || 5 == m || 7 == m || 8 == m || 10 == m || 12 == m)
    {
        year = y;
        month = m;
        day = d;
        return true;
    }
    if (isLeap(y))
    {
        if (2 == m && (d > 29))
        {
            year = 1900;
            month = 1;
            day = 1;
            return false;
        }
        else
        {

            year = y;
            month = m;
            day = d;
            return true;
        }
    }
    else
    {
        if (2 == m && (29 == d || 30 == d || 31 == d))
        {
            year = 1900;
            month = 1;
            day = 1;
            return false;
        }
        else
        {
            year = y;
            month = m;
            day = d;
            return true;
        }
    }
}

int main()
{
    int a;
    
    while(cin>>a)
    {
        if(a==0)
            break;
        else if(a==1)
        {
            powerDate d1(1900,1,1);
            cin >> d1;
            cout <<"現在日期: "<< d1<<endl;
        }
        else if (a==2)
        {
            powerDate d1(1900,1,1);
            cin >> d1;
            int n;
            cin >> n;
            d1[n];
            cout<<"現在日期: " << d1<< endl;
        }
    }
}