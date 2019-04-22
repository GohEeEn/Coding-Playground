#include<stdio.h>
#include<math.h>
/*Written By Ee En Goh, Student Number: 17202691, Date:20 Nov 2017*/
/* To write a function to calculate the cubed-root of a double precision number c by Newton-Rampson Method */

// Function Definition
double cubed_root_function(double c,double x1,double x2,int maxiters,int numiters,double EPSILON){
		maxiters = 1000;//max number of computation
		numiters = 0;//numbers of doing newton simpson rule 
		EPSILON = 0.0;
		x1 = c/3;
		
			while(numiters<maxiters && x1*x1*x1-c != EPSILON)
			{
				double fx = x1*x1*x1-c;
				double fdx = 3*x1*x1;
				x2 = x1-(fx/fdx);
				numiters++;
				
				x1 = x2;	
			}
			// printf("The number of iterations is %d \n",numiters);
			printf("\tThe cube root of input c is equal to %lf",x1);
		
	return x1;
}


// Function Declaration
double cubed_root_function(double c,double x1,double x2,int maxiters,int numiters,double EPSILON);

// Main function
int main(void){
	double x1,x2;
	int maxiters,numiters;
	double c;//User-input
	double result;
	double EPSILON = 0.0;
	
	printf("\tPlease input your variable c here : ");
	scanf("%lf",&c);
	
	puts("");
	
	// Call function
	cubed_root_function(c,x1,x2,maxiters,numiters,EPSILON);
	
	puts("");
	
	
	return 0;
}


				
	
		
		