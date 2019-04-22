/* Written By Ee En Goh, Student Number : 17202691 */

#include<stdio.h>
#include<string.h>
#define MAX_STR_SIZE 10

typedef struct carDetails{
	// Variables Declaration 
	int record_id; // Represent the record id of a car
	char licence_plate[MAX_STR_SIZE]; // Record of the licence plate
	char Make[MAX_STR_SIZE]; // The name of the car company who make the car
	char Model[MAX_STR_SIZE]; // The name of model of the car
	char Shape[MAX_STR_SIZE]; 
	char Colour[MAX_STR_SIZE]; // the colour of the car
	int Mileage;
	int cost_price; // The original price of the car buy from the car companies
	int price_sold; // The sold price to the customer
	int sales_person_id; // The id of the sales person
} carDetails;

// function prototype
void display_menu(void);
void add_record(void);
void read_record(void);
void total_car_sold(void);
void car_sold_givenColour(void);
void car_sold_givenSalePerson(void);
void highest_mileageCar(void);
void newest_LicencePlateCar(void);
void largest_Profit(void);
void totalProfit(void);
void averageProfit(void);
void SPwithBiggestTotalProfit(void);

int main(void){
	
	unsigned int choice;
	
	printf("Please enter the function you want:\n");
	display_menu(); // display the menu here
	printf("Your Choice: ");
	scanf("%d",&choice); // record my choice
	puts("");
	
	while(choice!=0)
	{
		switch(choice)
		{
			case 0:
				break;
			case 1:
				add_record();
				break;
			case 2:	
				read_record();
				break;
			case 3:
				total_car_sold();
				break;
			case 4:
				car_sold_givenColour();
				break;
			case 5:
				car_sold_givenSalePerson();
				break;
			case 6:
				highest_mileageCar();
				break;
			case 7:
				newest_LicencePlateCar();
				break;
			case 8:
				largest_Profit();
				break;
			case 9:
				totalProfit();
				break;
			case 10:
				averageProfit();
				break;
			case 11:
				SPwithBiggestTotalProfit();
				break;
			default: 
				puts("Invalid Choice, please try again");
				break;
		}
		printf("Please enter the function you want:\n");
		display_menu();
		printf("Your Choice: ");
		scanf("%d",&choice);
		puts("");
	}
}

// function definition

// function to display the function menu
void display_menu(void)
{
	puts("	 1 - ADD new car sale record into the file");
	puts("	 2 - READ the new car sale record of the file");
	puts("	 3 - Total number of cars sold");
	puts("	 4 - Total number of cars sold for a given color");
	puts("	 5 - Total number of cars promoted by a sale person");
	puts("	 6 - The car record with the HIGHEST MILEAGE");
	puts(" 	 7 - The car record with the NEWEST LICENCE PLATE");
	puts("	 8 - The car record with the LARGEST PROFIT");
	puts("	 9 - The TOTAL profit of the car record");
	puts("	10 - The AVERAGE profit of the car record");
	puts("	11 - The sale person's ID with the BIGGEST TOTAL PROFIT from all their sales");
	puts("	 0 - Exit Program");
}

