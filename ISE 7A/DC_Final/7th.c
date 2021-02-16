#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#include<string.h>
#define SIZE 32

int main(int argc,char* argv[])
{
	int temp=1,tag=0,root=3,rank,np;
	char msg[SIZE];
	MPI_Init(&argc,&argv);
	MPI_Status status;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&np);
	
	if(rank==3)
	{
		strcpy(msg,"Hello");
		
		for(temp=0;temp<np;temp++)
		{
			if(temp!=3)
			{
				MPI_Send(msg,SIZE,MPI_CHAR,temp,tag,MPI_COMM_WORLD);
				
			}
		}
	}
	else
	{
	   MPI_Recv(msg,SIZE,MPI_CHAR,root,tag,MPI_COMM_WORLD,&status);
	   printf("\n %s with rank %d from rank %d\n",msg,rank,root);
	   
	   }
	     MPI_Finalize();
	}
