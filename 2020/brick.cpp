#include <iostream>
using namespace std;
int main()
{
    int x = 0, sum = 0, avh = 0, nob; //avh=average hight,nob=number of brick
    int count = 1;
    while (cin >> nob)
    {
        sum = 0;
        x = 0;
        if (nob == 0)
            break;
        int brick[nob];
        for (int i = 0; i < nob; i++)
        {
            cin >> brick[i];
            sum += brick[i];
        }
            avh = sum / nob;
            for (int i = 0; i < nob; i++)
            {
                if (brick[i] > avh)
                {
                    x += brick[i] - avh;
                }
            }
            cout << "Set #" << count << endl;
            cout << "The minimum number of moves is " << x << "." << endl;
            cout << endl;
            count++;
        }
}