// function to add record into the text file
void add_record(void)
{
	FILE *fPtr; // declare a pointer to access the text file 
	
	if((fPtr = fopen("MarchSales.txt","r+")) == NULL)
	{
		puts("Error: The record file can't be opened");
	}
	else{
		carDetails empty_car = {0,{0},{0},{0},{0},{0},0,0,0,0}; 
		// empty carDetails variable that used to re-initialize the car variable
		
		carDetails car = {0,{0},{0},{0},{0},{0},0,0,0,0}; 
		// declare a struct carDetails variable that used to save the value of car sale information from the text file
		
		// read the whole text file , to get the last car sale record ID 
		fseek(fPtr,0,SEEK_SET); // set the pointer to the start of the text file
		
		while(!(feof(fPtr)))
		{
			// save the value from the file
			fscanf(fPtr,"%d %s %s %s %s %s %d %d %d %d",&car.record_id,car.licence_plate,car.Make,car.Model,car.Shape,car.Colour,&car.Mileage,&car.cost_price, &car.price_sold,&car.sales_person_id);
		}
		
		int last_recordID = car.record_id;
		printf("The last ID : %d\n",car.record_id);
		
		// re-initialize all of the variables recorded from the text.file accept the record ID, to set-up the ID automatically
		car = empty_car;
		
		// statement to get the car sale information from the user
		puts("Enter the sold car information here:");
		puts("Including the licence plate, car companies which makes the car, car model, car's shape, car's color, mileage, cost price, price sold, and the sales person's ID");
		puts("Example: 151D32190  AUDI  A4  Saloon  Grey  156041  20000  25000  1");
		puts("(NOTE: Please click Ctrl+Z (EOF), which means end of file when you want to stop input information)");
		scanf("%s %s %s %s %s %d %d %d %d",car.licence_plate,car.Make,car.Model,car.Shape,car.Colour,&car.Mileage,&car.cost_price,&car.price_sold,&car.sales_person_id);
		
		unsigned int no_ID_entered = 0; 
		// declared as a number of car sales information that input by the user in this round
		
		// enter information at the end of the file
		while(!(feof(stdin)))
		{
			fseek(fPtr,0,SEEK_END); // navigate the file pointer to the end of file
			
			no_ID_entered++; // every time enter this record loop, it will automatically help user to generate the record ID, by using the value of the last record ID, with a post-increment operator
			
			fprintf(fPtr,"\n");
			fprintf(fPtr,"%d %s %s %s %s %s %d %d %d %d",last_recordID+no_ID_entered, car.licence_plate, car.Make, car.Model, car.Shape, car.Colour, car.Mileage, car.cost_price, car.price_sold, car.sales_person_id);
			scanf("%s %s %s %s %s %d %d %d %d",car.licence_plate,car.Make,car.Model,car.Shape,car.Colour,&car.Mileage,&car.cost_price,&car.price_sold,&car.sales_person_id);
		}
		puts("Your input information has been recorded");
		
		fclose(fPtr); // close the connection to the file
	}
}

// function to read the record of the text file
void read_record()
{
	FILE *fPtr;
	
	if((fPtr = fopen("MarchSales.txt","r")) == NULL)
	{
		puts("Error: The record file can't be opened"); 
	}
	else
	{
		// point to the start of the file
		fseek(fPtr,0,SEEK_SET);
		
		carDetails carSales = {0,{0},{0},{0},{0},{0},0,0,0,0}; // declare a new carDetails variable to read the file information
		
		// temporary memory for storing 
		char licence_plate[MAX_STR_SIZE]={0};
		char Make[MAX_STR_SIZE]={0};
		char Model[MAX_STR_SIZE]={0}; 
		char Shape[MAX_STR_SIZE]={0}; 
		char Colour[MAX_STR_SIZE]={0};
		
		printf("%10s %15s %15s %15s %15s %15s %15s %15s %15s %20s","Record ID", "Licence Plate","Make","Model","Shape","Color","Mileage","Cost Price", "Price Sold","Sales Person ID");
		puts("");
		
		while(!(feof(fPtr)))
		{
			// save the value from the file
			fscanf(fPtr,"%d %s %s %s %s %s %d %d %d %d",&carSales.record_id,licence_plate,Make,Model,Shape,Colour,&carSales.Mileage,&carSales.cost_price, &carSales.price_sold,&carSales.sales_person_id);
			
			// assign the string value from the file into those temporary memory
			strcpy(carSales.licence_plate, licence_plate);
			strcpy(carSales.Make, Make);
			strcpy(carSales.Model, Model);
			strcpy(carSales.Shape, Shape);
			strcpy(carSales.Colour, Colour);
			
			printf("%10d %15s %15s %15s %15s %15s %15d %15d %15d %20d \n",carSales.record_id,carSales.licence_plate,carSales.Make,carSales.Model,carSales.Shape,carSales.Colour,carSales.Mileage,carSales.cost_price, carSales.price_sold,carSales.sales_person_id);
		}
		puts("\n");
		
		fclose(fPtr);
	}
}

