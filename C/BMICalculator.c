#include<stdio.h>

int BMICalculator(double weight, double height){
	
	double BMI;
	//weight in kilograms
	//height in centimeters
	
	height/=100;//to convert the height from centimeters to meters
	BMI = weight/(height*height);//using metric BMI formula 
	
	printf("The Result:\n");
	if(BMI<18.5)//according to the resource, the BMI values which is under 18.5 are counted as underweight 
	{
		printf("1. You are underweight\n");
		return 1;
	}
	else if(BMI>25)//BMI values which is bigger than 25 are counted as overweight
	{
		printf("2. You are overweight\n");
		return 2;
	}
	else
	{
		printf("0. You are in normal weight\n");
		return 0;
	}//BMI values that is located between 18.5 and 25 are counted as normal size
}	

int BMICalculator(double weight, double height);

int main(void){
	
	double height,weight;//the height and weight are recorded in double variables
	
	printf("Please input your height(in centimeters,cm) and weight(in kilograms,kg):\n");
	printf("When result is 0 -> normal range, 1-> underweight, 2->overweight\n");
	printf("*PS: 1 meter = 100 centimeters\n\n");
	
	printf("Height:");scanf("%lf",&height);
	printf("Weight:");scanf("%lf",&weight);printf("\n");
	
	BMICalculator(weight,height);//call for the function
}