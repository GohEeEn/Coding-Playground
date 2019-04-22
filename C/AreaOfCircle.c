#include<stdio.h>
#include<math.h>

/*Written By Ee En Goh, Student Number: 17202691, Date:6 Nov 2017*/
/*To write a program to calculate the area of the circle by using declared function*/

// Function definition
double Area_of_circle(double radius,double area)
{
	area = M_PI * radius * radius;
	return area;
}

// Function declaration
double Area_of_circle(double radius,double area);

// Main function
int main(void)
{
	double radius,area,area_of_the_circle;
	
	printf("Please input the radius of the circle\n");
	printf("Radius(in centimeter):\t");
	scanf("%lf",&radius);
	
	area_of_the_circle  = Area_of_circle(radius,area);
	
	printf("The area of the circle is %lf (in centimeter square)\n",area_of_the_circle);
	return 0;

}
	
	