/*Written By: Goh Ee En, Student Number:17202691*/
#include <stdio.h>
#include <math.h>
/*This is the N factorial program with for loop function*/
int main(void)
{
	double n,i, sum = 1;
	
	
	printf("Please insert an integer:\n");
	scanf("%lf",&n ); /*insert the possitive integer user wants*/
	
	if(n == 0)
	{
		printf("1");
	}
	else if (n < 0)
	{
		printf("Error: The factorial of a negative number doesn't exist\n");
	}
	else 
	{
		for(i=1;i<=n;i++)
			{
				sum *= i;
			}
			printf("The factorial of number is %lf"  ,sum);
	}
	return 0;

}
