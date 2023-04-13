#include <iostream>
#include <fstream>
#include <vector> 
#include <string> 
using namespace std;

void nofileerr(){
cout<<"\n__Caesar's code C++ by OlegTim__\n";	 
cout<<"It seems you don't have alphabet.txt and/or in.txt in the app's folder.\n";
cout<<"Press any key and the programme will create it.\n";
cout<<"Alphabet by default is standard English 26 letters. You can change it.\n";
cout<<"Alphabet can be non-Latin, save it as ANSI on Windows -> case-sensitive.\n";
cout<<"in.txt contains line you want to de/code, not more than 80 symbols.\n";
cout<<"All letters will be Uppercase, non-alphabetical symbols ignored.\n";
cout<<"All variants of code would be in out.txt    Run again after changes.\n";	
	 }

int main()
{
void nofileerr(); 	
char ch;
vector <char> alp;
vector <char> str;

ifstream in("alphabet.txt", ios::in | ios::binary);
if(!in) {
cout << "Cannot open alphabet.txt\n";
nofileerr(); 
ofstream out3("alphabet.txt"); 
if(!out3) {
cout << "Cannot create alphabet.txt\n";
return 1;
}
out3 << "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
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
return 1;
}
for (int i = 0; i < 80; i++) {
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
return 1;  				  
}

if (alp.size()<2){
cout << "Seems alphabet.txt contains 1 or zero symbols\n";
cout<<"\n"; system("pause"); 
return 1;  				  
}

ofstream out("out.txt"); 
if(!out) {
cout << "Cannot create out.txt\n";
return 1;
}
out.close();

ofstream out4("out.txt", ios::app); 
if(!out4) {
cout << "Cannot open out.txt\n";
return 1;
}

char s2[str.size()];
for (int i = 0; i < str.size(); i++) { s2[i]=str[i]; }
string s(s2); s="";
char s3[alp.size()];
for (int i = 0; i < alp.size(); i++) { s3[i]=alp[i]; }
string sa(s3); 

int t=0;
int arr[str.size()];
for (int i = 0; i < str.size(); i++) {
t = sa.find(str[i]); arr[i]=t;
}

for (int i = 0; i < alp.size(); i++) {//
for (int i2 = 0; i2 < str.size(); i2++) {
t=arr[i2]+i;
if (t>alp.size()-1) {t=t-alp.size();}
s+=alp[t];
}
out4  << s<<"\n"; s="";
}//

out4.close();

return 0;
}
