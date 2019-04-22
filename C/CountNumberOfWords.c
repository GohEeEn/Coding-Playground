#include<stdio.h>
#define length_of_characters 1000
/*Written By Ee En Goh, Student Number: 17202691, Date:6 Nov 2017*/
/*To write a program to count the numbers of word by using a defined function*/

void counting_the_words(char msg[length_of_characters],int i,int numbers_of_words)
{
	
	if(msg[0]==' '){
		printf("It is not following the grammartical rule to put spacebar at the first character\n");
		numbers_of_words = 0;
	}//the spacebar before word-input are not cosidered as an input
	
	while(msg[i] !='\0'){
	
		/*	
			Any lowercase or uppercase alphabet end with a spacebar input as the next input is counted as a word 
			Any lowercase or uppercase alphabet end with a null terminator as located in after 2 places of the character(the end of the whole string) is counted as a word
		*/
		if(((msg[i] >= 'A' && msg[i] <= 'Z')||(msg[i]>='a' && msg[i] <='z'))&&(msg[i+1]==' '||msg[i+1]=='\0'))
			numbers_of_words++;
		
		// Any symbol after a whitespace character is not counted as a word
		if(msg[i-1]==' ' && !(msg[i]>='A'&& msg[i]<='z'))
			numbers_of_words--;
		i++;		
	}
	
	
	printf("The numbers of word in the input strings is %d \n",numbers_of_words);
}

void counting_the_words(char msg[length_of_characters],int i,int numbers_of_words);

int main(void){
	char msg[length_of_characters]="";	//The input message
	int i=0, numbers_of_words = 1;		//loop number i, no.of word (There is a word before the whitespace character)
	
	printf("Please input your message:\n");
	fgets(msg,1000,stdin);//input your message

	counting_the_words(msg,i,numbers_of_words);

	return 0;
}