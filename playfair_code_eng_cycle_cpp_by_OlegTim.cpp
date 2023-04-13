 #include <iostream>
#include <fstream>
#include <vector> 
#include <string> 
using namespace std;

void nofileerr(){
cout<<"\n__Playfair code C++ by OlegTim__\n";	 
cout<<"Absent alphabet.txt and/or in.txt, key.txt in the app's folder.\n";
cout<<"Alphabet by default is  English 25 letters without J. You can change it.\n";
cout<<"Alphabet can be non-Latin, save it as ANSI on Windows -> case-sensitive.\n";
cout<<"in.txt contains line you want to de/code, not more than 150 symbols.\n";
cout<<"All letters will be Uppercase, non-alphabetical symbols ignored.\n";
cout<<"In options.txt you can select de/code, rows and column count.\n";
cout<<"options.txt will be created in need. With no errors console is not paused\n";
cout<<"You can enter different keys in key.txt - separate with new line\n";
cout<<"Result will be in out.txt   Run again after changes.\n";	
cout<<"Press any button and the programme will create files.\n";
	 }

int main()
{
int decode=0; 	
int m1=5;
int m2=5; 	
void nofileerr(); 	
char ch;
vector <char> alp;
vector <char> str;
vector <char> key;

ifstream ino("options.txt", ios::in | ios::binary);
if(!ino) {
cout << "Cannot open options.txt\n";
ofstream outo("options.txt"); 
if(!outo) {
cout << "Cannot create options.txt\n";
return 1;
}
outo << decode<<"\n";
outo << "^ in upper line: 1 to decode, 0 to code. ^\n";
outo << m1<<"\n";
outo << "^ in upper line: number of rows in matrix. ^\n";
outo << m2<<"\n";
outo << "^ in upper line: number of columns in matrix. ^";
outo.close();
}
string line;
int counter;
    while (getline(ino, line)) {
        printf("%s", line.c_str()); cout<<"\n";
        if (counter==0){decode=atoi( line.c_str() );}
          if (counter==2){m1=atoi( line.c_str() );}
           if (counter==4){m2=atoi( line.c_str() );}
        counter++;
    }

ino.close();
for (int i=0; i<20;i++){cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";}
  
ifstream in("alphabet.txt", ios::in | ios::binary);
if(!in) {
cout << "Cannot open alphabet.txt\n";
nofileerr(); 
ofstream out3("alphabet.txt"); 
if(!out3) {
cout << "Cannot create alphabet.txt\n";
return 1;
}
out3 << "ABCDEFGHIKLMNOPQRSTUVWXYZ";
out3.close();
cout<<"\n"; system("pause");
}
while(in) {
in.get(ch);
if(in) {alp.push_back(ch);}
}
in.close();

ifstream in2("in.txt", ios::in | ios::binary);
if(!in2) {
cout << "Cannot open in.txt\n";
nofileerr(); 
ofstream out2("in.txt"); 
if(!out2) {
cout << "Cannot create in.txt\n";
return 1;
}
out2.close();
cout<<"\n"; system("pause");
}
for (int i = 0; i < 150; i++) {
in2.get(ch);
if(in2) {
ch = toupper(ch);		
for (int i = 0; i < alp.size(); i++){if (alp[i]==ch){str.push_back(ch);}}		
		}
}
in2.close();

if (str.size()<1){
cout << "Seems no alphabet symbols in in.txt\n";
cout<<"\n"; system("pause");  				  
}

if (str.size()%2!=0){
if (decode==1){   					  
cout << "Not even number of symbols in in.txt\n";
cout<<"\n"; system("pause"); 
exit(1); 	}
else{
if (str[str.size()-1]==alp[alp.size()-1]){str.push_back(alp[alp.size()-2]);}
else{str.push_back(alp[alp.size()-1]);} 
	 } 				  
} 

if (alp.size()!=m1*m2){
cout << "Seems alphabet symbols count is not matching matrix size\n";
cout<<"\n"; system("pause");  				  
}

ofstream out("out.txt"); 
if(!out) {
cout << "Cannot create out.txt\n";
cout<<"\n"; system("pause");
return 1;
}
out.close();

for (int i = 0; i < str.size(); i= i+2) {
if (str[i]==str[i+1]){
if (decode==1){   					  
cout << "Bigramms cannot contain same letters. Check in.txt\n";
cout<<"\n"; system("pause"); 
exit(1); 	}
else{
if (str[i+1]==alp[alp.size()-1]){str[i+1]=alp[alp.size()-2];}
else{str[i+1]=alp[alp.size()-1];} 
	 }				  
   					  }
} 

string err; err="";
ifstream ink("key.txt", ios::in | ios::binary);
if(!ink) {
cout << "Cannot open key.txt\n";
nofileerr(); 
ofstream outk("key.txt"); 
if(!outk) {
cout << "Cannot create key.txt\n";
return 1;
}
outk.close();
cout<<"\n"; system("pause");
return 1;
}
while(getline(ink, line)) {
//	
			   
key.clear();  err="";
vector<char> keym(line.begin(), line.end());
 for (int i2 = 0; i2 < keym.size(); i2++) {
 	 ch = keym[i2];
ch = toupper(ch);
 for (int i = 0; i < alp.size(); i++){if (alp[i]==ch){key.push_back(ch);}}
	  }	 
if (key.size()<1){err="~Seems invalid key in key.txt"; 	 }
if (key.size()>alp.size()){err= "~Seems key is too long in key.txt"; 		}

int f = err.find("~");
if (f!=-1){
ofstream out5("out.txt", ios::app); 
if(!out5) {
cout << "Cannot open out.txt\n";
return 1;
}
out5  << err<<"\n"; 
out5.close(); 			  
   			  }
   			  else{//if key is good start

char matrix[m1][m2]; 
for (int i2 = 0; i2 < m1;  i2++) {
for (int i3 = 0; i3 < m2;  i3++) {	
matrix[i2][i3]='~'; }}

int wpos=0;
vector <char> key2;
for (int i = 0; i < key.size();  i++) {
int already = 0;
for (int i2 = 0; i2 < m1;  i2++) {
for (int i3 = 0; i3 < m2;  i3++) {
if (matrix[i2][i3] == key[i]){already++;}
	}
	}
int c1= (int)wpos/m2; int c2 = wpos%m2;
if (already==0){matrix[c1][c2] =key[i]; key2.push_back(key[i]); wpos++;}
	}

char s3[key2.size()];
for (int i = 0; i < key.size(); i++) { s3[i]=key[i]; }
string sk(s3); 
string s(s3);	s="";

for (int i = 0; i < alp.size(); i++){
int r = sk.find(alp[i]);
if (r==-1){
int c1= (int)wpos/m2; int c2 = wpos%m2;
matrix[c1][c2] =alp[i];  wpos++;   		   
			  }
	}		

int num=0; int n2=0; int n3=0; int n2b=0; int n3b=0;
char r='~'; char r2='~';

if (decode!=1){
//let's code the known message 
for (num=0; num<str.size(); num=num+2){
for (int i2 = 0; i2 < m1;  i2++) {
for (int i3 = 0; i3 < m2;  i3++) {
if (matrix[i2][i3] == str[num]){n2=i2;n3=i3;}	
	}}
for (int i2 = 0; i2 < m1;  i2++) {
for (int i3 = 0; i3 < m2;  i3++) {
if (matrix[i2][i3] == str[num+1]){n2b=i2;n3b=i3;}	
	}}

if (n2==n2b){//if on same row
if (n3<m2-1){r=matrix[n2][n3+1];} else{r=matrix[n2][0];} 	
if (n3b<m2-1){r2=matrix[n2b][n3b+1];} else{r2=matrix[n2b][0];} 	
				}
else{if (n3==n3b){//if on same column
if (n2<m1-1){r=matrix[n2+1][n3];} else{r=matrix[0][n3];} 	
if (n2b<m1-1){r2=matrix[n2b+1][n3b];} else{r2=matrix[0][n3b];} 	 		
		}else{//if not on same row and not on same column
r=matrix[n2][n3b];
r2=matrix[n2b][n3];				  
			  }}	
s+=r;s+=r2;
}

ofstream out4("out.txt", ios::app); 
if(!out4) {
cout << "Cannot open out.txt\n";
return 1;
}
if (s!="") {out4  << s<<"\n"; }
out4.close(); s="";
}

if (decode==1){
//let's decode the unknown message 
for (num=0; num<str.size(); num=num+2){
for (int i2 = 0; i2 < m1;  i2++) {
for (int i3 = 0; i3 < m2;  i3++) {
if (matrix[i2][i3] == str[num]){n2=i2;n3=i3;}	
	}}
for (int i2 = 0; i2 < m1;  i2++) {
for (int i3 = 0; i3 < m2;  i3++) {
if (matrix[i2][i3] == str[num+1]){n2b=i2;n3b=i3;}	
	}}

if (n2==n2b){//if on same row
if (n3>0){r=matrix[n2][n3-1];} else{r=matrix[n2][m2-1];} 	
if (n3b>0){r2=matrix[n2b][n3b-1];} else{r2=matrix[n2b][m2-1];} 	
				}
else{if (n3==n3b){//if on same column
if (n2>0){r=matrix[n2-1][n3];} else{r=matrix[m1-1][n3];} 	
if (n2b>0){r2=matrix[n2b-1][n3b];} else{r2=matrix[m1-1][n3b];} 	 		
		}else{//if not on same row and not on same column
r=matrix[n2][n3b];
r2=matrix[n2b][n3];				  
			  }}	
s+=r;s+=r2;
}

ofstream out5("out.txt", ios::app); 
if(!out5) {
cout << "Cannot open out.txt\n";
return 1;
}
if (s!="") {out5  << s<<"\n"; }
out5.close(); s="";
}			  	   
			  	   
			  	   	  }//if key is good end
////			   
}
ink.close();

return 0;
}
