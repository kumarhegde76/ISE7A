#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(int argc, char* argv[])
{
	int rank,size,i,j;
	double a[100],b[100];
	double mysum=0.0,allsum;

	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	if(rank==0)
		printf("The Process Started with %d Task\n",size);
		for(i=0;i<100;i++)
		{
			a[i]=1.0;
			b[i]=a[i];

		}

		for(j=0;j<100;j++)
		{
			mysum=mysum+a[j]*b[j];
		}
		printf("The task %d Partial sum is %f\n",rank,mysum);
		MPI_Reduce(&mysum,&allsum,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
		if(rank==0)
		{
			printf("Completed Process The global sum is %f\n",allsum);
		}

		MPI_Finalize();


	}
