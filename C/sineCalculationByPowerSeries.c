#include<stdio.h>
#include<math.h>

/*Written By Ee En Goh, Student Number: 17202691, Date:20 Nov 2017*/

/* To write a program to calculate sin(x) by defining a function with power-series expansion */

double sine_calculation(double radian_input,int n);

int main(void){
	//degree_input from user;radian_input is the degree_input converted into radian number
	double degree_input,radian_input;
	
	//The number of accuracy, to let the user to choose their number of calculation in the power-series expansion, the higher the more accuracy 
	int n;
	
	/* sine_result_1 is the result from own-coded function, while sine_result_2 is the result from math library sine function */
	double sine_result_1,sine_result_2;
	
	
	printf("Please input your angle value in degree number x and numbers of accuracy n \n");

	printf("Your degree number input x, 0<=x<=360 :\n");
	scanf("%lf",&degree_input);
	printf("Your number of accuracy n, n>=1 in integer \n");
	printf("The higher the value of n, the more accurate the result of sine function will be (n<=20)\n");
	scanf("%d",&n);
	printf("\n");
	
	radian_input = degree_input*(M_PI)/180;//To convert degree input from user into radian input
	sine_result_1 = sine_calculation(radian_input,n);//import own-coded function
	sine_result_2 = sin(radian_input);//answer from math library
	printf("Result of sin(x) by function = %lf \n",sine_result_1);
	printf("Result of sin(x) by library calculation = %lf \n",sine_result_2);
	
}

// Self-define sine calculation by using Power-series expansion
double sine_calculation(double radian_input,int n){
	
	// Initialise the total value of degree number undergoes sine function is 0 & the total sum of sine number in each loop
	double sine = radian_input;
	
	// Loop counter and the same time act as the coefficient of variable in each loop to do the calculation 
	int i = 1;
	
	// The function of calculating the factorialisation and the variable of factorial in the demonimator of power-series expansion fraction (2n+1)!
    double factorial= 1;
	

	while(i<=n)
	{				
		factorial*= (2*i)*(2*i+1);	//factorialisation in each operation
		
		/* eg.1!->3! = 1-> 1X2X3, thus the '2' number before 3 should also be created */
		//The general formula of power-series expansion 
		sine+= (pow((-1),i)*pow(radian_input,2*i+1))/(factorial);	
		
		printf("%lf \n",sine);
		printf("%d \n",factorial);
		i++;
	}
	return sine;
}