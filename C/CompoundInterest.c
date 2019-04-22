#include<stdio.h>
#include<math.h>
/* Written By Ee En Goh, to calculate the compound interest */
char main(){
	double P,A,r,n,k;
	//P is the starting amount of money
	//A is the amount that is accumulated after n years
	//r is the interest rate
	//n is the length of years from accumulation begun
	char finding;//To let the user insert the components that are needed
	printf("Please enter the component you are going to find(A/P/r/n/k):");
	scanf("%c",&finding);
	switch(finding){
		case 'A':
		{
			printf("Please enter the starting principal(in euro)(P):");
			scanf("%lf",&P);
			printf("Please enter the interest rate (as percentage rate per annum)(r):");
			scanf("%lf",&r);
			printf("Please enter the number of years(n):");
			scanf("%lf",&n);
			printf("Please enter the frequency that the interests are added into the account annually (euro per time)(k):");
			scanf("%lf",&k);
			
			A = P*pow((1+(r/(100*k))),(n*k));
			printf("\n");
			printf("The final accumulated amount(A) of P=%lf,r=%lf,n=%lf and k=%lf is %lf euro",P,r,n,k,A);
			break;
		}
		case 'P':
		{
			printf("Please enter the final accumulated amount(in euro)(A):");
			scanf("%lf",&A);
			printf("Please enter the interest rate (as percentage rate per annum)(r):");
			scanf("%lf",&r);
			printf("Please enter the number of years(n):");
			scanf("%lf",&n);
			printf("Please enter the frequency that the interests are added into the account annually (euro per time)(k):");
			scanf("%lf",&k);
			
			P = (1/A)*pow((1+(r/(100*k))),(n*k));
			printf("\n");
			printf("The starting principal(P) of A=%lf,r=%lf,n=%lf and k=%lf is %lf euro",A,r,n,k,P);
			break;
		}
		case 'r':
		{
			printf("Please enter the final accumulated amount(A):");
			scanf("%lf",&A);
			printf("Please enter the starting principal(P):");
			scanf("%lf",&P);
			printf("Please enter the number of years(n):");
			scanf("%lf",&n);
			printf("Please enter the frequency that the interests are added into the account annually (euro per time)(k):");
			scanf("%lf",&k);
			
			r = 100*k*(pow((A/P),((1/(n*k))))-1);
			printf("\n");
			printf("The interest rate(as percentage rate per annum)(r) of A=%lf,P=%lf,n=%lf and k=%lf is %lf euro per time",A,P,n,k,r);
			break;
		}
		case 'n':
		{
			printf("Please enter the final accumulated amount(A):");
			scanf("%lf",&A);
			printf("Please enter the starting principal(P):");
			scanf("%lf",&P);
			printf("Please enter the interest rate(as percentage rate per annum)(r):");
			scanf("%lf",&r);
			printf("Please enter the frequency that the interests are added into the account annually(k):");
			scanf("%lf",&k);
			
			n = log(A/P)/(k*log(1+(r/(100*k))));
			printf("\n");
			printf("The number of years(n) of A=%lf,P=%lf,r=%lf and k=%lf is %lf year(s)",A,P,r,k,n);
			break;
		}
	}
	return finding;
}
			
