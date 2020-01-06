#include <fstream>
#include <iostream>
using namespace std;
 
int main ()
{
    double av,count=0.0;
    int data, max, min, sum=0;

    // 以读模式打开文件
    ifstream infile;
    infile.open("a.txt");
    infile >> max;
    min = max;
    while (infile >> data)
    {
        count += 1;
        if(data>max)
            max = data;
        if(data<min)
            min = data;
        sum += data;
   }
   av = sum / count;
   cout << max << endl;
   cout << min << endl;
   cout << av << endl;
   // 关闭打开的文件
   infile.close();
 
   return 0;
}