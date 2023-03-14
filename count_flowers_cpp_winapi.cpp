#define _WIN32_WINNT 0x0500
#include <windows.h> 
#include <iostream.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>
using namespace std;
//in devcpp 4.9.9.2   tools - compiler options - compiler - add to linker cmd: -lgdi32 
//devcpp tools -compiler options - settings- linker - create console - (try y)

int colr = 0; int colg = 0; int colb = 0;
int x= 0; int y = 20; int d = 120; //100 for 550*110 ; 120 for 650*460
int col = 0; int shape = 0; int phase=0; int answ=0;
int randt=0; int randseed=0; int counter =0;
int arrc[13]= {0,0,0,0,0,0,0,0,0,0,0,0,0};
int arrs[13]= {0,0,0,0,0,0,0,0,0,0,0,0,0};

int main() {
void drawf(); 
cout<<"__ Count Flowers C++ by OlegTim __ \n\nPress <num> to start - for example, <1> \n" ;
cout<<"\nCount the number of flowers by colour, shape or both. \n";
cout<<"Press any number button (0-9) to answer, \ncheck if it's right and continue. \n";
cout<<"\n\nIf needed, adjust console to fit 4 columns \n";
cout<<"and 3 rows of flowers and 3 text rows below. \n";
cout<<"Tested at 650*460 pix console, 80 letters (8*12 pix each) in 33 lines.\n";
cout<<"\nPress <1> to start; <Esc> to quit. \n";
struct tm *ptr;
time_t lt;
lt = time('\0'); 
randseed=lt%10;
void answf();

while(true){
if(kbhit()){ 
switch(getch()){ 
case 27: { exit(0);  }	//esc
case 48: { answ=0;  break;  }
case 49: { answ=1;  break;  }
case 50: { answ=2;  break;  }
case 51: { answ=3;  break;  }
case 52: { answ=4;  break;  }
case 53: { answ=5;  break;  }
case 54: { answ=6;  break;  }
case 55: { answ=7;  break;  }
case 56: { answ=8;  break;  }
case 57: { answ=9;  break;  }
default: { answ=666;  break;  }
}
if  (answ!=666) {answf();}
}}
}

void answf(){
void genf();	 
void drawf();
void drawansw();
if (phase==2||phase==3){
phase=1;   			  
genf();	
drawf();   			  
}else{
if (phase==0){
phase=1;   			  
genf();	
drawf(); 
}
else{
if (phase==1){
if (answ==randt){phase=2;
cout<<answ<<" is OK! Press <num> for new game\n";
drawansw();
}
else {phase=3;
cout<<answ<<" is wrong. The answer is: "<<randt<<". Press <num> for new game\n"; 
drawansw();	
}		  	
}}}
}

