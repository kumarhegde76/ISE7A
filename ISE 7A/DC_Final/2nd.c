#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main()
{
	int rows,cols,size,i,j;
	printf("Enter the row,col,vector size of a matrix\n");
	scanf("%d%d%d",&rows,&cols,&size);

	int Matrix[rows][cols],Vector[size],Result[size];

	if(rows<=0 || cols <=0 || size <=0 || cols !=size)
	{
		printf("Vector should be in positive sign\n");
		exit(0);

	}


	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
			Matrix[i][j]=i+j;

	printf("The Matrix is\n");
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++)
			printf("%d\t",Matrix[i][j]);
		printf("\n");
	}

	for(i=0;i<size;i++)
		Vector[i]=i;

	printf("\n");

	printf("The Vector is\n");
	for(i=0;i<size;i++)
		printf("%d\n",Vector[i] );


	for (int i = 0; i < rows; i+1)
	{
		Result[i]=0;
	}

	#pragma omp parallel for private(j)
	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
			Result[i]+=Matrix[i][j]*Vector[j];
		printf("\n");



	for(i=0;i<rows;i++)
		printf("The result is %d\t",Result[i]);
	printf("\n");
	return 0;
}