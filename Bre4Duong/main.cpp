/*
A(20,30), B(120,80)
m<1 => 	xsau = xtruoc + 1
		y = mx + b
Q0 = dx - 2dy
Qi <= 0, ysau = ytruoc + 1
	Qi + 1 = Qi + 2dx - 2dy
Qi > 0, ysau = ytruoc
	Qi + 1 = Qi - 2dy
*/

#include <winbgim.h>
#include <stdio.h>

//TH1: A(20;30), B(120,80)
void Bre1(int xa, int ya, int xb, int yb, int color)
{	
	//m<1
	int dx = (xb - xa);
	int dy = (yb - ya);
	int x = xa;
	int y = ya;
	int Q = dx - 2*dy;	//Q0
	for(;x<=xb;x++){
		printf("x=%d, y=%d, Q=%d\n", x, y, Q);
		putpixel(x,y,color);
		if(Q<=0){
			y = y+1;
			Q = Q+2*dx-2*dy;
		}
		else{	//Q>0
			y = y;
			Q = Q-2*dy;
		}
	}
}

//TH2: B(120;80), A(20;30)
void Bre2(int xb, int yb, int xa, int ya, int color)
{
	//float m = (ya-yb)/(xa-xb);	//m=0,5<1
	int dx = (xa - xb);
	int dy = (ya - yb);
	int x = xb;
	int y = yb;
	int Q = dx - 2*dy;
	for(;x>xa;x--){
		printf("x=%d, y=%d, Q=%d\n", x, y, Q);
		putpixel(x,y,color);
		if(Q<0){
			y = y-1;
			Q = Q-2*dx+2*dy;
		}
		else{	//Q=>0
			Q = Q+2*dy;
		}	
	}
}

//TH3: A(20;80), B(120,30)
void Bre3(int xa, int ya, int xb, int yb, int color)
{
	int dx = (xb - xa);
	int dy = (yb - ya);
	int x = xa;
	int y = ya;
	int Q = dy + 2*dx;	//Q0
	for(;x<=xb;x++){
		printf("x=%d, y=%d, Q=%d\n", x, y, Q);
		putpixel(x,y,color);
		if(Q<0){
			y = y+1;
			Q = Q+2*dx+2*dy;
		}
		else{	//Q>0
			Q = Q+2*dx;
		}
	}
}

//TH4: A(120;30) B(20,80)
void Bre4(int xa, int ya, int xb, int yb, int color)
{
	//m=0,5<1 xa>xb
	int dx = (xb - xa);
	int dy = (yb - ya);
	int x = xa;
	int y = ya;
	int Q = 2*dy + dx;	//Q0
	for(;x>xb;x--){
		printf("x=%d, y=%d, Q=%d\n", x, y, Q);
		putpixel(x,y,color);
		if(Q<0){
			y = y-1;
			Q = Q+2*dx+2*dy;
		}
		else{	//Q>0
			Q = Q+2*dy;
		}
	}
}

/*
abs dx > abs dy

Truong hop he so goc m > 1
	Qo = 2dy - dx	x1<x2
	Qo = 2dy + dx	x1>x2
	Qo >= 0 	x++; Qo = Qo + 2dy - 2dx
	Qo < 0		Qo = Qo - 2dy
*/

int main(){
	initwindow(300,300);
	Bre1(20,30,120,80,4);
	Bre2(120,80,20,30,3);
	Bre3(20,80,120,30,2);
	Bre4(120,30,20,80,5);
	getch();
}