void drawf(){
for (int i = 0; i<100; i++){ cout <<  "\n"; }  
HWND hwnd = GetConsoleWindow(); 
HDC dc = GetDC(hwnd); 
RECT window = {}; 
HBRUSH brush;
RECT WinCoord = {}; 
GetWindowRect(hwnd, &WinCoord); 

x=0; y=2*d/5;
for (int i2 = 0; i2<4; i2++){
for (int i = 0; i<4; i++){

if (i+4*i2<13){
col = arrc[i+4*i2];
shape = arrs[i+4*i2];

if (i+4*i2==12){
x=4*d+d/5;y=2*d/5;   			   
brush = CreateHatchBrush(4,RGB(195, 195, 195)); 
SelectObject(dc, brush); 
Rectangle(dc, x-d/10, y-d/10, x+d+d/10, y+3*d+d/10); 
DeleteObject(brush);    			   
}

switch (col){
case 0: {colr=0; colg=0; colb=0; break;} //black for any color
case 1: {colr=0; colg=255; colb=0; break;}
case 2: {colr=0; colg=0; colb=255; break;}
case 3: {colr=255; colg=255; colb=0; break;}
case 4: {colr=0; colg=255; colb=255; break;}
case 5: {colr=255; colg=0; colb=255; break;}
case 6: {colr=255; colg=0; colb=0; break;} 
case 7:  {colr=255; colg=255; colb=255; break;}	   
}

if (shape==0){ //for any shape
brush = CreateHatchBrush(7, RGB(colr, colg, colb));
SelectObject(dc, brush);
Rectangle(dc, x, y, x+d, y+d);
DeleteObject(brush);
}
if (shape==1){
brush = CreateSolidBrush(RGB(colr, colg, colb)); 
SelectObject(dc, brush); 
Ellipse(dc,  x+5*d/16, y+2*d/16, x+11*d/16,y+8*d/16);
Ellipse(dc,  x+5*d/16, y+8*d/16, x+11*d/16,y+14*d/16);
Ellipse(dc,  x+2*d/16, y+5*d/16, x+8*d/16,y+11*d/16);
Ellipse(dc,  x+8*d/16, y+5*d/16, x+14*d/16,y+11*d/16);
DeleteObject(brush);
}
if (shape==2){
brush = CreateHatchBrush(7, RGB(colr, colg, colb));
SelectObject(dc, brush);
POINT poly[3] = { {x+6*d/16,y+d/2 },{ x+d/2 , y },{x+10*d/16, y+d/2} };
Polygon(dc, poly, 3);
POINT poly2[3] = { {x+6*d/16,y+d/2 },{ x+d/16 , y+15*d/16 },{x+10*d/16, y+d/2} };
Polygon(dc, poly2, 3);
POINT poly4[3] = { {x+6*d/16,y+d/2 },{ x+15*d/16 , y+15*d/16 },{x+10*d/16, y+d/2} };
Polygon(dc, poly4, 3);
DeleteObject(brush);
}
if (shape==3){
brush = CreateSolidBrush(RGB(colr, colg, colb)); 
SelectObject(dc, brush); 
Ellipse(dc,  x+5*d/8, y, x+3*d/8,y+4*d/8);
Ellipse(dc, x, y+5*d/8, x+4*d/8, y+3*d/8);
Ellipse(dc, x+4*d/8, y+3*d/8, x+d, y+5*d/8);
Ellipse(dc,  x+5*d/8, y+4*d/8, x+3*d/8,y+d);
DeleteObject(brush);
}
if (shape==4){	
brush = CreateSolidBrush(RGB(colr, colg, colb)); 
SelectObject(dc, brush); 
Ellipse(dc, x, y, x+d, y+d);
DeleteObject(brush);
}

brush = CreateSolidBrush(RGB(215, 175, 150)); 
SelectObject(dc, brush); 
Ellipse(dc, x+5*d/8, y+5*d/8, x+3*d/8, y+3*d/8);
DeleteObject(brush);
}
x+=d;
}
x=0; y+=d;
}

ReleaseDC(hwnd, dc); 
void genl();
genl();
}

void genf(){	 
void clearf();
clearf();

struct tm *ptr;
time_t lt;
lt = time('\0'); 
randt=lt%10;
if (randt==3||randt==9){if (randt==3){randt=9;}else{randt=3;}}

int getrandc();
int getrands(); 
int c = getrandc(); 
int s = getrands();

if (c==0&&s==0){c=1;}
arrc[12]=c;
arrs[12]=s;

int getrandnum();
int n =  0;
int countfl();

while (countfl()<randt){ //fill field with guessed type start
counter++;
n =  getrandnum();
int t=0;
if (arrc[n]==0){
t=arrc[12];
if (arrc[12]==0){t = getrandc();}
if (t==0) {t++;}
arrc[n]=t;
t=arrs[12];
if (arrs[12]==0){t = getrands();}
if (t==0) {t++;}
arrs[n]=t;
}
} //fill field with guessed type end

int isfieldfull();
while (isfieldfull()!=0){ //fill field with other type start
counter++;
n =  getrandnum();
int t=0;

if (arrc[n]==0){ 
t = getrandc();   				
while(t==0||t==arrc[12]) {t = getrandc();}
arrc[n]=t;
t = getrands();
while(t==0||t==arrs[12]) {t = getrands();}
arrs[n]=t;

if (arrc[12]!=0&&arrs[12]!=0){
t = getrandc();   							  
while(t==0) {t = getrandc(); }
arrc[n]=t;
if (arrc[n]!=arrc[12]){
t = getrands();   							  
while(t==0) {t = getrands(); }
arrs[n]=t;   					   
}
}

} // if(arrc[n]==0) end
} //fill field with other type end

}//genf() end

