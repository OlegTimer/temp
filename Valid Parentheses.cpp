#include <iostream>
#include <stack>
#include <string>
#include <fstream>
using namespace std;

bool isValid(string s) {
bool res = true;
if (s.length()%2!=0){res = false; }else{
stack <char> v;
for (int i = 0; i< s.length(); i++){//
if (s[i]=='(' || s[i]=='{' || s[i]=='['){ v.push(s[i]);    } 
if (s[i]==')' )  { if (v.top()=='('){ v.pop();  } else {res = false; break;} }
if (s[i]=='}' )  { if (v.top()=='{'){ v.pop();  } else {res = false; break;} }
if (s[i]==']' )  { if (v.top()=='['){ v.pop();  } else {res = false; break;} }
}//
}
return res;    
}

int main ()
{
cout<<"Valid Parentheses\n";
cout<<"Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',\n";
cout<<"determine if the input string is valid.\n";
cout<<"An input string is valid (1 true ; 0 false) if:\n";
cout<<"Open brackets must be closed by the same type of brackets.\n";
cout<<"Open brackets must be closed in the correct order.\n";
cout<<"Every close bracket has a corresponding open bracket of the same type.\n";
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
cout<<isValid(str); 

cout<<"\nby OlegTim\t";  system("pause");
  return 0;
}