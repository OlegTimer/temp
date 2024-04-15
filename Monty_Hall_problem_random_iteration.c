#include <stdio.h>
#include <time.h>

int main(){
time_t rawtime;
struct tm * timeinfo;
time ( &rawtime );
timeinfo = localtime ( &rawtime );
int seed = (int) timeinfo;
srand(seed%17);
int try, prdoor,sedoor,opdoor,winchoose,winchange;

printf("_ Monty Hall problem random iteration _\n\n");
printf("Given 3 doors with a 1 prize behind, you can choose (not open) 1 door");
printf("\nOther no-prize door would be open. Will you change  the door?\n\n");
printf("Enter the number of iterations, please: ");
scanf("%d",&try);
if (try<1){system("exit");}
printf("\n\n");

winchoose=winchange=0;
for (try; try>0; try--){
prdoor = (rand()%3)+1;
sedoor = (rand()%3)+1;
opdoor = (rand()%3)+1;
while(opdoor==sedoor || opdoor== prdoor){
opdoor = (rand()%3)+1;
}
printf("Prize door is: %d Choice is: %d Open is: %d", prdoor,sedoor,opdoor);
if (prdoor==sedoor){printf(" Win_choose\n");winchoose++;}
else{printf(" Win_change\n");winchange++;}
}

printf("\nWin counts, if you insist: %d If you change: %d",winchoose,winchange);
printf("\nin %d iterations\n\n",winchoose+winchange);
printf("\nby OlegTim	");system("pause");
return 0;}
