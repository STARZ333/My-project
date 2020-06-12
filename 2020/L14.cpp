#include <curses.h>
#include <stdlib.h> // rand()
#include <time.h>   // time()
#include<windows.h>
#define W 79
#define H 23
int inbase(int &y,int &x,int s);
int inother(int &y,int &x,int s);
int inedge(int &y,int &x,int s);
int inedge(int &y,int &x,int s)
{
	if(x==0&&y==0)
	{
		if(s<50)
		x++;
		else 
		y++;
	}
	else if(x==0&&y==23)
	{
			if(s<50)
		x++;
		else 
		y--;
	}
	else if(x==79&&y==23)
	{
			if(s<50)
		x--;
		else 
		y--;
	}
	else if(x==79&&y==0)
	{
		if(s<50)
		x--;
		else 
		y++;
	}
	else if(y==0||y==23)
	{
		if(s<33)
		x++;
		else if(s<66)
		x--;
		else if (s<100)
		{
			if(y==0)
			y++;
			if(y==23)
			y--;
		}
	}
	else if(x==0||x==79)
	{
		if(s<33)
		y++;
		else if(s<66)
		y--;
		else if (s<100)
		{
			if(x==0)
			x++;
			if(x==79)
			x--;
		}
	}
}

int inother(int &y,int &x,int s)
{
	if(s<85)
 	{
 		if(x>39)
		 x--;
		else if(x<39)
		x++;
		else if (y<11)
		y++;
		else if (y>11)
		y--;	
	}
	else if(s<90)
	{
		if(x>39)
		x++;
		else if(x<39)
		x--;
	}
	else if(s<95)
	{
		if(y>11)
		y--;
		else if(y<11)
		y++;
	}
	else if(s<100)
	{
		if(x>39)
		x++;
		else if(y>11)
		y--;
		else if(x<39)
		x--;
		else if(y<11)
		y++;
	}
	return 0;
}
int inbase(int &y,int &x,int s)
{
	if(s<25)
 	{
 		--y;//up
	 }
	 else if(s<50)
	 {
	 	++x;//right
	 }
	 else if(s<75)
	 {
	 	++y;//down
	 }
	 else if(s<100)
	 {
	 	--x;//left
	 }
	 return 0;
}

int main(void)
{
    initscr();
 
    box(stdscr, 23, 79); /*draw a box*/
 	int y=23/2;
 	int x=79/2;
    move(y, x); /*move to the center*/
 
    waddstr(stdscr, "o");
 	
 	
 	int s,t;
 	
 	t=time(0);
 	
	 srand(t);
 	while(1)	
 	{
 	s=rand()%100;
 	
	if(y==11&&x==39)
 	inbase(y,x,s);
 	else 
 	inother(y,x,s);
 	
	 inedge(y,x,s);
	 
	 move(y,x);
	 
	 waddstr(stdscr, "o");
	 
	 refresh();
	 
	 Sleep(500);
	 
	 erase();
  	}
 	
   
 
    endwin();
 
    return 0;
}

