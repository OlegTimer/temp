#include <iostream>
#include <stack>
#include <string>
#include <fstream>
using namespace std;

 string decodeString(string s) {
string res="";
string temp="";
string numcounter="";
stack <string> stackstr;
stack <int> count;
for (int i = 0; i<s.length(); i++){//-
	
if (isdigit(s[i])) { numcounter = numcounter+s[i];  }else{//not num
if (s[i]=='[') {// [
stackstr.push(temp);
int z = atoi( numcounter.c_str() );
count.push(z);
numcounter="";
temp="";
}// [
else{
if (s[i]==']') { // ]
string inner = temp;
int c = count.top();  count.pop();
string pre = stackstr.top();  stackstr.pop(); 
for (int q=0;q<c-1;q++){ inner += temp;}
temp = pre+inner;
}// ]
else{// letter
temp+=s[i];
}	//letter
}
}//not num
}//-
res=temp;
return res;      
    }



int main ()
{
cout<<"_ Decode String _\n";
cout<<"The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets\n";
cout<<"is being repeated exactly k times. Note that k is guaranteed to be a positive integer.\n";
cout<<"You may assume that the input string is always valid;\n";
cout<<"original data does not contain any digits and that digits are only for those repeat numbers, k.\n";
cout<<"Example: Input: s = 3[a2[c]] Output: accaccacc\n";
cout<<"Fill _matrixin1.txt  in the program's directory.\n";
cout<<"If absent, program will create new. Columns are tab-separated.\n\n";

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

cout<<"Input:\n"; 
cout<<str<<"\n"; 
cout<<"Output:\n"; 
cout<<decodeString(str)<<"\n"; 	

cout<<"\nby OlegTim\t";  system("pause");
  return 0;
}