#include<stdio.h>

int beanPricer(int n){
	
	int totalPrice;//used to record the sum of the price of jelly beans
	
	if(n>=0&&n<=100)//each jelly bean is cost 5c when the total numbers of jelly bean purchased is smaller or equal to 100
	{
		printf("The total prices of the jelly beans is ");
		totalPrice = n*5;
	}
	else if(n>100&&n<=250)//When the total number of jelly beans is between 100 and 250
	{
		printf("The total prices of the jelly beans is ");
		totalPrice = 100*5+(n-100)*3;
	}
	else if(n>250&&n<=700)//When the total number of jelly beans is between 250 and 700
	{
		printf("The total prices of the jelly beans is ");
		totalPrice = 100*5+150*3+(n-250)*2;
	}
	else if(n>700)//When the total number of jelly beans is larger than 700
	{
		printf("The total prices of the jelly beans is ");
		totalPrice = 100*5+150*3+450*2+(n-700)*1;
	}
	printf("%d",totalPrice);
	printf("\n");
	
	return totalPrice;
}

int beanPricer(int n);

int main(void)
{
	int numbers_of_jb;//Total numbers of jelly beans that a customer buy
	
	printf("Please input the numbers of jelly beans that you want to purchase(only in integers):\n");
	printf("Total number of jelly beans be purchased : "); 
	scanf("%d",&numbers_of_jb);
	printf("\n");

	beanPricer(numbers_of_jb);//call for the function take part
}