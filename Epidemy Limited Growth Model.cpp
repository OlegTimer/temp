#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;


int main ()
{
cout << "__ Epidemy (Limited Growth Model) __\n";

int population,  sicktime, immune, sick, sicktodayint, sickpre, fresh;
double coeff, sicktoday, sicktodaycum;

cout<<"Enter integer total population size: "; 	
cin>>	population;
cout<<"Enter double epidemy coeff (i.e. 0.5): "; 
cin>>coeff;
cout<<"Enter integer number of ill people from start: "; 
cin>>	sick;
cout<<"Enter integer days of being sick (and healthy after): "; 	
cin>>	sicktime;

// population = 1000; coeff = 0.5; sick = 1; sicktime = 7;

vector <int> v;
for (int i=0; i<sicktime; i++){
v.push_back(0);
}
fresh=population-sick;
sickpre=sick;
immune=0;
sicktodaycum=0.0;
sicktodayint = sick;
int day, sickmax = 0;
cout<<"\nday"<<"\t"<<"sick"<<"\t"<<"immune"<<"\t"<<"rest"<<"\n";


while(sickpre>0){
sicktoday = coeff*(population-sickpre-immune)/population*1.0*sickpre*1.0;

if (sicktoday + sicktodaycum <0.999){sicktodaycum+=sicktoday; v[0]=0; 	sicktodayint = round (sicktoday + sicktodaycum); }
else{ 
	sicktodayint = round (sicktoday + sicktodaycum);
	sicktoday = 0.0;
	sicktodaycum = sicktoday + sicktodaycum - sicktodayint*1.0 ;
	if (sicktodaycum<0){sicktodaycum=0.0;}	
	}
// cout<<"\n"<<sicktoday <<" "<<sicktodaycum<<" "<<sicktodayint; 	
immune+=v[sicktime-1];
for (int i=sicktime-1; i>0; i--){
v[i]=v[i-1];
		}
if (sicktoday + sicktodaycum <0.999 && sicktodayint==1) {sicktodayint=0;}		
v[0]=	sicktodayint;

sickpre = 0;	
for (int i=0; i<sicktime; i++){ sickpre+=v[i]; 	} ;
if(sickpre>sickmax){sickmax=sickpre;}
// for (int i=0; i<sicktime; i++){  cout<<v[i]<<" ";	} ; cout<<"\n";  //all sick at all days

cout<<day<<"\t"<<sickpre<<"\t"<<immune<<"\t"<<population-sickpre-immune<<"\n";
day++;
} 

cout<< "Lasted for "<<day<< " day(s). Been ill: "<<immune<<" Never been ill: "<<population-immune;
cout<<"\nMax total ill in one day: "<<sickmax;

cout<<"\nby OlegTim\t";  system("pause");
  return 0;
}