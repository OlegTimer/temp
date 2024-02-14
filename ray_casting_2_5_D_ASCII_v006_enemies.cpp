// Code by OlegTim. In devcpp 4.9.9.2  add *.cpp to *.dev and compile.
//Tested on Win7_64 1024*768, console 80*56 symbols. Console IO depends on OS
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>
using namespace std;

#define PI 3.14159

vector <double> x1q;
vector <double> y_1q;
vector <double> x2q;
vector <double> y2q;
vector <char> cq;
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
double distfactor=1;
double big_double = 99999999.0;
int symbols_in_line = 80; //columns num on screen
int lines_num = 56; //rows num on screen
double step = 1.0/(symbols_in_line/2);
int answ = 777;
double collideclose = 0.25;
int angle = 0;
int anglestep = 5;
double plx=0;
double ply=0;
vector<vector<vector<char> > > texlist;
vector <int> spriteid;
vector <double> spritex;
vector <double> spritey;
vector<vector<char> >  sprite;
vector<vector<char> >  sprite2;
int scr_shift=(symbols_in_line-lines_num)/2;
double scr_coef = symbols_in_line/2; 
vector <double> distSprite;
int sleep = 20; //ms
double  sb = 0.007; //small bot step
int fin = 0;
int fire = 0;
int once = 0;
int score = 0;
int reload = 8; //tacts of show fire animation*sleep (ms) to total reload gun
int timerTime=sleep*10;
int timer=timerTime;

void setCursorPosition(int y, int x){
static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
std::cout.flush();
COORD coord = { (SHORT)x, (SHORT)y };
SetConsoleCursorPosition(hOut, coord);
}


void showwin(){	 
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
}



void spriteRemove(int a){
if 	 (a>=0 && a <spriteid.size()){
spriteid.erase(spriteid.begin() + a);
spritex.erase(spritex.begin() + a);
spritey.erase(spritey.begin() + a);
distSprite.erase(distSprite.begin() + a);
}
}


void decrease_more_one_less_two(int pix_del){ //arg is how many pixels we need to delete in h	 
	 										  		   	   if (pix_del>0){
int interv = pix_del;
interv = (int) (lines_num/interv);
int i2,j2;
i2=j2=0;
for (int i = 0; i<	lines_num; i++){	
	for (int j = 0; j<	lines_num; j++){
if (i%interv!=0 && j%interv!=0) {sprite2[i2][j2]=sprite[i][j]; j2++; }
   			   }
if (i%interv!=0 )  {i2++; j2=0;} 			   
   			}

for (int i=0;i<lines_num; i++){for (int j=0;j<lines_num; j++){sprite[i][j]='`';}}

for (int i=0;i<lines_num; i++){for (int j=0;j<lines_num; j++){
if (sprite2[i][j]!='`')	{sprite[i+pix_del/2][j+pix_del/2]=sprite2[i][j];}
	}}
	  																	 }
}


void decrease_twice(){
char c1, c2, c3, c4;
c1=c2=c3=c4='`';
for (int i = 0; i<	lines_num; i+=2){
	for (int j = 0; j<	lines_num; j+=2){
c1=sprite[i][j];
c2=sprite[i][j+1];
c3=sprite[i+1][j];
c4=sprite[i+1][j+1];
int count1, count2, count3,count4;
count1= count2= count3=count4=1;
if (c1==c2){count1++;} if (c1==c3){count1++;} if (c1==c4){count1++;}
if (c2==c1){count2++;} if (c2==c3){count2++;} if (c2==c4){count2++;}
if (c3==c1){count3++;} if (c3==c2){count3++;} if (c4==c4){count3++;}
if (c4==c1){count4++;} if (c4==c2){count4++;} if (c4==c3){count4++;}
if (count1>=2){}else{if (count2>=2){c1=c2;}else{if (count3>=2){c1=c3;}
else{if (count4>=2){c1=c4;}else{}}}}
sprite2[i/2][j/2]=c1;
}}

for (int i=0;i<lines_num; i++){for (int j=0;j<lines_num; j++){sprite[i][j]='`';}}

for (int i=lines_num/4;i<lines_num; i++){for (int j=lines_num/4;j<lines_num; j++){
if	(sprite2[i-lines_num/4][j-lines_num/4]!='`')
{sprite[i][j]=sprite2[i-lines_num/4][j-lines_num/4];}
}}		 
}//dec twice end


void decrease(int a)//Changes sprite. a is a needed pixel height of sprite
{
 	 			  			  if (a<lines_num){
if (a>lines_num/2){// if decrease_more_one_less_two start
decrease_more_one_less_two(lines_num-a);  				   
}// if decrease_more_one_less_two end
else{ //if decrease_twice start
int tempa = lines_num;
while (tempa/a>=2){
decrease_twice();
tempa=tempa/2;	  
	  }
decrease_more_one_less_two(tempa-a);  		  
}//if decrease_twice end
	  				 				  		   }	 
}


