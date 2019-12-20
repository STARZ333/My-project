#include<iostream>
#include<string>
using namespace std;
int main()
{
  int i,a,b,c,d,number;
  string out;
  cin >> number;

  for (i = 0 ; i<number ;i++)
  {
    cin >> a >> b >> c >> d;
    if (a==b && b==c && c==d)
    {out=out+"square\n";}
    else if ( ((a==b)&&(c==d)) || ((a==c)&&(b==d)) || (((a==d)&&(b==c))) )
    {out = out + "rectangle\n";}
    else if ( (a<b+c+d)&&(b<a+c+d)&&(c<a+b+d)&&(d<a+b+c))
    {out = out + "quadrangle\n";}
    else 
    {out = out + "none\n";}
  }
  cout << out;
}