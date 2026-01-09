#include <iostream>
#include <stack>
#include <string>
#include <fstream>
using namespace std;

int lengthOfLastWord(string s) {
int end =  s.size()-1;
int start = end ;
char space = ' ';
for (int i = s.size()-1; i>-1; i--){	
if (s[i]==space && end==start){end--; start--;}
if (s[i]!=space ){start--;}
if (s[i]==space && end!=start){break;}
}
int res= end-start;	
if (s.size()==1){res=1;}
return res;
} 

int main ()
{
cout<<"Length of Last Word\n";
cout<<"Given a string s consisting of words and spaces,\n";
cout<<"return the length of the last word in the string.\n";
cout<<"A word is a maximal consisting of non-space characters only.\n";
cout<<"There will be at least one word.\n";
cout << "Fill _matrixin1.txt  in the program's directory.\n";
cout << "If absent, program will create new. Columns are tab-separated.\n\n";

string str ("");
   
ifstream file("./_matrixin1.txt");
if(!file) {
cout << "Cannot open file _matrixin1.txt. Trying to create new\n";
ofstream out3("_matrixin1.txt"); 
if(!out3) {
cout << "Cannot create _matrixin1.txt\n";
return 1;
}
out3 << "";
out3.close();
cout<<"\n"; system("pause");
return 1;
} 
 
if (file.is_open()) {  					
    std::string line;
    while (std::getline(file, line)) {		  
    str = line.c_str(); 
    }
    file.close();
}	

cout<<str<<"\n";  	
cout<<lengthOfLastWord(str); 

cout<<"\nby OlegTim\t";  system("pause");
  return 0;
}
