#include <stdio.h>
#include<graphics.h>
void midpoint(int xa, int ya, int xb, int yb, int color){
	int x=xa;
	int y=ya;
	int A=(yb-ya);
	int B=-(xb-xa);
	float M = (float)A+B/2;
	for(;x<=xb;x++){//m<1 xa<xb, => xsau=xtruoc+1
		printf("x= %d, y=%d, M= %.1f\n",x,y,M);
		putpixel(x,y,color);
		if(M<0){
			M+=A;
			y=y;//ysau=ytruowsc+1
		}
		
	}
}
int main(){
	initwindow(300,300);
	midpoint(20,30,120,80,4);
	getch();
}
