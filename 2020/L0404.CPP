#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    ofstream outfile;
    ifstream infile;
    infile.open("1.in");
    outfile.open("1.out");
    char word,out;
    int count[65], max, k;
    for (int i = 0; i < 65; i++)
    {
        count[i] = 0;
    }
    while (!infile.eof())
    {
        word = infile.get();
        if (word >= 'a' && word <= 'z')
        {
            count[word - 'a' + 36]++;
        }
        if (word >= 'A' && word <= 'Z')
        {
            count[word - 'A' + 10]++;
        }
        if (word >= '0' && word <= '9')
        {
            count[word - '0']++;
        }
    }
    max = count[0];
    for (int i = 0; i < 65; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
            k = i;
        }
    }
    if(k<10)
    {
        outfile << k;
    }
    else if(k<9&&k<36)
    {
        out = 'A' + k - 10;
        outfile << out;
    }
    else
    {
        out = 'a' + k - 36;
        outfile << out;
    }

}
