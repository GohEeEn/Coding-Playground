#include<stdio.h>

int overCrowded(int rooms, int people){
	
	double ratio;//used to save the result of the crowded ratio in double variables
	
	ratio=(double)people/(double)rooms;//change the data type of number of peoples and rooms, to satisfy the division that may has remainders
	
	printf("The result:\n");
	
	if(ratio<=2.00){//It is only allow 2 people the most in a room as the definition of not overcrowded, thus it means the biggest ratio allowed is 2
		
		printf(" 0. The child is not living in an over-crowded dwelling\n");	
		return 0;
	
	}
	else if(people==0){
		
		printf(" 0. No people is living here, thus it is not overcrowded\n");
		return 0;
	
	}//no people is in the room, thus it is not overcrowded at all
	else if(ratio>2.00)
	{
		
		printf(" 1. The child is living in an over-crowded dwelling\n");	
		return 1;	
	
	}//the ratio has the maximum 2 for not crowded, thus bigger than that is overcrowded
	else if(ratio<0)//the ratio shouldn't less than 0 
	{
		printf("Error: Invalid Input, the numbers of rooms and household members\n");
		return ratio;	
	}
}

int overCrowded(int rooms, int people);

int main(void){
	
	int rooms,people;//to save the numbers of rooms and people from user input
	
	printf("Please input the numbers of rooms and household members:\n");
	printf("*Output: 0->Not overcrowded, 1->overcrowded*\n\n");
	printf("The numbers of rooms(excluding bathrooms) = ");scanf("%d",&rooms);//lets user to input the numbers of rooms
	printf("The numbers of household members = ");scanf("%d",&people);printf("\n");//lets user to input the numbers of household members
	
	overCrowded(rooms,people);//function navigation

}	