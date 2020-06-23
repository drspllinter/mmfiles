#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TRUE 1
int main(int argc, char** argv) {
  // Initialize the MPI environment
  MPI_Init(NULL, NULL); 
  FILE* file = fopen ("test.mtx", "r");
  
  int i = 0;
  int j=0;
  float f=0;
  int numrow=0;
  int numcol=0;
  fscanf (file, "%d", &numrow);
  fscanf (file, "%d", &numcol);
  printf ("Matrix %d x %d\n", numrow, numcol);
  //fscanf (file, "%d", &i);    
  while (TRUE)
    {  
      fscanf (file, "%d", &i);
      fscanf (file, "%d", &j);
      fscanf (file, "%f", &f);
      if(feof(file)!=0)
        break;
      printf ("M[ %d , %d ] = %f\n", i, j, f);
    }
  fclose (file); 
  MPI_Finalize();
}

