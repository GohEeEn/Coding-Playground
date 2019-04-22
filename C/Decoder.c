#include<stdio.h>
#define total_num_alphabets 26
/*Written By Ee En Goh, Student Number: 17202691, Date:17 Oct 2017*/
/*To write a program to decode an encoded message to the original alphabets sequence*/

// Function Declaration
void decodeMessage(char encoded_msg[]);


int main(void){
	
	// Declare an empty character array to record the decoded message temporary
	char msg[] = "";
	char encoded_msg[] = ("Bicyik Fibbqai Km ixcmzi"); // Example decoded message
	
	puts("\t<< Decoder >>\n");
		
	
	// Example 
	puts("Example encoded message : Bicyik Fibbqai Km ixcmzi");
	puts("After decoded :");
	decodeMessage(encoded_msg);	
	
	puts("Enter the encoded message here to be decoded :");
	
	// Read the input message
	gets(msg);
	
	// Call the decoding function
	decodeMessage(msg);
}

void decodeMessage(char encoded_msg[]){
	
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
	char decoded_msg[]={0};	//The array used to store the decoded message
	int decoded_index_number = 0;
	h=0;
	i=0;
	j=0;
	//assign the value 0 on both i and j, to make them to start the value on 0
	
	while(encoded_msg[h] !='\0')//To count the whole length of input messages
	{
		N++;
		h++;
	}
	printf("The whole length of message is %d\n",N);
	
	while(i<N && encoded_msg[i] !='\0')//to scan the whole strings 
	{
		//functions for decoded lowercase and uppercase letters from encode sequence to the old sequence
		if(encoded_msg[i]>=97 && encoded_msg[i]<=122)//to deal with lowercase alphabets
		{
			for(j=0;j<total_num_alphabets;j++)
			{
				if(encoded_msg[i]==low_new_perm[j])//when the messages are found as same as the old alphabet sequence,
				{
					decoded_msg[decoded_index_number] = low_old_perm[j];
					//to switch the small size alphabets with the encoded small size alphabets
					decoded_index_number++;
				}
			}
			i++;
		}
		else if(encoded_msg[i]>= 65 && encoded_msg[i] <=90)//to deal with uppercase alphabets
		{
			for(j=0;j<total_num_alphabets;j++)
			{
				if(encoded_msg[i]==upper_new_perm[j])
				{
					decoded_msg[decoded_index_number] = upper_old_perm[j];
					decoded_index_number++;
				}
			}
			i++;
		}
		else
		{
			decoded_msg[decoded_index_number] = encoded_msg[i];
			//otherwise just copy it as the same input
			decoded_index_number++;
			i++;
		}
	}

	printf("\nThe decoded messages are:\n");
	for(i=0;i<decoded_index_number;i++)
		printf("%c",decoded_msg[i]);
	puts("\n");
}