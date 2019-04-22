/*Written by Ee En Goh, Student Number: 17202691, Date: 2nd Oct 2017*/
#include <stdio.h>

/*To identity the smallest number,2nd smallest,3rd smallest and the maximum number in 4 four random input*/
int main(void)
{	float vals[4] = {0}, temp;
	float temp_max;
	int i = 0, temp_index;
	float w,x,y,z;

	printf("Please input four floating numbers:\n");
	scanf("%f",&vals[0]);
	scanf("%f",&vals[1]);
	scanf("%f",&vals[2]);
	scanf("%f",&vals[3]);
	
	if(vals[0] < vals[1] || vals[0] < vals[2] || vals[0] < vals[3]){
		temp_max = vals[0] ; 
		for(i = 0 ; i < 4; i++){
			if(vals[i] > temp_max){
				temp_index = i;
				temp_max = vals[i];
			}
		}
		temp = vals[temp_index];
		vals[temp_index] = vals[0];
		vals[0] = temp;
	}
	
	if(vals[1] < vals[2] || vals[1] < vals[3]){
		temp_max = vals[1] ; 
		for(i = 1 ; i < 4; i++){
			if(vals[i] > temp_max){
				temp_max = vals[i];
				temp_index = i;
			}
		}
		temp = vals[temp_index];
		vals[temp_index] = vals[1];
		vals[1] = temp;
	}
	
	if(vals[2] < vals[3]){
		temp = vals[2];
		vals[2] = vals[3];
		vals[3] = temp;
	}
	/*To assign the smallest number be w, 2nd smallest be x, 3rd smallest be y, and the largest number be z*/	

	w = vals[3];
	x = vals[2];
	y = vals[1];
	z = vals[0];
 
	printf("The smallest number w is %f\n",w);
	printf("The second smallest number x is %f\n",x);
	printf("The second largest number y is %f\n",y);
	printf("The largest number z is %f\n",z);

return 0;	
}
	