// function to calculate the total number of car that has been sold
void total_car_sold()
{
	FILE *fPtr; // file pointer
	
	if((fPtr = fopen("MarchSales.txt","r")) == NULL)
	{
		puts("Error: The record file can't be opened"); 
	}
	else
	{
		carDetails carSales = {0,{0},{0},{0},{0},{0},0,0,0,0}; // declare a new carDetails variable to read the file information
		
		fseek(fPtr,0,SEEK_SET); // set the pointer to the start of the text file
		
		while(!(feof(fPtr)))
		{
			// save the value from the file
			fscanf(fPtr,"%d %s %s %s %s %s %d %d %d %d",&carSales.record_id,carSales.licence_plate,carSales.Make,carSales.Model,carSales.Shape,carSales.Colour,&carSales.Mileage,&carSales.cost_price, &carSales.price_sold,&carSales.sales_person_id);
		}
		
		// save the last result of the car sale ID as the total number of car sold
		int total_sold_car = carSales.record_id;
		
		if(total_sold_car>0)
			printf("The total number of car has been sold is %d\n\n",total_sold_car);
		else
			printf("No car has been sold\n");
		
		fclose(fPtr);
	}
	
}

// function to calculate the total number of car sold for a given colour
void car_sold_givenColour()
{
	FILE *fPtr; // file pointer
	
	if((fPtr = fopen("MarchSales.txt","r")) == NULL)
	{
		puts("Error: The record file can't be opened"); 
	}
	else
	{
		int numCarwiththatColour = 0; // declare an integer variable to record the total number of car with user's input color
		
		char checkColor[MAX_STR_SIZE] = {0}; // user check color of the car
		
		// user input
		puts("Enter your searching color here:");
		fscanf(stdin,"%s",checkColor);
		printf("\n");
		
		carDetails carSales = {0,{0},{0},{0},{0},{0},0,0,0,0}; 
		// declare a new carDetails variable to read the file information
		
		fseek(fPtr,0,SEEK_SET); 
		// set the pointer to the start of the text file
		
		while(!(feof(fPtr)))
		{
			// save the value from the file
			fscanf(fPtr,"%d %s %s %s %s %s %d %d %d %d",&carSales.record_id,carSales.licence_plate,carSales.Make,carSales.Model,carSales.Shape,carSales.Colour,&carSales.Mileage,&carSales.cost_price, &carSales.price_sold,&carSales.sales_person_id);
			
			if(strcmp(carSales.Colour,checkColor)==0)
				numCarwiththatColour++;
		}
		
		if(numCarwiththatColour>0)
			printf("There are %d car which has the color of %s has been sold\n\n",numCarwiththatColour,checkColor);
		else
			printf("No car with that color has been sold\n\n");
		
		fclose(fPtr);
	}
	
}

// function to calculate the total number of car sold that promoted by the sale person with specific ID
void car_sold_givenSalePerson()
{
	FILE *fPtr; // file pointer
	
	if((fPtr = fopen("MarchSales.txt","r")) == NULL)
	{
		puts("Error: The record file can't be opened"); 
	}
	else
	{
		int numCarwiththatSalePerson = 0; // declare an integer variable to record the total number of car promoted by the sale person
		
		int checkSalePersonID = 0; // The ID of the Sale Person been checked
		
		// user input
		puts("Enter the ID of the Sale Person:");
		scanf("%d",&checkSalePersonID);
		printf("\n");
		
		// check if the Sale Person's ID that the user input is valid , as there are only 5 sale person so the ID number should not more than 5 or smaller than 1
		while(!(checkSalePersonID>=1&&checkSalePersonID<=5))
		{
			puts("Your input sale person's ID is invalid, please try again");
			puts("Enter the ID of the Sale Person:");
			scanf("%d",&checkSalePersonID);
			printf("\n");
		}
	
		carDetails carSales = {0,{0},{0},{0},{0},{0},0,0,0,0}; 
		// declare a new carDetails variable to read the file information
		
		fseek(fPtr,0,SEEK_SET); 
		// set the pointer to the start of the text file
		
		while(!(feof(fPtr)))
		{
			// save the value from the file
			fscanf(fPtr,"%d %s %s %s %s %s %d %d %d %d",&carSales.record_id,carSales.licence_plate,carSales.Make,carSales.Model,carSales.Shape,carSales.Colour,&carSales.Mileage,&carSales.cost_price, &carSales.price_sold,&carSales.sales_person_id);
			
			if(carSales.sales_person_id == checkSalePersonID)
				numCarwiththatSalePerson++;
		}
		
		if(numCarwiththatSalePerson>0)
			printf("The sale person with ID number '%d' has promote %d car(s)\n\n",checkSalePersonID,numCarwiththatSalePerson);
		else
			printf("No car has been promoted by that sale person\n\n");
		
		fclose(fPtr);
	}
}