void showsprite(){
vector<vector<double> >  vec; 	 
for(int r=0;r<spriteid.size();r++){	 	 	 
double angle_sprite = atan2(spritex[r] - plx, spritey[r]- ply );
angle_sprite-=angle/57.3; 
while (angle_sprite < -PI) {angle_sprite += 2*PI;}	
while (angle_sprite >  PI) {angle_sprite -= 2*PI; }
//angle from PI/4 till -PI/4 OR 0.785 till -0.785 rad OR 45 grad till -45 grad
if (abs(angle_sprite)<1.57)				{
vector<double> v;   				   
double dis = distSprite[r];    				   
v.push_back(dis); 
v.push_back(spriteid[r]); 
v.push_back(angle_sprite); 
v.push_back(r); 
vec.push_back(v);					   
									   				} 
}

sort (vec.begin(), vec.end()); 
int deleteSpriteNum=-1;

for (int p = vec.size()-1; p>-1; p--){
int r = (int) (vec[p][1]);
for (int i = 0; i<	lines_num; i++){
for (int j = 0; j<	lines_num; j++){
sprite[i][j]=texlist[r][i][j]; sprite2[i][j]='`'; 
}}
int a = (int) ((lines_num*distfactor)/(vec[p][0])) ;
decrease(a);
//
for (int i = 0; i<lines_num; i++){
int col = (int) (i+  vec[p][2]*scr_coef+scr_shift);
if (col>=0 && col <symbols_in_line)						{
		   if (vec[p][0]<dist[col])					{ //--

if (r==1){
if (plx>spritex[vec[p][3]]) {spritex[vec[p][3]]+=sb*collideclose;} 
else{spritex[vec[p][3]]-=sb*collideclose;}   		  
if (ply>spritey[vec[p][3]]) {spritey[vec[p][3]]+=sb*collideclose;} 
else{spritey[vec[p][3]]-=sb*collideclose;}
if (col==symbols_in_line/2 && vec[p][0]<collideclose*60){deleteSpriteNum = (int) (vec[p][3]);}
}
		   	  										
	for (int j = 0; j<lines_num; j++){
if (sprite[j][i]!='`') {scr[j][col]=sprite[j][i];}}
   					   							   	} //--
   					   							  	 	}
}	
//	
}

if (fire>0){
fire--; 
if (fire>(reload-1)*sleep){ 
for(int i=lines_num-lines_num/28;i<lines_num;i++){
for(int j=symbols_in_line*0.45;j<symbols_in_line*0.55;j++){ scr[i][j] ='*';		}}
for(int i=lines_num-2*lines_num/28;i<lines_num-1*lines_num/28;i++){
for(int j=symbols_in_line*0.40;j<symbols_in_line*0.60;j++){ scr[i][j] ='*';		}}		
for(int i=lines_num-4*lines_num/28;i<lines_num-3*lines_num/28;i++){
for(int j=symbols_in_line*0.35;j<symbols_in_line*0.65;j++){ scr[i][j] ='*';		}}
for(int i=lines_num-6*lines_num/28;i<lines_num-5*lines_num/28;i++){
for(int j=symbols_in_line*0.25;j<symbols_in_line*0.75;j++){ scr[i][j] ='*';		}}
if (once==0 && deleteSpriteNum>-1) {char ch=7;cout<<ch; once++; score++; spriteRemove(deleteSpriteNum);  }			 			 
}}
	
showwin();
}


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

for(int i=0;i<symbols_in_line;i++){	
int a = (int) ((lines_num*distfactor)/  dist[i]) ;
for(int j=0;j<lines_num;j++){
		if (abs(lines_num/2 -j)<a){scr[j][i]=cf[i];}
		}			   
}

if (answ!=0 && answ!=1 && answ!=2){answ=777; showsprite();}
//showwin();			 
}//show end


