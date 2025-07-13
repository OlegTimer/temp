#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;



int searchInsert(vector<int>& nums, int target) {
int res=0;
int win =0;
int pos = nums.size()/2;
int left=0;
int right= nums.size()-1;
while (right-left>1){
// cout<<"pos:"<<pos<<" l:"<<left<<" r:"<<right<<" nums[pos]:"<<nums[pos]<<"\n";	  
if (nums[pos]==target){res=pos; win=1; break;}
if (nums[pos]>target){right=pos-1; pos-=(right-left)/2; continue;}
if (nums[pos]<target){left=pos+1;  pos+=(right-left)/2; continue;}	  
	  }
if (win==0){
if (nums[pos]>target)
{ while (nums[pos]>target){pos--; } if (nums[pos]<target){pos++; } }
else { while (nums[pos]<target){pos++;  } }
res=pos;	
	 }	 
return res;        
}
    
    
int main() {
cout<<"__ Search Insert Position __\n";
cout<<"Given a sorted array of distinct integers and a target value, \n";
cout << "return the index if the target is found.\n";
cout<<"If not, return the index where it would be if it were inserted in order.";
cout << "\nSay, Input: nums = [1,3,5,6], target = 2 Output: 1\n";
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
vector<double> v;
for (int i = 0; i < arr.size(); i++) {
int d = atoi(arr[i].c_str());
 array.push_back(d); 
} 
    }
    file.close();
}	

if(array.size()<3){cout<<"empty entry\n";system("pause");return 1;} 

int target = array[array.size()-1];
array.pop_back();
cout<<"Input of array is:\n";
for (int i =0;i<array.size(); i++){cout<<array[i]<<" "; }	cout<<"\n";
cout<<"Target is: "<<target<<"\n";

int result;
result = searchInsert(array, target);
cout<<"Output: "<<result;

cout<<"\n\nbyOlegTim\n";
    system("pause");
    return 0;
}
