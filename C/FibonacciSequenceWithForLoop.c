/*Written by Ee En Goh, Student Number: 17202691, Date: 2nd Oct 2017*/
#include <stdio.h>
#include <math.h>
/*This is the Fibonacci Sequence program with for loop function*/
int main(void)
{
	double a, b, c;
	int i, n=50;
	
	if (n==1)
		printf("1\n");
	if (n==2)
		printf("1\n");

	b = 1;
	c = 1;

	for (i=3; i<=n; i++ )
	{
		a = b + c;
		printf("%f\n", a);
		c = b;
		b = a;
		
	}
	return 0;
}
