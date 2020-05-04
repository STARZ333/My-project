#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    ofstream outfile;
    ifstream infile;
    infile.open("1.in");
    outfile.open("1.out");
    string str,Array[100];
    int count = 0;
    char c;
    double len=0,ave=0,sum=0;
    while (!infile.eof())
    {
        getline(infile, str);
        len = str.length();
        Array[count] = str;
        sum += len;
        count++;
    }
    ave = sum / count;
    for (int i = 0; i < count;i++)
    {
        if(Array[i].length()>=ave)
        {
            c = Array[i].at(0);
            outfile << c;
        }
    }
    outfile << endl;
}