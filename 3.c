#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<omp.h>
int main(){
	int n,i,j,k,x,y;
	scanf("%d",&n);
	int prime[n+1];
	for(i=0;i<=n;i++)
		prime[i]=1;
	double sine[n+1];
	#pragma omp parallel sections num_threads(10)
	{
		#pragma omp section
		{
            for(i=2;i<=n;i++){
                for(j=i*i;j<=n;j+=i){
                    prime[j]=0;
                }
            }
        }
        #pragma omp section
        {
        for(k=0;k<=n;k++)
            sine[k]=sin(k);
        }

    }
    printf("primes\n");
        for(i=2;i<=n;i++){
            if(prime[i]!=0)
                printf("%d ",i);
        }
    printf("sines\n");
        for(i=0;i<=n;i++){
            printf("%lf ",sine[i]);
        }
}