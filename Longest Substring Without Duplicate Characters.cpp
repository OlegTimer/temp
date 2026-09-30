#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_set>
using namespace std;


int lengthOfLongestSubstring(string s) {
unordered_set <char> set;
int left =-1;
int right = -1;
int max =0;
int count=0;
for (int i =0; i <s.length(); i++){//
if (set.count(s[i]) ){
if (count > max){max = count;}
count--;
i--;
set.erase(s[left]);
left++;
}
else{
right = i;
set.insert(s[right]);
count++;
if (left==-1){left=i;}	
}
// for (int z=left; z<right+1; z++) {cout <<s[z]; } cout <<"\n";
}//
if (count > max){max = count;}
return    max;     
}

    
int main() {
cout<<"__ Longest Substring Without Duplicate Characters - Sliding Window__\n";	
cout<<"Given a string s, find the length of the longest substring without duplicate characters.";
cout << "\nFill _input.txt  in the program's directory.\n";
cout << "If absent, program will create new. \n";
 	
string s ("");
   
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
 	std::getline(file, line);
	s = line.c_str();
    file.close();
}	

if(s.size()<1){cout<<"empty entry\n";system("pause");return 1;} 

cout<<"\nInput s:\n";
cout<<s<<"\n\nOutput:\n";
cout<<lengthOfLongestSubstring(s)<<"\n";

cout<<"\nbyOlegTim\n";
    system("pause");
    return 0;
}