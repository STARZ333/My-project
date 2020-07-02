#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <curses.h>
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
int min(int a, int b, int c)
{
    int m;
    if (a < b)
    {
        m = a;
        a = b;
        b = m;
    }
    if (a < c)
    {
        m = a;
        a = c;
        c = m;
    }
    if (b < c)
    {
        m = b;
        b = c;
        c = m;
    }

    return c;
}

class elavator
{
private:
    int times;           //時間
    int name;            //電梯名稱
    int nowFloor;        //當前樓層
    int xposition;       //電梯左端x坐標
    int NumOfPeo;        //人數
    int useAmount;       //使用量
    
    int updown;          //運動方向-1下樓,1上樓,0停留
    int stoptime;        //停留時間
public:
    int targetFloor[10]; //電梯內各人目標樓層
    void setPosition(int x); //設置x坐標
    int getXposition();
    bool full(); //是否滿員
    void setNowFloor(int x);
    int getnowFloor();  //獲取當前樓層
    int getuseAmount(); //獲取使用量
    void setName(int name);
    int getName();
    void setUpDown(int x);
    int getUpDown();
    void setNOP(int x);
    int getNOP();
    void setTargetFloor(int x);
    int getTargetFloor();
    void initialTargetFloor();
    void setUseAmount(int x);
};

class people
{
private:
    int ifGetTargetFloor;       //是否到達目標樓層
    int upDown;      //-1下，1上，0停
    int targetFloor; //目標樓層
    int nowFloor;    //當前樓層
    int passTime;    //上樓已過時間
    int stayTime;    //停留時間
    int waitTime;    //總等待時間
    int inWhichEla;  // -1不在電梯,0,1,2,分別對應三個電梯
    bool state;      //人是否已產生

public:
    void setinWhichEla(int x);
    void settargetFloor();
    void setTargetFloor(int x);
    int getTargetFloor();
    void setNowFloor(int x);
    void randstayTime();
    int getStayTime();
    void setmove(bool x);
   
    void upOrdown(); //1up   -1 down    0 stay
    int getNowFloor();
    void setState(bool s);
    bool getState();
    int getInWhichEla();
    void setupDown(int x);
    int getUpDown();
    void setPassTime(int x);
    int getPassTime();
    void setWaitTime(int x);
    int getWaitTime();
    void setIfGetTF(int x);
    int getIfGetTF();
};

