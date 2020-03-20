#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    ofstream outfile;
    ifstream infile;
    infile.open("1.in");
    outfile.open("1.out");
    char password,num;
    password = infile.get();
    outfile.put(password);
    while (!infile.eof())
    {
        num = infile.get();
        if (num != '\n')
        {
            num = num ^ password;
            outfile.put(num);
        }
    }
    infile.close();
    outfile.close();
}