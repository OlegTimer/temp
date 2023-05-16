#include <windows.h>
#include <windowsx.h>
#include <sstream>
#include <string>
#include <iostream>
#include <math.h>
#include <vector> 
using namespace std;

// Code by OlegTim. Tested on Win7, 800*600 and 1024*768, fullscreen and windowed
//devcpp 4.9.9.2  tools -compiler options - settings- linker - create console - (try n)
//  tools - compiler options - compiler - add this to linker cmd -lgdi32 

#define ID_MYBUTTON 1 
#define ID_MYBUTTON2 2 
#define ID_MYBUTTON3 3 
#define ID_MYBUTTON4 4 
#define ID_MYBUTTON5 5 
#define ID_MYBUTTON6 6 
#define ID_MYBUTTON10 10
#define ID_MYBUTTON20 20 
#define ID_MYBUTTON30 30 
#define ID_MYBUTTON40 40 
#define ID_MYBUTTON50 50 
#define ID_MYBUTTON60 60
#define ID_MYBUTTON11 11
#define ID_MYBUTTON21 21 
#define ID_MYBUTTON31 31 
#define ID_MYBUTTON41 41 
#define ID_MYBUTTON51 51 
#define ID_MYBUTTON61 61

LRESULT CALLBACK MainWinProc(HWND,UINT,WPARAM,LPARAM);
HWND hMainWnd;
int pitch=0;
int roll=0;
int yaw =0;
int d = 150; //cube size
int kx=2*d; int ky=2*d;
int dm = 25; //menu line height
  int width = 800;
  int height = 600;
  
static void go(){
if (pitch <0) {pitch = 360+pitch;} 
if (pitch >359) {pitch = pitch-360;} 
if (roll <0) {roll = 360+roll;} 
if (roll >359) {roll = roll-360;}  
if (yaw <0) {yaw = 360+yaw;} 
if (yaw >359) {yaw = yaw-360;}  
RedrawWindow(hMainWnd,NULL,NULL,RDW_INVALIDATE | RDW_ERASE);	   
	   }  

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE,LPSTR,int ss) {
 WNDCLASS wc;
 wc.style=0;
 wc.lpfnWndProc=MainWinProc;
 wc.cbClsExtra=wc.cbWndExtra=0;
 wc.hInstance=hInst;
 wc.hIcon=NULL;
 wc.hCursor=LoadCursor(NULL, IDC_ARROW);
 wc.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
 wc.lpszMenuName=NULL;
 wc.lpszClassName="W";
 if (!RegisterClass(&wc)) return FALSE;

  hMainWnd=CreateWindow("W","Cube_rotate_by_OlegTim",WS_OVERLAPPEDWINDOW,
  0,0,width,height,NULL,NULL,hInst,NULL);
 if (!hMainWnd) return FALSE;
 
SetWindowPos(hMainWnd, HWND_TOP, 0, 0, GetSystemMetrics(SM_CXSCREEN), //fullscreen w tab
GetSystemMetrics(SM_CYSCREEN), SWP_FRAMECHANGED); 
/*
WINDOWPLACEMENT wpc; //fullscreen without tab and borders
GetWindowPlacement(hMainWnd,&wpc);
                SetWindowLong(hMainWnd,GWL_STYLE,WS_POPUP);
                SetWindowLong(hMainWnd,GWL_EXSTYLE,WS_EX_TOPMOST);
                ShowWindow(hMainWnd,SW_SHOWMAXIMIZED);
*/
 
 ShowWindow(hMainWnd,ss);
 UpdateWindow(hMainWnd);

 MSG msg; 
 while (GetMessage(&msg,NULL,0,0)) {
  TranslateMessage(&msg); 
  DispatchMessage(&msg); 
 } 
 return msg.wParam; 
}

