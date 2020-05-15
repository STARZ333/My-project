#include <iostream>
using namespace std;
void merge(int *data, int start, int end, int *result);

void merge_sort(int *data, int start, int end, int *result)
{
    if (1 == end - start)
    {
        if (data[start] > data[end])
        {
            int temp = data[start];
            data[start] = data[end];
            data[end] = temp;
        }
        return;
    }
    if (0 == end - start)
        return;

    merge_sort(data, start, (end - start + 1) / 2 + start, result);
    merge_sort(data, (end - start + 1) / 2 + start + 1, end, result);

    merge(data, start, end, result);

    for (int i = start; i <= end; ++i)
        data[i] = result[i];
}

void merge(int *data, int start, int end, int *result)
{
    int mid = (end - start + 1) / 2;
    int left_Max = mid + 1;
    int left_index = start;
    int right_index = start + mid + 1;
    int result_index = start;
    while (left_index < start + left_Max && right_index < end + 1)
    {

        if (data[left_index] <= data[right_index])
            result[result_index++] = data[left_index++];
        else
            result[result_index++] = data[right_index++];
    }
    while (left_index < start + left_Max)
        result[result_index++] = data[left_index++];
    while (right_index < end + 1)
        result[result_index++] = data[right_index++];
}

int main()
{
    int x, a;
    cin >> x;
    int num[x];
    for (int i = 0; i < x; i++)
    {
        cin >> num[i];
    }
    int result[x];
    merge_sort(num, 0, x - 1, result);

    while (cin >> a)
    {
        if (a <= 0)
            break;
        cout << num[a - 1] << endl;
    }
}