class building
{
private:
    int call[12][2]; //[][0]=1上 [][1]=1下

public:
    void build();
    void moveIn(elavator ela[], people p[]);//進電梯
    void moveOut(elavator ela[], people p[]);//出電梯
    void setEmptyElaNextFloor(elavator ela[], people p[]);//設置空電梯去哪裡
    void receiveCall(elavator ela[], people p[]);//接收人按電梯的呼叫
    void elaShow(elavator ela[], people p[]);//電梯顯示
    void elaMove(elavator ela[], people p[]);//電梯移動
    void initialize(elavator e[], people p[]);//初始化
    void peoShow(elavator e[], people p[]);//顯示人
    void timing(elavator e[], people p[]);//計時
};
void people::setTargetFloor(int x)
{
    targetFloor = x;
}
int people::getStayTime()
{
    return stayTime;
}
int people::getIfGetTF()
{
    return ifGetTargetFloor;
}
void people::setIfGetTF(int x)
{
    ifGetTargetFloor = x;
}
void people::setWaitTime(int x)
{
    waitTime = x;
}
int people::getWaitTime()
{
    return waitTime;
}
void building::timing(elavator e[], people p[])
{
    int i = 0;
    int s=1;
    while (i < 150)
    {
        if (p[i].getState()==true&&p[i].getInWhichEla()==-1 && p[i].getNowFloor() == 1)
        {
            p[i].setWaitTime(p[i].getWaitTime() + 1);
        }
        else if(p[i].getState()==true&&p[i].getNowFloor()!=1&&p[i].getInWhichEla()==-1)
        {
            p[i].setPassTime(p[i].getPassTime() + 1);
            if(p[i].getPassTime()==p[i].getStayTime())
            {
                s = rand() % 100 + 1;
                if(s<81)
                {
                    p[i].setTargetFloor(1);
                    p[i].setupDown(-1);
                }
                else
                {
                    do{
                    p[i].setTargetFloor(rand() % 11 + 2);
                    } while (p[i].getTargetFloor() == p[i].getNowFloor());
                    if(p[i].getTargetFloor()>p[i].getNowFloor())
                    {
                        p[i].setupDown(1);
                    }
                    else if(p[i].getTargetFloor()<p[i].getNowFloor())
                    {
                        p[i].setupDown(-1);
                    }
                    p[i].setWaitTime(p[i].getWaitTime() + 1);
                }
            }
        }
        else if(p[i].getState()==true&&p[i].getInWhichEla()==-1&&p[i].getIfGetTF()!=0&&p[i].getTargetFloor()!=p[i].getNowFloor())
        {
            p[i].setWaitTime(p[i].getWaitTime() + 1);
        }
        i++;
    }
}
void building::peoShow(elavator e[], people p[])
{
    int i = 0;
    int y[13], x[13];
    char id[2];
    x[1] = 79;
    y[1] = 24;
    for (int i = 2; i < 13; i++)
    {
        x[i] = 4;
        y[i] = 26 - 2 * i;
    }
    while (i < 150)
    {
        if (p[i].getState() == true && p[i].getInWhichEla() == -1 && p[i].getNowFloor() == 1)
        {
            move(y[1], x[1]);
            itoa(p[i].getTargetFloor(), id, 10);
            waddstr(stdscr, id);
            x[1] += 3;
        }
        else if (p[i].getState() == true && p[i].getInWhichEla() == -1 && p[i].getNowFloor() != 1)
        {
            move(y[p[i].getNowFloor()], x[p[i].getNowFloor()]);
            itoa(p[i].getTargetFloor(), id, 10);
            waddstr(stdscr, id);
            x[p[i].getNowFloor()] += 3;
        }
        i++;
    }
}
void building::initialize(elavator e[], people p[])
{
    for (int i = 0; i < 12; i++)
    {
        call[i][0] = 0;
        call[i][1] = 0;
    }
    for (int i = 0; i < 150; i++)
    {
        p[i].setNowFloor(1);
        p[i].setinWhichEla(-1);
        p[i].setState(false);
        p[i].setPassTime(0);
        p[i].settargetFloor();
        p[i].upOrdown();
        p[i].setWaitTime(0);
    }
    for (int j = 0; j < 3; j++)
    {
        e[j].setName(j);
        e[j].setNOP(0);
        e[j].setNowFloor(1);
        e[j].initialTargetFloor();
        e[j].setUpDown(0);
    }
}
void elavator::setUseAmount(int x)
{
    useAmount = x;
}
void elavator::initialTargetFloor()
{
    for (int i = 0; i < 10; i++)
    {
        targetFloor[i] = 0;
    }
}
int elavator::getXposition()
{
    return xposition;
}
void building::elaShow(elavator ela[], people p[])
{
    int lenth = 9;
    char f[2];
    
    for (int k = 0; k < 3; k++)
    {	
        move(ela[k].getnowFloor() * -2 + 26, ela[k].getXposition());
        for (int i = 0; i < lenth; i++)
        {
            waddstr(stdscr, "_");
        }
        
        move(ela[k].getnowFloor() * -2 + 27, ela[k].getXposition() + lenth / 2);
        char num[2];
        itoa(ela[k].getNOP(), num, 10);
        waddstr(stdscr, num);
    }
}
void building::elaMove(elavator ela[], people p[])
{
    for (int i = 0; i < 3; i++)
    {
        if (ela[i].getUpDown() == 1&&ela[i].getnowFloor()!=12)
        {
            ela[i].setNowFloor(ela[i].getnowFloor() + 1);
            ela[i].setUseAmount(ela[i].getuseAmount() + ela[i].getNOP() + 3);
        }
        else if (ela[i].getUpDown() == -1&&ela[i].getnowFloor()!=1)
        {
            ela[i].setNowFloor(ela[i].getnowFloor() - 1);
            ela[i].setUseAmount(ela[i].getuseAmount() + ela[i].getNOP() + 3);
        }
    }
}
void building::receiveCall(elavator ela[], people p[])
{
    int i = 0;
    while (i < 150)
    {
        if (p[i].getState() && p[i].getInWhichEla() == -1 && p[i].getNowFloor() != p[i].getTargetFloor())
        {
            if (p[i].getUpDown()==-1)
            {
                if (call[p[i].getNowFloor() - 1][0] == 0)
                    call[p[i].getNowFloor() - 1][0] == 1;
            }
            else if (p[i].getUpDown() == -1)
            {
                if (call[p[i].getNowFloor() - 1][1] == 0)
                    call[p[i].getNowFloor() - 1][1] == 1;
            }
        }
        i++;
    }
}
void elavator::setNowFloor(int x)
{
    nowFloor = x;
}
void people::setPassTime(int x)
{
    passTime = x;
}
int people::getPassTime()
{
    return passTime;
}

