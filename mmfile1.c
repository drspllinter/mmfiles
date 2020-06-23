#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TRUE 1
int main(int argc, char** argv) {
  // Initialize the MPI environment
  MPI_Init(NULL, NULL); 
  FILE* file = fopen ("bcsstk01.mtx", "r");
  
  int i = 0;
  int j=0;
  float f=0;
  int numrow=0;
  int numcol=0;
  int nonzero=0;
  fscanf (file, "%d", &numrow);
  fscanf (file, "%d", &numcol);
  fscanf (file, "%d", &nonzero);
  printf ("Matrix %d x %d\n", numrow, numcol);
  //fscanf (file, "%d", &i);    
  while (TRUE)
    {  
      fscanf (file, "%d", &i);
      if(feof(file)!=0)
        break;
      fscanf (file, "%d", &j);
      fscanf (file, "%f", &f);
      printf ("M[ %d , %d ] = %f\n", i, j, f);
    }
  fclose (file); 
  MPI_Finalize();
}
