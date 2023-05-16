#include <windows.h>
#include <windowsx.h>
#include <CommCtrl.h>
#include <math.h>
#include <sstream>
#include <string>
#include <iostream>
#include <vector> 
using namespace std;

// Code by OlegTim. Tested on Win7X64,  1024*768, fullscreen and windowed
//devcpp 4.9.9.2  tools -compiler options - settings- linker - create console - (try n)
//  tools - compiler options - compiler - add this to linker cmd -lgdi32 

int pitch=45;
int roll=0;
int yaw =45;
int d = 150; //cube size
int sx=2*d; int sy=2*d;
int dm = 25; //menu line height
  int width = 1024;
  int height = 768;
 
HINSTANCE hInstance;
HWND hwnd;
HWND pitch_edit; 
HWND roll_edit; 
HWND  jaw_edit;
HWND track_pitch;
HWND track_roll;
HWND track_yaw;

int r,g,b,r1,g1,b1,r2,g2,b2; 
int xa1,xa2,xa3,xa4,xb1,xb2,xb3,xb4,xc1,xc2,xc3,xc4;
int ya1,ya2,ya3,ya4,yb1,yb2,yb3,yb4,yc1,yc2,yc3,yc4;

void showinfo(){
MessageBox(hwnd,"Press <Enter> or 'show' to apply. <Esc> to quit.\n\
M and < to pitch. > and ? to roll.\n\
Tab/Caps for jaw.\n",
"info",MB_OK); 	 
	 }

void cal(){
int kx=2*d; int ky=2*d;	 
r=g=b=r1=g1=b1=r2=g2=b2=0;
xa1=xa2=xa3=xa4=xb1=xb2=xb3=xb4=xc1=xc2=xc3=xc4=0;
ya1=ya2=ya3=ya4=yb1=yb2=yb3=yb4=yc1=yc2=yc3=yc4=0;

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
	 }

void go2(){
	 std::basic_string<TCHAR> text;
if (pitch <-719|| pitch>719) {pitch = 0;} 
if (pitch <0) {pitch = 360+pitch;} 
if (pitch >359) {pitch = pitch-360;} 
std::ostringstream strs;
strs << pitch;
 text = strs.str(); 
 SetWindowText(pitch_edit, text.c_str()); 
 
 std::basic_string<TCHAR> text3;
if (roll <-719|| roll>719) {roll = 0;} 
if (roll <0) {roll = 360+roll;} 
if (roll >359) {roll = roll-360;} 
std::ostringstream strs3;
strs3 << roll;
 text3 = strs3.str(); 
 SetWindowText(roll_edit, text3.c_str()); 
 
  	 std::basic_string<TCHAR> text2;
if (yaw <-719|| yaw>719) {yaw = 0;} 
if (yaw <0) {yaw = 360+yaw;} 
if (yaw >359) {yaw = yaw-360;} 
std::ostringstream strs2;
strs2 << yaw;
 text2 = strs2.str(); 
 SetWindowText(jaw_edit, text2.c_str()); 
 
 SendMessage(track_pitch, TBM_SETPOS, TRUE, pitch);
 SendMessage(track_roll, TBM_SETPOS, TRUE, roll);
 SendMessage(track_yaw, TBM_SETPOS, TRUE, yaw);
cal(); 
RedrawWindow(hwnd,NULL,NULL,RDW_INVALIDATE );
SetFocus(hwnd);	 
	 }

