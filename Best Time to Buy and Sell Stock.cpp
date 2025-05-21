#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
int maxProfit(vector<int>& prices) {
int z = 0;
int min = prices[0];
int max = prices[0];
for (int i =1;i<prices.size(); i++){//
if (prices[i]<min){
min = prices[i];
}
else{
	if (prices[i]-min>z){max = prices[i]; z= max-min;}
}
}//	
return z;        
    }
int main() {
cout<<"__ Best Time to Buy and Sell Stock __\n";
cout<<"Array prices, prices[i] is the price of a given stock on the i-th day";
cout << "\nFill _input.txt  in the program's directory.\n";
cout << "If absent, program will create new. Columns are tab-separated.\n";
cout << "You want to maximize profit by choosing a single day to buy one stock";
cout << "\nand choosing a different day in the future to sell that stock.\n";
cout << "Returns the maximum profit you can achieve from this transaction.\n\n";
 	
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

cout<<"Input of prices is:\n";
for (int i =0;i<prices.size(); i++){cout<<prices[i]<<" "; }	cout<<"\n";

cout<<"Max profit is: "<<maxProfit(prices);

cout<<"\nbyOlegTim\n";
    system("pause");
    return 0;
}