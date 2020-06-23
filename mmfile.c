#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv) {
  // Initialize the MPI environment
  MPI_Init(NULL, NULL); 
  FILE* file = fopen ("test.mtx", "r");
  int i = 0;
  int numrow=0;
  int numcol=0;
  fscanf (file, "%d", &numrow);
  fscanf (file, "%d", &numcol);
  printf ("Matrix %d x %d\n", numrow, numcol);
  //fscanf (file, "%d", &i);    
  while (!feof (file))
    {  
      fscanf (file, "%f", &i);
      printf ("%f ", i);
      
    }
  fclose (file); 
  MPI_Finalize();
}
