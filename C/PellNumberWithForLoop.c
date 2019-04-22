/*Written by Ee En Goh, Student Number: 17202691, Date: 2nd Oct 2017*/
#include <stdio.h>
#include <math.h>
/*Pell number program*/
int main(void)
{	int n,i;
	double a, b=0, c=1;
	printf("Please insert a positive integer:\n");
	scanf("%d\n",&n);
	printf("\n");
	
	/*Insert the required positive integer*/
	
	if(n == 0)
	{
		printf("The pell number of 0 = 0\n");
	}
	
	if(n == 1)
	{
		printf("The pell number of 1 = 1\n");
	}
		
	for(i=2;i<=n;i++)
	{	
			
		a = 2*c + b;
		b = c ;
		c = a;
	}
	printf("The pell number of %d = %lf\n",n,a);
	
	return 0;
}
