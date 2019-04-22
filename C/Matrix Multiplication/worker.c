/**
 *  @author     Ee En Goh
 *  @studentid  17202691
 *  @email      ee.goh@ucdconnect.ie
 */
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <math.h>

#define PORTNUM 2343
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void displayMatrix(int *matrix[], int row, int col);
void matrix_multiplication(int numPartition, int matrixSize ,int partOfA[matrixSize/numPartition][matrixSize], int matrixB[matrixSize][matrixSize], int partOfC[matrixSize/numPartition][matrixSize]);

// ----- Function Definition -----
/** 
 * Matrix Multiplication Calculation Function
 */
	
void matrix_multiplication(int numPartition, int matrixSize ,int partOfA[matrixSize/numPartition][matrixSize], int matrixB[matrixSize][matrixSize], int partOfC[matrixSize/numPartition][matrixSize]){
	puts("Calculation time !!");
	int rowPartition = (int)(matrixSize/numPartition);

	// Calculation
	for(int i = 0 ; i < rowPartition ; i++){	// Counter for row number of matrixA
		for(int j = 0 ; j < matrixSize ; j++){		// Counter for column number of matrix B				
			for(int k = 0 ; k < matrixSize ; k++){	// Counter for row number of matrix B
				partOfC[i][j] += partOfA[i][k] * matrixB[k][j];
			}
			printf("partOfC[%d][%d] : %d\n",i,j,partOfC[i][j]);
		}
	}
}

/**
*	Function to display the elements of a matrix / vector with size row * col
*	@param matrix 	The reference to the matrix/vector 
*	@param row 		The total row number of given matrix/vector
*	@param col		The total column number of given matrix/vector
*/
void displayMatrix(int *matrix[], int row, int col){

	for(int i = 0 ; i < row ; i++){
		for(int j = 0 ; j < col ; j++){
			printf("%d ", matrix[i][j]);
		}
		puts("");
	}
	puts("");
}
// ----- END OF Function Definition -----

// Worker Process 
int main(int argc, char **argv){
	
	/* char *ip = NULL;
	
	if(argc > 1){ 			// It means there are a command line argument given
		ip = argv[1];
	}else{
		ip = "127.0.0.1"; 	// Else it is working on the same machine : localhost 
	}*/
	
	struct sockaddr_in client;
	socklen_t socksize = sizeof(struct sockaddr_in);
	
	memset(&client, 0, sizeof(client));
	
	client.sin_family 		= AF_INET;
	client.sin_addr.s_addr 		= INADDR_ANY;
	client.sin_port			= htons(PORTNUM);
	
	int connectSocket;
	if((connectSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("Client socket creation error ");
		exit(EXIT_FAILURE);
	}else
		puts("Client socket creation success!");
	
	if((connect(connectSocket, (struct sockaddr *)&client, socksize)) < 0){
		perror("Connection failed ");
		exit(EXIT_FAILURE);
	}else{
		puts("Connected to server !");
		printf("connectSocket : %d\n",connectSocket);
	}
	// Buffer
	int numPartition;
	int matrixSize;
	
	recv(connectSocket, &matrixSize, sizeof(int), 0);	// Received
	recv(connectSocket, &numPartition, sizeof(int), 0);	// Received
	
	printf("\nMatrices Size - %d x %d\nNumber of Partition - %d\n",matrixSize, matrixSize, numPartition);

// 	pthread_mutex_lock(&mutex);
	
	int rowsOfPartition = matrixSize/numPartition;
	int matrixB[matrixSize][matrixSize];
	int partOfA[rowsOfPartition][matrixSize];
	int partOfC[rowsOfPartition][matrixSize];
	
	// Receive matrixB from server
	for(int i = 0 ; i < matrixSize ; i++){
		for(int j = 0 ; j < matrixSize ; j++){
			if(recv(connectSocket, &matrixB[i][j], sizeof(int) , 0) < 0){
				perror("Transfer Data Failed [B] ");
				exit(EXIT_FAILURE);
			}else
				printf("Data received of matrixB[%d][%d]!\n",i,j);	
	        }
        }
	
	// DEBUG :  Display matrixB
	//for(int i = 0 ; i < matrixSize ; i++){
	//	for(int j = 0 ; j < matrixSize ; j++)
	//		printf("B[%d][%d] : %d\n",i,j,matrixB[i][j]);
	//}	
	puts("");
	

	// Receive partition of matrix A and sent calculated partition of matrix C
	// Counter of receiving different partitions
	for(int k = 0 ; k < numPartition; k++){		
		
		puts("New worker process");
		printf("rowsOfPartition : %d\n", rowsOfPartition);

		// Receiving the partition of matrix A and send back partition of matrix C	
		// Counter of receiving rows in each partition
		for(int i = 0 ; i < rowsOfPartition; i++) {

			printf("Entering  partition %d time(s) !\n", rowsOfPartition);
	
			// Receiving column elements Of matrix A
			for(int j = 0 ; j < matrixSize ; j++){

				if(recv(connectSocket, &partOfA[i][j], sizeof(int), 0) < 0){
					perror("Receiving error in A");
					exit(EXIT_FAILURE);
				}
				else{	
					printf("part of A[%d][%d] : %d\n",i,j,partOfA[i][j]);
				}
			}			
			printf("Receive partition of matrix A :\n");
		
			// Doing matrix multiplication here	
			matrix_multiplication(numPartition, matrixSize, partOfA, matrixB, partOfC);
	
			// Sending the calculated result back	
			puts("Sending calculation result ...");
			for(int j = 0 ; j < matrixSize ; j++){
				send(connectSocket,&partOfC[i][j], sizeof(int), 0);
				printf("%d ",partOfC[i][j]);
			}puts("");

			sleep(2);
	}
}	
	close(connectSocket);
	printf("Data Transfer Done !\n");
	
	return EXIT_SUCCESS;
}
