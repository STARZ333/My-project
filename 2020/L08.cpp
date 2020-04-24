#include <iostream>
#include <cmath>
using namespace std;
class BankAcc
{
private:
    double NTD = 0, USD = 0, EUD = 0;

public:
    BankAcc(double a, double b, double c)
    {
        setNTD(a);
        setUSD(b);
        setEUD(c);
    }
    void reset(const double n, const double u, const double e);
    void setNTD(const double m);
    void setUSD(const double m);
    void setEUD(const double m);
    double getNTD();
    double getUSD();
    double getEUD();
    double valueInNTD();
    double valueInUSD();
    double valueInEUD();
    void output();
    BankAcc operator+(const BankAcc &b)
    {
        NTD += b.NTD;
        USD += b.USD;
        EUD += b.EUD;
        return BankAcc(NTD, USD, EUD);
    }
    BankAcc operator-(const BankAcc &b)
    {
        NTD -= b.NTD;
        USD -= b.USD;
        EUD -= b.EUD;
        return BankAcc(NTD, USD, EUD);
    }
    BankAcc operator%(const BankAcc &b)
    {
        NTD = abs(NTD - b.NTD);
        USD = abs(USD - b.USD);
        EUD = abs(EUD - b.EUD);
        return BankAcc(NTD, USD, EUD);
    }
    BankAcc operator*(const BankAcc &b)
    {
        NTD += b.NTD*0.99;
        USD += b.USD*0.99;
        EUD += b.EUD*0.99;
        return BankAcc(NTD, USD, EUD);
    }
    BankAcc operator/(const BankAcc &b)
    {
        NTD -= b.NTD*1.01;
        USD -= b.USD*1.01;
        EUD -= b.EUD*1.01;
        return BankAcc(NTD, USD, EUD);
    }
};

void BankAcc::setNTD(const double m)
{
    NTD = m;
}

void BankAcc::setUSD(const double m)
{
    USD = m;
}

void BankAcc::setEUD(const double m)
{
    EUD = m;
}
void BankAcc::reset(const double n, const double u, const double e)
{
    setNTD(n);
    setUSD(u);
    setEUD(e);
}

double BankAcc::getNTD()
{
    return NTD;
}
double BankAcc::getUSD()
{

    return USD;
}
double BankAcc::getEUD()
{

    return EUD;
}

void BankAcc::output()
{

    cout << "NTD:" << valueInNTD() << " USD:" << valueInUSD() << " EUD:" << valueInEUD() << endl;
}

double BankAcc::valueInNTD()
{
    double total;
    total = NTD + USD * 30 + EUD * 40;
    return total;
}

double BankAcc::valueInUSD()
{
    double total;
    total = NTD / 30 + USD + EUD * 40 / 30;
    return total;
}
double BankAcc::valueInEUD()
{
    double total;
    total = NTD / 40 + USD * 30 / 40 + EUD;
    return total;
}

int main()
{
    double x, y, z, a, b, c;

    cin >> x >> y >> z;
    cin >> a >> b >> c;
    BankAcc x1(x, y, z), x2(a, b, c);
    x1.output();
    x2.output();

    x1 + x2;
    cout << "+:";
    x1.output();

    x1.reset(x, y, z);
    x1 - x2;
    cout << "-:";
    x1.output();

    x1.reset(x, y, z);
    x1 % x2;
    cout << "%:";
    x1.output();

    x1.reset(x, y, z);
    x1 *x2;
    cout << "*:";
    x1.output();

    x1.reset(x, y, z);
    x1 / x2;
    cout << "/:";
    x1.output();
}