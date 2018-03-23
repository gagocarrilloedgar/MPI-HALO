#include "headers.h"
#include "mpi.h"

int worksplit(int start, int end,int P,int whoami,int *mystart, int *myend){

	int N=0,x=0,r=0;

	*mystart=start;
	N=end-start;

	if(N<P) return(0); // not ok 
	if(end<start) return(0); // not ok

	for (int i =0; i<=P-1; ++i)
	{
		x=N/P;
		r=N%P;

		if (i<r){
			x=x+1;
		}

		*myend=*mystart+x-1;

		if (i==whoami){
			break;
		}

		*mystart=*myend+1;	
	
	}
	return (1);
}
