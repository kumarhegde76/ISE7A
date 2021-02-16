#include<stdio.h>
#include<math.h>
#include<omp.h>
#include<stdlib.h>
double sines[1000];
double primes[1000];

void prime_table(int prime_num)
{
	int p=0,i=2,j,prime;
	while(p<prime_num)
	{
		prime=1;
		for(j=2;j<i;j++)
			if((i%j)==0)
			{
				prime=0;
				break;
			}
		          if(prime)
			    {
				primes[p]=i;
				p++;
			    }	
		i++;
	}


}
void sine_table(int sine_num)
{
	int i;
	double a;
	for(i=0;i<sine_num;i++)
	{
		sines[i]=sin(i*M_PI/180);
	}
}
int main()
{
	int n,m,size;
	printf("Enter the Value\n");
	scanf("%d",&size);
	#pragma omp parallel sections
	{
		#pragma omp section
		{
			prime_table(size);
			for(n=0;n<size;n++)
			{
				printf("%lf\n",primes[n]);
			}
		}
	
		#pragma omp section
		{
			sine_table(size);
			for(m=0;m<size;m++)
				printf("%lf\n",sines[m]);
		} 

	}
	return 0;
}