// function to check the car record with the highest mileage
void highest_mileageCar()
{
	FILE *fPtr; // file pointer
	
	if((fPtr = fopen("MarchSales.txt","r")) == NULL)
	{
		puts("Error: The record file can't be opened"); 
	}
	else
	{
		int current_highest_mileage = 0; // declare an integer variable to record the current highest of mileage during the reading of text file, to do as a comparison with other car records' mileage
		
		carDetails carSales = {0,{0},{0},{0},{0},{0},0,0,0,0}; 
		// declare a new carDetails variable to read the file information
		
		fseek(fPtr,0,SEEK_SET); 
		// set the pointer to the start of the text file
		
		while(!(feof(fPtr)))
		{
			// save the value from the file
			fscanf(fPtr,"%d %s %s %s %s %s %d %d %d %d",&carSales.record_id,carSales.licence_plate,carSales.Make,carSales.Model,carSales.Shape,carSales.Colour,&carSales.Mileage,&carSales.cost_price, &carSales.price_sold,&carSales.sales_person_id);
			
			if(carSales.Mileage>current_highest_mileage)
				current_highest_mileage = carSales.Mileage;
		}
		printf("The HIGHEST MILEAGE within all the car sale record is %d\n\n",current_highest_mileage);
		
		fclose(fPtr);
	}
	
}

// function to check the car record with the newest licence plate
void newest_LicencePlateCar()
{
	FILE *fPtr; // file pointer
	
	if((fPtr = fopen("MarchSales.txt","r")) == NULL)
	{
		puts("Error: The record file can't be opened"); 
	}
	else
	{
		char newestLicencePlate[MAX_STR_SIZE] = {0}; 
		// declare a string variable to record the current newest license plate during the reading of text file, to do as a comparison with other car records' license plate
		
		carDetails carSales = {0,{0},{0},{0},{0},{0},0,0,0,0}; 
		// declare a new carDetails variable to read the file information
		
		fseek(fPtr,0,SEEK_SET); 
		// set the pointer to the start of the text file
		
		while(!(feof(fPtr)))
		{
			// save the value from the file
			fscanf(fPtr,"%d %s %s %s %s %s %d %d %d %d",&carSales.record_id,carSales.licence_plate,carSales.Make,carSales.Model,carSales.Shape,carSales.Colour,&carSales.Mileage,&carSales.cost_price, &carSales.price_sold,&carSales.sales_person_id);
			
			if(strcmp(newestLicencePlate,carSales.licence_plate)<0)
				strcpy(newestLicencePlate,carSales.licence_plate);
		}
		printf("The NEWEST LICENCE PLATE within all the car sale record is %s\n\n",newestLicencePlate);
		
		fclose(fPtr);
	}
	
}

// function to check the car record with the largest profit
void largest_Profit()
{
	FILE *fPtr; // file pointer
	
	if((fPtr = fopen("MarchSales.txt","r")) == NULL)
	{
		puts("Error: The record file can't be opened"); 
	}
	else
	{
		int current_largest_profit = 0; // declare an integer variable to record the current largest profit during the reading of text file, to do as a comparison with other car records' profit
		
		carDetails carSales = {0,{0},{0},{0},{0},{0},0,0,0,0}; 
		// declare a new carDetails variable to read the file information
		
		fseek(fPtr,0,SEEK_SET); 
		// set the pointer to the start of the text file
		
		while(!(feof(fPtr)))
		{
			// save the value from the file
			fscanf(fPtr,"%d %s %s %s %s %s %d %d %d %d",&carSales.record_id,carSales.licence_plate,carSales.Make,carSales.Model,carSales.Shape,carSales.Colour,&carSales.Mileage,&carSales.cost_price, &carSales.price_sold,&carSales.sales_person_id);
			
			if(carSales.price_sold-carSales.cost_price>current_largest_profit)
				current_largest_profit = carSales.price_sold - carSales.cost_price;
		}
		printf("The LARGEST PROFIT within all the car sale record is %d\n\n",current_largest_profit);
		
		fclose(fPtr);
	}
	
}

