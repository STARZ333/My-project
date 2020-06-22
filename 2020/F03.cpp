#include <iostream>
using namespace std;
class cards // 位置都是由 1 開始
{
public:
    cards();                                  //產生一副新牌，順序由 0…51
    int getCard();                            //回傳陣列最後一張牌，並將最後一張牌刪除
    int getCard(const int pos);               //回傳 pos 位置的牌, for 第三題
    bool swapCards(const int a, const int b); //把 a 與 b 位置的牌交換
    int remainCards();                        //回傳目前有幾張牌
    void newCards();                          //不管還有沒有牌，直接產生一副新的牌
    int& operator[] (int i);
private:
    int cardArray[52];
    int totalCards;
};
int& cards::operator[] (int i)    //返回引用，这样才可以对返回值赋值
{
    return cardArray[i-1];
}
int cards::getCard(const int pos)
{
    return cardArray[pos - 1];
}
cards::cards()
{
    for (int i = 0; i < 52; i++)
    {
        cardArray[i] = i;
    }
    totalCards = 52;
}
int cards::getCard()
{
    int t;
    int i = totalCards - 1;

    t = cardArray[i];
    cardArray[i] = -1;
    totalCards -= 1;
    return t;
}
bool cards::swapCards(const int a, const int b)
{
    int temp;
    temp = cardArray[a - 1];
    cardArray[a - 1] = cardArray[b - 1];
    cardArray[b - 1] = temp;
    return 1;
}
int cards::remainCards()
{
    for (int i = 51; i >= 0; i--)
    {
        if (cardArray[i] != -1)
            return i + 1;
    }
}
void cards::newCards()
{
    for (int i = 0; i < 52; i++)
    {
        cardArray[i] = i + 1;
    }
}


int main()
{
    cards kkk;
    int x;
    while(cin>>x)
    {   
        if(x==0)
            break;
        if(x<=kkk.remainCards())
        {
            int p=kkk[x];
            int f, n;
            f = p / 13;
            n = p % 13;
            if (f == 0)
            {
                cout << "Spade ";
            }
            else if (f == 1)
                cout << "Heart ";
            else if (f == 2)
                cout << "Diamond ";
            else if (f == 3)
                cout << "Club ";
            if (n == 0)
                cout << "A" << endl;
            
            else if (n < 10)
                cout << n+1 << endl;
            else if (n == 10)
                cout << "J" << endl;
            else if (n == 11)
                cout << "Q" << endl;
            else if (n == 12)
                cout << "K" << endl;
        }
        else if(x>kkk.remainCards())
        {
            cout << "Error." << endl;
        }
    }
}