int people::getTargetFloor()
{
    return targetFloor;
}
void elavator::setTargetFloor(int x)
{
    targetFloor[NumOfPeo] = x;

    sort(targetFloor, targetFloor + NumOfPeo);
}
int elavator::getTargetFloor()
{
    if (targetFloor[0] == 0)
        return 1;
    else if (updown == 1)
        return targetFloor[0];
    else if (updown == -1)
        return targetFloor[NumOfPeo - 1];
}
void elavator::setNOP(int x)
{
    NumOfPeo = x;
}
int elavator::getNOP()
{
    return NumOfPeo;
}
void people::setupDown(int x)
{
    upDown = x;
}
int people::getUpDown()
{
    return upDown;
}
void elavator::setUpDown(int x)
{
    updown = x;
}

int elavator::getUpDown()
{
    return updown;
}
int people::getInWhichEla()
{
    return inWhichEla;
}
void building::moveIn(elavator ela[], people p[])
{
    int i = 0;
    //int m = min(ela[0].getuseAmount(), ela[1].getuseAmount(), ela[2].getuseAmount());

    while (i < 150)
    {
        //1F
        if (p[i].getState() && p[i].getInWhichEla() == -1 && p[i].getNowFloor() == 1)
        {

            for (int j = 0; j < 3; j++)
            {
                if (ela[j].full() == 0 && ela[j].getnowFloor() == 1)
                {
                    p[i].setinWhichEla(j);
                    ela[j].setNOP(ela[j].getNOP() + 1);
                    ela[j].setTargetFloor(p[i].getTargetFloor());
                    ela[j].setUpDown(1);
                    call[ela[j].getnowFloor() - 1][0] = 0;
                    break;
                }
            }
        }
        //up
        if (p[i].getState() && p[i].getInWhichEla() == -1 && p[i].getUpDown() == 1)
        {
            for (int j = 0; j < 3; j++)
            {
                if (ela[j].getnowFloor() == p[i].getNowFloor() && ela[j].full() == 0 && ela[j].getUpDown() == 1)
                {
                    p[i].setinWhichEla(j);
                    ela[j].setNOP(ela[j].getNOP() + 1);
                    ela[j].setTargetFloor(p[i].getTargetFloor());
                    call[ela[j].getnowFloor() - 1][0] = 0;
                    break;
                }
            }
        }
        //down
        if (p[i].getState() && p[i].getInWhichEla() == -1 && p[i].getUpDown() == -1)
        {
            for (int j = 0; j < 3; j++)
            {
                if (ela[j].getnowFloor() == p[i].getNowFloor() && ela[j].full() == 0 && ela[j].getUpDown() == -1)
                {
                    p[i].setinWhichEla(j);
                    ela[j].setNOP(ela[j].getNOP() + 1);
                    ela[j].setTargetFloor(p[i].getTargetFloor());
                    call[ela[j].getnowFloor() - 1][1] = 0;
                    break;
                }
            }
        }
        i++;
    }
}
void building::moveOut(elavator ela[], people p[])
{
    int i = 0;
    int name;
    while (i < 150)
    {
        if (p[i].getState()==true && ela[p[i].getInWhichEla()].getnowFloor() == p[i].getTargetFloor() && p[i].getInWhichEla() != -1)
        {
            
            name = p[i].getInWhichEla();
            p[i].setinWhichEla(-1);
            p[i].setNowFloor(ela[name].getnowFloor());
            p[i].randstayTime();
            p[i].setPassTime(0);
            
            p[i].setIfGetTF(p[i].getIfGetTF()+1);
            ela[name].setNOP(ela[name].getNOP() - 1);
            if (ela[name].getNOP() == 0)
            {
                ela[name].setUpDown(0);
            }
        }
        if(p[i].getState()==true&&p[i].getTargetFloor()==1&&ela[p[i].getInWhichEla()].getnowFloor() == p[i].getTargetFloor()&& p[i].getInWhichEla() != -1)
        {
            name = p[i].getInWhichEla();
            p[i].setinWhichEla(-1);
            p[i].setNowFloor(ela[name].getnowFloor());
            ela[name].setNOP(ela[name].getNOP() - 1);
            p[i].setState(false);
            if (ela[name].getNOP() == 0)
            {
                ela[name].setUpDown(0);
            }
        }
        i++;
    }
}
void building::setEmptyElaNextFloor(elavator ela[], people p[])
{
    int m = 15, f;
    for (int i = 0; i < 3; i++)
    {
        if (ela[i].getNOP() == 0 && ela[i].getUpDown() == 0 )
        {
            for (int j = 0; j < 12; j++)
            {
                if (call[j][0] || call[j][1])
                {

                    if (abs(j + 1 - ela[i].getnowFloor()) < m)
                    {
                        m = abs(j + 1 - ela[i].getnowFloor());
                        f = j + 1;
                    }
                }
            }
            ela[i].setTargetFloor(f);
            ela[i].setUpDown(-1);
            /*if (ela[i].getnowFloor() > f)
            {
                ela[i].setUpDown(-1);
            }
            else if (ela[i].getnowFloor() < f)
            {
                ela[i].setUpDown(1);
            }*/
        }
    }
}
void building::build()
{
    int x = 0, y = 2, f = 12;
    char ff[3];
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            call[i][j] = 0;
        }
    }
    move(y, x);
    for (int i = 0; i < 12; i++)
    {
        move(y, x);
        itoa(f, ff, 10);
        waddstr(stdscr, ff);
        waddstr(stdscr, "F");
        f--;
        y += 2;
    }
}

