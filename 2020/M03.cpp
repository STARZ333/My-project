#include <fstream>
#include <iostream>
#include<cstring>
using namespace std;
int main()
{
    ofstream outfile;
    ifstream infile;
    infile.open("1.in");
    outfile.open("1.out");
    char **pptrArray;
    string i;
    pptrArray = new char*[200];
    int x, y;
    for (int j = 1; j < 101;j++)
    {
        getline(infile, i);
        pptrArray[j] = new char[200];
        strcpy(pptrArray[j], i.c_str());
    }
    while(infile >> x >> y)
    {
        outfile << pptrArray[x][y - 1]<<endl;
    }
    
}