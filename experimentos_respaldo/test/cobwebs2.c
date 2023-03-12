#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

double map(double x, double beta){
    float xn = 0.0;
    xn = beta*(x-x*x);
    return xn;
}

int main(void){

    FILE *file = fopen("cobwebs2.txt", "w");

    if (file == NULL) {
        printf("Error while opeing file.\n");
        return 1;
    }

    printf("See cobwebs2.txt\n");
    double beta = 3.9;
    int iter = 20;
    double xnew, xold = 0.0;

    xold = 0.1;
    xnew = map(xold, beta);
    fprintf(file,"%lf\t%lf\n", xold, 0.0);
    fprintf(file,"%lf\t%lf\n", xold, xnew);
    xold = xnew;
    for (int i = 0; i < iter; i++) { // x += h
        xnew = map(xold, beta);
        fprintf(file,"%lf\t%lf\n", xold, xold);
        fprintf(file,"%lf\t%lf\n", xold, xnew);
        xold = xnew;
    }

    fclose(file);

    return 0;
} 