LRESULT CALLBACK MainWinProc(HWND hw,UINT msg,WPARAM wp,LPARAM lp) {
 switch (msg) {
   case WM_PAINT : 	
   	{	
RECT rect; 
if(GetWindowRect(hMainWnd, &rect))
{
   width = rect.right - rect.left;
   height = rect.bottom - rect.top;
}
int menux = width -(width-height);		   
		   	
HDC hdc; 
PAINTSTRUCT ps; 
RECT re;		
hdc=BeginPaint(hMainWnd, &ps);

re.top=0;
re.left=0;
re.right=menux;
re.bottom=height;
FillRect(hdc, &re, HBRUSH(CreateSolidBrush(RGB(165,75,165)))); //violet

int r,g,b,r1,g1,b1,r2,g2,b2; 
r=g=b=r1=g1=b1=r2=g2=b2=0;
int xa1,xa2,xa3,xa4,xb1,xb2,xb3,xb4,xc1,xc2,xc3,xc4;
xa1=xa2=xa3=xa4=xb1=xb2=xb3=xb4=xc1=xc2=xc3=xc4=0;
int ya1,ya2,ya3,ya4,yb1,yb2,yb3,yb4,yc1,yc2,yc3,yc4;
ya1=ya2=ya3=ya4=yb1=yb2=yb3=yb4=yc1=yc2=yc3=yc4=0;

// r=200;g=191;b=231;xa1+=d/2;ya1+=0;xa2+=0;ya2+=d/4;xa3+=d/2;ya3+=d/2;xa4+=d;ya4+=d/4; //lviol
// r1=255;g1=255;b1=255; xb1+=0;yb1+=d/4;xb2+=0;yb2+=3*d/4;xb3+=d/2;yb3+=d;xb4+=d/2;yb4+=d/2;
// r2=180;g2=180;b2=180; xc1+=d/2;yc1+=d/2;xc2+=d/2;yc2+=d;xc3+=d;yc3+=3*d/4;xc4+=d;yc4+=d/4;

double coord[8][3];
double camx, camy, camz; camx =camy= 0; camz=3;
coord[0][0]=-1; coord[0][1]=1; coord[0][2]=1;
coord[1][0]=1; coord[1][1]=1; coord[1][2]=1;
coord[2][0]=1; coord[2][1]=-1; coord[2][2]=1;
coord[3][0]=-1; coord[3][1]=-1; coord[3][2]=1;
coord[4][0]=-1; coord[4][1]=1; coord[4][2]=-1;
coord[5][0]=1; coord[5][1]=1; coord[5][2]=-1;
coord[6][0]=1; coord[6][1]=-1; coord[6][2]=-1;
coord[7][0]=-1; coord[7][1]=-1; coord[7][2]=-1;

//to radian, clock-wise
double yawr; 
double tx; int ix;

yawr= (360-yaw)/57.3; 
for (int i=0; i<8; i++){
tx = coord[i][0];
coord[i][0]= tx*cos(yawr)-coord[i][1]*sin(yawr);
coord[i][1]= tx*sin(yawr)+coord[i][1]*cos(yawr); }

yawr = (360-roll)/57.3; 
for (int i=0; i<8; i++){
tx = coord[i][0];
coord[i][0]= tx*cos(yawr)-coord[i][2]*sin(yawr);
coord[i][2]= tx*sin(yawr)+coord[i][2]*cos(yawr); }

yawr = (360-pitch)/57.3; 
for (int i=0; i<8; i++){
tx = coord[i][1];
coord[i][1]= tx*cos(yawr)-coord[i][2]*sin(yawr);
coord[i][2]= tx*sin(yawr)+coord[i][2]*cos(yawr); }

double dist[8];
double dclose = 5;
for (int i=0; i<8; i++){
dist[i]=sqrt((camz-coord[i][2])*(camz-coord[i][2])+(camy-coord[i][1])*(camy-coord[i][1]));
dist[i]=sqrt(dist[i]*dist[i]+(camx-coord[i][0])*(camx-coord[i][0]));
if (dist[i]<dclose){dclose= dist[i];}}
dclose+=0.00001; //double badly equals
vector <int> ivector; // (3+8)*11 = 33
  																  																		
if (dist[0]<dclose||dist[1]<dclose||dist[2]<dclose||dist[3]<dclose){ //upper side, blue 
ivector.push_back(0);  ivector.push_back(0); ivector.push_back(255);
tx = coord[0][0]*d+kx; ix=(int)tx; ivector.push_back(ix); 
tx=-coord[0][1]*d+kx; ix = (int)tx; ivector.push_back(ix);
tx = coord[1][0]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx=-coord[1][1]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx = coord[2][0]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx=-coord[2][1]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx = coord[3][0]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx=-coord[3][1]*d+kx; ix=(int)tx; ivector.push_back(ix);  } 

if (dist[2]<dclose||dist[3]<dclose||dist[6]<dclose||dist[7]<dclose){ //front, white
ivector.push_back(255);  ivector.push_back(255); ivector.push_back(255);
tx = coord[3][0]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx=-coord[3][1]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx = coord[2][0]*d+kx; ix=(int)tx; ivector.push_back(ix); 
tx=-coord[2][1]*d+kx; ix = (int)tx; ivector.push_back(ix);
tx = coord[6][0]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx=-coord[6][1]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx = coord[7][0]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx=-coord[7][1]*d+kx; ix=(int)tx; ivector.push_back(ix);  }  

if (dist[2]<dclose||dist[1]<dclose||dist[5]<dclose||dist[6]<dclose){ //right, lgray
ivector.push_back(170);  ivector.push_back(170); ivector.push_back(170);
tx = coord[2][0]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx=-coord[2][1]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx = coord[1][0]*d+kx; ix=(int)tx; ivector.push_back(ix); 
tx=-coord[1][1]*d+kx; ix = (int)tx; ivector.push_back(ix);
tx = coord[5][0]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx=-coord[5][1]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx = coord[6][0]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx=-coord[6][1]*d+kx; ix=(int)tx; ivector.push_back(ix);  } 

if (dist[4]<dclose||dist[7]<dclose||dist[3]<dclose||dist[0]<dclose){ //left, mgray
ivector.push_back(85);  ivector.push_back(85); ivector.push_back(85);
tx = coord[4][0]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx=-coord[4][1]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx = coord[7][0]*d+kx; ix=(int)tx; ivector.push_back(ix); 
tx=-coord[7][1]*d+kx; ix = (int)tx; ivector.push_back(ix);
tx = coord[3][0]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx=-coord[3][1]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx = coord[0][0]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx=-coord[0][1]*d+kx; ix=(int)tx; ivector.push_back(ix);  } 

if (dist[4]<dclose||dist[0]<dclose||dist[1]<dclose||dist[5]<dclose){ //back, black
ivector.push_back(0);  ivector.push_back(0); ivector.push_back(0);
tx = coord[4][0]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx=-coord[4][1]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx = coord[0][0]*d+kx; ix=(int)tx; ivector.push_back(ix); 
tx=-coord[0][1]*d+kx; ix = (int)tx; ivector.push_back(ix);
tx = coord[1][0]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx=-coord[1][1]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx = coord[5][0]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx=-coord[5][1]*d+kx; ix=(int)tx; ivector.push_back(ix);  } 

if (dist[7]<dclose||dist[4]<dclose||dist[5]<dclose||dist[6]<dclose){ //bottom, lviol
ivector.push_back(200);  ivector.push_back(191); ivector.push_back(231);
tx = coord[7][0]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx=-coord[7][1]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx = coord[4][0]*d+kx; ix=(int)tx; ivector.push_back(ix); 
tx=-coord[4][1]*d+kx; ix = (int)tx; ivector.push_back(ix);
tx = coord[5][0]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx=-coord[5][1]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx = coord[6][0]*d+kx; ix=(int)tx; ivector.push_back(ix);
tx=-coord[6][1]*d+kx; ix=(int)tx; ivector.push_back(ix);  } 

if (ivector.size()>0){
r=ivector[0]; g = ivector[1] ;b = ivector[2];
xa1=ivector[3]; ya1=ivector[4]; xa2= ivector[5]	; ya2=ivector[6];			  
 xa3=ivector[7]; ya3=ivector[8]; xa4= ivector[9]	; ya4=ivector[10];   }
 if (ivector.size()>15){
r1=ivector[11]; g1 = ivector[12] ;b1 = ivector[13];
xb1=ivector[14]; yb1=ivector[15]; xb2= ivector[16]	; yb2=ivector[17];			  
 xb3=ivector[18]; yb3=ivector[19]; xb4= ivector[20]	; yb4=ivector[21];   }
  if (ivector.size()>25){
r2=ivector[22]; g2 = ivector[23] ;b2 = ivector[24];
xc1=ivector[25]; yc1=ivector[26]; xc2= ivector[27]	; yc2=ivector[28];			  
 xc3=ivector[29]; yc3=ivector[30]; xc4= ivector[31]	; yc4=ivector[32];   }

for (int i = 0; i < ivector.size(); i++){ cout << ivector[i] << " " ;} cout<<"===\n";
for (int i=0; i<8; i++){for (int i2=0; i2<3; i2++){cout<<coord[i][i2]<<" ";} cout<<"\n";}
for (int i=0; i<8; i++){cout<<dist[i]<<"\n";} cout<<"\n\n\n";

HBRUSH hBrush = CreateSolidBrush(RGB(r, g, b)); //start drawing
HBRUSH hOldBrush = SelectBrush(hdc, hBrush);
POINT vertices[] = { {xa1, ya1},{xa2, ya2}, {xa3, ya3}, {xa4, ya4} };
Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));

 hBrush= CreateSolidBrush(RGB(r1, g1, b1));
 hOldBrush = SelectBrush(hdc, hBrush);
POINT vertices2[] =  { {xb1, yb1},{xb2, yb2}, {xb3, yb3}, {xb4, yb4} };
Polygon(hdc, vertices2, sizeof(vertices2) / sizeof(vertices2[0]));

 hBrush= CreateSolidBrush(RGB(r2, g2, b2));
 hOldBrush = SelectBrush(hdc, hBrush);
POINT vertices3[] =  { {xc1, yc1},{xc2, yc2}, {xc3, yc3}, {xc4, yc4} };
Polygon(hdc, vertices3, sizeof(vertices3) / sizeof(vertices3[0]));

re.top=0;
re.left=menux;
re.right=width;
re.bottom=height;
FillRect(hdc, &re, HBRUSH(CreateSolidBrush(RGB(212,208,200)))); //gray menu

DeleteObject(hBrush);
DeleteObject(hOldBrush);

ReleaseDC(hMainWnd, hdc);  
ValidateRect(hMainWnd, NULL);
ValidateRect(hMainWnd, NULL);
EndPaint(hMainWnd, &ps);

int x = height+5;
int y = 5;

static std::basic_string<TCHAR> text;
std::ostringstream strs;
strs << pitch;
text = strs.str();

CreateWindow(TEXT("STATIC"),TEXT("Pitch: "),  WS_VISIBLE | WS_CHILD,
  x,y,2*dm,dm-5,     hw,(HMENU)4,NULL,NULL  );
  x+=2*dm;
CreateWindow(TEXT("STATIC"),TEXT(text.c_str()),  WS_VISIBLE | WS_CHILD,
  x,y,2*dm,dm-5,     hw,(HMENU)4,NULL,NULL  ); 
  x=height+5;
  y+=dm;
 CreateWindow("button","-1",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
  x,y,dm,dm,hw,(HMENU)ID_MYBUTTON,NULL,NULL);
  x+=dm;
  CreateWindow("button","-10",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
  x,y,dm,dm,hw,(HMENU)ID_MYBUTTON2,NULL,NULL);
    x+=dm;
  CreateWindow("button","-60",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
  x,y,dm,dm,hw,(HMENU)ID_MYBUTTON3,NULL,NULL);
     x+=2*dm;
  CreateWindow("button","+1",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
  x,y,dm,dm,hw,(HMENU)ID_MYBUTTON4,NULL,NULL);
  x+=dm;
  CreateWindow("button","+10",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
  x,y,dm,dm,hw,(HMENU)ID_MYBUTTON5,NULL,NULL);
    x+=dm;
  CreateWindow("button","+60",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
  x,y,dm,dm,hw,(HMENU)ID_MYBUTTON6,NULL,NULL);
  
   x=height+5;
  y+=2*dm;
static std::basic_string<TCHAR> text2;
std::ostringstream strs2;
strs2 << roll;
text2 = strs2.str();
  CreateWindow(TEXT("STATIC"),TEXT("Roll: "),  WS_VISIBLE | WS_CHILD,
  x,y,2*dm,dm-5,     hw,(HMENU)4,NULL,NULL  );
  x+=2*dm;
CreateWindow(TEXT("STATIC"),TEXT(text2.c_str()),  WS_VISIBLE | WS_CHILD,
  x,y,2*dm,dm-5,     hw,(HMENU)4,NULL,NULL  ); 
  x=height+5;
  y+=dm;
CreateWindow("button","-1",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
  x,y,dm,dm,hw,(HMENU)ID_MYBUTTON10,NULL,NULL);
  x+=dm;
  CreateWindow("button","-10",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
  x,y,dm,dm,hw,(HMENU)ID_MYBUTTON20,NULL,NULL);
    x+=dm;
  CreateWindow("button","-60",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
  x,y,dm,dm,hw,(HMENU)ID_MYBUTTON30,NULL,NULL);
     x+=2*dm;
  CreateWindow("button","+1",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
  x,y,dm,dm,hw,(HMENU)ID_MYBUTTON40,NULL,NULL);
  x+=dm;
  CreateWindow("button","+10",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
  x,y,dm,dm,hw,(HMENU)ID_MYBUTTON50,NULL,NULL);
    x+=dm;
  CreateWindow("button","+60",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
  x,y,dm,dm,hw,(HMENU)ID_MYBUTTON60,NULL,NULL);  
  
    x=height+5;
  y+=2*dm;
static std::basic_string<TCHAR> text3;
std::ostringstream strs3;
strs3 << yaw;
text3 = strs3.str();
  CreateWindow(TEXT("STATIC"),TEXT("Yaw: "),  WS_VISIBLE | WS_CHILD,
  x,y,2*dm,dm-5,     hw,(HMENU)4,NULL,NULL  );
  x+=2*dm;
CreateWindow(TEXT("STATIC"),TEXT(text3.c_str()),  WS_VISIBLE | WS_CHILD,
  x,y,2*dm,dm-5,     hw,(HMENU)4,NULL,NULL  ); 
  x=height+5;
  y+=dm;
CreateWindow("button","-1",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
  x,y,dm,dm,hw,(HMENU)ID_MYBUTTON11,NULL,NULL);
  x+=dm;
  CreateWindow("button","-10",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
  x,y,dm,dm,hw,(HMENU)ID_MYBUTTON21,NULL,NULL);
    x+=dm;
  CreateWindow("button","-60",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
  x,y,dm,dm,hw,(HMENU)ID_MYBUTTON31,NULL,NULL);
     x+=2*dm;
  CreateWindow("button","+1",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
  x,y,dm,dm,hw,(HMENU)ID_MYBUTTON41,NULL,NULL);
  x+=dm;
  CreateWindow("button","+10",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
  x,y,dm,dm,hw,(HMENU)ID_MYBUTTON51,NULL,NULL);
    x+=dm;
  CreateWindow("button","+60",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
  x,y,dm,dm,hw,(HMENU)ID_MYBUTTON61,NULL,NULL); 
  
break;
}
      
       case WM_CHAR:  	   
