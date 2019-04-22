#include<stdio.h>
#define const input_num
/*Written By Ee En Goh, Student Number: 17202691, Date:13 Nov 2017*/
/*Write a program to do the factorization of input number by function*/

// Function Declaration
void prime_factorization(int N,int i, int input_num);//The function is declared as prime_factorization

// main function
int  main(void){
	//N is declared as the input number too, i is the counter number, 
	int i,N,input_num; 
	
	printf("Please input the positive integer number for factorization:\n"); 
	scanf("%d",&input_num);
	
	N = input_num ;//N is functioned as a calculation of input number to find the prime factor , while input_num is used as the maximum range for the loop 
	
	printf("The prime factor of your input number is/are\n");
	prime_factorization(N,i,input_num);
	return 0;
}

// Prime Factor Function
void prime_factorization(int N,int i, int input_num){ 
	//As number 0 and 1 can't be used to make it a prime factor, thus we start the counter from number 2
	for(i=2;i<input_num;i++){
		
		while(N%i == 0){
			printf("%d ",i);
			N = N/i;
		}
	}
}