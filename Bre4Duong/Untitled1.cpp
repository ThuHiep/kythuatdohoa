#include<winbgim.h>
#include<stdio.h>
#include<math.h>

void ellipse(int xc, int yc, int x, int y, int color){
	putpixel(xc+x, yc+y, color);
	putpixel(xc-x, yc+y, color);
	putpixel(xc+x, yc-y, color);
	putpixel(xc-x, yc-y, color);
	
}
void Midpoint(int xc, int yc, int rx, int ry){
	int x=0;
	int y=ry;
	
	//ve mien 1
	float p1 = round(ry*ry - rx*rx*ry + rx*rx/4);
	int px=0;
	int py=2*rx*rx*y;
	while(px<py){
		ellipse(xc, yc, x, y, 4);
		px=px+2*ry*ry;
		x++;
		if(p1<0){
			p1=p1+ry*ry+px;
		}
		else{
			y--;
			py=py-2*rx*rx;
			p1=p1+ry*ry+px-py;
		}
	}
	
}
int main(){
	initwindow(400,400);
	Midpoint(100,100,100,50);
	getch();
}
	


