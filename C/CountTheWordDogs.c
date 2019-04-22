#include<stdio.h>
#define MAX_LENGTH 1000
/*Written By Ee En Goh, Student Number: 17202691, Date:31 Oct 2017*/

int main(void){
	int i = 0,k=0;
	//The loop number i for transforming the case of alphabets, loop number k for detecting the occurence of letter 'dogs'
	
	char msg_input[MAX_LENGTH];//To define the length of input strings, if can't be over 1000
	
	char convertion;//To detect the lowercase letters from all the input letters and turn into uppercase letters, that is easier to count the occurence of 'dogs'
	
	int dogs_count=0;//The number of occurence of 'dogs'
	
	printf("Please input your message here\n");
	fgets(msg_input,1000,stdin);//store the input as the strings by key in, limit 1000 characters
		
		while(msg_input[i]!='\0')
		{
			convertion = msg_input[i];
			if(convertion>='a'&& convertion<='z' )
			{
				msg_input[i]=msg_input[i]-32;//to tranform all the lowercase alphabets into uppercase
				//In ASCII code, the gaps of the same alphabet but different cases is 32
			}
			i++;
		}
		while(msg_input[k]!='\0')
		{
			if(msg_input[k] == 68 && msg_input[k+1] == 79 && msg_input[k+2] == 71 && msg_input[k+3] == 83)
			{	
				dogs_count++;
				//68 = uppercase letter D in ASCII code
				//79 = uppercase letter O in ASCII code
				//71 = uppercase letter G in ASCII code
				//83 = uppercase letter S in ASCII code
			}
			k++;
		}

	printf("The numbers of occurence of word 'dogs' is %d\n",dogs_count);
}	