#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;


vector<int> findAnagrams(string s, string p) {
vector<int> z;
unordered_map<char, int> pmap;
for (int i =0;i<p.size(); i++){ 
if (pmap.count(p[i])) {pmap[p[i]]++;} else {pmap[p[i]]=1;}
}
unordered_map<char, int> smap;
for (int i =0;i<p.size(); i++){ 
if (smap.count(s[i])) {smap[s[i]]++;} else {smap[s[i]]=1;}
}

for (int i =0;i<s.size()-p.size()+1; i++){
// cout <<"\n__ "; if (pmap==smap){cout <<"Y"; }else{cout <<"N";}cout <<"\n";
// for (const auto& element : smap) {std::cout << element.first << "\t" << element.second << std::endl; } cout <<"\n";
// for (const auto& element : pmap) {std::cout << element.first << "\t" << element.second << std::endl; }	
if (pmap==smap){z.push_back(i); }
if (smap.count(s[i+p.size()])) {smap[s[i+p.size()]]++;} else {smap[s[i+p.size()]]=1;}
if (smap.count(s[i])) {smap[s[i]]--; if (smap[s[i]] <1) {smap.erase(s[i]);} }
}


return    z;     
}

    
int main() {
cout<<"__ Sliding Window Anagrams in a String __\n";
cout<<"Given two strings s and p, return an array of all the start indices of p's anagrams in s.";
cout << "\nFill _input.txt  in the program's directory.\nFirst line for s, second for p. ";
cout << "If absent, program will create new. \n";
 	
string s ("");
string p ("");
   
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
	std::getline(file, line);
	p = line.c_str();
    file.close();
}	

if(s.size()<1){cout<<"empty entry\n";system("pause");return 1;} 
if(s.size()<p.size()){cout<<"s cannot be smaller than p\n";system("pause");return 1;} 

cout<<"\nInput s:\n";
cout<<s<<"\n";
cout<<"Input p:\n";
cout<<p<<"\n\nOutput:\n";

vector<int> z = findAnagrams(s,p);
for (int i =0;i<z.size(); i++){cout<<z[i]<<" "; }	cout<<"\n";


cout<<"\nbyOlegTim\n";
    system("pause");
    return 0;
}