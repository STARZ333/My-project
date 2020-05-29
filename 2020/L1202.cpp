#include <iostream>
using namespace std;

class intList //pos 從 1 開始（陣列從0開始）
{
public:
    void insert(int value);            //新增 value 到數列
    bool remove(int pos);              //刪除 pos 位置的正整數
    int getValue(int pos);             //回傳 pos 位置的值
    bool setValue(int pos, int value); //設定 pos 位置的值為 value
    int getSize();                     //sizeUsed 的 accessor
protected:
    bool swapValue(int pos1, int pos2);
    int *data = new int[10]; //資料存放的動態陣列
private:
    int totalSize = 10; //目前動態陣列的大小
    int sizeUsed = 0;   //目前有幾個正整數
    void expandSize();  //擴增動態陣列大小為兩倍
};
int intList::getSize()
{
    return sizeUsed;
}
bool intList::setValue(int pos, int value)
{
    data[pos - 1] = value;
    return 1;
}
int intList::getValue(int pos)
{
    cout << data[pos] << endl;
    return data[pos];
}
bool intList::remove(int pos)
{
    data[pos] = data[sizeUsed - 1];
    data[sizeUsed - 1] = 0;
    return 1;
}
void intList::insert(int x)
{
    data[sizeUsed] = x;
    sizeUsed++;
    if (sizeUsed == totalSize)
        expandSize();
}
bool intList::swapValue(int pos1, int pos2)
{
    int temp;
    temp = data[pos1 - 1];
    data[pos1 - 1] = data[pos2 - 1];
    data[pos2 - 1] = temp;
    return 0;
}
void intList::expandSize()
{
    int *temp = new int[sizeUsed * 2];
    for (int j = 0; j < sizeUsed; j++)
    {
        temp[j] = data[j];
    }
    delete[] data;
    data = temp;
    totalSize *= 2;
}
class searchList : public intList
{
public:
    int search(int value)
    {
        for (int i = 0; i < intList::getSize(); i++)
        {
            if (data[i] == value)
            {
                return i;
            }
            
        }return -1;
    }
};

int
main()
{
    int x;
    searchList List;
    while (cin >> x)
    {
        if (x > 0)
        {
            List.insert(x);
        }
        else if (x < 0)
        {
                if (List.search(-x) != -1)
                {
                    List.remove(List.search(-x));
                    cout << "ok" << endl;
                }
                else
                    cout << "no" << endl;
         
        }
        else if (x == 0)
            break;
    }
}