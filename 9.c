#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#include<math.h>
int main(int argc, char **argv){
	int pcircle=0,ptotal=0,tpcircle,tptotal,numproc,rank,i,j;
	double x,y,t1,t2;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&numproc);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	t1=MPI_Wtime();
	for(i=0;i<100000;i++){
		x=(double)rand()/RAND_MAX;
		y=(double)rand()/RAND_MAX;
		ptotal++;
		if(pow(x,2)+pow(y,2)<1.0)
			pcircle++;
	}
	MPI_Reduce(&ptotal,&tptotal,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	MPI_Reduce(&pcircle,&tpcircle,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	t2=MPI_Wtime();
if(rank==0){
	double pi=4*((double)tpcircle/tptotal);
	printf("%d\t%lf\t%lf",tpcircle,pi,t2-t1);
}
MPI_Finalize();
}