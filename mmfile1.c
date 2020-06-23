#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TRUE 1
int main(int argc, char** argv) {
  // Initialize the MPI environment
  MPI_Init(NULL, NULL); 
  FILE* file = fopen ("bcsstk01.mtx", "r");
  FILE *fp = fopen("cd.mtx", "w");
  int i = 0;
  int j=0;
  float f=0;
  int numrow=0;
  int numcol=0;
  int nonzero=0;
  fscanf (file, "%d", &numrow);
  fscanf (file, "%d", &numcol);
  fscanf (file, "%d", &nonzero);
  float M[numrow][numcol];
  for (int k=0; k<48; k++)
  {
    for (int w=0; w<48; w++)
    {
      M[k][w]=0; 
    }
  }
  printf ("Matrix %d x %d\n", numrow, numcol);
  //fscanf (file, "%d", &i);    
  while (TRUE)
  {  
      fscanf (file, "%d", &i);
      if(feof(file)!=0)
        break;
      fscanf (file, "%d", &j);
      fscanf (file, "%f", &f);
      M[i-1][j-1]=f;
      fprintf(fp, "%d, %d, %f\n", i, j, M[i-1][j-1]);
     // printf ("M[ %d , %d ] = %f\n", i-1, j-1, M[i-1][j-1]);
  }
      

  fclose (file);
  fclose (fp);
  MPI_Finalize();
}
