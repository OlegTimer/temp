#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void moveZeroes(vector<int>& nums) {
int p1 = 0;
int p2 = 1;	
for (int i =0;i<nums.size(); i++){
if (nums[p1]==0 && nums[p2]!=0){ nums[p1] =  nums[p2];  nums[p2] = 0;} 
if (nums[p1]!=0) {p1++;}
if (p2+1<nums.size())	{p2++;}  else {break;}
// for (int i2 =0;i2<nums.size(); i2++){cout<<nums[i2]<<" "; }	cout<<"_"<<i<<"_\n";
}	        
}

int main() {
cout<<"__ Best Move Zeroes __\n";
cout<<"Given an integer array nums move all 0's to the end\n";
cout<<"of it while maintaining the relative order of the non-zero elements.";
cout << "\nFill _input.txt  in the program's directory.\n";
cout << "If absent, program will create new. Columns are tab-separated.\n";
cout << "You must do this in-place without making a copy of the array.";
 	
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
vector<int> v;
for (int i = 0; i < arr.size(); i++) {
int d = atoi(arr[i].c_str());
 prices.push_back(d); 
} 
    }
    file.close();
}	

if(prices.size()<2){cout<<"too small entry\n";system("pause");return 1;} 

cout<<"\n\nInput is:\n";
for (int i =0;i<prices.size(); i++){cout<<prices[i]<<" "; }	cout<<"\n";

moveZeroes(prices);

cout<<"Output is:\n";
for (int i =0;i<prices.size(); i++){cout<<prices[i]<<" "; }	cout<<"\n";

cout<<"\nbyOlegTim\n";
    system("pause");
    return 0;
}