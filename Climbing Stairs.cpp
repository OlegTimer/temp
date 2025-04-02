#include <iostream>
using namespace std;
int climbStairs(int n) {
int temp=0;	
int pre=0;
int now=1;
for (int i=0;i<n;i++){
temp = pre+now;
pre = now;
now = temp;	
}
return now;        
    }
int main() {
cout<<"Climbing Stairs. You are climbing a staircase. It takes n steps to reach the top.";
cout<<"\nEach time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?";
cout<<"\nEnter num of stairs: ";	
int input;	
cin>>input;
input = climbStairs(input);
cout<<"Number of ways is: "<<input<<"\nbyOlegTim\n";
    system("pause");
    return 0;
}