void elavator::setName(int Name)
{
    name = Name;
}
int elavator::getName()
{
    return name;
}
bool elavator::full()
{
    if (NumOfPeo == 10)
        return 1;
    else if (NumOfPeo < 10)
        return 0;
}
void elavator::setPosition(int x)
{
    xposition = x;
}
int elavator::getuseAmount()
{
    return useAmount;
}

int elavator::getnowFloor()
{
    return nowFloor;
}

void people::setState(bool s)
{
    state = s;
}

bool people::getState()
{
    return state;
}
int people::getNowFloor()
{
    return nowFloor;
}
void people::upOrdown()
{
    if (targetFloor > nowFloor)
    {
        setupDown(1);
    }
    else if (targetFloor < nowFloor)
    {
        setupDown(-1);
    }
    else if (targetFloor == nowFloor)
    {
        setupDown(0);
    }
}



void people::randstayTime()
{
    stayTime = rand() % 81 + 20;
}

void people::setNowFloor(int x)
{
    nowFloor = x;
}

void people::settargetFloor()
{
    if (nowFloor == 1)
        targetFloor = rand() % 11 + 2;
    else
    {
        do
            targetFloor = rand() % 12 + 1;
        while (nowFloor == targetFloor);
    }
}
void people::setinWhichEla(int x)
{
    inWhichEla = x;
}
int main()
{
    srand(time(0));
    initscr();

    people p[150];
    building b;
    elavator e[3];

    int t = 0, num, nop = 0,tot=0;
    char tt[3], pp[4];

    //box(stdscr, 23, 79); /*draw a box*/
    e[0].setPosition(35);
    e[1].setPosition(50);
    e[2].setPosition(65);
    b.initialize(e, p);

    while (1)
    {
        t++;
        move(0, 84);
        waddstr(stdscr, "time:");
        move(0, 89);
        itoa(t, tt, 10);
        waddstr(stdscr, tt);

        num = rand() % 3;
        tot = nop + num;
        if(tot>150)
            tot = 150;
        for (int i = nop; i < tot; i++)
        {
            p[i].setState(true);
        }
        if(nop<150)
        nop += num;
        if(nop>150)
            nop = 150;

        move(1, 84);
        waddstr(stdscr, "nop:");
        itoa(nop+1, pp, 10);
        waddstr(stdscr, pp);

        b.build();

        b.receiveCall(e, p);

        b.setEmptyElaNextFloor(e, p);

        b.moveIn(e, p);

        b.moveOut(e, p);

        b.timing(e, p);

        b.peoShow(e, p);

        b.elaMove(e, p);

        b.elaShow(e, p);

        refresh();

        Sleep(100);

        erase();
    }

    endwin();

    return 0;
}
