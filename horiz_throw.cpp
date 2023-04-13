#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <math.h>
#include <vector> 
#include <iostream>
#include <fstream>
#include <string> 
using namespace std;
//tested on Win7
double margin=1; // in m,  half-distance from target point
double tx=13; //target x
double ty=6; //target y
double angle=45;  	//degrees  
double  h= 0 ; //start h, meters
double delta = 0.1; //step, sec
double density = 1.23; //1.23 kg/m^3 on sea lvl for air
double s = 0.0314; //square meters front projection
double c = 0.4; //drag factor
double g = 9.81; // 9.81 for Earth
double m = 0.15; //kg
double v= 20 ; //  m/s
double vinit=0;
double vx=0; 
double x=0; 
double y=0; 
double t=0; 
double impact_speed=0;
double maxh=0;
double tot= -1; //time on target
vector <double> vec;

int console_line_length = 80;
int console_line_num = 47; //plus 10 to text out
int option = 0;

double getval(){
char str[20];
double x;
gets(str);
x=atof(str);
return x;	
	}
	
void typeparam(){
do{
cout<<"\nType angle in degrees (0.0-90.0): \n";
angle = getval();
}while(angle>90||angle<0);

do{
cout<<"Type start speed in m/s <10 m/s is 36 km/h> (0.0-300.0): \n";
v = getval();
}while(h>300||h<0);

do{
cout<<"Type delta step in seconds <0.1 is ok> (0.001-10.0): \n";
delta = getval();
}while(delta>10||delta<0.001);

do{
cout<<"Type air density in kg*m^3 <1.23 sea level> (0.0-1000.0): \n";
density = getval();
}while(density>1000||density<0);

do{
cout<<"Type front_projection in m^2 <if r=0.1 m, f=0.0314 m^2 > (0.0-100.0): \n";
s = getval();
}while(s>100||s<0);

do{
cout<<"Type drag factor, please. \n";
cout<<"<Disk, surface to stream: 1.17 >\n";
cout<<"<Half-sphere, base to stream: 1.17 >\n";
cout<<"<Cube, side to stream: 1.05 >\n";
cout<<"<Cylinder, base to stream: 0.82 >\n";
cout<<"<Cube, edge to stream: 0.8 >\n";
cout<<"<Cone, sharp to stream: 0.5 >\n";
cout<<"<Sphere: 0.47 >\n";
cout<<"<Half-sphere, spherical to stream: 0.38 >\n";
cout<<"<Drop, fat side to stream: 0.04 >\n";
cout<<"Type drag factor <0 to ignore air drag> (0.0-10.0): \n";
c = getval();
}while(c>10||c<0);

do{
cout<<"Type g <9.81 for Earth> (0.0-100.0): \n";
g = getval();
}while(g>100||g<0);

do{
cout<<"Type mass in kg (0.001-1000.0): \n";
m= getval();
}while(m>1000||m<0.001);

do{
cout<<"Type start height in meters (0.0-1000.0): \n";
h = getval();
}while(h>1000||h<0); 

do{
cout<<"Type margin to target in meters <1 is good>(0-100.0): \n";
margin = getval();
}while(margin>100||margin<0);

do{
cout<<"Type OX target in meters (0-100000.0): \n";
tx = getval();
}while(tx>100000||tx<0);

do{
cout<<"Type OY target in meters (0-100000.0): \n";
ty = getval();
}while(ty>100000||ty<0);

cout<<"____________________________________________________________\n\n\n"; 	 
	 }	// typeparam end
	 
void count(){
angle =angle/57.3; //to radian 
vinit = v;
vx =v*cos(angle);
v =v*sin(angle);
y+=h;

double f,a,fx,ax,yabs,xabs;
while (y>=0){
yabs = v; 
if (v<0){yabs=-yabs;}	  
f = -density*yabs*v*c*s/2;
a=-g+f/m;
y=y+v*delta+a*delta*delta/2;
if (y>maxh){maxh=y;}
v=v+a*delta;

xabs = vx; 
if (vx<0){xabs=-xabs;}
fx = -density*xabs*vx*c*s/2;
ax=fx/m;
x=x+vx*delta+ax*delta*delta/2;
vx=vx+ax*delta;
 if (angle>1.55323 ||vinit==0){vx=0; x=0; } // for 90 deg and zero speed

if (x<tx+margin && x>tx-margin && y<ty+margin && y>ty-margin){tot = t;  }
t+=delta;
if (option!=2) {vec.push_back(x); vec.push_back(y);}
// cout<<x<<"\t"<<y<<"\t"<<t<<"\t"<<vx<<"\t"<<v<<"\t"<<a<<"\t"<<ax<<"\t"<<f<<"\t"<<fx<<"\n";
// printf("%.2f\t%.2f\t%.2f\n",x,y,t);
	  }
impact_speed = sqrt(vx*vx+v*v);		  
	 }// count end	 	 
	 
