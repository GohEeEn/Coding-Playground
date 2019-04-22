#include<stdio.h>

/*Written By Ee En Goh, Student Number: 17202691, Date:13 Nov 2017*/
/*To write a program that returns 4 values corresponding to days, hours, minutes and seconds equivalent to a given total number of seconds by return to the argument*/


void convert_secs(int total_secs, int *days, int *hours, int *minutes, int *seconds)
{
	int d,h,m,s;//days,hours,minutes,seconds
	
	int remaining_secs = total_secs;
	d = remaining_secs/(24*60*60);
	remaining_secs %= 24*60*60;
	h = remaining_secs/(60*60);
	remaining_secs %= 60*60;
	m = remaining_secs/60;
	remaining_secs %= 60;
	s = remaining_secs;
	*days = d;
	*hours = h;
	*minutes = m;
	*seconds = s;
}
void convert_secs(int total_secs, int *days, int *hours, int *minutes, int *seconds);

int main(void)
{
	int total_secs,days,hours,minutes,seconds;
	printf("Please input the amount of seconds:\n");
	scanf("%d",&total_secs);
	convert_secs(total_secs,&days,&hours,&minutes,&seconds);
	printf("There are %d days ",days); 
	printf("%d hours " ,hours);
	printf("%d minutes ",minutes); 
	printf("and %d seconds from the input amount of seconds",seconds);
	
	return 0;
}


