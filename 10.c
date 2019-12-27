#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
int main(int argc, char **argv){
	int rank,numproc,newrank,newnumproc,i,j,k,x,y,color;
	MPI_Comm newcom;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&numproc);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	color=rank/2;
	MPI_Comm_split(MPI_COMM_WORLD,color,rank,&newcom);
	MPI_Comm_size(newcom,&newnumproc);
	MPI_Comm_rank(newcom,&newrank);

	printf("%d of %d in world is %d of %d subset\n",rank,numproc,newrank,newnumproc);
MPI_Comm_free(&newcom);
MPI_Finalize();


}