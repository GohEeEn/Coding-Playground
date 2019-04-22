#include<stdio.h>
#include<math.h>

/*Written By Ee En Goh, Student Number: 17202691, Date:6 Nov 2017*/
/*To write a program to calculate the convertion of Euros to Sterlings by using declared function*/

double convertion_of_Euro_to_Sterling(double euro,double sterling)
{
	sterling = 0.8*euro;
	return sterling;
}

double convertion_of_Euro_to_Sterling(double euro,double sterling);

int main(void)
{
	double euro,sterling,convertion;
	
	printf("Please input the value of euro:");
	printf("The amount of your Euro:");
	scanf("%lf",&euro);
	printf("\n");
	
	convertion = convertion_of_Euro_to_Sterling(euro,sterling);
	
	printf("The converted amount of Sterlings is %lf sterling\n",convertion);
	
	return 0;
}