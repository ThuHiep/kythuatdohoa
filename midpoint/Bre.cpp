#include<bits/stdc++.h>
#include<graphics.h>
#include<math.h>
#include<stdio.h>
using namespace std;

void line1(int x1, int y1, int x2, int y2){
	int dx = x2 - x1;
	int dy = y2 - y1;
	int p = 2*dy - dx;
	for(int x = x1, y = y1; x <= x2; x++)
	{
		putpixel(x, y, 15);
		if(p < 0) p += 2*dy;
		else p += 2*dy-2*dx, y++;
	}
}

void line2(int x1, int y1, int x2, int y2){
	int dx = x2 - x1; 
	int dy = y2 - y1;
	int p = - 2*dy + dx;
	for(int x = x1, y = y1; x >= x2; x--)
	{
		putpixel(x, y, 15);
		if(p < 0) p += - 2*dy;
		else p += - 2*dy+2*dx, y--;
	}
}

void line3(int x1, int y1, int x2, int y2){
	int dx = x2 - x1;
	int dy = y2 - y1;
	int p = - 2*dy - dx;
	for(int x = x1, y = y1; x <= x2; x++)
	{
		putpixel(x, y, 15);
		if(p < 0) p += -2*dy;
		else p += -2*dy-2*dx, y--;
	}
}


void line5(int x1, int y1, int x2, int y2){ //dx > 0, dy > 0, |dx| < |dy|
	int dx = x2 - x1;
	int dy = y2 - y1;
	int p = 2*dx + dy;
	for(int y = y1, x = x1; y >= y2; y--)
	{
		putpixel(x, y, 15);
		if(p < 0) p += 2*dx;
		else p += 2*dx + 2*dy, x++;
	}
}


int main()
{
	initwindow(300, 300);
	int x1 = 71, y1 = 38, x2 = 83, y2 = 5;
	int dx = x2 - x1;
	int dy = y2 - y1;
	if(abs(dx) > abs(dy))
		if(x1 < x2 && y1 < y2) line1(x1, y1, x2, y2); //18 9 51 21
		if(x1 > x2 && y1 > y2) line2(x1, y1, x2, y2); //51 21 18 9
		if(x1 < x2 && y1 > y2) line3(x1, y1, x2, y2); //18 55 63 43
	
		//line4
	else
		if(x1 < x2 && y1 > y2) line5(x1, y1, x2, y2);

	getch();
	return 0;
}
