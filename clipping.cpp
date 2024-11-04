#include<graphics.h>
#include<stdio.h>


int xwmin=100;
int xwmax = 300;
int ywmin = 100;
int ywmax=300;
void khoitao(){
	setcolor(15);
	setlinestyle(1,0,2);
	rectangle(xwmin, ywmax, xwmax, ywmin);
	
}
float Max(float a, float b){
	return (a>b)?a:b;
}
float Min(float a, float b){
	return (a<b)?a:b;
}

void LiangBasky(int xa, int ya, int xb, int yb){
	setcolor(4);
	line(xa,ya,xb,yb);
	printf("Toa do cua xa = %d, ya=%d, xb=%d, yb=%d",xa,ya,xb,yb);
	int dx=xb-xa;
	int dy=yb-ya;
	
	int p[4]={-dx,dx,-dy,dy};
	int q[4]={xa-xwmin,xwmax-xa,ya-ywmin,ywmax-ya};
	printf("\nPk[]: ");
	for(int i=0;i<4;i++){
		printf("%5d",p[i]);
	}
	printf("\nQk[]");
		for(int i=0;i<4;i++){
			printf("%5d",q[i]);
		}
	int x0,x1,y0,y1;
	float t1=0;
	float t2=1;
	for(int i=0;i<4;i++){
		if(p[i]<0){
			t1=Max(t1,(float)q[i]/p[i]);
			
		}
		else{
			t2=Min(t2,(float)q[i]/p[i]);
			
		}
		
	}
	printf("\nt1: %f va t2: %f",t1,t2);
	x0=xa+t1*dx;
	y0=ya+t1*dy;
	x1=xa+t2*dx;
	y1=ya+t2*dy;
	printf("\nx0= %d, y0=%d, x1=%d, y1=%d",x0,y0,x1,y1);
	setcolor(2);
	line(x0,y0,x1,y1);
	
	
	
	
	
	
}
int main (){
	initwindow(500,500);
	khoitao();
	LiangBasky(150,280,260,150);
	LiangBasky(150,150,250,250);
	LiangBasky(150,150,250,30);
		LiangBasky(150,150,250,380);
		LiangBasky(150,150,50,250);
		LiangBasky(150,150,365,250);
		LiangBasky(200,200,365,20);
		LiangBasky(200,200,10,90);
		LiangBasky(200,200,50,320);
		LiangBasky(200,200,10,420);
		LiangBasky(200,200,365,320);
		LiangBasky(200,200,365,390);
	LiangBasky(50,200,365,280);
	LiangBasky(250,50,280,380);
	LiangBasky(50,200,280,280);
	LiangBasky(50,200,250,50);
	LiangBasky(380,250,200,50);
		LiangBasky(280,380,365,280);
		LiangBasky(80,380,365,380);
	getch();
	
	
}