// function to calculate the total profit of all the car sale record
void totalProfit()
{
	FILE *fPtr; // file pointer
	
	if((fPtr = fopen("MarchSales.txt","r")) == NULL)
	{
		puts("Error: The record file can't be opened"); 
	}
	else
	{
		int total_profit = 0; // declare an integer variable to save the total profit
		
		carDetails carSales = {0,{0},{0},{0},{0},{0},0,0,0,0}; 
		// declare a new carDetails variable to read the file information
		
		fseek(fPtr,0,SEEK_SET); 
		// set the pointer to the start of the text file
		
		while(!(feof(fPtr)))
		{
			// save the value from the file
			fscanf(fPtr,"%d %s %s %s %s %s %d %d %d %d",&carSales.record_id,carSales.licence_plate,carSales.Make,carSales.Model,carSales.Shape,carSales.Colour,&carSales.Mileage,&carSales.cost_price, &carSales.price_sold,&carSales.sales_person_id);
			
			total_profit += carSales.price_sold - carSales.cost_price;
		}
		printf("The total profit of all the car sale record is %d\n\n",total_profit);
		
		fclose(fPtr);
	}
	
}

// function to calculate the average profit of the car sale records
void averageProfit()
{
	FILE *fPtr; // file pointer
	
	if((fPtr = fopen("MarchSales.txt","r")) == NULL)
	{
		puts("Error: The record file can't be opened"); 
	}
	else
	{
		int total_profit = 0; // declare an integer variable to save the total profit
		
		carDetails carSales = {0,{0},{0},{0},{0},{0},0,0,0,0}; 
		// declare a new carDetails variable to read the file information
		
		fseek(fPtr,0,SEEK_SET); 
		// set the pointer to the start of the text file
		
		while(!(feof(fPtr)))
		{
			// save the value from the file
			fscanf(fPtr,"%d %s %s %s %s %s %d %d %d %d",&carSales.record_id,carSales.licence_plate,carSales.Make,carSales.Model,carSales.Shape,carSales.Colour,&carSales.Mileage,&carSales.cost_price, &carSales.price_sold,&carSales.sales_person_id);
			
			total_profit += carSales.price_sold - carSales.cost_price;
		}
		
		float average_profit = (float)total_profit/((float)carSales.record_id); 
		// declare a double variable the average profit 
		
		printf("The average profit of all the car sale record is %f\n\n",average_profit);
		
		fclose(fPtr);
	}
}

// function to find the sale person with the biggest total profit from all their sales
void SPwithBiggestTotalProfit()
{
	FILE *fPtr; // file pointer
	
	if((fPtr = fopen("MarchSales.txt","r")) == NULL)
	{
		puts("Error: The record file can't be opened"); 
	}
	else
	{
		int SalePersonIDwithBiggestProfit = 0;
		int earnedProfit[5] = {0};
		
		carDetails carSales = {0,{0},{0},{0},{0},{0},0,0,0,0}; 
		// declare a new carDetails variable to read the file information
		
		fseek(fPtr,0,SEEK_SET); 
		// set the pointer to the start of the text file
		
		// while loop to calculate the total profit of all sale person
		while(!(feof(fPtr)))
		{
			// save the value from the file
			fscanf(fPtr,"%d %s %s %s %s %s %d %d %d %d",&carSales.record_id,carSales.licence_plate,carSales.Make,carSales.Model,carSales.Shape,carSales.Colour,&carSales.Mileage,&carSales.cost_price, &carSales.price_sold,&carSales.sales_person_id);
			
			earnedProfit[carSales.sales_person_id-1] += carSales.price_sold-carSales.cost_price;
		}
		
		// for loop to compute the sale person with the biggest profit
		int biggestProfit = 0;

		for(size_t i=0;i<5;i++)
		{
			if(earnedProfit[i]>biggestProfit)
			{
				biggestProfit = earnedProfit[i];
				SalePersonIDwithBiggestProfit = i+1;
			}
		}
		printf("The Sale Person with ID '%d' has the BIGGEST TOTAL PROFIT %d within the car sale record\n\n",SalePersonIDwithBiggestProfit,biggestProfit);
		
		fclose(fPtr);
	}
}