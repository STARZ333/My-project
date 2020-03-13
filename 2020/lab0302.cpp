#include <fstream>
#include <iostream>
#include<string>
using namespace std;
int main()
{
    ofstream outfile;
    ifstream infile;
    string i;
    
    infile.open("1.txt");
    outfile.open("2.txt");
    while(getline(infile,i))
    {
        outfile << i.length() << i <<"\n";
    }

}