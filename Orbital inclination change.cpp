#include <iostream>
#include <math.h>
using namespace std;

int main()
{
cout << "_ Get Orbital inclination/plane change delta-v (km/s)_\n"; 	
double pi = 3.141592653589;
double height; 	
double earthRadius = 6371.0;
int gravParam = 398600;
double deltaAngle;
double losses = 18.1;
cout<<"\nPlease, remember, the escape velocity from Earth is 11.186 km/s";
cout<<"\nA sphere of influence (SOI) of Earth is about 1 mln km";
cout << "\n\nInsert height of round orbit on Earth surface (km) (i.e. 200.0): ";
cin >> height;
cout << "Insert angle change on Earth (degrees) (i.e. 90.0): ";
cin >> deltaAngle;
double vel = sqrt(gravParam/(earthRadius+height));
deltaAngle = deltaAngle *pi/180;
double res = 2*vel*sin(deltaAngle/2);
double inc = res;
cout<<"\nOrbital inclination change delta-v is: "<<res<<" km/s"; 
cout<<"\nOrbital velocity is: "<<vel<<" km/s"; 
cout << "\nRequired to reach such orbit BEFORE inclination change:";
res = sqrt(2*gravParam/earthRadius) * sqrt(1 -(earthRadius/(2*(height+earthRadius))));
cout<<"\nMinimal characteristic delta v with NO losses: "<<res<<" km/s"; 
res+=res*losses/100;
cout<<"\n_Assuming total amount of losses (grav, etc) is "<<losses <<"% from minimal characteristic delta v, ";
cout<<"\ncharacteristic delta v WITH losses is: "<<res<<" km/s"<<"\n";
cout<<"_Assuming Earth rotation speed is 0.465 km/s and rocket is launched east at it best course,";
cout<<"\nthe delta v is decreased and, depending on launch pad,  delta v is:";
res-=0.465;
cout<<"\nfor equator (Kuru): "<<res<<" km/s and with inc. change: "<<res+inc<<" km/s";
res+=0.056;
cout<<"\nfor Cape Canaveral: "<<res<<" km/s and with inc. change: "<<res+inc<<" km/s";
res+=0.092;
cout<<"\nfor Baykonur: "<<res<<" km/s and with inc. change: "<<res+inc<<" km/s";
cout<<"\n\nby OlegTim\t"; system("pause");
return 0;
}