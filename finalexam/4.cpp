#include<iostream>
using namespace std;
int main()
{
    bool finish=false;
    int s,i,j,number[100];
    cin >> s;
    srand(s);
    //阵列初始化
    for (j = 0; j < 100;j++)
        number[j] = 0;

    for ( i = 1; i <= 10000;i++)
    {
        number[rand() % 100 ] += 1;
        for (int k = 0; k < 100;k++)
        {
            if(number[k]==100)
            {
                    cout << k + 1<<endl;
                    finish = true;
                    break;
            }
        }
        if(finish)
            break;
    }

}
