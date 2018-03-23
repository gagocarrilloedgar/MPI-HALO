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

   	M=(double *)malloc(sizeof (double)*width*width);
	R=(double *)malloc(sizeof (double)*width*1);
	S=(double *)malloc(sizeof (double)*width*1);

   if (M==NULL || R==NULL || S==NULL) 
    {
        printf("Out of memory\n");
        exit(1);
    }
	
	for (int j = 1; j <=heigth; ++j)
	{
		for (int i = 0; i<width; ++i)
		{
			*(M+i+j*N)=*(Q+i+(j+mystart-1)*N);
		}
	}
	
	data_to_send(N,M,S,&mystart,&myend);
	halo1(R,S,N);
	data_placing(M,R,&mystart,&myend,N);

	data_to_send2(N,M,S,&mystart,&myend);
	halo2(R,S,N);
	data_placing2(M,R,&mystart,&myend,N);

 
		for (int j = 0; j< N/2; ++j)
	{
		for (int i = 0; i < N; ++i)
		{
			printf(" rank=%d ", rank() );
			if (*(M+i+j*width)<10)
			{
				printf("   %.1f    ",*(M+i+j*width) );
			}
			else{
			printf("  %.1f    ",*(M+i+j*width) );
			}
		}
		printf("\n");
	}


	free (R);
	free (M);
	free (S);
	free (Q);
	
	crash();
}

