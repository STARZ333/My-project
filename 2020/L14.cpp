#include <curses.h>
#include <stdlib.h> // rand()
#include <time.h>   // time()
#include <windows.h>
#define W 79
#define H 23
int inbase(int &y, int &x, int s);
int inother(int &y, int &x, int s);
int inedge(int &y, int &x, int s);
int d;
int inedge(int &y, int &x, int s)
{
    if (x == 0 && y == 0)
    {
        if (s < 50)
        {
            x++;
            d = 2;
            return 1;
        }
        else
        {
            y++;
            d = 3;
            return 1;
        }
    }
    else if (x == 0 && y == 23)
    {
        if (s < 50)
        {
            x++;
            d = 2;
            return 1;
        }
        else
        {
            y--;
            d = 1;
            return 1;
        }
    }
    else if (x == 79 && y == 23)
    {
        if (s < 50)
        {
            x--;
            d = 4;
            return 1;
        }
        else
        {
            y--;
            d = 1;
            return 1;
        }
    }
    else if (x == 79 && y == 0)
    {
        if (s < 50)
        {
            x--;
            d = 4;
            return 1;
        }
        else
        {
            y++;
            d = 3;
            return 1;
        }
    }
    else if (y == 0 || y == 23)
    {
        if (s < 33)
        {
            x++;
            d = 2;
            return 1;
        }
        else if (s < 66)
        {
            x--;
            d = 4;
            return 1;
        }
        else if (s < 100)
        {
            if (y == 0)
            {
                y++;
                d = 3;
                return 1;
            }
            if (y == 23)
            {
                y--;
                d = 1;
                return 1;
            }
        }
    }
    else if (x == 0 || x == 79)
    {
        if (s < 33)
        {
            y++;
            d = 3;
            return 1;
        }
        else if (s < 66)
        {
            y--;
            d = 1;
            return 1;
        }
        else if (s < 100)
        {
            if (x == 0)
            {
                x++;
                d = 2;
                return 1;
            }
            if (x == 79)
            {
                x--;
                d = 4;
                return 1;
            }
        }
    }
}

int inother(int &y, int &x, int s)
{
    if (s < 85)
    {
        if (d == 1)
            y--;
        if (d == 2)
            x++;
        if (d == 3)
            y++;
        if (d == 4)
            y--;
    }
    else if (s < 90) //向顺时针方向转90°
    {
        if (d == 1)
        {
            x++;
            d = 2;
        }
        else if (d == 2)
        {
            y++;
            d = 3;
        }
        else if (d == 3)
        {
            x--;
            d = 4;
        }
        else if (d == 4)
        {
            y--;
            d = 1;
        }
    }
    else if (s < 95) //180°
    {
        if (d == 1)
        {
            y++;
            d = 3;
        }
        else if (d == 2)
        {
            x--;
            d = 4;
        }
        else if (d == 3)
        {
            y--;
            d = 1;
        }
        else if (d == 4)
        {
            x++;
            d = 2;
        }
    }
    else if (s < 100) //270
    {
        if (d == 1)
        {
            x--;
            d = 4;
        }
        else if (d == 2)
        {
            y--;
            d = 1;
        }
        else if (d == 3)
        {
            x++;
            d = 2;
        }
        else if (d == 4)
        {
            y++;
            d = 3;
        }
    }
    return 0;
}
int inbase(int &y, int &x, int s)
{
    if (s < 25)
    {
        --y; //up
        d = 1;
    }
    else if (s < 50)
    {
        ++x; //right
        d = 2;
    }
    else if (s < 75)
    {
        ++y; //down
        d = 3;
    }
    else if (s < 100)
    {
        --x; //left
        d = 4;
    }
    return 0;
}

int main(void)
{
    initscr();

    box(stdscr, 23, 79); /*draw a box*/
    int y = 23 / 2;
    int x = 79 / 2;
    move(y, x); /*move to the center*/

    waddstr(stdscr, "o");

    int s, t;

    t = time(0);

    srand(t);
    while (1)
    {
        s = rand() % 100;
        if (x == 0 || y == 0 || x == 79 || y == 23)
            inedge(y, x, s);
        else if (y == 11 && x == 39)
            inbase(y, x, s);
        else
            inother(y, x, s);

        //inedge(y, x, s);

        move(y, x);

        waddstr(stdscr, "o");

        refresh();

        Sleep(500);

        erase();
    }

    endwin();

    return 0;
}
