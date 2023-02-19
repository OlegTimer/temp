#include <stdio.h>
#include <iostream.h>
int arr[9] ;
int main()
{
cout <<"__ Tic tac toe C++ by OlegTim __"<<"\n";
cout <<"Make lines. 0 to quit."<<"\n"<<"\n";
 for (int i = 0; i < 9; i++){ arr[i]=0;	 }	
void  arrshow();
void  place(int);
int answer;

while (true){
arrshow();
cout << "Insert cell number: ";
cin >> answer;

if (answer==0){exit(0);}
if (answer>0&&answer<10){
cout <<"\n";
place(answer-1);
}
else{cout <<"\n" <<"Enter 0-9 only!"<<"\n"; answer=-1;}
}
cout <<"\n"; system("pause");
return 0;
}

void arrshow(){
	 int z=0;
	 for (int i = 0; i < 9; i++){ 
	 	 int res = arr[i];
	 	 if (res==0) {cout <<  i+1;}else{
		 if (res==1) {cout <<"X";}else{cout <<"O";} }
		  z++;
		  if (z>2){z=0; cout<<"\n";}	 
	 }	
	 }
	 
void place(int i){
	 int checkv(int num);
	 if (arr[i]==0){
	arr[i]=1;
cout  <<"You placed X to: " << i+1 <<"\n"; 
int res = checkv(1);
if (res==0){
  void compmove();
	  compmove();}
	  else{
	  	   void end (int num);
	  end(1);	   
	  	   }   
} //if arr[i] !=0
else{cout << i+1 <<" cell is already in use" <<"\n";}
	 }	  
	 
void compmove(){
	 int r1=0; int r2=0; int r3=0;
     int c1=0; int c2=0; int c3=0;
	 int i = 0; int t=0;
	if (arr[4]==0){t=4;}else{	   						 	   						 
int iterat(int num);
int thirdpc =0;
int thirdpl =0;
for (int i = 0; i<8; i++){
int line =  iterat(i);
 r1= (line%1000)/100;
 r2= (line%100)/10;
 r3= line%10;
 c1 = arr[r1];  c2 = arr[r2];  c3 = arr[r3];
//cout <<c1 <<" "<<c2<<" "<<c3<< "\n";
if (c1==0||c2==0||c3==0) {if (c1+c2+c3==4){thirdpc++;  break;}}
if (c1==0||c2==0||c3==0) {if (c1+c2+c3==2)if(c1!=2&&c2!=2&&c3!=2){{thirdpl++; break;}}}
}//loop end	   						 

if (thirdpc>0){		   
if (arr[r1]==0){t=r1;} if (arr[r2]==0){t=r2;} if (arr[r3]==0){t=r3;}
				  }else{
		if (thirdpl>0){		   			   
if (arr[r1]==0){t=r1;} if (arr[r2]==0){t=r2;} if (arr[r3]==0){t=r3;}		   			   
		   			   }else{
for (i = 0; i<9; i++){ if (arr[i]==0){t=i; break;}  } 					   		 
					   		 				  }		  		
   					 }   					 					 
								}//if center is not zero end
	
	int r= 0;	  
	 for (i = 0; i<9; i++){	 if (arr[i]==0){r++;} }
	 if (r==0){void end (int num);
	  end(0);}
	  else{
	  	  if (arr[t]==0) {arr[t]=2;
cout  <<"Computer placed O to: " << t+1 <<"\n"; }
	 	 int checkv(int num);
	 int res = checkv(2);
	 if (res!=0){ void end (int num);
	  end(2);}
	  }
	 }	 
	 
	 void end (int num){
	 	  void  arrshow();
	 	  arrshow();
	 	   for (int i = 0; i < 9; i++){ arr[i]=0;	 }
if (num==0){ cout  <<"_ Draw... _" <<"\n"; }
if (num==1){ cout  <<"_ You WIN! _" <<"\n"; }
if (num==2){ cout  <<"_ You failed. _" <<"\n"; }
	 	  cout   <<" Starting new game: "<<"\n"<<"\n";
	 	  }
	 	  
	 	  int checkv(int num){
int res = 0;	
int iterat(int num);
for (int i = 0; i<8; i++){
int line =  iterat(i);
int r1= (line%1000)/100;
int r2= (line%100)/10;
int r3= line%10;
int c1 = arr[r1]; int c2 = arr[r2]; int c3 = arr[r3];
//cout <<c1 <<" "<<c2<<" "<<c3<< "\n";
if (c1==num&&c2==num&&c3==num){res++; break;}
}
	  return res;
	 }	
	 
	 int iterat(int num){
	 	 int res=1000;
if (num==0){ res = res+ 12;}
if (num==1){ res = res+ 345;}
if (num==2){ res = res+ 678;}
if (num==3){ res = res+ 36;}
if (num==4){ res = res+ 147;}
if (num==5){ res = res+ 258;}
if (num==6){ res = res+ 48;}
if (num==7){ res = res+ 246;}
	 	   return res;
			}