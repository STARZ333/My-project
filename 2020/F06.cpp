#include <Windows.h>
#include <ctime>
#include <curses.h>
#include <string>
using namespace std;
int main(void)
{
    initscr();

    box(stdscr, 25, 61); /*draw a box*/
    while (1)
    {
        struct tm *newtime;
        time_t long_time;
        time(&long_time); //Get time as long integer
        newtime = localtime(&long_time);
        int h = newtime->tm_hour; //得到当前时间的小时
        int m = newtime->tm_min;  //得到当前时间的分钟
        int s = newtime->tm_sec;  //秒
        h=6; 
        move(h, m);
        char str[2];
        itoa(s, str, 10);
        waddstr(stdscr, str);
        refresh();
        Sleep(1000);
        erase();
    }
    endwin();
}
