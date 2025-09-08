#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main ()
{
cout << "__ Given an matrix, return all elements of the matrix in spiral order. __\n";
cout << "Fill _matrixin1.txt  in the program's directory.\n";
cout << "If absent, program will create new. Columns are tab-separated.\n";
 	
vector<vector<int> >  matrix1;	
vector<string> arr;
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
arr.clear();		  
    str = line.c_str();
  string delim("\t");
  size_t prev = 0;
  size_t next;
  size_t delta = delim.length();
  while( ( next = str.find( delim, prev ) ) != string::npos ){
    arr.push_back( str.substr( prev, next-prev ) );
    prev = next + delta;
  }
 arr.push_back( str.substr(prev ) ); 
vector<int> v;
for (int i = 0; i < arr.size(); i++) {
double d = atof(arr[i].c_str());
v.push_back(d);
}
 matrix1.push_back(v);   
    }
    file.close();
}	


if(matrix1.size()<1){cout<<"ERR empty entry\n";system("pause");return 1;} 	


cout<<"\nInput:\n"; 
for (int i = 0; i < matrix1.size(); i++) {
	for (int i2 = 0; i2 < matrix1[i].size(); i2++) {
cout<<matrix1[i][i2]<<"\t";
	}
	cout<<"\n";
}

cout<<"\n";
int h = matrix1.size();
int w = matrix1[0].size();
int t,r,l,b;
t=l=0;
r=w;
b=h;

while (r-l>0 && b-t>0){
if (r-l>0 && b-t>0) { for (int i=l;i<r;  i++){cout<<matrix1[t][i]	<<" ";} }
if (r-l>0 && b-t>0) { for (int i=t+1;i<b;  i++){cout<<matrix1[i][r-1]	<<" ";} }
if (r-l>0 && b-t>0) { for (int i=r-2;i>l-1;  i--){cout<<matrix1[b-1][i]	<<" ";} }
if (r-l>0 && b-t>0) { for (int i=b-2;i>t;  i--){cout<<matrix1[i][l]	<<" "; }}
if (r-l>0) {l++;r--;}
if (b-t>0) { t++;b--;}
}

cout<<"\nby OlegTim\t";  system("pause");
  return 0;
}