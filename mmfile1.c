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
  float M[48][48];
  for (int k=0; k<48; k++)
  {
    for (int w=0; w<48; w++)
    {
      M[k][w]=0; 
    }
  }
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
      M[i-1][j-1]=f;
      //printf ("M[ %d , %d ] = %f\n", i, j, M[i][j]);
    }
    for (int i = 0; i <48; i++){
	for (int j = 0; j <48; j++){
		printf("%f", M[i][j]);
		if(j!=47)
		{
				printf(", ");	
		}
	}
	printf("\n");
   }
  fclose (file); 
  MPI_Finalize();
}
