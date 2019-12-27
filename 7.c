#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
int main(int argc, char **argv){
	int a=10,numproc,rank,b,i;
	char *s="hello";
	char s2[23];
	MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&numproc);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	if(rank==0){
		for(i=1;i<4;i++){
		MPI_Recv(s2,32,MPI_BYTE,i,1,MPI_COMM_WORLD,&status);
		printf("%s recv from %d of %d\n",s2,i,numproc);
	}
	}
	else{
		MPI_Send(s,sizeof(s),MPI_BYTE,0,1,MPI_COMM_WORLD);
	}
	if(rank==0){
		printf("thats all");
	}
	MPI_Finalize();
}