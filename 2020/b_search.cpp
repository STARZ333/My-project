#include <iostream>
using namespace std;
int main()
{
    int n, left, right, a,mid;
    cin >> n;
    int arr[n];
    for (int j = 0; j < n; j++)
    {
        cin >> arr[j];
    }
    while (cin >> a)
    {
        if (a < 0)
            break;
            left = 0;
            right = n - 1;
        while (left <= right)
        {
            
            mid = left + (right-left) / 2;
            if(arr[mid]==a)
            {
                cout << "True\n";
                break;
            }
            else if(arr[mid]>a)
            {
                right = mid-1;
            }
            else if (arr[mid]<a)
            {
                left = mid + 1;
            }
        }
        if(left>right)
            cout << "False\n";
    }
}