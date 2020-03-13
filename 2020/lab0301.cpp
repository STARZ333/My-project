#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
int prime(int a)
{
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}
int main()
{

    int data;

    // 以读模式打开文件
    ofstream outfile;
    ifstream infile;
    infile.open("1.txt");
    outfile.open("2.txt");

    while (infile >> data)
    {
        if(data==1||data==2)
        {
            outfile << "2\n";
        }
        else
        {
            for (int i = data-1; i >= 2;i--)
            {
                if(prime(i))
                {    outfile << i << "\n";
                    break;
            }
            }
        }
    }
    
    // 关闭打开的文件
    infile.close();
    outfile.close();

    return 0;
}