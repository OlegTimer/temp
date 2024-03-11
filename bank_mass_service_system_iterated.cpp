#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;
int main()
{
int entermax,servmin,servmax,total,maxdelay,cashiers;
cout<<"_ Bank mass service system iterated _\n\n";
cout<<"Stating from zero, clients visit the bank. Cashiers need some time.\n";
cout<<"Given some random range of new clients and serve time,\n";
cout<<"let's find the value of clients waiting too long of all time.\n\n";
cout<<"Say, minimal time to serve client is 1 minute, and maximal is 9,\n";
cout<<"No more than 4 new clients can appear in 1 minute.\n";
cout<<"Client is OK to wait not more than 15 minutes.\n";
cout<<"Total day of work is 480 minutes with 6 cashiers.\n";
cout<<">> Client will wait too long about 7 % of total time.\n";
cout<<"If it's too much, we can use 7 cashiers: client will not wait too long";

cout<<"\n\n\nEnter integer min. time for a cashier to serve a client, please: ";
cin>>servmin;
cout<<"Enter integer max. time for a cashier to serve a client, please: ";
cin>>servmax;
cout<<"Enter integer max. number of new clients to enter in 1 minute: ";
cin>>entermax;
cout<<"Enter integer number of minutes of total day of work: ";
cin>>total;
cout<<"Enter integer value of minutes client is OK to wait: ";
cin>>maxdelay;
cout<<"Enter integer number of cashiers: ";
cin>>cashiers;

time_t lt = time('\0');
srand(lt%15);
int randseed = rand();
int servdelta = servmax-servmin;
int temprand,badtime,customers,newcustomers,offcustomers,timeserv,wait;
badtime=customers=0;

for (int i=0; i<total; i++){
temprand = randseed%(servdelta+1);
randseed++;
timeserv=temprand+1;
temprand = randseed%(entermax+1);
newcustomers=temprand;
randseed++;
offcustomers = round(cashiers/timeserv);
customers += newcustomers - offcustomers;
if (customers<0){customers=0;}
wait = customers/(cashiers*timeserv);
if (wait>maxdelay){badtime++;}
}

double res = 100.0*badtime/total;
cout<<"\nWait too long at "<<res<<" % of total time.";
cout<<"\nby_OlegTim \t"; system("pause");
return 0;
}
