#include<stdio.h>
/*Written By Ee En Goh, Student Number: 17202691*/

double tempConverterCelc(double tempCelsius){
	double tempFah;
	
	tempFah = tempCelsius*1.8 + 32;//the formula to convert Fahrenheit into Celsius
	printf("The conversion to Fahrenheit is %.2f \n",tempFah);//expressing the result in 2 decimal number 
	
	return tempFah;
}//Conversion from Celsius to Fahrenheit

double tempConverterFah(double tempFah){
	double tempCelsius;

	tempCelsius = (tempFah-32)/1.8;//The formula to convert Celsius into Fahrenheit
	printf("The conversion to Celsius is %.2f \n",tempCelsius);//expressing the result in 2 decimal number
	
	return tempCelsius;
}//Conversion from Fahrenheit to Celsius

double tempConverterCelc(double tempCelsius);
double tempConverterFah(double tempFah);

int main(void){

	int function_num;//to choose if you want to convert Fahrenheit to Celcius or inverse
	double temperature;//to record the temperature input value from users
	
	printf("Please choose the conversion you want:\n");
	printf(" 1->Fahrenheit to Celsius\n 2->Celsius to Fahrenheit\n\n");
	printf("Your function: ");scanf("%d",&function_num);//to receive the information of which function the user wants
	printf("\n");
	
	if(function_num==1){
		
		printf("Please input your temperature rate in Fahrenheit:\n");
		printf("Temperature in Fahrenheit = ");
		scanf("%lf",&temperature);//record the value of temperature in double variable
		printf("\n");
		tempConverterFah(temperature);
	
	}//Conversion from Fahrenheit to Celsius
	else if(function_num==2){
		
		printf("Please input your temperature rate in Celsius:\n");
		printf("Temperature in Celsius = ");
		scanf("%lf",&temperature);//record the value of temperature in double variable
		printf("\n");
		tempConverterCelc(temperature);
	
	}//Conversion from  Celsius to Fahrenheit 

}	
		