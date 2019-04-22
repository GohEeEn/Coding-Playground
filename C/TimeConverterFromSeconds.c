#include<stdio.h>

/*Written By Ee En Goh, Student Number: 17202691, Date:13 Nov 2017*/
/*To write a program that returns 4 values corresponding to days, hours, minutes and seconds equivalent to a given total number of seconds by struct function*/

typedef struct Time
{
	int days;
	int hours;
	int minutes;
	int seconds;
} Time;

Time convert_secs(int total_secs){
	Time t;
	int remaining_secs = total_secs;
	t.days = remaining_secs/(24*60*60);
	remaining_secs %= (24*60*60);
	t.hours = remaining_secs/(60*60);
	remaining_secs %= (60*60);
	t.minutes = remaining_secs/(60);
	remaining_secs %= 60;
	t.seconds = remaining_secs;
	
	return t;
}

Time convert_secs(int total_secs);

int main(void){
	int x;
	Time y;

	printf("Please input your specific numbers of seconds:\n");
	scanf("%d",&x);
	puts("");
	
	y = convert_secs(x);
	
	printf("The numbers of Days = %d \n",y.days);
	printf("The numbers of Hours = %d \n",y.hours);
	printf("The numbers of Minutes = %d \n",y.minutes);
	printf("The numbers of Seconds = %d \n",y.seconds);

	return 0;
}


	
	
	