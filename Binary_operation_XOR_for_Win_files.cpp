#include <iostream>
#include <fstream>
#include <sstream>
#include <vector> 
#include <string>
#include <ctime>
#include <windows.h>
#include <conio.h>
using namespace std;

#define KEYSIZE 8

string key="00000000 ";
string input_name = "_input.txt";
string output_name = "_output.txt";
string pathin = "_in";
string pathout = "_out ";
vector <char> res;
string mask="*.* ";
int deletein = 0; // 0 false ; 1 true
int rewrite = 0;
int once = 1;
int sleep = 10000; //ms


char modif(char a, char b){
return a^b;
}


void fileread( string s ){
char ch;
int counter;
char arr_input_chars[KEYSIZE];
	 
ifstream in(s.c_str(), ios::in | ios::binary);
if(!in) {
cout << "Cannot open file.\n"; system("pause");
exit(1);
}

res.clear();
counter = 0;

while(in) {
if (counter	< KEYSIZE)
{ 			
in.get(arr_input_chars[counter]);
counter++;  
} 
else {
counter=0;
for (int i=0; i<KEYSIZE; i++){
	res.push_back( modif(arr_input_chars[i], key[i]) );
	}
}	  

}
in.close();

for (int i=0; i<counter-1; i++){
	res.push_back( modif(arr_input_chars[i], key[i]) );
	}	 
}// fileread() end


void filewrite(string s){	 	 
ofstream out(s.c_str()); 
if(!out) {
cout << "Cannot open file.\n"; system("pause");
exit(1);
}
for (int i=0; i <  res.size(); i++){out<<res[i];}
out.close(); 
}// filewrite() end


void options_read(){
ifstream ino("./_options.txt", ios::in | ios::binary);
if(!ino) {
cout<<"_options.txt is absent in program's dir, creating new. Customize it.\n";
system("pause");
ofstream outo("./_options.txt"); 
if(!outo) {
cout << "Cannot create _options.txt\n";
system("pause"); exit(1);
}
outo << "(Options are Win ANSI) input file mask: \n";
outo << "*.*\n";
outo << "delete input files? (1 yes, 0 no): \n";
outo << "0\n";
outo << "path for saving output files directory (start in program's dir):\n";
outo << "_out\n";
outo << "rewrite output files? (1 yes, 0 no - will create new name): \n";
outo << "0\n";
outo << "launch once? (1 yes, 0 no): \n";
outo << "1\n";
outo << "sleep time for cycle (ms): \n";
outo << "10000\n";
outo << "8-byte key for XOR operation: \n";
outo << "00000000\n";
outo << "path for input files directory (start in program's dir):\n";
outo << "_in";
outo.close();
}
string line;
int counter=0;
while (getline(ino, line)) {

if (counter==1){mask = line;  }
if (counter==3){deletein = atoi( line.c_str() );}
if (counter==5){pathout = line;}
if (counter==7){rewrite = atoi( line.c_str() );}
if (counter==9){once = atoi( line.c_str() );}
if (counter==11){sleep = atoi( line.c_str() );}
if (counter==13){key = line;}
if (counter==15){pathin = line;}
counter++;
    }
ino.close(); 
mask[mask.size()-1] = '\0';
pathout[pathout.size()-1] = '\0';
key[key.size()-1] = '\0'; 	   
}// options_read end


void dir_create(){ 
if (CreateDirectory(pathin.c_str(), NULL) ||
 ERROR_ALREADY_EXISTS == GetLastError())
{} else {cout << "Cannot input dir\n"; system("pause"); exit(1); }

if (CreateDirectory(pathout.c_str(), NULL) ||
 ERROR_ALREADY_EXISTS == GetLastError())
{} else {cout << "Cannot output dir\n"; system("pause"); exit(1); }
}


bool if_exist(string s)
{
std::ifstream infile(s.c_str());
return infile.good();
}


void checkdir(){
WIN32_FIND_DATA FindFileData;
HANDLE hf;
string sway = ".\\"+pathin+"\\"+mask;
hf=FindFirstFile(sway.c_str(), &FindFileData);
if (hf!=INVALID_HANDLE_VALUE)
{  							 
do
{
string s =   FindFileData.cFileName;							   	
	if (s.compare(".") != 0 && s.compare("..") != 0){//--	   								   				
s=".\\"+pathin+".\\"+FindFileData.cFileName;

string so = pathout;
char t[so.size()];
for (int i=0; i<so.size(); i++){t[i]=so[i];}
t[so.size()-1] = '\0';
string g = t;

string newn = "checkIfFileOpen";
string sn = s+newn; 
int isopen =0;
try{
isopen= rename( s.c_str(), sn.c_str() ); //0 for success
rename( sn.c_str(), s.c_str() );
}
catch (...){
//cout << "File is opened, cannot be renamed" <<"\n";
	  }

if (isopen==0){
fileread(s);
if (deletein){ DeleteFile( s.c_str() ); }

s=".\\"+g+".\\"+FindFileData.cFileName;
if (rewrite){filewrite(s); }else
{//if not rewrite start
int addnum=0;
string st = FindFileData.cFileName;
size_t lastindex = st.find_last_of("."); 
string raw = st.substr(0, lastindex);
string ext = st.substr(lastindex, st.size()-1); 						   
while(1)									{
string st =".\\"+g+".\\"+raw; 
std::ostringstream strs2;
strs2 << addnum;
st+= strs2.str(); 
st+=ext;

if ( !if_exist(st)) {filewrite(st);break;}
addnum++;
		 								   }
}//if not rewrite end
}//isopen==0 end
}//--							     
}
while (FindNextFile(hf,&FindFileData)!=0);
FindClose(hf);
}
}//checkdir() end


int main()
{
cout<<"Binary_operation_XOR_for_Win_files_by_OlegTim\n";  	
options_read();
dir_create();
 
checkdir();	

cout<<"...Working... Press ESC to quit\n";
while (once==0){
Sleep(sleep);
checkdir();		  
if(kbhit()){ 		 
char choice = getch();
choice=tolower(choice);
switch(choice){ 
case 27: { once=1; }	//esc
default: {   break;  }
}}}


return 0;
}
