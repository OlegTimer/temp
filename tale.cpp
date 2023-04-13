#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include<windows.h> 
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;
/*
Latin symbols works almost always.
Non-Latin symbols depend on OS language and encoding.
Tested on Win7 with ANSI.
To run national symbols may work:
setlocale(0, "");  or CharToOem();
You may read and write binary text files (i.e. Japanese in UTF-8 or Unicode), 
but not show properly non-Latin symbols in console.
German alphabet can be simplified to Latin, but for Cyrillic symbols there is no guarantee.
Use TAB for language separation. __Best, OlegTim	    
 */

char sym[256];
char* alt(const char* text) { CharToOem(text, sym); return sym; } 
int main ()
{
int randt=0;
struct tm *ptr;
time_t lt;
 	
vector<string> arr;
vector<string> t0;
vector<string> t1;
string s2;
vector<string> t2;
vector<string> t3;
string s3;
vector<string> t4;
vector<string> t5;
string s4("");
string s5("");

 int langnum=1;
 int counter = 0;
 string sendenter("");
char hero[80];
char evil[80];
 
  string delim("	");
  size_t prev = 0;
  size_t next;
  size_t delta = delim.length();
 	
ifstream file("./lang.txt");
if(!file) {
cout << "Cannot open lang.txt\n";
cout << "Creating default lang.txt  Run app again.\n";
ofstream out3("lang.txt"); 
if(!out3) {
cout << "Cannot create lang.txt\n";
cout<<"\n"; system("pause");
exit(1);
}
out3 << "Press <1> for English. \n";
out3 << "Type your your favorite hero's name \n";
out3 << "and press <Enter>: \n";
out3 << "Type the name of hero you don't like \n";
out3 << "Good! Listen to my tale:\n";
out3 << "In a land far away,\n";
out3 << "in the Cookies Valley,\n";
out3 << "in the Caramel Valley,\n";
out3 << "in the Sugar Valley,\n";
out3 << "~~separ\n";
out3 << "there was a\n";
out3 << "wonderful\n";
out3 << "magnificent\n";
out3 << "beautiful\n";
out3 << "~~separ\n";
out3 << "mansion\n";
out3 << "palace\n";
out3 << "castle\n";
out3 << "~~separ\n";
out3 << "This lands belonged to\n";
out3 << "Once, in the gloomy weather, the villain came.\n";
out3 << "The villain's mouth claimed: 'Ha-ha, I am\n";
out3 << "I will do some ungood!'\n";
out3 << "~~separ\n";
out3 << "grabbed foe's nose\n";
out3 << "grabbed foe's butt\n";
out3 << "grabbed foe's ear\n";
out3 << "~~separ\n";
out3 << "and threw into trash bin.\n";
out3 << "And life was nice and charming again.\n";
out3 << "Press any key for new story\n";
out3.close();
cout<<"\n"; system("pause");
exit(1);
}

if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
		  
if(counter==0){
cout<<"__ Strange Tales by OlegTim __ \n\n";	
cout<<"Select language:\n";			   
cout<<alt(line.c_str())<<"\nAnd press <Enter>. \n>";		  
cin >> langnum; langnum--;
}

if (counter!=0){//main sycle start
  prev =0; 
  arr.clear();
       while( ( next = line.find( delim, prev ) ) != string::npos ){
    arr.push_back( line.substr( prev, next-prev ) );
    prev = next + delta;
  }
arr.push_back( line.substr(prev ) );

if (counter==1&&arr.size()<langnum+1){
cout << "Language number seems wrong. \n";
cout<<"\n"; system("pause"); 
exit(1);    						  						 
}

int r = line.find("~~separ");
if (r!=-1){counter++; }


if (counter==4){ counter++; cout<<" "<<sendenter<<"\n>";cin >> evil; cout<<"\n";}
if (counter==3){ counter++; cout<<"\n>";cin >> hero;}
if (counter==2){sendenter = alt(arr[langnum].c_str()); counter++; cout<<" ";	}
if (counter==1){counter++; cout<<"\nOK. ";}
						 
if (counter<5) {cout<<alt(arr[langnum].c_str());}
else{//
if (counter==21){s5 += (alt(arr[langnum].c_str()) );}
if (counter==20){s4 = s4+"\n"+(alt(arr[langnum].c_str()) ); counter++;}
if (counter==19){s4 += (alt(arr[langnum].c_str()) );counter++;}
if (counter==18){ counter++;}
if (counter==17){t5.push_back(alt(arr[langnum].c_str()) );}
if (counter==16){ counter++;}
if (counter==15){t4.push_back(alt(arr[langnum].c_str()) ); }
if (counter==14){ s3 = (alt(arr[langnum].c_str()) ); counter++;}
if (counter==13){ counter++;}
if (counter==12){t3.push_back(alt(arr[langnum].c_str()) );}
if (counter==11){ counter++;}
if (counter==10){t2.push_back(alt(arr[langnum].c_str()) );}
if (counter==9){s2 = (alt(arr[langnum].c_str()) ); counter++;}
if (counter==8){ counter++;}
if (counter==7){t1.push_back(alt(arr[langnum].c_str()) );}
if (counter==5){cout<<"\n";}
if (counter==5||counter==6){t0.push_back(alt(arr[langnum].c_str()) ); counter++;}
}//
}//main sycle end
if(counter==0){counter++;}
    }
    file.close();
} 	

while (!kbhit()){
for (int i=0; i<20;i++){cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";}	  
lt = time('\0'); 
randt=lt%10;
int m=0;

int num  =randt;   if (num>t1.size()-1||num<0){num=0;}
for (int i =0; i <lt%100; i++){ m = rand();}
int num2 =m%10;   if (num2>t2.size()-1||num2<0){num2=0;}
for (int i =0; i <lt%100-1; i++){ m = rand();}
int num3 =m%10;   if (num3>t3.size()-1||num3<0){num3=0;}
for (int i =0; i <lt%100-2; i++){ m = rand();}	
int num4 =m%10;   if (num4>t5.size()-1||num4<0){num4=0;}
// cout<<randt<<num<<num2<<num3<<num4<<"\n";

cout<<"\n"<<t0[0]<<"\n"<<t0[1];	
cout<<" "<<t1[num]<<"\n"<<s2<<" "<<t2[num2]<<" "<<t3[num3]<<".\n";
cout<<s3<<" "<<hero<<".\n";
cout<<t4[0]<<"\n"<<t4[1]<<" "<<evil<<"!\n"<<t4[2]<<"\n";
cout<<hero<<" "<<t5[num4]<<" "<<s4<<"\n";
cout<<"\n_ "<<s5<<" _\n";
cout<<"";  system("pause");
}

  return 0;
}
