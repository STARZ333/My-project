#include <cstring>
#include <iostream>
using namespace std;

class student
{
public:
    bool setName(const char *stName);
    bool setCal(const int score);
    bool setPhy(const int score);
    bool setIcs(const int score);
    const char *getName();
    int getCal();
    int getPhy();
    int getIcs();
    double getAverage();
    student(const char *stName);
    student(const char *stName, const int cal, const int phy, const int ics);

private:
    int cal;
    int psy;
    int ics;
    char *pname;
};
student::student(const char *stName)
{
    pname = new char[strlen(stName)];
    setName(stName);
    cal = rand() % 101;
    psy = rand() % 101;
    ics = rand() % 101;
    getName();
    getCal();
    getPhy();
    getIcs();
    getAverage();
}
student::student(const char *stName, const int c, const int p, const int i)
{
    pname = new char[strlen(stName)];
    setName(stName);
    cal = c;
    psy = p;
    ics = i;
    getName();
    getCal();
    getPhy();
    getIcs();
    getAverage();
}
bool student::setName(const char *stName)
{
    strcpy(pname, stName);
    return 0;
}
const char *student::getName()
{
    cout << pname << endl;
    return 0;
}
bool student::setCal(const int score)
{

    cal = score;
    return 0;
}
bool student::setPhy(const int score)
{

    psy = score;
    return 0;
}
bool student::setIcs(const int score)
{

    ics = score;
    return 0;
}
int student::getCal()
{
    cout << cal << endl;
    return 0;
}
int student::getPhy()
{
    cout << psy << endl;
    return 0;
}
int student::getIcs()
{
    cout << ics << endl;
    return 0;
}
double student::getAverage()
{
    double s = cal + psy + ics;
    double a = s / 3;
    cout << a << endl;

    return 0;
}
int main()
{
    char *name;
    name = new char[30];
    int n;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        else if (n == 1)
        {
            int x;
            cin >> x;
            srand(x);
            cin >> name;
            student stscore(name);
        }
        else if (n == 2)
        {
            cin >> name;
            int c, p, i;
            cin >> c >> p >> i;
            student stscore(name, c, p, i);
        }
    }
}
