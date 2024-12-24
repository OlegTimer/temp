#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<vector<int> >  matrix1;

int singleman(){
int z=1;	
	for (int i = 0; i<matrix1.size()/2; i++){
	if (matrix1[i][i]==-1){z=0; break;}
	}
return z;	
}


int main ()
{
cout << "__ Finding Bipartite Matching (Stable Marriage Problem) __\n";
cout << "Fill _matrixin1.txt  in the program's directory. _output.txt will be created.\n";
cout << "If absent, program will create new. Columns are tab-separated.\n_\n";
cout << "Perfect Matching. In 2 same-number groups elements range elements in other group\n";
cout<<"Say, John prefers Mary rather than Kate. Tom prefers Kate rather than Mary.\n";
cout<<"Mary prefers Tom rather than John. Kate prefers John rather than Tom.\n";
cout<<"The table of desire (person on left feels to right; 1 is best) will be:\n";
cout<<"\tJohn\tTom\tMary\tKate\n";
cout<<"John\t0\t0\t1\t2\n"; 
cout<<"Tom\t0\t0\t2\t1\n";
cout<<"Mary\t2\t1\t0\t0\n";
cout<<"Kate\t1\t2\t0\t0\n";
cout<<"The input must be:\n";
cout<<"0\t0\t1\t2\n";
cout<<"0\t0\t2\t1\n";
cout<<"2\t1\t0\t0\n";
cout<<"1\t2\t0\t0\n";
 	
vector<string> arr;
string str ("");
   
ifstream file("./_matrixin1.txt");
if(!file) {
cout << "Cannot open file _matrixin1.txt. Trying to create new\n";
ofstream out3("_matrixin1.txt"); 
if(!out3) {
cout << "Cannot create _matrixin1.txt\n";
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
if (d==0){d=-1;}
v.push_back(d);
}
 matrix1.push_back(v);   
    }
    file.close();
}	

if(matrix1.size()<1){cout<<"ERR_empty entry\n";system("pause");return 1;} 
if(matrix1.size()<4){cout<<"ERR_at least 4 people\n";system("pause");return 1;} 	
if(matrix1.size()!=matrix1[0].size()){cout<<"entry not square\n";system("pause");return 1;}
if(matrix1.size()%2!=0){cout<<"ERR 2 groups must be of a same size\n";system("pause");return 1;} 
 
cout<<"\nInput:\n"; 
for (int i = 0; i < matrix1.size(); i++) {
	for (int i2 = 0; i2 < matrix1[i].size(); i2++) {
		int r = matrix1[i][i2];
		if (r==-1){r=0;}
cout<<r<<"\t";
	}
	cout<<"\n";
} 
cout<<"\n";

//cout<<singleman()<<"\n";
while (singleman()==0){
int m=0;	
	for (int i = 0; i<matrix1.size()/2; i++){
	if (matrix1[i][i]==-1){m=i; break;}
	}
	
int f=0;
int top = 2147483647 ; // first is top, second is worse... etc	
	for (int i = matrix1.size()/2; i<matrix1.size(); i++){
	if (matrix1[m][i]!=-1 && matrix1[m][i]<top){top=matrix1[m][i];f=i; }
	}

//	cout<<m<<"\t"<<f<<"\n"; 	system("pause");
if (matrix1[f][f]==-1){
	matrix1[f][f]=m;
	matrix1[m][m]=f;
}
	else {
		if (matrix1[f][m] !=-1 && matrix1[f][m] < matrix1[f][f] ){
				int pre = matrix1[f][f];
				matrix1[f][f]=m;
				matrix1[m][m]=f;
				matrix1[f][pre]=-1;
				matrix1[pre][pre]=-1;
				}else{matrix1[m][f]=-1;}
	}
	
}


cout<<"Couples in order, starting from 0 as first name (M F):\n";
	for (int i = 0; i<matrix1.size()/2; i++){
cout<<i<<"\t"<<matrix1[i][i]<<"\n";
	}


ofstream outw("./_output.txt"); 
if(!outw) {
cout << "Cannot create _output.txt\n";
cout<<"\n"; system("pause");
exit(1);
}
	for (int i = 0; i<matrix1.size()/2; i++){
outw<<i<<"\t"<<matrix1[i][i]<<"\n";
	}	
outw.close();	
	

cout<<"\nby OlegTim\t";  system("pause");
  return 0;
}