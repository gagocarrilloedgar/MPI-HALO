#include "headers.h"
#include "mpi.h"
void checkr(int r,char *txt) {
  if (r!=MPI_SUCCESS) {
    fprintf(stderr,"Error: %s\n",txt);
    exit(-1);
  }
}

int commsize() {
  int a,b;
  a=MPI_Comm_size(MPI_COMM_WORLD,&b);
  checkr(a,"quants");
  return(b);
}

int rank() {
  int a,b;
  a=MPI_Comm_rank(MPI_COMM_WORLD,&b);
  checkr(a,"whoami");
  return(b);
}

void crash()
{
	MPI_Finalize();
	exit(-1);
}