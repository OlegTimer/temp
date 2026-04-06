#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<vector<int> >  matrix1;


int orangesRotting(vector<vector<int> >& grid) {
int res= -1; 
int fresh =0;
int rot = 0; 
int delta = -1;
int empty =0; 
int steps = 0;
for (int i = 0; i < grid.size(); i++) {for (int i2 = 0; i2 < grid[i].size(); i2++) { if (grid[i][i2]==1){ fresh++; } if (grid[i][i2]==2){ rot++; } }}
int rotstart = rot;
int freshstart = fresh;

while (delta!=0)
{//
for (int i = 0; i < grid.size(); i++) {for (int i2 = 0; i2 < grid[i].size(); i2++) { 
if (i-1>-1 && grid[i-1][i2]==2 && grid[i][i2]==1){ grid[i][i2]=3; } 
if (i2-1>-1 && grid[i][i2-1]==2 && grid[i][i2]==1){ grid[i][i2]=3; } 
if (i+1 < grid.size() && grid[i+1][i2]==2 && grid[i][i2]==1){ grid[i][i2]=3; } 
if (i2+1 <  grid[i].size() && grid[i][i2+1]==2 && grid[i][i2]==1){ grid[i][i2]=3; } 
}}

delta=0;
for (int i = 0; i < grid.size(); i++) {for (int i2 = 0; i2 < grid[i].size(); i2++) { if (grid[i][i2]==3){ grid[i][i2]=2; delta++; rot++; fresh--;  } }}
// cout<<"\n"; for (int i = 0; i < grid.size(); i++) {for (int i2 = 0; i2 < grid[i].size(); i2++) {cout<<grid[i][i2]<<"\t";}cout<<"\n";}
steps++;
}//

 cout<<"\nFin:\n"; for (int i = 0; i < grid.size(); i++) {for (int i2 = 0; i2 < grid[i].size(); i2++) {cout<<grid[i][i2]<<"\t";}cout<<"\n";}  

if (fresh==0 ){res=steps-1;}
return   res;      
}


int main ()
{
cout << "__ Rotting Oranges Step Simulation __\n";
cout << "You are given an m x n grid where each cell can have one of three values:";
cout << "\n0 representing an empty cell,\n";
cout << "1 representing a fresh orange, or\n";
cout << "1 representing a fresh orange, or\n";
cout << "2 representing a rotten orange. ";
cout << "Every step,  \nany fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.\n";
cout << "Return the minimum number of steps that must elapse until no cell has a fresh orange.\n";
cout << "If this is impossible, return -1.\n";
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


int res = orangesRotting(matrix1);
cout<<"\nRes: "<< res;

cout<<"\nby OlegTim\t";  system("pause");
  return 0;
}
