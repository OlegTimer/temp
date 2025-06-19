#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;


void qs(int *num, int left, int right)
{
  register int i, j;
  int x, y;
  i = left; j = right;
  x = num[(left+right)/2]; 
  do {
    while((num[i] < x) && (i < right)) i++;
    while((x < num[j]) && (j > left)) j--;
    if(i <= j) {
      y = num[i];
      num[i] = num[j];
      num[j] = y;
      i++; j--;
    }
  } while(i <= j);
  if(left < j) qs(num, left, j);
  if(i < right) qs(num, i, right);
}


vector<int> twoSum(vector<int>& nums, int target) {
vector<int> res;
res.push_back(0); 
res.push_back(0); 
int num[nums.size()];
for (int i=0; i<nums.size();i++){num[i]=nums[i];}
qs(num,0,nums.size()-1);
// for (int i=0; i<nums.size();i++){cout<<num[i]<<" ";}
int br = 0;
for (int i=0; i<nums.size();i++)		{
if (br==1){break;}	  	  
if (nums[i]>=target){continue; }
if (nums[i]+num[0]>target){continue; }
int delta =0;
while(1)	{
if (nums[i]+num[delta]==target){//
if (nums[i]==num[delta]  ){//-
if (delta-1>-1 && num[delta-1]==nums[i]){  delta--;}
else if(delta+1<=nums.size()-1 && num[delta+1]==nums[i]){ delta++;} else{break;}
}//-
res[0]=i;
for (int i2=0; i2<nums.size();i2++)
{if (nums[i2]==num[delta] && i2!=i){res[1]=i2; break;} }
br=1; break;
}//	
if (nums[i]+num[delta]<target){int v = (nums.size()-delta)/2;  delta+=v;}
if (nums[i]+num[delta]>target){int v = (nums.size()-delta)/2;  delta-=v;}	 
		 	}	
								  	  }		
return res;        
}
    
    
int main() {
cout<<"__ Two Sum __\n";
cout<<"Given an array of integers nums and an integer target, \n";
cout << "return indices of the two numbers such that they add up to target.\n";
cout << "You may assume that each input would have exactly one solution, \n";
cout << "and you may not use the same element twice.\n";
cout << "Say, Input: nums = [2,7,11,15], target = 9 Output: [0,1]\n";
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
double d = atof(arr[i].c_str());
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

vector<int> result;
result = twoSum(array, target);
cout<<"Output: ["<<result[0]<<","<<result[1]<<"]";

cout<<"\n\nbyOlegTim\n";
    system("pause");
    return 0;
}
