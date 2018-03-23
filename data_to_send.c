#include "headers.h"
#include "mpi.h"

void data_to_send(int N, double M[],double S[],int *mystart,int *myend){

	int width=N;
	int heigth;
	heigth= myend-mystart+1;

	if (rank()%2==0)
	{
		for (int j = 0; j <1 ; ++j)
		{
			for (int i = 0; i < width; ++i)
			{
				*(S+i+j*width)=*(M+i+(j+heigth)*width);
			}
		}
	}
	else
	{
		for (int j = 0; j < 1 ; ++j)
		{
			for (int i = 0; i < width; ++i)
			{
				*(S+i+j*width)=*(M+i+(j+1)*width);
			}
		}
	}

}

void data_to_send2(int N, double M[],double S[],int *mystart,int *myend){

	int width=N;
	int heigth;
	heigth= myend-mystart+1;

	if (rank()%2==0 && rank()!=0)
	{
		for (int j = 0; j <1 ; ++j)
		{
			for (int i = 0; i < width; ++i)
			{
				*(S+i+j*width)=*(M+i+(j+1)*width);
			}
		}
	}
	else if (rank()%2!=0 && rank()!=(commsize()-1))
	{
		for (int j = 0; j < 1 ; ++j)
		{
			for (int i = 0; i < width; ++i)
			{
				*(S+i+j*width)=*(M+i+(j+heigth)*width);
			}
		}
	}

}