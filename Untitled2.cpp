#include <graphics.h>
#include<stdio.h>
#include<math.h>
//A(20,30), B(120,80)
void DDA1(int xa, int ya, int xb, int yb, int color){
	float m= float(yb-ya)/(xb-xa);
	//truong hop nay: m<1 va xa<xb
	int xsau=xa;
	float ysau=ya;
	for(;xsau<=xb;xsau++){
		printf("xsau=%d, ysau = %.0f\n",xsau,round(ysau));
		ysau=ysau+m;
		putpixel(xsau,round(ysau),color);
	}
	
}

//A(120,80), B(20,30)
void DDA2(int xa, int ya, int xb, int yb, int color){
	float m= float(yb-ya)/(xb-xa);
	//truong hop nay: m=0,5<1 va xa>xb
	int xsau=xa;
	float ysau=ya;
	for(;xsau>=xb;xsau--){
		printf("xsau=%d, ysau = %.0f\n",xsau,round(ysau));
		ysau=ysau-m;
		putpixel(xsau,round(ysau),color);
	}
	
}

//A(120,30), B(20,80)
//void DDA1(int xa, int ya, int xb, int yb, int color){
//	float m= float(yb-ya)/(xb-xa);
//	//truong hop nay: m=0,5<1 va xa>xb
//	int xsau=xa;
//	float ysau=ya;
//	for(;xsau>=xb;xsau--){
//		printf("xsau=%d, ysau = %.0f\n",xsau,round(ysau));
//		ysau=ysau-m;
//		putpixel(xsau,round(ysau),color);
//	}
//}


int main()
{
	initwindow(800,800);
	DDA1(20,30,120,80,5);
	DDA2(120,80,20,30,5);
	getch();
}
