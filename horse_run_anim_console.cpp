#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

int delay = 160; //step delay ms
string dist="";

int stand(){
cout<<dist<<"            .'' \r\n";	
cout<<dist<<"  ._.-.___.' (`\\ \r\n";
cout<<dist<<" //(        (  \r\n";
cout<<dist<<" ||(  ).__. ) \r\n";
cout<<dist<<"   |  |   | | \r\n";
cout<<dist<<"   |  |   | | \r\n";	
	}

int left(){
cout<<dist<<"            .'' \r\n";	
cout<<dist<<"  ._.-.___.' (`\\ \r\n";
cout<<dist<<" //(        (  \r\n";
cout<<dist<<"'/ )\ ).__. )  \r\n";
cout<<dist<<"' <' `\\ ._/'\\ \r\n";
cout<<dist<<"   `   \\     \\ \r\n \r\n";
}

int right(){
cout<<dist<<"            .'' \r\n";	
cout<<dist<<"  ._.-.___.' (`\\ \r\n";
cout<<dist<<" //(        (  \r\n";
cout<<dist<<"'/ )\ ).__. ))  \r\n";
cout<<dist<<"   __/     /\\ \r\n";
cout<<dist<<"      \\   /  \\ \r\n \r\n";
}	
	
int main(void){
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\
\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";		
int stand(); stand();
cout<<"\r\n\r\nHi! Press any key to run the horse! (80 symbols in line assumed)";
int left(); int right();
while (!kbhit()){}

int leg=0;
for (int i=0 ; i <60 ; i++){
int t = clock();
while ((clock()-t)<delay){}	
leg++;
dist+=" ";
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\
\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
if (leg%2==0){left();	} else {right();}
	}
	
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\
\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";	
stand();

cout<<"\nby OlegTim  "; system("pause"); return 0;
} 
