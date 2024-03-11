#include <iostream>
using namespace std;

int main()
{
cout<<"_ Limited grow model predator-prey _\n\n";	
cout<<"Let's assume, wolves eat rabbits only. Their population is limited.\n";
cout<<"Max number of rabbits is 100. Rabbits number at start is 50\n";
cout<<"Wolves' number is 10. Wolf natural death rate is 0.8 per cycle (year)\n";	
cout<<"Rabbit's death coefficient is 0.01 Wolf's birth coefficient is 0.012\n";		
cout<<"If we iterate 20 cycles, number of wolfes and rabbits is const: 66/33\n";

int iter;
double rabbitMax,rabbit,wolf,wolfDeath,rabbitDeath,wolfBirth; 

cout<<"\nEnter max number of rabbits, please: ";
cin>>rabbitMax;
cout<<"Enter the start number of rabbits: ";
cin>>rabbit;
cout<<"Enter the start number of wolves: ";
cin>>wolf;
cout<<"Enter the natural death rate of wolves: ";
cin>>wolfDeath;
cout<<"Enter the death coefficient of rabbits: ";
cin>>rabbitDeath;
cout<<"Enter the birth coefficient of wolves: ";
cin>>wolfBirth;
cout<<"Enter the number of cycles: ";
cin>>iter;

cout<<"\nCycle\tRabbit\tWolf\n";
for (int i = 0; i<iter+1; i++){	
cout<<i<<"\t";
printf("%.1f\t", rabbit); 
printf("%.1f\n", wolf); 
if (i==0){cout<<"___\t___\t___\n";}
rabbit = (1 + ((rabbitMax-rabbit)/rabbitMax) -rabbitDeath*wolf) * rabbit;
wolf = (1 - wolfDeath + wolfBirth*rabbit) * wolf;	
}
	
cout<<"\n\nby OlegTim\t"; system("pause");
return 0;
}
