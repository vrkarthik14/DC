#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
int main(int argc, char **argv){
	int rank,numproc,i,j,k,x1=4,y1=3,x2=3,y2=5,A[4][5],B[3][5],C[4][5],info[3]={0,0,0},l;
	int data[3]={0,0,0};
	for(i=0;i<4;i++){
		for(j=0;j<5;j++){
			A[i][j]=1;
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<5;j++){
			B[i][j]=2;
		}
	}
	for(i=0;i<4;i++){
			for(j=0;j<5;j++){
				C[i][j]=0;
			}
			
		}
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&numproc);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	if(rank==0){
		for(l=0;l<x1*y2;l++){
		MPI_Recv(info,3,MPI_INT,MPI_ANY_SOURCE,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		C[info[0]][info[1]]=info[2];
	}
	}
	else{
		for(i=rank-1;i<x1;i+=(numproc-1)){
			
			for(j=0;j<y2;j++){
				data[2]=0;
				for(k=0;k<3;k++){
					data[2]+=A[i][k]*B[k][j];
				}
				data[0]=i;
				data[1]=j;
				//printf("%d %d %dfrom %d\n",data[0],data[1],data[2],rank );
				MPI_Send(data,3,MPI_INT,0,1,MPI_COMM_WORLD);
			}
		}
	}
	if(rank==0){
		for(i=0;i<4;i++){
			for(j=0;j<5;j++){
				printf("%d ",C[i][j]);
			}
			printf("\n");
		}
	}
	MPI_Finalize();

}