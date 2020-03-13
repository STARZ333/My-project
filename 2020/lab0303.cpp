#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    ofstream outfile;
    ifstream infile;
    infile.open("1.txt");
    outfile.open("2.txt");
    char k;
    while (infile.get(k))
    {
        if(k=="\n")
            break;
        if (k >= 'a' && k <= 'z')
        {
            k = k - 32;
            outfile << k;
        }
        else
        {
            outfile << k;
        }
    }
}