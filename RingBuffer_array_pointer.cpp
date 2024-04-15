#include <iostream>
using namespace std;

#define SIZE 4

class RingBuff {
int arr[SIZE];
int *pos;
public :
RingBuff(); 
void add (int i) ;
int get ();
};

RingBuff::RingBuff()
{ pos =   &arr[0];}

void RingBuff::add(int i)
{  
*pos = i;
pos++;
if(pos>&arr[SIZE-1]) {pos=&arr[0];} 
}

int RingBuff::get()
{ 
pos-- ;
if(pos<&arr[0]) {pos=&arr[SIZE-1];} 
return *pos;
}


int main ()
{ 
RingBuff arr; 

for (int i=0; i<9;i++){arr.add(i*10);}
for (int i=0; i<9;i++){cout<<arr.get()<<"\n";}

cout<<"\nby OlegTim\t"; system("pause");
return 0;
}

