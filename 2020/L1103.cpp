#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
string delete_i(string it,int m_i)//删除第m_1个
{
    int length = it.length();
    string temp = "";
    for (int i = 0; i < m_i;i++)
        temp += it[i];
     for (int i=m_i+1;i<length;i++)
         temp += it[i];
     return temp;
}
void full(string &in,const string save="")
{
    int length = in.length();
    if(length==0)
        cout << save << endl;
    else 
    {
        string n_save = save + in[0];
        string n_in = delete_i(in, 0);
        full(n_in, n_save);
        for (int i = 1; i < length;i++)
        {
            if(in[i]!=in[i-1])
            {
                string n_save = save + in[i];
                string n_in = delete_i(in, i);
                full(n_in, n_save);
            }
        }
    }
}
int main()
{
    string in;
    cin >> in;
    sort(in.begin(), in.end());
    full(in);
    return 0;
}