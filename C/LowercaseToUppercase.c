#include<stdio.h>
#include<stdlib.h>

/*Written By Ee En Goh, Student Number: 17202691, Date:17 Oct 2017*/
/*To write the program to convert the lowercase characters to uppercase characters*/

int main(void){
	int i = 0;//The loop number i
	char msg_input[1000];//define the length of strings, if can't be over 1000
	char convertion;//
	printf("Please input a message you want to convert(only alphabets):\n");
	scanf("%s",&msg_input);
	
	while(msg_input[i]!='\0')
	{
		convertion = msg_input[i];
		if(convertion>='a'&& convertion<='z' )
		{
			msg_input[i]=msg_input[i]-32;
			i++;
		}
	}
	printf("After the convertion, the message become:\n%s\n",msg_input);
}			
