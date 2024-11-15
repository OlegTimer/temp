#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main ()
{
cout << "__ Different-shaped island counter __\n";
cout << "Fill _matrixin1.txt  in the program's directory.\n";
cout << "If absent, program will create new. Columns are tab-separated.\n";
cout<<"0 for water, and 1 for ground. Islands are totally water-separated, no diag.\n\n";
 	
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

if(matrix1.size()<1){cout<<"empty entry\n";system("pause");return 1;} 	
int startWater=0; 
int startGround=0;
 
for (int i = 0; i < matrix1.size(); i++) {
	for (int i2 = 0; i2 < matrix1[i].size(); i2++) {
cout<<matrix1[i][i2]<<" ";
if(matrix1[i][i2]!=0&&matrix1[i][i2]!=1){cout<<"\nERR_0_or_1_only\n";system("pause");return 1;}
if (i>0 && i2>0 ){
	if (matrix1[i][i2]==1 && matrix1[i-1][i2-1]==1&& matrix1[i][i2-1]==0 && matrix1[i-1][i2]==0){cout<<"\nERR_NO_diag\n";system("pause");return 1;}
	if (matrix1[i][i2]==0 && matrix1[i-1][i2-1]==0&& matrix1[i][i2-1]==1 && matrix1[i-1][i2]==1){cout<<"\nERR_NO_diag\n";system("pause");return 1;}
	}
if(matrix1[i][i2]==0){startWater++;}
if(matrix1[i][i2]==1){startGround++;}
	}
	cout<<"\n";
}

cout<<"\n";
if(startGround==0&&startWater!=0){cout<<"0 islands\n";system("pause");return 0;}
if(startGround!=0&&startWater==0){cout<<"1 island\n";system("pause");return 0;}
int count = 0;
int column, width;
column= width=0;

while(startGround>0)	{
for (int i = 0; i < matrix1.size(); i++) {
for (int i2 = 0; i2 < matrix1[i].size(); i2++) {
if(matrix1[i][i2]==1)
{//
count++;
matrix1[i][i2]=2;

int count2 = 1;
while (count2>0){//-
for (int q = 0; q < matrix1.size(); q++) {
for (int q2 = 0; q2 < matrix1[i].size(); q2++) {if(matrix1[q][q2]==2){
matrix1[q][q2]=0;
startGround--;
 if (q2>0 && matrix1[q][q2-1]==1){matrix1[q][q2-1]=2;}
 if (q2< matrix1[i].size()-1 && matrix1[q][q2+1]==1){matrix1[q][q2+1]=2;}
 if (q>0 && matrix1[q-1][q2]==1){matrix1[q-1][q2]=2;}
 if (q< matrix1.size()-1 && matrix1[q+1][q2]==1){matrix1[q+1][q2]=2;}
} }}	
count2 = 0;	
for (int q = 0; q < matrix1.size(); q++) {
for (int q2 = 0; q2 < matrix1[i].size(); q2++) {if(matrix1[q][q2]==2){count2++;} }}
}//-

}//
}}						 
	  					 }

cout<<"\n"<<count<<" island(s)";
cout<<"\nby OlegTim\t";  system("pause");
  return 0;
}