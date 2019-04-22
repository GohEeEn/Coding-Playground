#include<stdio.h>
#define total_num_alphabets 26 //26 type ofalphabets

/*Written By Ee En Goh, Student Number: 17202691, Date:17 Oct 2017*/
/*To write a program to encode a message with the specific alphabets resequence*/
int main(void){
	char low_new_perm[total_num_alphabets] = ("qjczieaungsdfxmphybklortvw");
	//New sequence of permutation of lowercase alphabets qjczieaungsdfxmphybklortvw
	
	char upper_new_perm[total_num_alphabets] = ("QJCZIEAUNGSDFXMPHYBKLORTVW");
	//New sequence of permutation of uppercase alphabets QJCZIEAUNGSDFXMPHYBKLORTVW
	
	char low_old_perm[total_num_alphabets] = ("abcdefghijklmnopqrstuvwxyz");
	//Old sequence of permutation of lowercase alphabets abcdefghijklmnopqrstuvwxyz
	
	char upper_old_perm[total_num_alphabets] = ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	//Old sequence of permutation of uppercase alphabets ABCDEFGHIJKLMNOPQRSTUVWXYZ
	
	int i,j;				//outer loop integer i, inner loop integer j
	int h;					//loop to count the length of messages
	int N = 0;				//The whole length of input messages
	char msg[N];			//The input messages(strings)
	char encoded_msg[]={0};	//The array used to store the decoded message
	int encoded_index = 0;
	h=0;
	i=0;
	j=0;
	//assign the value 0 on both i and j, to make them to start the value on 0
	
	printf("Please input the sentence you wanna convert according to the permutation of alphabets rearranged\n");
	gets(msg);
	
	while(msg[h] !='\0')//To count the whole length of input messages
	{
		N++;
		h++;
	}
	printf("The whole length of message is %d\n",N);
	
	//to read the whole strings 
	while(i<=N && msg[i] !='\0')
	{
		//functions for encoded lowercase and uppercase letters
		if(msg[i]>=97 && msg[i]<=122)//to deal with lowercase alphabets
		{
			for(j=0;j<total_num_alphabets;j++)
			{
				//when the messages are found as same as the old alphabet sequence,
				if(msg[i]==low_old_perm[j])
				{
					// Switch the small size alphabets with the encoded small size alphabets
					encoded_msg[encoded_index] = low_new_perm[j];
					encoded_index++;
				}
			}
			i++;
		}
		//to deal with uppercase alphabets
		else if(msg[i]>= 65 && msg[i] <=90)
		{
			for(j=0;j<total_num_alphabets;j++)
			{
				if(msg[i]==upper_old_perm[j])
				{
					encoded_msg[encoded_index] = upper_new_perm[j];
					encoded_index++;
				}
			}
			i++;
		}
		else
		{
			encoded_msg[encoded_index] = msg[i];
			//just copy it as the same input
			encoded_index++;
			i++;
		}
	}

	printf("\nThe decoded messages are:\n");
	for(i=0;i<encoded_index;i++)
		printf("%c",encoded_msg[i]);
}
