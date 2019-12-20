#include <iostream>
using namespace std;
int main()
{
	int n, store, walk, i, x,y,max,min;
	cin >>n;
	for(i=1;i<=n;i++)
	{
		cin>>store;
		for(y=1;y<=store;y++)
		{cin>>x;
		if(y==1)
		{
			max=x;
			min=x;
		}
		if(x>max)
		{
			max=x;
		}
		if(x<min)
		{
			min=x;
		}
        }
		walk=(max-min)*2;
		cout<<walk<<endl;
	}
 } 