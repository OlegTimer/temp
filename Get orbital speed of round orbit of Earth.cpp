#include <iostream>
#include <math.h>
using namespace std;

int main()
{
cout << "_ Get orbital speed of round orbit of Earth _\n\n"; 	
double height; 	
cout << "Insert height on Earth (km): ";
cin >> height;
long double speed = sqrt(398600/(6371+height));
cout<<"\Orbital speed is: "<<speed<<" km/s"; 
cout<<"\n\nby OlegTim\t"; system("pause");
return 0;
}
