// Code by OlegTim. In devcpp 4.9.9.2  add *.cpp to *.dev and compile.
//Tested on Win7_64 1024*768, console 80*56 symbols. Console IO depends on OS
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void setCursorPosition(int y, int x){
static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
std::cout.flush();
COORD coord = { (SHORT)x, (SHORT)y };
SetConsoleCursorPosition(hOut, coord);
}

vector <double> x1;
vector <double> y_1;
vector <double> x2;
vector <double> y2;
vector <char> c;
vector <double> k;
vector <double> b;
vector <int> k_ind;
vector <double> r;
vector <double> dist;
vector <char> cf;
vector<vector<char> >  scr;
vector<vector<char> >  scrprev;
double delta=0.001;
double distfactor=3;
double big_double = 99999999.0;
int symbols_in_line = 80; //columns num on screen
int lines_num = 56; //rows num on screen
double step = 1.0/(symbols_in_line/2);
int answ = 666;
double collideclose = 3.0;

void show(){
double k0;
k.clear();
b.clear();
k_ind.clear();
dist.clear();
cf.clear();
scr.clear();
for (int i=0; i<x1.size(); i++){
	if (y_1[i]>=0 ||	y2[i]>=0){
if (x1[i]==x2[i])	{x1[i]-=delta;}
k0 = (y2[i]-y_1[i])/(x2[i]-x1[i]);
k.push_back( k0 );
b.push_back( y_1[i]-k0*x1[i] );
k_ind.push_back(i);
	}
}

for(int i=0;i<symbols_in_line;i++){dist.push_back(big_double);}
for(int i=0;i<symbols_in_line;i++){cf.push_back(' ');}
for(int i=0;i<r.size();i++){//let's send rays
for(int j=0;j<k.size();j++){ 		
if ((r[i]-k[j])!=0){
double x,y;   					
x = b[j]/(r[i]-k[j]);
y=	r[i]*x;	

if(y>=0){//	
double xl,xr;
if (x1[k_ind[j]]<x2[k_ind[j]]){xl=x1[k_ind[j]]; xr=x2[k_ind[j]];}
else{xr=x1[k_ind[j]]; xl=x2[k_ind[j]];}	
if (x>=xl && x<=xr)						{		 
double dist_min = sqrt(x*x + y*y); 									
if (dist[i]>dist_min) {dist[i]=dist_min; cf[i] = c[k_ind[j]];}
   					  					 }
		 }//
}
		}	
		}

for(int i=0;i<lines_num;i++){
char tmp_char;
if (i<lines_num/2){tmp_char=' ';}else{tmp_char='-';}	
vector<char> v;	
for(int i=0;i<symbols_in_line;i++){v.push_back(tmp_char);}	
scr.push_back(v);
		}

for(int i=0;i<dist.size();i++){	
int a = (int) ((lines_num*distfactor)/  dist[i]) ;
for(int j=0;j<lines_num;j++){
		if (abs(lines_num/2 -j)<a){scr[j][i]=cf[i];}
		}			   
}

		
for(int i=0;i<lines_num;i++){
for(int j=0;j<symbols_in_line;j++){
if (scr[i][j]!=scrprev[i][j]){
   if (i==lines_num-1 && j==symbols_in_line-1){}else{
   scrprev[i][j]=scr[i][j];
   setCursorPosition(i, j);
   std::cout <<scr[i][j];
   			 			 }
				 }
		}
}
setCursorPosition(lines_num-1, symbols_in_line-1);	 
}//show end


void rotate(){
double co,si;	 
if (answ==4){co=0.921061; si=-0.389418;} else{co=0.921061; si=0.389418;} //for 22 degrees
for (int i=0;i<x1.size();i++){
double xt = x1[i];
x1[i] = xt*co - y_1[i]*si;
y_1[i] = xt*si + y_1[i]*co;
xt = x2[i];
x2[i] = xt*co - y2[i]*si;
y2[i] = xt*si + y2[i]*co;
}
show();
		 
}


void forward(){
double ahead = dist[dist.size()/2];	 
if (ahead>collideclose){
for (int i=0;i<x1.size();i++){
y_1[i] -=collideclose;
y2[i] -=collideclose;
} 
show();  						
}
}


void answf(){
if (answ==4 || answ==5) {rotate();	}
if (answ==2) {forward();}
	 }


int main() {
double d = -1.0;
for (int i=0;i<symbols_in_line/2;i++){
r.push_back(1/d);	
d+=	step;
	}
for(int i=r.size()-1;i>-1;i--){r.push_back(-r[i]);}	//creating sector of rays

for(int i=0;i<lines_num;i++){	
vector<char> v;	
for(int i=0;i<symbols_in_line;i++){v.push_back('`');}	
scrprev.push_back(v);
		}

x1.push_back(-30); y_1.push_back(30); x2.push_back(30); y2.push_back(30); c.push_back('*');
x1.push_back(-30); y_1.push_back(-30); x2.push_back(-30); y2.push_back(30); c.push_back('&');
x1.push_back(30); y_1.push_back(30); x2.push_back(30); y2.push_back(-30); c.push_back('^');
x1.push_back(-30); y_1.push_back(-30); x2.push_back(30); y2.push_back(-30); c.push_back('#');
x1.push_back(10); y_1.push_back(10); x2.push_back(20); y2.push_back(10); c.push_back('%');
x1.push_back(10); y_1.push_back(20); x2.push_back(20); y2.push_back(20); c.push_back('+');
x1.push_back(20); y_1.push_back(20); x2.push_back(20); y2.push_back(10); c.push_back('=');
x1.push_back(10); y_1.push_back(10); x2.push_back(10); y2.push_back(20); c.push_back('@');


cout<<"\n_ Ray casting 2.5 D ASCII v004 Win by OlegTim _\n\n";
cout<<"Adjust console, please (console IO depends on OS): \n";
cout<<symbols_in_line<<" symbols in line; "<<lines_num<<" lines\n";
cout<<"Monotype font is good, i.e. Lucida Console\n\n";
cout<<"Press '<' to turn left and '>' to turn right. \n";
cout<<"Press 'w' to move forward. \n";
cout<<"Press any key to start. \n";

while(!kbhit()){}
system("cls");		
show(); 			 

while(true){
if(kbhit()){ 		 
char choice = getch();
choice=tolower(choice);
switch(choice){ 
case 27: { exit(0); }	//esc
case 119: { answ=2; break;  }//w
case 44: { answ=4; break;  }//<
case 46: { answ=5; break;  }//>
default: { answ=666;  break;  }
}
if  (answ!=666) {answf();}
}}	
			
cout <<"\n"; system("pause");
return 0;
}
