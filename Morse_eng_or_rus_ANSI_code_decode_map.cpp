#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
using namespace std;
// Morse_eng_or_rus_ANSI_code_decode_map_by_OlegTim
string s = "Enter line to _input.txt in program's directory. Run the program. \
Rus ANSI on Windows is case-sensitive, try capital. \
Result is in _output.txt";
map<char, string> m;
map<char, string> n;
map<char, string> r;

string getmcode(char c){
string s="";
map<char, string>::iterator p;
p = m.find(c);
if(p!= m.end()){s=p->second;}
return s;	   
}
string getncode(char c){
string s="";
map<char, string>::iterator p;
p = n.find(c);
if(p!= n.end()){s=p->second;}
return s;	   
}
string getrcode(char c){
string s="";
map<char, string>::iterator p;
p = r.find(c);
if(p!= r.end()){s=p->second;}
return s;	   
}
char getmchar(string s){
char c=' ';
for (std::map<char, string>::iterator it = m.begin(); it != m.end(); ++it)
{
char i = it->first; 	
string i2 = it->second;
if (i2==s){c=i; }
}
return c;	   
}
char getnchar(string s){
char c=' ';
for (std::map<char, string>::iterator it = n.begin(); it != n.end(); ++it)
{
char i = it->first; 	
string i2 = it->second;
if (i2==s){c=i; }
}
return c;	   
}
char getrchar(string s){
char c=' ';
for (std::map<char, string>::iterator it = r.begin(); it != r.end(); ++it)
{
char i = it->first; 	
string i2 = it->second;
if (i2==s){c=i; }
}
return c;	   
}

int main()
{
int fromcode =0; //if 0 from letters to code; if not 0 from code to letters
string sp=" ";  	
string s1="";
string s2="";  	
m.insert(pair<char, string>('A', ".-"));
m.insert(pair<char, string>('B', "-..."));
m.insert(pair<char, string>('C', "-.-."));
m.insert(pair<char, string>('D', "-.."));
m.insert(pair<char, string>('E', "."));
m.insert(pair<char, string>('F', "..-."));
m.insert(pair<char, string>('G', "--."));
m.insert(pair<char, string>('H', "...."));
m.insert(pair<char, string>('I', ".."));
m.insert(pair<char, string>('J', ".---"));
m.insert(pair<char, string>('K', "-.-"));
m.insert(pair<char, string>('L', ".-.."));
m.insert(pair<char, string>('M', "--"));
m.insert(pair<char, string>('N', "-."));
m.insert(pair<char, string>('O', "---"));
m.insert(pair<char, string>('P', ".--."));
m.insert(pair<char, string>('Q', "--.-"));
m.insert(pair<char, string>('R', ".-."));
m.insert(pair<char, string>('S', "..."));
m.insert(pair<char, string>('T', "-"));
m.insert(pair<char, string>('U', "..-"));
m.insert(pair<char, string>('V', "...-"));
m.insert(pair<char, string>('W', ".--"));
m.insert(pair<char, string>('X', "-..-"));
m.insert(pair<char, string>('Y', "-.--"));
m.insert(pair<char, string>('Z', "--.."));

n.insert(pair<char, string>('1', ".----"));
n.insert(pair<char, string>('2', "..---"));
n.insert(pair<char, string>('3', "...--"));
n.insert(pair<char, string>('4', "....-"));
n.insert(pair<char, string>('5', "....."));
n.insert(pair<char, string>('6', "-...."));
n.insert(pair<char, string>('7', "--..."));
n.insert(pair<char, string>('8', "---.."));
n.insert(pair<char, string>('9', "----."));
n.insert(pair<char, string>('0', "-----"));

r.insert(pair<char, string>('À', ".-"));
r.insert(pair<char, string>('Á', "-..."));
r.insert(pair<char, string>('Â', ".--"));
r.insert(pair<char, string>('Ã', "--."));
r.insert(pair<char, string>('Ä', "-.."));
r.insert(pair<char, string>('Å', "."));
r.insert(pair<char, string>('Æ', "...-"));
r.insert(pair<char, string>('Ç', "--.."));
r.insert(pair<char, string>('É', ".."));
r.insert(pair<char, string>('È', ".---"));
r.insert(pair<char, string>('Ê', "-.-"));
r.insert(pair<char, string>('Ë', ".-.."));
r.insert(pair<char, string>('Ì', "--"));
r.insert(pair<char, string>('Í', "-."));
r.insert(pair<char, string>('Î', "---"));
r.insert(pair<char, string>('Ï', ".--."));
r.insert(pair<char, string>('Ğ', ".-."));
r.insert(pair<char, string>('Ñ', "..."));
r.insert(pair<char, string>('Ò', "-"));
r.insert(pair<char, string>('Ó', "..-"));
r.insert(pair<char, string>('Ô', "..-."));
r.insert(pair<char, string>('Õ', "...."));
r.insert(pair<char, string>('Ö', "-.-."));
r.insert(pair<char, string>('×', "---."));
r.insert(pair<char, string>('Ø', "----"));
r.insert(pair<char, string>('Ù', "--.-"));
r.insert(pair<char, string>('Ü', "-..-"));
r.insert(pair<char, string>('Û', "-.--"));
r.insert(pair<char, string>('İ', "..-.."));
r.insert(pair<char, string>('Ş', "..--"));
r.insert(pair<char, string>('ß', ".-.-"));

ifstream in("_input.txt", ios::in | ios::binary);
if(!in) {
// cout << "Cannot open _input.txt\n";
ofstream out3("_input.txt"); 
if(!out3) {
cout << "Cannot create _input.txt\n";
return 1;
}
out3 << s;
out3.close();
}
s="";
char ch;
while(in) {
in.get(ch);
if(in) { 
s+=ch;}
}
in.close();

for(int i=0; s[i]; i++){ s[i] = toupper(s[i]);}
if (s[0]=='.' || s[0]=='-'){fromcode=1;}

if (fromcode==0){
for(int i=0; s[i]; i++){   				 
char ch = s[i];
if (ch=='¨'){ch='Å';} 
if (ch=='Ú'){ch='Ü';}
s1+=getmcode(ch);
s1+=getncode(ch);
s1+=getrcode(ch);
s1+=sp;
}
}

if (fromcode!=0){
vector<string> arr;
size_t prev = 0;
size_t next;
size_t delta = sp.length();
while( ( next = s.find( sp, prev ) ) != string::npos ){
arr.push_back( s.substr( prev, next-prev ) );
prev = next + delta;
  }
arr.push_back( s.substr(prev ) );
for (int i = 0; i < arr.size(); i++) {
if(getmchar(arr[i])!=' '){ s1+=getmchar(arr[i]); }
if(getrchar(arr[i])!=' '){ s2+=getrchar(arr[i]); }
if(getnchar(arr[i])!=' '){ s1+=getnchar(arr[i]);  s2+=getnchar(arr[i]); }
}   				 
}

ofstream out("_output.txt"); 
if(!out) {
cout << "Cannot create _output.txt\n";
return 1;
}
out.close();
ofstream out4("_output.txt", ios::app); 
if(!out4) {
cout << "Cannot open _output.txt\n";
return 1;
}
out4 << s1<<"\n";
out4 <<s2;
out4.close();

return 0;
}
