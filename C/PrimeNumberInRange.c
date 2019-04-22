#include <stdio.h>

/*Written By Ee En Goh, Student Number: 17202691, Date:21 Oct 2017*/

int main(void){
	int N=0;//Input Number, Maximum number of the range
	int i,j;
	// The time i to run the inner loop, The time to run the outer loop
	// j is also the number for expressing a specific numbers in each loop in an acsending sequence by one;
	//i is also each the number to have the division with j within the interval, to determine that if the specific number j can be divided fully by any other number; 
	
	printf("Please insert the maximum integer of range,N\n");
	scanf("%d",&N);//Input the maximum number of the interval
	
	printf("The prime numbers between 0 and %d interval is/are\n",N);
	for(j=1;j<=N;j++)
	{	
	 //Running an outer loop and the increment of integer j as a fixed number in each loop
		for(i=2;i<=j;i++)
		//Running an inner loop,which is start from 2 is because that the occurence of prime number is started from 2 
		{	
			if(j%i==0)
		//To remove the number which can be divided by any other integers fully 
				{
					break;
				//It means to terminate the loop when it is not a prime number,
				//It shows that the specific number can also be divided by other smaller number
				}
		}
		
		if(i==j)
		//This shows that the specific number can be only divided fully by ifselves
			printf("%d ",j);
	}
	
}
	
	
		
	
	