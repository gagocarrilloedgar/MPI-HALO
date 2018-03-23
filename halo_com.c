#include "headers.h"
#include "mpi.h"

int halo1(double R[],double S[],int N){
	
	int h=1;

		if (rank()%2==0)
		{
			checkr(MPI_Send(S,N*h,MPI_DOUBLE,rank()+1,0,MPI_COMM_WORLD),"sending" );
			MPI_Status st;
			checkr(MPI_Recv(R,N*h,MPI_DOUBLE,rank()+1,0,MPI_COMM_WORLD,&st),"receiving");

		}
		else
		{
			MPI_Status st;
			checkr(MPI_Recv(R,N*h,MPI_DOUBLE,rank()-1,0,MPI_COMM_WORLD,&st),"receiving");
			checkr(MPI_Send(S,N*h,MPI_DOUBLE,rank()-1,0,MPI_COMM_WORLD),"sending" );
		}
}

int halo2(double R[],double S[],int N){
	
	int h=1;

		if (rank()%2==0 && rank()!=0)
		{
			MPI_Status st;
			checkr(MPI_Recv(R,N*h,MPI_DOUBLE,rank()-1,0,MPI_COMM_WORLD,&st),"receiving");
			checkr(MPI_Send(S,N*h,MPI_DOUBLE,rank()-1,0,MPI_COMM_WORLD),"sending" );
		}
		else if (rank()%2!=0 && rank()!=(commsize()-1)) 
		{
			checkr(MPI_Send(S,N*h,MPI_DOUBLE,rank()+1,0,MPI_COMM_WORLD),"sending" );
			MPI_Status st;
			checkr(MPI_Recv(R,N*h,MPI_DOUBLE,rank()+1,0,MPI_COMM_WORLD,&st),"receiving");
			
		}
}
