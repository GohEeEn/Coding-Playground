#include <stdio.h>
#include <math.h>

int main(void)
{
	double a, b ,c;
	double r1 , r2;
	const int d = 4,e = 2;
   

	printf("Please input the three required floating numbers to the a,b,c to form a quadratic equation\n");
	scanf("%lf",&a);
	scanf("%lf",&b);
	scanf("%lf",&c);
	
	if(a==0)
	{
		printf("Error : The root cannot be computed when a is zero.\n");
	}
	else if((b*b) < (d*a*c)) 
	{
		printf("Error : It is not a real root but imaginary root.\n");
	}
	else if((b*b) > (d*a*c))
	{
		printf("There are two unequal real root.\n");
    }
	else if((b*b) == (d*a*c)) 
	{
		printf("There are two equal real root.\n");
	}		
	r1 = ((-b+sqrt((b*b)-(d*a*c)))/(e*a));
	
	r2 = ((-b-sqrt((b*b)-(d*a*c)))/(e*a));
	
	printf("The answer of the quadratic equation are:\n");
	printf("r1 = %lf\n", r1);
	printf("r2 = %lf\n", r2);
	
	
	return 0;
}

	
	
	
	
	
	
	
	
	
