#include <graphics.h>
#include<stdio.h>
#include<stdlib.h>
//khai bao bien
int xwmin = 100;
int xwmax = 300;
int ywmin = 100;
int ywmax = 300;
int x0,y0,x1,y1;//toa do duong thang sau khi xen tia
int xgd,ygd;
float m;
void khoitao(){//ve cua so cat
setlinestyle(1,1,2);
setcolor(15);
rectangle(xwmin,ywmax,xwmax,ywmin);
}

int mahoa(int x, int y){
	if(x>=xwmin && x<=xwmax && y>=ywmin && y<=ywmax)
		return 0;//0000(2)=0(10)
	if(x>=xwmin && x<=xwmax && y>=ywmin)
		return 4;//0100(2)=4(10)
	if(x>=xwmin && x<=xwmax && y<=ywmax)
		return 8;//1000(2)=8(10)
	if(x<xwmin && y>=ywmin && y<=ywmax)
		return 1;//0001(2)=1(10)
	if(x>xwmax && y>=ywmin && y<=ywmax)
		return 2;//0010(2)=2(10)
	if(x<xwmin && y<ywmin )
		return 5;//0101(2)=5(10)
	if(x>xwmax && y<ywmin )
		return 6;//0110(2)=6(10)
	if(x<xwmin && y>ywmax )
		return 9;//1001(2)=9(10)
	if(x>xwmax && y>ywmax )
		return 10;//1010(2)=10(10)
				
	
	
	
}
//tim giao diem: xet tung diem(x,y))
void timgiaodiem(int x, int y){
	switch (mahoa(x,y)) {
		case 0://diem(x,y) ben trong cua so
			xgd=x;
			ygd=y;
			break;
		case 4://diem(x,y) ben duoi cua so
			ygd=ywmin;
			xgd=x+(ygd-y)/m;
			break;
		case 8:{//diem(x,y) ben tren cua so
			ygd=ywmax;
			xgd=x+(ygd-y)/m;
			break;
		}
		case 1:{//diem(x,y) ben trai cua so
			xgd=xwmin;
			ygd=y+(xgd-x)*m;
			break;
		}
		case 2:{//diem(x,y) ben phai cua so
			xgd=xwmax;
			ygd=y+(xgd-x)*m;
			break;
		}
		case 6:{//diem(x,y) ben duoi cua so
			ygd=ywmin;
			xgd=x+(ygd-y)/m;
			if(xgd>xwmax){
			xgd=xwmax;
			ygd=y+(xgd-x)*m;}
			break;
		}
		case 5:{//diem(x,y) ben trai cua so
			ygd=ywmin;
			xgd=x+(ygd-y)/m;
			if(xgd<xwmin){
			xgd=xwmin;
			ygd=y+(xgd-x)*m;
			}
			break;
		}
		case 9:{//diem(x,y) ben duoi ben  trai cua so
			ygd=ywmax;
			xgd=x+(ygd-y)/m;
			if(xgd<xwmin){
			xgd=xwmin;
			ygd=y+(xgd-x)*m;
			}
			break;
		}
		case 10:{//diem(x,y) ben duoi cua so
			ygd=ywmax;
			xgd=x+(ygd-y)/m;
			if(xgd>xwmax){
			xgd=xwmin;
			ygd=y+(xgd-x)*m;
			}
			break;
		}
			
			
		
		
		
		default:
			//TODO
			break;
	}
}
void CohenSutherland(int xa, int ya, int xb, int yb){
	if(xa==xb){
		m=INT_MAX;
	}
	if(ya==yb){
		m=0;
	}
	if(xa != xb && ya!=yb){
		m=(float)(yb-ya)/(xb-xa);
	}
	
	setcolor(2);
	line(xa,ya,xb,yb);
	//tim giao diem
	printf("\nMa hoa A = %d va B = %d",mahoa(xa,ya),mahoa(xb,yb));
	timgiaodiem(xa,ya);
	x0=xgd;
	y0=ygd;
	timgiaodiem(xb,yb);
	x1=xgd;
	y1=ygd;
	//in ra man hing toa do cac giao diem
	printf("\nx0 = %d, y0 = %d, x1 = %d, y1 = %d",x0,y0,x1,y1);
	if(x0<xwmin || x0>xwmax || y0<ywmin || y0>ywmax || x1<xwmin || x1>xwmax || y1<ywmin || y1>ywmax){
		
	}
	else{
		setcolor(4);
		line(x0,y0,x1,y1);	
	}	
}
//chuong trinh chinh
int main(){
	initwindow(400,400);
	khoitao();
	//CohenSutherland(150,150,250,250);
	//CohenSutherland(150,150,250,30);
	//CohenSutherland(150,150,250,380);
	//CohenSutherland(150,150,50,250);
	//CohenSutherland(150,150,365,250);
	//CohenSutherland(200,200,365,20);
	//CohenSutherland(200,200,10,90);
	//CohenSutherland(200,200,50,320);
	//CohenSutherland(200,200,10,420);
	//CohenSutherland(200,200,365,320);
	//CohenSutherland(200,200,365,390);
//	CohenSutherland(50,200,365,280);
//	CohenSutherland(250,50,280,380);
//	CohenSutherland(50,200,280,280);
//	CohenSutherland(50,200,250,50);
//	CohenSutherland(380,250,200,50);
	CohenSutherland(280,380,365,280);
	CohenSutherland(80,380,365,380);
	
	
	
	getch();
}
