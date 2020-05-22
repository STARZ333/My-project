#include<iostream>
using namespace std;

int F(int x)
{
    if(x==1||x==2)
        return 1;
    else  
    
        return F(x - 1) + F(x - 2);
    

}

int main()
{
    int x;
    while (cin>>x)
    {
        if(x<1)
            break;
        cout << F(x) << endl;
    }
}