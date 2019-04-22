#include<stdio.h>
#include<math.h>

/*Written By Ee En Goh, Student Number: 17202691, Date:6 Nov 2017*/
/*To write a function to calculate the area of a triangle by using a declared function*/

double Area_of_Triangle(double height,double base,double area)
{
	area = 0.5*height*base;
	
	return area;
}
	
double Area_of_Triangle(double height,double base,double area);
	
int main(void){
	double height,base,area,area_of_the_triangle;
	
	printf("Please input the base and the height of the triangle\n");
	printf("Base(in cm):\t");
	scanf("%lf",&base);
	printf("\n");
	printf("Height(in cm):\t");
	scanf("%lf",&height);
	printf("\n");
	
	area_of_the_triangle = Area_of_Triangle(base,height,area);
	
	printf("The area of your triangle is %.2lf (in centimeter square)\n",area_of_the_triangle);

	return 0;
}
	
	
	
	
	
	