if ((TCHAR)wp==0x1B){PostQuitMessage(0); break;} 
// if ((TCHAR)wp==VK_SPACE){PostQuitMessage(0); break;}
break;
      
  case WM_COMMAND:
  	    
   if (LOWORD(wp)==ID_MYBUTTON) {
pitch--;
go();
   return 0;
}

    if (LOWORD(wp)==ID_MYBUTTON2) {
pitch-=10;
go();
   return 0;
}

    if (LOWORD(wp)==ID_MYBUTTON3) {
pitch-=60;
go();
   return 0;
}

   if (LOWORD(wp)==ID_MYBUTTON4) {
pitch++;
go();
   return 0;
}

    if (LOWORD(wp)==ID_MYBUTTON5) {
pitch+=10;
go();
   return 0;
}

    if (LOWORD(wp)==ID_MYBUTTON6) {
pitch+=60;
go();
   return 0;
}

 if (LOWORD(wp)==ID_MYBUTTON10) {
roll--;
go();
   return 0;
}

    if (LOWORD(wp)==ID_MYBUTTON20) {
roll-=10;
go();
   return 0;
}

    if (LOWORD(wp)==ID_MYBUTTON30) {
roll-=60;
go();
   return 0;
}

   if (LOWORD(wp)==ID_MYBUTTON40) {
roll++;
go();
   return 0;
}

    if (LOWORD(wp)==ID_MYBUTTON50) {
roll+=10;
go();
   return 0;
}

    if (LOWORD(wp)==ID_MYBUTTON60) {
roll+=60;
go();
   return 0;
}

if (LOWORD(wp)==ID_MYBUTTON11) {
yaw--;
go();
   return 0;
}

    if (LOWORD(wp)==ID_MYBUTTON21) {
yaw-=10;
go();
   return 0;
}

    if (LOWORD(wp)==ID_MYBUTTON31) {
yaw-=60;
go();
   return 0;
}

   if (LOWORD(wp)==ID_MYBUTTON41) {
yaw++;
go();
   return 0;
}

    if (LOWORD(wp)==ID_MYBUTTON51) {
yaw+=10;
go();
   return 0;
}

    if (LOWORD(wp)==ID_MYBUTTON61) {
yaw+=60;
go();
   return 0;
}

  case WM_DESTROY:
   PostQuitMessage(0);
   return 0;
 }
 return DefWindowProc(hw,msg,wp,lp);
}