int isfieldfull(){
	int m=0;
for (int i = 0; i<12; i++){if (arrc[i]==0){m++;}} 	
	return m;
	}

int countfl(){
int m=0;
if (arrc[12]==0){
for (int i = 0; i<12; i++){if (arrs[i]==arrs[12]){m++;}}   				 
}else{if (arrs[12]==0){
for (int i = 0; i<12; i++){if (arrc[i]==arrc[12]){m++;}} 		 
}else{
for (int i = 0; i<12; i++){if (arrs[i]==arrs[12]&&arrc[i]==arrc[12]){m++;}} 	  
	  }}
return m;
}

int getrandnum(){ //0-11
int getrandnum2();	
int m=99;
while (m>11){m=getrandnum2();}
return m;
}
int getrandnum2(){
int m=0;
for (int i =0; i <(counter+1)*3; i++){ m = rand();} 
m=m%100;
return m;	
	}

int getrandc(){
	 int m =0;
for (int i =0; i <randt+randseed+counter; i++){
	 m = rand();} 
if (m<10){m=(m+1)*10;}
m = m%10;
if (m==8){m=3;} if (m==9){m=4;}
return m;
}
	 
int getrands(){
	 int m =0;
for (int i =0; i <randt+randseed+counter+1; i++){
	 m = rand();} 
if (m<10){m=(m+1)*10;}
m = m%10;
if (m==5){m=1;} if (m==6){m=3;} if (m==7){m=3;} if (m==8){m=4;} if (m==9){m=1;}
return m;
}

void clearf(){
for (int i = 0; i<13; i++){arrc[i]=0; arrs[i]=0;}
counter=0;	 
}

void genl(){
string sc = "";	
if (arrc[12]==1){sc="green ";}
if (arrc[12]==2){sc="blue ";}	
if (arrc[12]==3){sc="yellow ";}	
if (arrc[12]==4){sc="aqua ";}	
if (arrc[12]==5){sc="violet ";}
if (arrc[12]==6){sc="red ";}	
if (arrc[12]==7){sc="white ";}
string sh = "";	
if (arrs[12]==1){sh="bubble ";}
if (arrs[12]==2){sh="spike ";}
if (arrs[12]==3){sh="cross ";}
if (arrs[12]==4){sh="round ";}	 	 
cout<<"                                                                              .\n";
cout<<"How many "<<sc<<sh<<"flowers are there?\n";
}

void drawansw(){
HWND hwnd = GetConsoleWindow(); 
HDC dc = GetDC(hwnd); 
RECT window = {}; 
HBRUSH brush;
RECT WinCoord = {}; 
GetWindowRect(hwnd, &WinCoord);
colr=255; colg=0; 
if (phase==2){colr=0; colg=255;}
x=4*d+d/5;y=2*d/5+d;
brush = CreateSolidBrush(RGB(colr, colg, 0)); 
SelectObject(dc, brush); 
if (phase==2){
POINT poly[4] = { {x,y },{ x+d/2 , y+ d/2},{x+d, y},{x+d/2,y +d/4 } };
Polygon(dc, poly, 4);
}else{
POINT poly[4] = { {x,y },{ x+d , y+ d},{x+d, y+7*d/8},{x+d/8,y  } };
Polygon(dc, poly, 4);
POINT poly2[4] = { {x,y+d },{ x+d/8 , y+ d},{x+d, y},{x+7*d/8,y  } };
Polygon(dc, poly2, 4);			
}
DeleteObject(brush);	 
}
