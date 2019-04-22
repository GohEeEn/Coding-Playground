#include<stdio.h>

int spacer(int x){
	
	int unspaced_digit = x;
	int spaced_digit=0;//used to record each integer in each index
	int divisor = 100000;//used to divide with the 6-digit numbers and get the integer in each index
	int sum=0;//used to make as the sum of values in each index
	int i;//loop counter
	
	if(x>999999||x<100000){
		printf("Error: Invalid input, only 6-digit numbers are available\n");
	}//out of the range 100000 to 999999 means the input won't be 6-digit integer
	else
	{	
		printf("Result:\n");
		for(i=1;i<=6;i++){
		
			spaced_digit = unspaced_digit/divisor;//record the integer value in each index numbers
			printf("%d    ",spaced_digit);
			unspaced_digit = unspaced_digit-(spaced_digit*divisor);//preparation to move on to the next index numbers
			divisor/=10;//preparation for next index numbers
			sum+=spaced_digit;//add up all the integers in each index
	
		}
		printf("%d",sum);
		printf("\n");
	}
	
	return sum;
}

int spacer(int x);

int main(void){
	
	int six_digits_input;//used to record 6-digits input from users
	
	printf("\n");
	printf("Please input your six-digit number(integer only):\n");
	printf("Your six-digit number = ");scanf("%d",&six_digits_input);
	printf("\n");
	
	spacer(six_digits_input);//call for the function
	
}
	
		
		
		
		
		
		