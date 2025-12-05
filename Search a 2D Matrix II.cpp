#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<vector<int> >  matrix1;


bool searchMatrix(vector<vector<int> >& matrix, int target) {
bool res = false;
int right = matrix[0].size()-1;
for (int i = 0; i < matrix.size(); i++) {
if (res==false){//
	for (int i2 = right; i2 > -1; i2--) {		
if (matrix[i][i2]==target){res=true; break;}
if (matrix[i][i2]>target){right--;}
}
}else{break;}//
}
return   res;      
}


int main ()
{
cout << "__ Search a 2D Matrix II __\n";
cout << "Algorithm that searches for a value target in an m x n integer matrix.";
cout << "\nIntegers in each row are sorted in ascending from left to right.\n";
cout << "Integers in each column are sorted in ascending from top to bottom.\n";
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

cout<<"\nEnter target: ";
int target;
cin>>target;
bool res = searchMatrix(matrix1, target);
if (res==1){cout<< "true";}else{cout<< "false";}

cout<<"\nby OlegTim\t";  system("pause");
  return 0;
}