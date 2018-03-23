#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Common mpi functions
void crash();
void checkr(int r,char *txt);
int commsize();
int rank();

//Halo update functions

//Worksplit function
int worksplit(int start, int end,int P,int whoami,int *mystart, int *myend);

// MPI communication function
int halo1(double R[],double S[], int N);
int halo2(double R[],double S[], int N);

void data_to_send(int N, double M[],double R[],int *mystart,int *myend);
void data_to_send2(int N, double M[],double R[],int *mystart,int *myend);

void data_placing(double M[],double R[],int *mystart,int *myend,int N);
void data_placing2(double M[],double R[],int *mystart,int *myend,int N);
