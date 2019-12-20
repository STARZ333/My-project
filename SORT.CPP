#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
 int a[20]={2,3,1,4,6,5,8,7,9,10,12,11,14,13,17,16,15,19,18,20},i;
 for(i=0;i<20;i++)
  cout<<a[i]<<endl;
 sort(a,a+20);
 for(i=0;i<20;i++)
 cout<<a[i]<<endl;
 return 0;
}
