#include <iostream>
using namespace std;
int main() {
cout<<"Pascal's Triangle.\n";
cout<<"In it, each number is the sum of the two numbers directly above";
cout<<"\nEnter num of rows (1-30): ";	
int input;	
cin>>input;
if(input<1||input>30){cout<<"err_input\n";system("pause");return 0;}
if (input%2==0){input++;}
int input2 = input*2+1;
int arr[input][input2];
for (int i = 0; i<input; i++){for (int i2 = 0; i2<input2; i2++){arr[i][i2]=0;}}
arr[0][input]=1;
for (int i = 1; i<input; i++){
for (int i2 = 0; i2<input2; i2++){
int left=0;
int right=0;
if (i2-1>0){left=arr[i-1][i2-1];}
if (i2+1<input2){right=arr[i-1][i2+1];}
arr[i][i2]=left+right;
}}
for (int i = 0; i<input; i++){for (int i2 = 0; i2<input2; i2++){cout<<"";
if (arr[i][i2]==0){cout<<" ";}else{cout<<arr[i][i2];}
cout<<"\t";}cout<<"\n";}
cout<<"\nbyOlegTim\n";
    system("pause");
    return 0;
}