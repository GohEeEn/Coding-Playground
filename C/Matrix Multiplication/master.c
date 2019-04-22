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

/**
 * Structure to pass multiple value into a thread
 * Components :
 * - Total number of horizontal partitions of matrix A created 
 * - The size of matrices
 * - The whole matrix A
 * - The whole matrix B
 * - Partition of C
 */
typedef struct{
	int numPartition;
	int matrixSize;
	int **matrixA;
	int **matrixB;
	int **matrixC;
	int clientfd;
	int serverfd;
	int rowCounter;
}Workers;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; 

// ----- FUNCTIONS DEFINITION -----
/** 
 *  Function that used to initialize a nxn matrix
 *  @param n The number of rows and columns of matrix
 *  @return An initialized matrix
 *  DONE
 */
int** init_matrices(int n){
	
	// Create a block memory for n pointer elements array and return a pointer to it [int matrix[]]
	int **matrix = malloc(sizeof(int *) * n);
	
	// DEBUG : Create a block memory for n elements array that link to each pointer elements in matrix[]
	for(int i = 0 ; i < n ; i++){
		matrix[i] = malloc(sizeof(int) * n);
	}
	
	// Case if memory allocation not success
	if(matrix == NULL){
		perror("Memory Allocation malloc() fail");
		return NULL;
	}
		
	/* Initialize random number generator : No enough randomness yet */
	srand((unsigned) time(NULL));
	
	// Initialize with randomized matrix
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			// matrix[i][j] = rand() % 50;
			matrix[i][j] = i + j;	
		}
	}
	
	return matrix;
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

/**
*	Pthread function : Sending partition of matrix A to the worker program
*	TODO
*/
void* sendData(void *argv){
	
	Workers *data = (Workers *)argv;

	// puts("New Pthread Function Called");	
		
	// Send the whole matrix B
	puts("Sending matrix B ...");
	
	for(int i = 0 ; i < data->matrixSize ; i++){
		for(int j = 0 ; j < data->matrixSize ; j++){
			send(data->clientfd,&(data->matrixB[i][j]), sizeof(int),0);
			// printf("matrixB[%d][%d] : %d\n",i,j,data->matrixB[i][j]);
		}
	}

	puts("Send matrix B done!");

//	printf("data->matrixSize : %d ; numPartition : %d\n",data->matrixSize, data->numPartition);	
	int partitionRows = data->matrixSize/data->numPartition;	
	int newCall = data->rowCounter;
	
	// Send partition of matrix A and receive partition of matrix C	
	for(int i = partitionRows * newCall ; i < partitionRows * (newCall+1) ; i++){
		
		printf("i = %d\n",i);
			
		// Send partition of matrix A to client
		for(int j = 0 ; j < data->matrixSize; j++){
			send(data->clientfd, &(data->matrixA[i][j]), sizeof(int), 0);
		//	printf("%d ", data->matrixA[i][j]);
		}
		puts("Partition of matrix A sent");
		
		sleep(2);
	
		// Receive calculation result from client
		for(int k = 0 ; k < data->matrixSize ; k++){
			
			if(recv(data->clientfd, &(data->matrixC[i][k]), sizeof(int), 0)<0){
				perror("Data Transfer from worker process unsuccessful ");
			}else{
			//	printf("Data receives :[%d][%d] %d\n",i,k,data->matrixC[i][k]);
			}
		}
	}

	pthread_exit(NULL);
}

// ----- END OF FUNCTIONS DEFINITION -----

// master program / process
int main(int args, char **argv){
	
	// 2 argv should be given
	if(args != 3){
		perror("Incorrect number of command line arguments given\n");
		exit(EXIT_FAILURE);
	}

	Workers work; // General Workers struct
	
	/** The number of rows and columns of the matrices , n */
	int size = atoi(argv[1]);
	/** The number of worker processes to be created , p*/
	int num_partition = atoi(argv[2]);

	// Numbers of rows of matrix A is expected to be divided into p partitions
	if(size % num_partition != 0){	
		perror("Invalid input : number of partition should divides matrix size");
		exit(EXIT_FAILURE);
	}

	/** The number of rows per partition */
	// int size_partition = size / num_partition;
	
	// ----- Initialize matrixA and matrixB -----
	printf("Generating %d x %d matrices A and B\n",size,size);
	
	work.numPartition	= num_partition;
	work.matrixSize 	= size;
	work.matrixA 		= init_matrices(size);
	work.matrixB 		= init_matrices(size);

	// Assign memory space for matrixC	
	work.matrixC = malloc(sizeof(int *) * size);
	for(int i = 0 ; i < size ; i++){
		if((work.matrixC[i] = malloc(sizeof(int) * size)) < 0)
			perror("Allocate memory for matrix C ");
	}
	
	// displayMatrix(matrixA, size, size);
	// displayMatrix(matrixB, size, size);
	
	// ----- END OF Initialize matrixA and matrixB -----
	
	// ----- Socket ------
	struct sockaddr_in client, server;
	socklen_t socksize = sizeof(struct sockaddr_in);
	
	memset(&server, 0, socksize);
	
	// Connection property setting
	server.sin_family = AF_INET; 	
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_port = htons(PORTNUM);
	
	// Declare a server socket 
	if((work.serverfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("Client socket creation error");
		exit(EXIT_FAILURE);
	}else{
		puts("Client Socket created");
	}
	
	// Connect the server socket to given port number and local address
	bind(work.serverfd,(struct sockaddr *)&server, socksize);
	listen(work.serverfd, 1);
	
	puts("Waiting for connection ... ");
	
	if((work.clientfd = accept(work.serverfd, (struct sockaddr *)&client, &socksize)) < 0){
		perror("Connection not found ");
		exit(EXIT_FAILURE);
	}else{
		puts("Connection from client success!");
		printf("client fd : %d\n",work.clientfd);
	}
	send(work.clientfd, &size, sizeof(int), 0);		// Send the size of matrices
	send(work.clientfd, &num_partition, sizeof(int), 0);	// Send the number of partitions
	
	puts(""); // TODO
	
	// ----- Pthread -----
	pthread_t tid[num_partition];
	work.rowCounter = 0; // Row number of matrix A that has been sent	
	printf("Number of partition : %d\n", num_partition);	

	// Sending partition of A with size matrixSize/numPartition	

	for(int i = 0 ; i < num_partition ; i++){

		pthread_mutex_lock(&mutex);
		pthread_create(&tid[i], NULL, sendData, (void *)&work);
		pthread_join(tid[i], NULL);
		pthread_mutex_unlock(&mutex);
		work.rowCounter++;
		puts("");
	}

	// sleep(2);

	// ----- END OF Pthread -----
	
	// Display returned data
	puts("Received matrix C : ");
	displayMatrix(work.matrixC, size, size);
	
	// Close sockets
	close(work.clientfd);
	close(work.serverfd);
	
	return EXIT_SUCCESS;
}
