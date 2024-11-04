#include <winbgim.h>//ham line ve duong thang
#include <stdio.h>
#include<math.h>//round lam tron


#define maxdinh 20//so dinh toi da cua da giac
#define INPUT "color.txt"//file toa do da giac 

int dinh[maxdinh][2];
int n;//so dinh cua da giac
FILE *fp;//con tro tap tin
float m[maxdinh];
//buoc 1 doc noi dung tap tin
void readfile (){
	fp=fopen(INPUT,"r");
	if(fp==NULL){
		printf("File not found");
	}
	else{
		//doc so dinh tu file luu vao n
		fscanf(fp,"%d",&n);
		printf("So dinh la: %d",n);
		//doc tung so trong file luu vao dinh [][]
		for(int i=0;i<n;i++){
			for(int j=0;j<2;j++){
				fscanf(fp,"%d",&dinh[i][j]);
			}
		}
		printf("\nCac dinh cua da giac:\n");
		for(int i=0;i<n;i++){
			for(int j=0;j<2;j++){
				printf("%5d",dinh[i][j]);
			}
				printf("\n");	
		}
		fclose(fp);
	}
	
}
//buoc 2 ve da giac
void vedagiac(){
	//them 1 dinh cuoi co toa do la dinh dau
	dinh[n][0]=dinh[0][0];
	dinh[n][1]=dinh[0][1];
	for(int i=0;i<n;i++){//duyet cac dinh cua da giac
		line(dinh[i][0],dinh[i][1],dinh[i+1][0],dinh[i+1][1]);//ve duong thang
		//dinh[i][0]: xi,	dinh[i][1]:yi
		//dinh[i+1][0]: xi+1,	dinh[i+1][1]: yi+1
	}
}
//buoc3. tinh he so goc
void hesogoc(){
	//m = dy/dx
	for(int i=0;i<n;i++){
		int dx=dinh[i+1][0] - dinh[i][0];
		int dy=dinh[i+1][1] - dinh[i][1];
		//cong tbuc tinh xgd=(xtruoc + (y-ytruoc)/m)
		if(dx==0){
			m[i]=99999;
		}
		if(dy==0){
			m[i]=1;//mien la m[i] khac 0
		}
		else{
			m[i]=(float)(dy/dx);
		}
	}
	printf("\nHe so goc: \n");
	for(int i=0;i<n;i++){
		printf("%.1f ", m[i]);
	}
	
}
//buoc4 to mau
void scanline(){
	int xgd[maxdinh];
	//tim ymin va ymax
	int ymin = dinh[0][1];
	int ymax = dinh[0][1];
	for(int i=1;i<n;i++){
		if(ymin>dinh[i][1]){
			ymin = dinh[i][1];
		}
		if(ymax < dinh[i][1]){
			ymax = dinh[i][1];
		}
		
	}
	printf("\nymin = %d, ymax = %d",ymin,ymax);
	//tim giao diem cua y dong quet voi cac canh cua da giac
	int y=ymin;
	
	while(y<=ymax){
		int dem=0;
		for(int i=0;i<n;i++){
		//duyet qua xem xet khi nao co giao diem
			if((y>=dinh[i][1]&& y<dinh[i+1][1]) || (y<dinh[i][1]&& y>=dinh[i+1][1]) ){
				//co giao diem
				xgd[dem++]= round(dinh[i][0]+ (y-dinh[i][1])/m[i]);
			
			}
		}
		//voi moi dong quyet ta co so giao diem la 
		for(int i=0;i<dem;i++){
			printf("\ny=%d: (%d,%d)",y,xgd[i],y);
		}
		//sap xep tang dan hoanh do giao diem
		for(int i=0;i<dem-1;i++){
			for(int j=i+1;j<dem;j++){
				if(xgd[i] > xgd[j]){
					int tam = xgd[i];
					xgd[i]=xgd[j];
					xgd[j]= tam;
				}
			}
		}
		for(int i=0;i<dem-1;i+=2){
			line(xgd[i],y,xgd[i+1],y);
		}
		y++;
	}
}
int main(){
	readfile();
	initwindow(500,500);
	vedagiac();
	hesogoc();
	scanline();
	getch();
	
}
