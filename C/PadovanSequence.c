/*Written by Ee En Goh, Student Number: 17202691, Date: 3nd Oct 2017*/
#include <stdio.h>
#include <math.h>
/*Padovan numbers sequence of number N program*/
int main(void)
{	int n,i;
	float N,in_a,in_b,in_c;
	/* N = P(n),in_a = P(n-1),in_b = P(n-2),in_c = P(n-3)*/
	printf("Please insert the positive integer:\n");
	scanf("%d\n",&n);
	printf("\n");
	
	if(n == 0)
	{
		printf("The padovan sequence of integers 0 = 1\n");
	}
	if(n == 1)
	{
		printf("The padovan sequence of integers 1 = 1\n");
	}
	if(n == 2)
	{
		printf("The padovan sequence of integers 2 = 1\n");
	}
	if(n == 3)
	{
		printf("The padovan sequence of integers 3 = 1\n");
	}
	/*by definition the padovan numbers have the result of one when n=0,1,2,3*/
	
			
	else {
		in_a = 1;
		in_b = 1;
		in_c = 1;
		for(i=4;i<=n;i++)
		{	
			N = in_b + in_c; //P(n) = P(n-2) + P(n-3)
			in_c = in_b;
			in_b = in_a;
			in_a = N;
			/*for the next integer, the previous P(n)->P(n-1),P(n-1)->P(n-2),P(n-2)->P(n-3);the value of new P(n-1) need to be stored for the next integer*/ 
		}
		printf("The padovan sequence of integers %d = %f\n",n,N);
	}
	
	
	return 0;
}	
	
	
