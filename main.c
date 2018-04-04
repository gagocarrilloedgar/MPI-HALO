#include "headers.h"
#include "mpi.h"

int main (int argc, char** argv){

	int N=8,mystart, myend,start=0,end=N,width,heigth;
	double *M,*R,*S,*Q;

	checkr(MPI_Init(&argc,&argv),"init");

	srand (time(NULL)+rank());

	Q=(double *)malloc(sizeof(double)*N*N);

	if (Q==NULL)
    	{
       	 	printf("Out of memory\n");
        	exit(1);
    	}

    //llenamos la matriz de forma random

   for (int j = 0; j< N; ++j)
   {
    	for (int i = 0; i < N; ++i)
   		{
   			*(Q+i+j*N)=rand()%100;
   		}
   }

   	worksplit(start,end,commsize(),rank(),&mystart,&myend);
   	width=N;
	heigth=myend-mystart+1;

  M=(double *)malloc(sizeof (double)*width*(heigth+3));
	R=(double *)malloc(sizeof (double)*width*1);
	S=(double *)malloc(sizeof (double)*width*1);

   if (M==NULL || R==NULL || S==NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }


	for (int j = 1; j <=heigth; ++j)
	{
		//printf("rank=%d ", rank());
		for (int i = 0; i<width; ++i)
		{
			*(M+i+j*N)=*(Q+i+(j+mystart-1)*N);
		//	printf(" %f-%d-%d ",*(M+i+j*N),i,j);
		}
		//printf("\n");
	}
	halo_update(M,S,R,N, myend,mystart);

	for (int j = 0; j< (heigth+2); ++j)
	{
		for (int i = 0; i < N; ++i)
		{
			printf(" rank=%d ", rank() );
			if (*(M+i+j*width)<10)
			{
				printf("   %.1f-%d-%d    ",*(M+i+j*width),i,j );
			}
			else{
			printf("  %.1f-%d-%d    ",*(M+i+j*width),i,j );
			}
		}
		printf("\n");
	}
	MPI_Barrier(MPI_COMM_WORLD);



	free (R);
	free (M);
	free (S);
	free (Q);

	crash();
}