void draw(){
double co,si;
co = cos(angle/57.3);
si = sin(angle/57.3);

for (int i=0;i<x1q.size();i++){
x1[i] = x1q[i]	 -plx;
y_1[i] = y_1q[i] -ply;
x2[i] = x2q[i]	 -plx;
y2[i] = y2q[i]   -ply;
	}

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


void analyze(){
draw();
}


void rotate(){	 
if (answ==4){angle-=anglestep;}
if (answ==5){angle+=anglestep;} 
if (angle<0){angle=359+angle;}
if (angle>359) {angle = angle - 360;}
analyze();	 
}


int checkclosesprites(){
int close=0;	 
vector <double> distSprite2;
double plx2 = plx+ collideclose*sin(angle/57.3);
double ply2 = ply+ collideclose*cos(angle/57.3);
for(int r=0;r<spriteid.size();r++){	 	 	  				   
double dis = sqrt((ply2-spritey[r])*(ply2-spritey[r]) + (plx2-spritex[r])*(plx2-spritex[r])); 
if (dis<collideclose*2.1){ if (spriteid[r]==1){fin=1;} close++;break; }
distSprite2.push_back(dis);
}	 

if (close==0){
for (int i = 0; i<distSprite.size();i++){distSprite[i]=distSprite2[i];}	
}
return close;	
}


void forward(){
int close=checkclosesprites();	 
if (close==0){		  
//sprites are not close; check walls 
if (dist[0]> collideclose*2.1 && dist[symbols_in_line/2]> collideclose*2.1 
&& dist[symbols_in_line-1]> collideclose*2.1 )
   { 			  
plx += collideclose*sin(angle/57.3);
ply += collideclose*cos(angle/57.3);
	}
}

analyze();
}


void backward(){
angle+=180;	 
rotate();
forward();
angle+=180;
answ=777;	 
rotate();
}


void stepright(){
angle+=90;	 
rotate();
forward();
angle-=90;
answ=777;	 
rotate();	 
}

void stepleft(){
angle-=90;	 
rotate();
forward();
angle+=90;
answ=777;	 
rotate();	 
}


void firef(){
if (fire<=0) {once=0; fire=reload*sleep; rotate();} 
else{answ=777;checkclosesprites(); analyze();}
}


void turn180(){
angle+=180;	 
rotate();	 
}

void answf(){
if (answ==4 || answ==5) {rotate();	}
if (answ==3) {forward();}
if (answ==2) {backward();}
if (answ==1) {stepright();}
if (answ==0) {stepleft();}
if (answ==32) {firef(); }
if (answ==47) {turn180(); }
if (answ==777) {checkclosesprites(); analyze();}
}


void worldMove(){
timer--;
if (timer<=0){
timer=timerTime;
if (spriteid.size()<8){
struct tm *ptr;
time_t lt = time('\0'); 
int rand=lt%10; 
int xr,yr; xr=yr=0;
if (rand==1 || rand==5){xr=18; yr=18;}
if (rand==2 || rand==6){xr=-18; yr=-18;}
if (rand==3 || rand==7){xr=-18; yr=18;}
if (rand==4 || rand==8){xr=19; yr=-19;}
double dis = sqrt((ply-yr)*(ply-yr) + (plx-xr)*(plx-xr)); 
if (dis>collideclose*75)		{  					   
spriteid.push_back(1); spritex.push_back(xr);	spritey.push_back(yr);
distSprite.push_back(big_double);
								 }
}
}	 
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

x1q.push_back(-20); y_1q.push_back(20); x2q.push_back(20); y2q.push_back(20); cq.push_back('[');
x1q.push_back(-20); y_1q.push_back(-20); x2q.push_back(-20); y2q.push_back(20); cq.push_back('#');
x1q.push_back(20); y_1q.push_back(20); x2q.push_back(20); y2q.push_back(-20); cq.push_back('|');
x1q.push_back(-20); y_1q.push_back(-20); x2q.push_back(20); y2q.push_back(-20); cq.push_back(']');

x1q.push_back(5); y_1q.push_back(5); x2q.push_back(5); y2q.push_back(15); cq.push_back('(');
x1q.push_back(5); y_1q.push_back(15); x2q.push_back(15); y2q.push_back(15); cq.push_back(')');
x1q.push_back(15); y_1q.push_back(15); x2q.push_back(15); y2q.push_back(5); cq.push_back('/');
x1q.push_back(5); y_1q.push_back(5); x2q.push_back(15); y2q.push_back(5); cq.push_back('\\');

x1q.push_back(-15); y_1q.push_back(-5); x2q.push_back(-15); y2q.push_back(15); cq.push_back('@');
x1q.push_back(-15); y_1q.push_back(15); x2q.push_back(-5); y2q.push_back(15); cq.push_back('$');
x1q.push_back(-5); y_1q.push_back(15); x2q.push_back(-5); y2q.push_back(5); cq.push_back('%');
x1q.push_back(-15); y_1q.push_back(-5); x2q.push_back(-5); y2q.push_back(5); cq.push_back('<');

x1q.push_back(-15); y_1q.push_back(-15); x2q.push_back(-5); y2q.push_back(-5); cq.push_back('&');
x1q.push_back(-5); y_1q.push_back(-5); x2q.push_back(-5); y2q.push_back(-15); cq.push_back('^');
x1q.push_back(-15); y_1q.push_back(-15); x2q.push_back(-5); y2q.push_back(-15); cq.push_back('>');

x1q.push_back(5); y_1q.push_back(-5); x2q.push_back(15); y2q.push_back(-5); cq.push_back('+');
x1q.push_back(5); y_1q.push_back(-5); x2q.push_back(5); y2q.push_back(-15); cq.push_back('~');
x1q.push_back(5); y_1q.push_back(-15); x2q.push_back(15); y2q.push_back(-5); cq.push_back('}');

for (int i=0;i<x1q.size();i++){
x1.push_back(x1q[i]);
y_1.push_back(y_1q[i]);
x2.push_back(x2q[i]);
y2.push_back(y2q[i]);
c.push_back(cq[i]);	
	}

vector<vector<char> >  spritet;	
for (int i = 0; i<	lines_num; i++){
	vector<char> v;
	for (int j = 0; j<	lines_num; j++){
 v.push_back('`');
		}
	spritet.push_back(v);	
	}	
texlist.push_back(spritet);

for (int i = 0; i<lines_num; i++){for (int j = 0; j<lines_num; j++){spritet[i][j]='`'; }}
for(int i=lines_num*0.125; i<lines_num*0.875; i++){
		for(int j=lines_num*0.25; j<lines_num*0.75; j++){spritet[i][j]='o';}}
for(int i=lines_num*0.375; i<lines_num*0.625; i++){for(int j=0; j<lines_num; j++){spritet[i][j]='o';}}
for(int i=lines_num*0.25; i<lines_num*0.75; i++){
		for(int j=lines_num*0.125; j<lines_num* 0.875; j++){spritet[i][j]='o';}}		
texlist.push_back(spritet);

for (int i = 0; i<lines_num; i++){for (int j = 0; j<lines_num; j++){spritet[i][j]='`'; }}
for(int i=0; i<lines_num; i++){
		for(int j=lines_num*0.4; j<lines_num*0.6; j++){spritet[i][j]='!';}}
for(int i=0; i<lines_num*0.35; i++){
		for(int j=lines_num*0.4; j<lines_num*0.6; j++){spritet[i][j]='.';}}		
for(int i=lines_num*0.1; i<lines_num*0.25; i++){
		for(int j=lines_num*0.25; j<lines_num* 0.75; j++){spritet[i][j]='.';}}
for(int i=lines_num*0.05; i<lines_num*0.3; i++){
		for(int j=lines_num*0.35; j<lines_num* 0.65; j++){spritet[i][j]='.';}}		
texlist.push_back(spritet);

for (int i = 0; i<	lines_num; i++){
	vector<char> v;
	for (int j = 0; j<	lines_num; j++){
	v.push_back('`');
		}
sprite.push_back(v); sprite2.push_back(v);
	}
	
spriteid.push_back(2); spritex.push_back(15);	spritey.push_back(-15);		
spriteid.push_back(1); spritex.push_back(4);	spritey.push_back(19);

for(int r=0;r<spriteid.size();r++){	 	 	  				   
double dis = sqrt((ply-spritey[r])*(ply-spritey[r]) + (plx-spritex[r])*(plx-spritex[r])); 
distSprite.push_back(dis);
}

cout<<"_ Ray casting 2.5 D ASCII v006 Win by OlegTim _\n\n";
cout<<"Adjust console, please (console IO depends on OS): \n";
cout<<symbols_in_line<<" symbols in line; "<<lines_num<<" lines\n";
cout<<"Monotype font is good, i.e. Lucida Console\n\n";
cout<<"Press '<' to turn left and '>' to turn right. \n";
cout<<"Press '/' or on some keyboards '?' to turn 180\n";
cout<<"Press 'w' to move forward; 's' backward. \n";
cout<<"Press 'a' to step left; 'd' to step right. \n";
cout<<"Avoid balls of 'o'.\n";
cout<<"<Space> to shoot balls for points, takes time to reload.\n";
cout<<"<Esc> to quit.\n";
cout<<"\nPress any key to start.\n";

while(!kbhit()){}
system("cls");		
analyze();		 

while(fin==0){			  
if(kbhit()){ 		 
char choice = getch();
choice=tolower(choice);
switch(choice){ 
case 27: { fin=1; break; }	//esc
case 97: { answ=0; break;  }//a
case 100: { answ=1; break;  }//d
case 115: { answ=2; break;  }//s
case 119: { answ=3; break;  }//w
case 44: { answ=4; break;  }//<
case 46: { answ=5; break;  }//>
case 32: { answ=32; break;  }//space
case 47: { answ=47; break;  }// / or ?
default: { answ=777;  break;  }
}
}
Sleep(sleep);
worldMove();
answf();
}	

system("cls");	
cout <<"\n\nGame over. \nYour score is: "<<score;
cout <<"\n\nPress 'Esc' to quit\n";
while(true){
if(kbhit()){ 		 
char choice = getch();
choice=tolower(choice);
switch(choice){ 
case 27: { exit(0); }	//esc
default: {   break;  }
}}}
			
cout <<"\n"; system("pause");
return 0;
}
