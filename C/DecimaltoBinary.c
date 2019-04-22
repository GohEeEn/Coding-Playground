#include<stdio.h>
#include<math.h>
#define MAX_SIZE 12
/*Written By: Ee En Goh,Student Number: 17202691, Date: 10 October 2017*/
/*To transfer a decimal number into a binary number*/

int main (void){
	
	int decimalNum, remainder, temp = 1;
	int display = 0;
	long binaryNum = 0;
	
	printf("Please insert the decimal integer that you want to change into binary number(Bin),\n");
	scanf("%d", &decimalNum);
	
	display = decimalNum;
	printf("\n");
	
	if(decimalNum==0)
	{
		printf("The binary value of decimal number %d is ",decimalNum);
		printf("0\n");
	}
	else if(decimalNum==1)
	{
		printf("The binary value of decimal number %d is ",decimalNum);
		printf("1\n");
		
	}
	else 
	{
		printf("%d %ld\n", decimalNum, binaryNum);
		while(decimalNum!=0){
			
			remainder = decimalNum%2;
			decimalNum /= 2;
			
			// Assign the convert digit to the binary number variable
			binaryNum = binaryNum + remainder*temp;
			
			// move to the next binary digit
			temp *= 10;		
		}
		printf("The binary value of decimal number %d is %ld",display,binaryNum);
		
	}
	
	return 0;
}
			
			
	
	
			
	
