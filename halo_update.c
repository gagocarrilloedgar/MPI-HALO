#include "headers.h"
#include "mpi.h"

void halo_update(double M[],double S[],double R[],int N, int  myend, int mystart)
{
  data_to_send(N,M,S,mystart,myend);
  halo1(R,S,N);
  data_placing(M,R,mystart,myend,N);

  MPI_Barrier(MPI_COMM_WORLD);

  data_to_send2(N,M,S,mystart,myend);
  halo2(R,S,N);
  data_placing2(M,R,mystart,myend,N);

  MPI_Barrier(MPI_COMM_WORLD);
}
