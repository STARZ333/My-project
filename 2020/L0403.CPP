#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    ofstream outfile;
    ifstream infile;
    infile.open("1.in");
    outfile.open("1.out");
    char password, num;
    infile.get(password);
    outfile.put(password);
    while (infile.get(num))
    {
        num = num ^ password;
        outfile.put(num);
    }

infile.close();
outfile.close();
}
