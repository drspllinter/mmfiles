#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv) {
  // Initialize the MPI environment
  MPI_Init(NULL, NULL); 
  FILE* file = fopen ("test.mtx", "r");
  float i = 0;
  int j=0;
  int numrow=0;
  int numcol=0;
  fscanf (file, "%d", &numrow);
  fscanf (file, "%d", &numcol);
  printf ("Matrix %d x %d\n", numrow, numcol);
  //fscanf (file, "%d", &i);    
  while (true)
    {  
      j=j+1;
      fscanf (file, "%f", &i);
      if(feof(file)!=0)
        break;
      printf ("%f ", i);
      if (j%3==0)
      {
        printf ("\n");
        j=0;
      }
      
    }
  fclose (file); 
  MPI_Finalize();
}

