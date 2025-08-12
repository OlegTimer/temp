#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;



int majorityElement(vector<int>& nums) {
int counter = 0;
int maj=0;
for (int i =0; i<nums.size();i++){//
if (counter==0){
maj=nums[i]; counter++;	
}
else{
if (maj=nums[i]){counter++;	}	else{counter--;	}
}
}//
return maj;        
}
//Boyer–Moore    
    
int main() {
cout<<"__ Majority Element __\n";
cout<<"Given an array nums of size n, return the majority element. \n";
cout<<"The majority element is the element that appears more than n/2 times.\n";
cout<<"You may assume that the majority element always exists in the array.";
cout << "\nSay, Input: nums = [3,2,3] Output: 3\n";
cout << "Fill _input.txt  in the program's directory. Array and target.\n";
cout << "If absent, program will create new. Columns are tab-separated.\n\n";
 	
vector<int> array;	
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
 array.push_back(d); 
} 
    }
    file.close();
}	

if(array.size()<1){cout<<"empty entry\n";system("pause");return 1;} 

cout<<"Input of array is:\n";
for (int i =0;i<array.size(); i++){cout<<array[i]<<" "; }	cout<<"\n";

int result;
result = majorityElement(array);
cout<<"Output: "<<result;

cout<<"\n\nbyOlegTim\n";
    system("pause");
    return 0;
}
