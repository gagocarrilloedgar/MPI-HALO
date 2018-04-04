#include "headers.h"
#include "mpi.h"

void data_placing(double M[],double R[],int mystart,int myend,int N){

	int width=N;
	int heigth;
	heigth= myend-mystart+1;

	if (commsize()%2==0)
	{
		if (rank()%2==0)
		{
			for (int j = 0; j < 1; ++j)
			{
				for (int i = 0; i < N; ++i)
				{
					*(M+i+(j+heigth+1)*N) = *(R+i+j*N);
				}
			}
		}

		else
		{
			for (int j = 0; j < 1; ++j)
			{
				for (int i = 0; i < N; ++i)
				{
					*(M+i+(j)*N)=*(R+i+j*N);
				}
			}
		}
	}

	else if (commsize()%2!=0)
	{
		if (rank()%2==0 && rank()!=(commsize()-1))
		{
			for (int j = 0; j < 1; ++j)
			{
				for (int i = 0; i < N; ++i)
				{
					*(M+i+(j+heigth+1)*N)=*(R+i+j*N);
				}
			}
		}

		else if(rank()%2!=0)
		{
			for (int j = 0; j < 1; ++j)
			{
				for (int i = 0; i < N; ++i)
				{
					*(M+i+(j)*N)=*(R+i+j*N);
				}
			}
		}
	}


}



void data_placing2(double M[],double R[],int mystart,int myend,int N){
	int width=N;
	int heigth;
	heigth= myend-mystart+1;

	int h=1,end=myend,start=mystart;

	if (commsize()%2==0)
	{
		if (rank()%2==0 && rank()!=0)
		{
			for (int j = 0; j < 1; ++j)
			{
				for (int i = 0; i < width; ++i)
				{
					*(M+i+(j)*N)=*(R+i+j*N);
				}
			}
		}

		else if( rank()%2!=0 && rank()!=(commsize()-1))
		{
			for (int j = 0; j < 1; ++j)
			{
				for (int i = 0; i < width; ++i)
				{
					*(M+i+(j+heigth+1)*N)=*(R+i+j*N);
				}
			}
		}
	}

	else if (commsize()%2!=0)
	{
		if (rank()%2==0 && rank()!=0)
		{
			for (int j = 0; j < 1; ++j)
			{
				for (int i = 0; i < width; ++i)
				{
					*(M+i+(j)*N)=*(R+i+j*N);
				}
			}
		}

		else if( rank()%2!=0)
		{
			for (int j = 0; j < 1; ++j)
			{
				for (int i = 0; i < width; ++i)
				{
					*(M+i+(j+heigth+1)*N)=*(R+i+j*N);
				}
			}
		}
	}


}
