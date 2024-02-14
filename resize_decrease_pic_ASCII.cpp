#include <iostream>
#include <vector>
using namespace std;

int lines_num = 56; //rows num on screen	
vector<vector<char> >  sprite;
vector<vector<char> >  sprite2;


void decrease_more_one_less_two(int pix_del){ //arg is how many pixels we need to delete in h	 
	 										  		   	   if (pix_del>0){
int interv = pix_del;
interv = (int) (lines_num/interv);
int i2,j2;
i2=j2=0;
for (int i = 0; i<	lines_num; i++){	
	for (int j = 0; j<	lines_num; j++){
if (i%interv!=0 && j%interv!=0) {sprite2[i2][j2]=sprite[i][j]; j2++; }
   			   }
if (i%interv!=0 )  {i2++; j2=0;} 			   
   			}

for (int i=0;i<lines_num; i++){for (int j=0;j<lines_num; j++){sprite[i][j]='`';}}

for (int i=0;i<lines_num; i++){for (int j=0;j<lines_num; j++){
if (sprite2[i][j]!='`')	{sprite[i+pix_del/2][j+pix_del/2]=sprite2[i][j];}
	}}
	  																	 }
}


void decrease_twice(){
char c1, c2, c3, c4;
c1=c2=c3=c4='`';
for (int i = 0; i<	lines_num; i+=2){
	for (int j = 0; j<	lines_num; j+=2){
c1=sprite[i][j];
c2=sprite[i][j+1];
c3=sprite[i+1][j];
c4=sprite[i+1][j+1];
int count1, count2, count3,count4;
count1= count2= count3=count4=1;
if (c1==c2){count1++;} if (c1==c3){count1++;} if (c1==c4){count1++;}
if (c2==c1){count2++;} if (c2==c3){count2++;} if (c2==c4){count2++;}
if (c3==c1){count3++;} if (c3==c2){count3++;} if (c4==c4){count3++;}
if (c4==c1){count4++;} if (c4==c2){count4++;} if (c4==c3){count4++;}
if (count1>=2){}else{if (count2>=2){c1=c2;}else{if (count3>=2){c1=c3;}
else{if (count4>=2){c1=c4;}else{}}}}
sprite2[i/2][j/2]=c1;
}}

for (int i=0;i<lines_num; i++){for (int j=0;j<lines_num; j++){sprite[i][j]='`';}}

for (int i=lines_num/4;i<lines_num; i++){for (int j=lines_num/4;j<lines_num; j++){
if	(sprite2[i-lines_num/4][j-lines_num/4]!='`')
{sprite[i][j]=sprite2[i-lines_num/4][j-lines_num/4];}
}}		 
}//dec twice end


void decrease(int a)//Changes sprite. a is a needed pixel height of sprite
{
 	 			  			  if (a<lines_num && a>0){
if (a>lines_num/2){// if decrease_more_one_less_two start
decrease_more_one_less_two(lines_num-a);  				   
}// if decrease_more_one_less_two end
else{ //if decrease_twice start
int tempa = lines_num;
while (tempa/a>=2){
decrease_twice();
tempa=tempa/2;	  
	  }
decrease_more_one_less_two(tempa-a);  		  
}//if decrease_twice end
	  				 				  		   }	 
}


int main() {
for (int i = 0; i<	lines_num; i++){
	vector<char> v;
	for (int j = 0; j<	lines_num; j++){
if (i<lines_num/2)	{	v.push_back('*');} else {v.push_back('&');}
		}
	sprite.push_back(v);	
	}
	
for (int i =24; i<	32; i++){for (int j = 24; j<	32; j++){sprite[i][j]='$'; }}

for (int i = 0; i<	lines_num; i++){
	vector<char> v;
	for (int j = 0; j<	lines_num; j++){
	v.push_back('`');
		}
	sprite2.push_back(v);	
	}	

for (int i = 0; i<lines_num; i++){for (int j = 0; j<lines_num; j++){cout<<sprite[i][j]; } cout<<"\n";}	
cout<<"Enter even int the height of pixels to decrease (2-54) and press Enter: ";
int dec = 26;
cin>>dec;
decrease(dec);
for (int i = 0; i<lines_num; i++){for (int j = 0; j<lines_num; j++){cout<<sprite[i][j]; } cout<<"\n";}	
			
cout <<"\n"; system("pause");
return 0;
}
