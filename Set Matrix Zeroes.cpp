#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<vector<int> >  matrix1;


void setZeroes(vector<vector<int> >& matrix) {
int mark =  2147483647;	
for (int i = 0; i < matrix.size(); i++) {
	for (int i2 = 0; i2 < matrix[i].size(); i2++) {
if (matrix[i][i2]==0) {matrix[0][i2]=mark; matrix[i][0]=mark; }
}}	


for (int i = 0; i < matrix.size(); i++) { //horizontal line to 0
if (matrix[i][0]==mark){
	for (int i2 = 0; i2 < matrix[i].size(); i2++) {if (matrix[i][i2]!=mark) {matrix[i][i2]=0;} }
}
}

for (int i = 0; i < matrix[0].size(); i++) { //vert line to 0
if (matrix[0][i]==mark){
	for (int i2 = 0; i2 < matrix.size(); i2++) {matrix[i2][i]=0; }
}
}

	for (int i = 0; i < matrix.size(); i++) {
	for (int i2 = 0; i2 < matrix[i].size(); i2++) {
if (matrix[i][i2]==mark) {matrix[i][i2]=0; }
}}		

for (int i = 0; i < matrix.size(); i++) {
	for (int i2 = 0; i2 < matrix[i].size(); i2++) {
cout<<matrix1[i][i2]<<"\t";
	}
	cout<<"\n";
}
cout<<"\n";	
}	


int main ()
{
cout << "__ Set Matrix Zeroes__\n";
cout << "Given an m x n integer matrix matrix, if an element is 0,";
cout << "\nset its entire row and column to 0's.\nYou must do it in place.\n";
cout << "Fill _matrixin1.txt  in the program's directory.\n";
cout << "If absent, program will create new. Columns are tab-separated.\n";
 		
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

cout<<"\nOutput:\n";
setZeroes(matrix1);

cout<<"\nby OlegTim\t";  system("pause");
  return 0;
}