void graph(){
double xmax = x; if (tx>x){xmax=tx;}
double ymax = maxh; if (ty>maxh){ymax=ty;}	 
double xs = xmax/console_line_length;
double ys = ymax/console_line_num;
double step = xs; if (ys>xs){step=ys;} //meters in 1 symbol on screen
double arrstep = 1.0*console_line_length/(vec.size()/2);

//  cout<<"V_size (xy): "<<(vec.size()/2)<<" Step: "<<step<<" m. Arrstep: "<<arrstep<<"\n";
//  for (int i=0; i<vec.size(); i++) { printf("%.2f\t",vec[i]); if (i%2!=0){cout<<"\n";}}

int r =  0;
int cx, cy;
char matrix[console_line_num ][console_line_length]; 
for (int i2 = 0; i2 < console_line_num;  i2++) {
for (int i3 = 0; i3 < console_line_length;  i3++) {	
matrix[i2][i3]=' '; }}

for (int i=0; i<console_line_length; i++) { //
 r = (int) round(i/arrstep*2); //vec contains both x y
 if (r%2!=0){r--;}
if (r>-1 && r<vec.size()-1){
// printf("%i\t%i\n",r,i);
//  printf("%f\t%f\n",vec[r],vec[r+1]);
cx =   (int) round(vec[r]/step);
cy =   (int)(console_line_num- round(vec[r+1]/step));
 if (angle>1.55323 ||vinit==0){cx=0; } //for 90 and zero start speed
if (cx>-1 && cx<console_line_length && cy>-1 && cy <console_line_num){
if (matrix[cy][cx]==' '){matrix[cy][cx]='o';}   		  
			 }
}	
	}//
cx = (int) round(tx/step);
cy = (int)(console_line_num- round(ty/step));
if (cx<-1){ cx=0; }
if (cx>console_line_length-1){cx= console_line_length-1; }
if (cy<-1){ cy=0; }
if (cy >console_line_num-1){cy=console_line_num-1;}
matrix[cy][cx]='X';
   		  	
for (int i=0; i<console_line_num; i++) {
for (int i2=0; i2<console_line_length; i2++) {
	cout<<matrix[i][i2];
	}	
	}
			
	 }  // graph end
	 
void res_console(){
cout<<"\nAngle: "<< angle*57.3<<" degrees. Start speed: "<<vinit<<" m/s.\n";
cout<<"Delta_step: "<<delta<<" s. Air_density: "<<density<<" kg*m^3.\n";
cout<<"Front_projection: "<<s<<" m^2. Drag_factor: "<<c<<"\n"; 
cout<<"g: "<<g<<" Mass: "<<m<<" kg. Start_height: "<<h<<" m.";
cout<<"\n____OX_range: "<<x<<" m. Speed on impact: "<<impact_speed<<" m/s. \n";
cout<<"Max_height:  "<<maxh<<" m."<<" Time: "<<t<<" s. \n"; 	  
cout<<"With margin: "<<margin<<" m, reaches coord X: "<<tx<<"m, Y: "<<ty<<" m. at: "<<tot<<" s.";
	 }	

void clean(){
 vinit=0;
 vx=0; 
 x=0; 
 y=0; 
 t=0; 
 impact_speed=0;
 maxh=0;
 tot= -1; 
vec.clear();	 
	 }	  
	 
void writeout(){
ofstream outw("out.txt"); 
if(!outw) {
cout << "Cannot create out.txt\n";
cout<<"\n"; system("pause");
exit(1);
}
for (int i=0; i<vec.size(); i++) { outw<<vec[i]<<"\t"; if (i%2!=0){outw<<"\n";}}
outw.close();	 
	 }	 
	 
	 void writeout2(){
ofstream out5("out2.txt", ios::app); 
if(!out5) {
cout << "Cannot open out2.txt\n";
cout<<"\n"; system("pause");
exit(1);
}
out5<<angle*57.3<<"\t"<<vinit<<"\t"<<delta<<"\t"<<density<<"\t"<<s<<"\t"<<c<<"\t";
out5<<g<<"\t"<<m<<"\t"<<h<<"\t"<<margin<<"\t"<<tx<<"\t"<<ty<<"\t";
out5<<tot<<"\t"<<x<<"\t"<<impact_speed<<"\t"<<maxh<<"\t"<<t<<"\n";
out5.close();	 
	 }	

