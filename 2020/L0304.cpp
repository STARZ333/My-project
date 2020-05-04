#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    ofstream outfile;
    ifstream infile;
    infile.open("1.in");
    outfile.open("1.out");
    char k,aft;
    while (infile.get(k))
    {
        if(k=='\n')
            break;
        aft = k ^ 'a';
        outfile << aft;
    }
    outfile << "\n";
    infile.close();
    outfile.close();
}
