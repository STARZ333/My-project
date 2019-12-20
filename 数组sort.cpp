#include<string>
#include<vector>
#include<iostream>
#include<algorithm>//算法。sort用
using namespace std;
int main()
{
    int a[5]={23,55,34,98,18},i;
    
	
    sort(a, a + 5);
    for (i = 0; i <5;i++)
        cout << a[i]<<endl;
}
