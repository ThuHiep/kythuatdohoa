#include<stdio.h>
#include<graphics.h>

// A(20,30) B(120,80)
void Bre1(int xa, int ya, int xb, int yb, int color){
	int dx=(xb-xa);
	int dy=(yb-ya);
	int Q=dx-2*dy;
	int x=xa;
	int y=ya;
	for(;x<=xb;x++){
		
		printf("x=%d, y=%d, Q=%d\n",x,y,Q);
		putpixel(x,y,color);

		if(Q<0){
			y=y+1;
			Q=Q+2*dx-2*dy;
		}
		else{
			Q=Q-2*dy;
		}
			}
}
//B(20,80) 		A(120,30)
void Bre2(int xa, int ya, int xb, int yb, int color){
	int dx=(xb-xa);
	int dy=(yb-ya);
	int Q=2*dy-dx;
	int x=xa;
	int y=ya;
	for(;x>xb;x--){
		printf("x=%d, y=%d, Q=%d\n",x,y,Q);
		putpixel(x,y,color);
		if(Q<0){
			y=y-1;
			Q=Q-2*dx+2*dy;
		}
		else{
			Q=Q+2*dy;
		}
	}
}
//A(20,80) 		B(120,30)
//m<1
void Bre3(int xa, int ya, int xb, int yb, int color){
	int dx=(xb-xa);
	int dy=(yb-ya);
	int Q=dy+2*dx;
	int x=xa;
	int y=ya;
	for(;x<=xb;x++){
		printf("x=%d, y=%d, Q=%d\n",x,y,Q);
		putpixel(x,y,color);
		if(Q<0){
			y=y+1;
			Q=Q+2*dx+2*dy;
		}
		else{
			Q=Q+2*dx;
		}
	}
}
//A(120,30)	B(20,80)
void Bre4(int xa, int ya, int xb, int yb, int color){
	int dx=(xb-xa);
	int dy=(yb-ya);
	int Q=2*dy+dx;
	int x=xa;
	int y=ya;
	for(;x>xb;x--){
		printf("x=%d, y=%d, Q=%d\n",x,y,Q);
		putpixel(x,y,color);
		if(Q<0){
			y=y-1;
			Q=Q+2*dx+2*dy;
		}
		else{
			Q=Q+2*dy;
		}
	}
}


//TH m>1
/*
x1<x2 Q0=2dy-dx
x1>x2 Q0=2dy+dx
Q0=2dy-dx
Q0>=0 	Q0=Q0+2dy-2dx y=y
Q0<0	Q0= Q0+2dy
*/
//A(3,4) 	B(8,10)	m=1.6>1
/*
dx=5	2dx=10
dy=6	2dy=12
Q0= 7
x	y		Q0




*/
int main(){
	initwindow(200,200);
	Bre1(20,30,120,80,2);
	Bre2(120,80,20,30,4);
	Bre3(20,80,120,30,6);
	Bre4(120,30,20,80,8);
	getch();
}