void go(){
	 std::basic_string<TCHAR> text;
TCHAR buff[1024] = {0};
GetWindowText(pitch_edit, buff, 1024); 
text = buff;  
pitch = atoi(text.c_str());
if (pitch <-719|| pitch>719) {pitch = 0;} 
if (pitch <0) {pitch = 360+pitch;} 
if (pitch >359) {pitch = pitch-360;} 
std::ostringstream strs;
strs << pitch;
 text = strs.str(); 
 SetWindowText(pitch_edit, text.c_str()); 
 
 std::basic_string<TCHAR> text3;
TCHAR buff3[1024] = {0};
GetWindowText(roll_edit, buff3, 1024); 
text3 = buff3;  
roll = atoi(text3.c_str());
if (roll <-719|| roll>719) {roll = 0;} 
if (roll <0) {roll = 360+roll;} 
if (roll >359) {roll = roll-360;} 
std::ostringstream strs3;
strs3 << roll;
 text3 = strs3.str(); 
 SetWindowText(roll_edit, text3.c_str()); 
 
  	 std::basic_string<TCHAR> text2;
TCHAR buff2[1024] = {0};
GetWindowText(jaw_edit, buff2, 1024); 
text2 = buff2;  
yaw = atoi(text2.c_str());
if (yaw <-719|| yaw>719) {yaw = 0;} 
if (yaw <0) {yaw = 360+yaw;} 
if (yaw >359) {yaw = yaw-360;} 
std::ostringstream strs2;
strs2 << yaw;
 text2 = strs2.str(); 
 SetWindowText(jaw_edit, text2.c_str()); 
 
 SendMessage(track_pitch, TBM_SETPOS, TRUE, pitch);
 SendMessage(track_roll, TBM_SETPOS, TRUE, roll);
 SendMessage(track_yaw, TBM_SETPOS, TRUE, yaw);
cal(); 
RedrawWindow(hwnd,NULL,NULL,RDW_INVALIDATE );
SetFocus(hwnd);	 
	 }
 
 
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM LParam) {
  
    switch (msg) {
		   
		   case WM_HSCROLL:
        {   	  //
if((HWND)LParam == track_yaw ) { 
 int  dwPos = SendMessage(track_yaw, TBM_GETPOS, 0, 0);
if (dwPos!=yaw) {yaw = dwPos;   go2();	 }
        break ;
		}
		if((HWND)LParam == track_roll) { 
 int  dwPos = SendMessage(track_roll, TBM_GETPOS, 0, 0);
if (dwPos!=roll) {roll = dwPos;   go2();	 }
        break ;
		}
		if((HWND)LParam == track_pitch ) { 
 int  dwPos = SendMessage(track_pitch, TBM_GETPOS, 0, 0);
if (dwPos!=pitch) {pitch = dwPos;   go2();	 }
        break ;
		}
    }//
		   		   
case WM_KEYDOWN:
	 switch(wParam)	
	 { 
case VK_TAB: yaw++; go2();  break;
case VK_CAPITAL: yaw--; go2();  break;
case 0X4D: pitch--; go2();  break;
case 0XBC: pitch++; go2();  break;
case 0XBE: roll--; go2();  break;
case 0XBF: roll++; go2();  break;
					   }    
break;	   
		   
    case WM_COMMAND:
        if (wParam == 100) {
go();	
        }
         if (wParam == 101) {
showinfo();	
        }
        break;

    case WM_PAINT:
       {
        PAINTSTRUCT ps;
    HDC hdc;
    HBRUSH hBrush; 
        hdc = BeginPaint(hWnd, &ps);
        
HDC memDC = CreateCompatibleDC( hdc );
RECT rcClientRect;
        GetClientRect( hwnd, &rcClientRect );
    HBITMAP bmp = CreateCompatibleBitmap( hdc, 
            rcClientRect.right - rcClientRect.left, 
            rcClientRect.bottom - rcClientRect.top );
			 HBITMAP oldBmp = (HBITMAP)SelectObject( memDC, bmp );		        
       
RECT re;

re.top=0;
re.left=0;
re.right=width;
re.bottom=height;
FillRect(memDC, &re, HBRUSH(CreateSolidBrush(RGB(212,208,200)))); 

re.top=0;
re.left=0;
re.right=height;
re.bottom=height;
FillRect(memDC, &re, HBRUSH(CreateSolidBrush(RGB(165,75,165)))); //violet


HPEN hPen=CreatePen(PS_NULL, 3, RGB(0, 0, 0));
SelectObject(memDC, hPen);
 hBrush = CreateSolidBrush(RGB(r, g, b)); //start drawing
HBRUSH hOldBrush = SelectBrush(memDC, hBrush);
POINT vertices[] = { {xa1, ya1},{xa2, ya2}, {xa3, ya3}, {xa4, ya4} };
Polygon(memDC, vertices, sizeof(vertices) / sizeof(vertices[0]));

 hBrush= CreateSolidBrush(RGB(r1, g1, b1));
 hOldBrush = SelectBrush(memDC, hBrush);
POINT vertices2[] =  { {xb1, yb1},{xb2, yb2}, {xb3, yb3}, {xb4, yb4} };
Polygon(memDC, vertices2, sizeof(vertices2) / sizeof(vertices2[0]));

 hBrush= CreateSolidBrush(RGB(r2, g2, b2));
 hOldBrush = SelectBrush(memDC, hBrush);
POINT vertices3[] =  { {xc1, yc1},{xc2, yc2}, {xc3, yc3}, {xc4, yc4} };
Polygon(memDC, vertices3, sizeof(vertices3) / sizeof(vertices3[0]));

BitBlt( hdc, 0, 0, rcClientRect.right - rcClientRect.left, 
            rcClientRect.bottom - rcClientRect.top, memDC, 0, 0, SRCCOPY );
SelectObject( memDC, oldBmp );
        DeleteObject( bmp ); 
        DeleteDC( memDC );            

DeleteObject(hPen); 
DeleteObject(hBrush);
DeleteObject(hOldBrush);
ReleaseDC(hwnd, hdc);  
        EndPaint(hWnd, &ps);
        }
        break;
 
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hWnd, msg, wParam, LParam);
}
 
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE h2, LPSTR cmd, int cmShow) {
    WNDCLASS wc = {0};
    wc.lpszClassName = TEXT("Myclass");
    wc.lpfnWndProc = WndProc;
    wc.hbrBackground = CreateSolidBrush(RGB(212, 208, 200));
    wc.hCursor=LoadCursor(NULL,IDC_ARROW); 
    RegisterClass(&wc);
 
 hwnd = CreateWindow(wc.lpszClassName,"Cube_rotate_v2_by_OlegTim",
 WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0,0,width,height,0,0,hInstance,0);

SetWindowPos(hwnd, HWND_TOP, 0, 0, GetSystemMetrics(SM_CXSCREEN), //fullscreen w tab
GetSystemMetrics(SM_CYSCREEN), SWP_FRAMECHANGED); 
/*
WINDOWPLACEMENT wpc; //fullscreen without tab and borders
GetWindowPlacement(hwnd,&wpc);
                SetWindowLong(hwnd,GWL_STYLE,WS_POPUP);
                SetWindowLong(hwnd,GWL_EXSTYLE,WS_EX_TOPMOST);
                ShowWindow(hwnd,SW_SHOWMAXIMIZED);
*/

RECT rect; 
if(GetWindowRect(hwnd, &rect))
{
   width = rect.right - rect.left;
   height = rect.bottom - rect.top;
}

int x = height+5;
int y = 5;

HWND hwndButton = CreateWindow("BUTTON", "show", 
WS_CHILD | WS_VISIBLE, x, y, dm*2, dm, hwnd, (HMENU)100, hInstance, 0);
y+=dm+20;

CreateWindow(TEXT("STATIC"),TEXT("Pitch: "),  WS_VISIBLE | WS_CHILD,
  x,y,2*dm,dm-5,     hwnd,(HMENU)4,NULL,NULL  );
  x+=3*dm; 
 std::basic_string<TCHAR> text;
std::ostringstream strs;
strs << pitch;
text = strs.str();  
 pitch_edit=CreateWindow(TEXT("edit"),TEXT(text.c_str()), 
        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
        x,y,50,dm,hwnd,(HMENU)5,NULL,NULL );
y+=dm+20;  x = height+5;
track_pitch = CreateWindowEx(0, TRACKBAR_CLASS, NULL,
    WS_CHILD | WS_VISIBLE | TBS_AUTOTICKS,  x, y, 8*dm, dm,
    hwnd, NULL, hInstance, NULL);    
SendMessage(track_pitch, TBM_SETRANGE, (WPARAM) TRUE,  (LPARAM) MAKELONG(0, 359));
y+=dm+20;  x = height+5;

CreateWindow(TEXT("STATIC"),TEXT("Roll: "),  WS_VISIBLE | WS_CHILD,
  x,y,2*dm,dm-5,     hwnd,(HMENU)6,NULL,NULL  );
  x+=3*dm; 
 std::basic_string<TCHAR> text3;
std::ostringstream strs3;
strs3 << roll;
text3 = strs3.str();  
 roll_edit=CreateWindow(TEXT("edit"),TEXT(text3.c_str()), 
        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
        x,y,50,dm,hwnd,(HMENU)7,NULL,NULL );
y+=dm+20;  x = height+5;  
track_roll = CreateWindowEx(0, TRACKBAR_CLASS, NULL,
    WS_CHILD | WS_VISIBLE | TBS_AUTOTICKS,  x, y, 8*dm, dm,
    hwnd, NULL, hInstance, NULL);    
SendMessage(track_roll, TBM_SETRANGE, (WPARAM) TRUE,  (LPARAM) MAKELONG(0, 359));
y+=dm+20;  x = height+5;

CreateWindow(TEXT("STATIC"),TEXT("Yaw: "),  WS_VISIBLE | WS_CHILD,
  x,y,2*dm,dm-5,     hwnd,(HMENU)8,NULL,NULL  );
  x+=3*dm; 
 std::basic_string<TCHAR> text2;
std::ostringstream strs2;
strs2 << yaw;
text2 = strs2.str();  
 jaw_edit=CreateWindow(TEXT("edit"),TEXT(text2.c_str()), 
        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
        x,y,50,dm,hwnd,(HMENU)9,NULL,NULL );
y+=dm+20;  x = height+5;    

// InitCommonControls();  // do, if Comctl32.dll version < 6.0
track_yaw = CreateWindowEx(0, TRACKBAR_CLASS, NULL,
    WS_CHILD | WS_VISIBLE | TBS_AUTOTICKS,  x, y, 8*dm, dm,
    hwnd, NULL, hInstance, NULL);    
SendMessage(track_yaw, TBM_SETRANGE, (WPARAM) TRUE,  (LPARAM) MAKELONG(0, 359));

y=height-4*dm;  x = height+5;  
HWND hwndButton2 = CreateWindow("BUTTON", "info", 
WS_CHILD | WS_VISIBLE, x, y, dm*2, dm, hwnd, (HMENU)101, hInstance, 0);

go2();//to show on first run                
  MSG msg;
    while (GetMessage(&msg, NULL , 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
           if(msg.message==WM_KEYDOWN)
             {
                   if(msg.wParam==VK_ESCAPE)
                   {
                        PostQuitMessage(0);
                   }
				   if(msg.wParam==VK_RETURN)
                                       {
									   		go();  
									   		}
				   }
        
    }
    return 0;
}
