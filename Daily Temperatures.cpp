#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;


vector<int> dailyTemperatures(vector<int>& temperatures) {
vector<int> res;
for (int i =0;i<temperatures.size(); i++){res.push_back(0); }
stack <int>	st;

for (int i =0;i<temperatures.size(); i++)	{//-	
while(!st.empty() && temperatures[i] > temperatures[st.top()] )			{//
int topIndex = st.top();
st.pop();
res[topIndex] = i - topIndex;															 	
																		}//
st.push(i);
		   							 	  	}//-
return  res;   
}

    
int main() {
cout<<"__ Daily Temperatures (next greater element problem) __\n";
cout<<"Given an array of int temperatures represents the daily temperatures,\n";
cout<<"return an array answer such that answer[i] is the number of day\n";
cout<<"you have to wait after the ith day to get a warmer temperature.";
cout<<"\nIf there is no future day for which this is possible, answer[i]==0\n";
cout<<"Fill _input.txt  in the program's directory. If absent\n";
cout<<"program will create new. Columns are tab-separated (and end too).\n\n";
 	
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
for (int i = 0; i < arr.size(); i++) {
int d = atoi(arr[i].c_str());
 array.push_back(d); 
} 
    }
    file.close();
}	

if(array.size()<1){cout<<"empty entry\n";system("pause");return 1;} 

cout<<"v Input of array is: v\n";
for (int i =0;i<array.size(); i++){cout<<array[i]<<"\t"; }	cout<<"\n";

vector<int> res = dailyTemperatures(array);

for (int i =0;i<res.size(); i++){cout<<res[i]<<"\t"; }	cout<<"\n";
cout<<"^ How many days to wait for hotter temperature: ^\n";
cout<<"\n\nbyOlegTim\n";
    system("pause");
    return 0;
}
