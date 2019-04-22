#include<stdio.h>

int mathTest(int x,int y,int z){
	
	double average;//the average value of 3 inputs
	int product,sum;//the multiplication and addition between 3 inputs 
	
	printf("\n");
	printf("The three numbers are %d, %d and %d. ",x,y,z);
	
	average = ((double)x+(double)y+(double)z)/3;//the values of x,y and z should be changed into double, to enable to calculate the average with decimal values
	printf("The average is %.2f. ",average);
	
	product = x*y*z;
	printf("The product is %d. ",product);
	
	sum = x+y+z;
	printf("The sum is %d. ",sum);
	
	if(x>=y&&x>=z)//means x is the largest number compare to y and z
	{
		printf("The largest is %d. ",x);
		if(y>=z)//means y is larger than z, thus z is having the smallest number
		{
			printf("The smallest is %d. ",z);
		}
		else if(z>=y)//means z is larger than y, thus y is having the smallest number
		{
			printf("The smallest is %d. ",y);
		}	
	}
	else if(y>=x&&y>=z)//means y is the largest number compare to x and z
	{
		printf("The largest is %d. ",y);
		if(x>=z)//means x is larger than z, thus z is having the smallest number
		{
			printf("The smallest is %d. ",z);
		}
		else if(z>=x)//means z is larger than x, thus x is having the smallest number
		{
			printf("The smallest is %d. ",x);
		}	
	}
	else if(z>=x&&z>=y)//means z is the largest number compare to x and y
	{
		printf("The largest is %d. ",z);
		if(x>=y)//means x is larger than y, thus y is having the smallest number
		{
			printf("The smallest is %d. ",y);
		}
		else if(y>=x)//means y is larger than x, thus x is having the smallest number
		{
			printf("The smallest is %d. ",x);
		}	
	}
	return average;
}

int mathTest(int x,int y,int z);

int main(void){
	
	int x,y,z;//three user-input integers 
	
	printf("Please input your three integers x,y and z:\n");
	printf("x = ");scanf("%d",&x);
	printf("y = ");scanf("%d",&y);
	printf("z = ");scanf("%d",&z);
	
	mathTest(x,y,z);//declare the use of function
}