#include <stdio.h>
#include <string.h>  
#include <mpi.h>
#include <math.h>

// função q representa f(x)= x^2 - 4x + 8
double func(double x) {
    return (double) pow(x,2)-4*x+8;
}

//função que calcula area aproximada de um retângulo, no intervalo [a,b] de func
double integra(double a, double b) {
    double altura, largura;
    if (a > b) {
        return integra(b,a);
    }
    if (func(a) < func(b)) {
        altura = func(b);
    }
    else {
        altura = func(a);
    }
    largura = b - a;
    return altura*largura;
}

double integraIntervalo(double a, double b, double delta) {
    double final = (a > b)? a : b;
    double inicio = (b < a)? b : a;
    double deltaInicio;
    double total;
    while (inicio < final) {
        total += integra(inicio, inicio+delta);
        inicio += delta;
    }
    
    return total;
}

int main(void) {
   int        comm_size;               
   int        my_rank;
   double     inicio, fim;
   double     area, areaAux;
  

   MPI_Init(NULL, NULL); 
   MPI_Comm_size(MPI_COMM_WORLD, &comm_size); 
   MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); 
   
   inicio = (double) my_rank + 1;
   fim = (double) inicio + 1;
   //printf("%lf %lf \n", inicio, fim);
   
   area = integraIntervalo(inicio, fim, 0.000001);
   printf("%lf \n", area);
   
   if (my_rank != 0) {
      /* Envio da mensagem para o processo 0 */
      MPI_Send(&area, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
   } else {  
      
      for (int q = 1; q < comm_size; q++) {
         /* Recepção da mensagem do processo q */
         MPI_Recv(&areaAux, 1, MPI_DOUBLE, q, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
         area += areaAux;
      }
      /* Impressão da mensagem do processo centralizador */
      printf("A área é: %lf \n", area);
   }

   /* Finaliza MPI */
   MPI_Finalize(); 

   return 0;
}  /* main */