int main()
{
cout<<"__Throw to horizon by OlegTim __ \n\n";

ifstream ino("./options.txt", ios::in | ios::binary);
if(!ino) {
cout<<"options.txt is absent. Creating new. Update it and console, if needed.\n";
ofstream outo("./options.txt"); 
if(!outo) {
cout << "Cannot create options.txt\n";
return 1;
}
outo << option<<"\n";
outo << "^ in upper line: mode (0 manual, 1 read once from throw_in.txt, \
2 read many lines from throw_in.txt (makes only final out2.txt)) ^\n";
outo << console_line_length<<"\n";
outo << "^ in upper line: console_line_length, symbols ^\n";
outo << console_line_num<<"\n";
outo << "^ in upper line: console_num_rows, symbols (+10 to text out) ^\n\n";
outo << "in throw_in.txt : angle speed delta density space drag g mass height \
margin targetx targety\n";
outo <<"in out.txt x and y coord in m for each step (Tab separated)\n";
outo << "in out2.txt : angle speed delta density space drag g mass height \
margin targetx targety tot(-1 no reach) distance |impact_speed_xy| max_H time\n";
outo <<"at new run out.txt and out2.txt may be rewritten!\n\n";
outo <<"1.3 point for nums in app, some text processors use comma 1,3 \n";
outo.close();
}
string line;
int counter=0;
    while (getline(ino, line)) {
	 line.c_str();
        if (counter==0){option=atoi( line.c_str() );}
          if (counter==2){console_line_length=atoi( line.c_str() );}
           if (counter==4){console_line_num=atoi( line.c_str() );}
        counter++;
    }
ino.close();
// cout<<console_line_length <<" "<<console_line_num<<" "<<option<<"\n";

ifstream file2("./throw_in.txt");
if(!file2) {
cout << "Cannot open throw_in.txt\n";
cout << "Creating default throw_in.txt \n";
ofstream out3("./throw_in.txt"); 
if(!out3) {
cout << "Cannot create throw_in.txt\n";
cout<<"\n"; system("pause");
exit(1);
}
out3<<angle<<"\t"<<v<<"\t"<<delta<<"\t"<<density<<"\t"<<s<<"\t"<<c<<"\t";
out3<<g<<"\t"<<m<<"\t"<<h<<"\t"<<margin<<"\t"<<tx<<"\t"<<ty<<"\n";
out3.close();
}
file2.close();

ofstream out("out.txt"); 
if(!out) {
cout << "Cannot create out.txt\n";
cout<<"\n"; system("pause");
return 1;
}
out.close();

ofstream outs("out2.txt"); 
if(!outs) {
cout << "Cannot create out.txt\n";
cout<<"\n"; system("pause");
return 1;
}
outs.close();

if (option==0){
while (1){
clean();	  
typeparam();	
count();	 		  
graph();	  	  
res_console();
writeout();
writeout2();
cout<<"\nContinue  ";system("pause");
}
}// option =0 end

if (option==1){
ifstream file("./throw_in.txt");
if (file.is_open()) {	     					
    std::string line;
    while (std::getline(file, line)) {
        line.c_str();
        vector<string> arr;
  string delim("\t");
  size_t prev = 0;
  size_t next;
  size_t delta3 = delim.length();
  while( ( next = line.find( delim, prev ) ) != string::npos ){
    arr.push_back( line.substr( prev, next-prev ) );
    prev = next + delta3;
  }
arr.push_back( line.substr(prev ) );

angle =atof(arr[0].c_str());
v =atof(arr[1].c_str());
delta =   atof(arr[2].c_str());
density =atof(arr[3].c_str());
s =atof(arr[4].c_str());
c =atof(arr[5].c_str());
g =atof(arr[6].c_str());
m =atof(arr[7].c_str()); 
h =atof(arr[8].c_str());
margin =atof(arr[9].c_str());
tx =atof(arr[10].c_str());
ty =atof(arr[11].c_str());

count();	 		  
graph();	  	  
res_console();
writeout();
writeout2();
cout<<"\nQuit  ";system("pause");
exit(0);
    }
    file.close();
}
}// option =1 end


if (option==2){
ifstream file("./throw_in.txt");
if (file.is_open()) {
clean();	     					
    std::string line;
    while (std::getline(file, line)) {
        line.c_str();
        vector<string> arr;
  string delim("\t");
  size_t prev = 0;
  size_t next;
  size_t delta3 = delim.length();
  while( ( next = line.find( delim, prev ) ) != string::npos ){
    arr.push_back( line.substr( prev, next-prev ) );
    prev = next + delta3;
  }
arr.push_back( line.substr(prev ) );

angle =atof(arr[0].c_str());
v =atof(arr[1].c_str());
delta =   atof(arr[2].c_str());
density =atof(arr[3].c_str());
s =atof(arr[4].c_str());
c =atof(arr[5].c_str());
g =atof(arr[6].c_str());
m =atof(arr[7].c_str()); 
h =atof(arr[8].c_str());
margin =atof(arr[9].c_str());
tx =atof(arr[10].c_str());
ty =atof(arr[11].c_str());

count();	 		  
writeout2();
clean();
    }
    file.close();
}
}// option =2 end
	  
return 0;
}
