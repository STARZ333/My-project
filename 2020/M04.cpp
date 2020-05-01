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
    int count = 0, all = 0;
    while (infile.get(k))
    {
        if (k == '\n')
            break;
        all++;
        if (k == 'a' || k == 'e' || k == 'i' || k == 'o' || k == 'u' || k == 'A' || k == 'E' || k == 'I' || k == 'O' || k == 'U')
            count++;
    }
    outfile << count << endl;
    outfile << all - count << endl;
}