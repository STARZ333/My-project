#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    ofstream outfile;
    ifstream infile;
    infile.open("1.in");
    outfile.open("1.out");
    char k;
    while (infile.get(k))
    {
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
    outfile << "\n";
    infile.close();
    outfile.close();
}
