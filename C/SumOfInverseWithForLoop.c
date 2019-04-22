#include<stdio.h>
/*To write a program to do the sum of inverse 1 to N*/

int main(void){
		int N;//the maximum value of N 
		double i;//loop counter, question??only if i is a double data type then it works??
		double ivr_sum = 0;//the sum of inverse to N

		printf("Please enter your maximum value of N, to do the sum of inverse of the first N numbers:");
		scanf("%d",&N);
		printf("\n");
		
		if(N==0)
		{
			printf("Error: invaild input to infinity\n");
		}
		else
		{	
			for(i=1;i<=N;i++){
				ivr_sum = ivr_sum + (1/i);
				//printf("value of sum in i=%lf is %lf \n",i,ivr_sum);
			}			
			printf("The sum of the inverse of the first %d numbers is %lf",N,ivr_sum);
		}
}		
