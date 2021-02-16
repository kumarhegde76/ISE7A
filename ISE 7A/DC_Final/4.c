#include<stdio.h>
#include<omp.h>

void main()
{
	int fact1=1,fact2=1,n,i;


	printf("Enter the number to find its factorial\n");
	scanf("%d",&n);

	#pragma omp parallel for firstprivate(n)
	for(i=2;i<=n;i++)
		fact1=fact1*i;

	printf("when first private not used\n");
	printf("The Factorial of %d is %d\n",n,fact1);


	#pragma omp parallel for firstprivate(n,fact2)
	for(i=2;i<=n;i++)
		fact2=fact2*i;

	printf("When First private is used \n");
	printf("The factorial of %d is %d\n",n,fact2 );
}