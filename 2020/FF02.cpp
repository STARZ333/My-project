#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <curses.h>
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;



class elavator
{
private:
    int times;                                            //時間 
    int name;                                             //電梯名稱 
    int nowFloor;                                         //當前樓層 
    int xposition;                                        //電梯左端x坐標 
    int NumOfPeo;                                         //人數 
    int useAmount ;                                    //使用量 
    int targetFloor[10]; //電梯內各人目標樓層 
    int updown ;                                       //運動方向-1下樓,1上樓,0停留 
    int stoptime ;                                     //停留時間 
public:
    void setPosition(int x); //設置x坐標 
    int getXposition();
    bool full();        //是否滿員 
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
    
};



class people
{
private:
    bool move;       //
    int upDown ;  //-1下，1上，0停
    int targetFloor; //目标楼层
    int nowFloor;    //当前楼层
    int passTime;
    int stayTime;   //停留时间
    int inWhichEla; // -1不在电梯,0,1,2,
    bool state;     //人是否已產生 

public:
    void setinWhichEla(int x);
    void settargetFloor();
    int getTargetFloor();
    void setNowFloor(int x);
    void randstayTime();
    void setmove(bool x);
    bool getmove();
    void upOrdown(); //1up   -1 down    0 stay
    int getNowFloor();
    void setState(bool s);
    bool getState();
    int getInWhichEla();
    void setupDown(int x);
    int getUpDown();
    void setPassTime(int x);
    int getPassTime();
    
};




class building
{
private:
    int call[12][2]; //[][0]=1上 [][1]=1下

public:
    void build();
    void moveIn(elavator ela[], people p[]);
    void moveOut(elavator ela[], people p[]);
    void setEmptyElaNextFloor(elavator ela[], people p[]);
    void receiveCall(elavator ela[], people p[]);
    void elaShow(elavator ela[], people p[]);
    void elaMove(elavator ela[], people p[]);
    void initialize(elavator e[], people p[]);
};
void building::initialize(elavator e[], people p[])
{
    for (int i = 0;i<12;i++)
    {
        call[i][0] = 0;
        call[i][1] = 0;
    }
    for (int i = 0; i < 150; i++)
    {
        p[i].setNowFloor(1);
        p[i].setinWhichEla(-1);
        p[i].setState(0);
        p[i].setPassTime(0);
        p[i].settargetFloor();
        p[i].upOrdown();
    }
    for (int j = 0; j < 3;j++)
    {
        e[j].setName(j);
        e[j].setNOP(0);
        e[j].setNowFloor(1);
    }
}

int elavator::getXposition()
{
    return xposition;
}
void building::elaShow(elavator ela[], people p[])
{
    int lenth = 9;
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
    for (int i = 0; i < 3;i++)
    {
        if(ela[i].getUpDown())
        {
            ela[i].setNowFloor(ela[i].getnowFloor() + 1);
        }
        else if(ela[i].getUpDown()==-1)
        {
            ela[i].setNowFloor(ela[i].getnowFloor() - 1);
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
            if (p[i].getUpDown())
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
void elavator:: setNowFloor(int x)
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
    while (i < 150)
    {
        //up
        if (p[i].getState() && p[i].getInWhichEla() == -1 && p[i].getmove() == 0)
        {
            for (int j = 0; j < 3; j++)
            {
                if (ela[j].getnowFloor() == p[i].getNowFloor() && ela[j].full() == 0 && ela[j].getUpDown() == 1 && p[i].getUpDown() == 1)
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
        if (p[i].getState() && p[i].getInWhichEla() == -1 && p[i].getmove() == 0)
        {
            for (int j = 0; j < 3; j++)
            {
                if (ela[j].getnowFloor() == p[i].getNowFloor() && ela[j].full() == 0 && ela[j].getUpDown() == -1 && p[i].getUpDown() == -1)
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
    while (i < 150)
    {
        if (p[i].getState() && p[i].getNowFloor() == p[i].getTargetFloor() && p[i].getInWhichEla() != -1)
        {
            int name;
            name = p[i].getInWhichEla();
            p[i].setinWhichEla(-1);
            p[i].setNowFloor(ela[name].getnowFloor());
            p[i].randstayTime();
            p[i].setPassTime(0);
            ela[name].setNOP(ela[name].getNOP() - 1);
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
        if (ela[i].getNOP() == 0 && ela[i].getUpDown() == 0)
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
bool people::getmove()
{
    return move;
}



void people::setmove(bool x)
{
    move = x;
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

    int t = 0,num,nop=0;
    char tt[3], pp[4];
    
    
    
    //box(stdscr, 23, 79); /*draw a box*/
    e[0].setPosition(30);
    e[1].setPosition(42);
    e[2].setPosition(54);
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
        
        for (int i = nop; i < nop+num;i++)
        {
            p[i].setState(true);
        }
        nop += num;
        
        move(1, 84);
        waddstr(stdscr, "nop:");
        
        itoa(nop, pp, 10);
        waddstr(stdscr, pp);
        
        
        b.build();

        b.receiveCall(e, p);

        b.setEmptyElaNextFloor(e, p);

        b.moveIn(e, p);

        b.moveOut(e, p);

        b.elaMove(e, p);

        b.elaShow(e, p);

        refresh();


        Sleep(1000);

        erase();
    }

    endwin();

    return 0;
}
