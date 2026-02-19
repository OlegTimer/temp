#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
int singleNumber(vector<int>& nums) {
int z =   nums[0];
if (nums.size()>1) {
for (int i =1;i<nums.size(); i++){
z=z^nums[i];
}	
}     
return z;        
    }
int main() {
cout<<"__ Single Number __\n";
cout<<"Given a non-empty array of integers nums, every element appears twice except for one.";
cout << "Find that single one.";
cout << "\nYou must implement a solution with a linear runtime complexity and use only constant extra space.\n";
cout << "Fill _input.txt  in the program's directory.\n";
cout << "If absent, program will create new. Columns are tab-separated.\n\n";

 	
vector<int> prices;	
vector<string> arr;
string str ("");
   
ifstream file("./_input.txt");
if(!file) {
cout << "Cannot open file _input.txt. Trying to create new\n";
ofstream out3("_input.txt"); 
if(!out3) {
cout << "Cannot create _input.txt\n";
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
vector<double> v;
for (int i = 0; i < arr.size(); i++) {
double d = atof(arr[i].c_str());
 prices.push_back(d); 
} 
    }
    file.close();
}	

if(prices.size()<1){cout<<"empty entry\n";system("pause");return 1;} 

cout<<"Input is:\n";
for (int i =0;i<prices.size(); i++){cout<<prices[i]<<" "; }	cout<<"\n";

cout<<"\nSingle is: "<<singleNumber(prices);

cout<<"\nbyOlegTim\n";
    system("pause");
    return 0;
}