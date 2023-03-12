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

    FILE *file = fopen("cobwebs.txt", "w");

    if (file == NULL) {
        printf("Error while opeing file.\n");
        return 1;
    }

    printf("See cobwebs.txt\n");

    /* double x = 0.0; */
    /* double a = 0.0; */
    /* double b = 1.0; */
    /* double h = 0.001; */
    /* int    n = (b-a)/h + 1; */
    double beta = 3.9;
    int iter = 10;
    double xnew, xold, dx, dy = 0.0;

    xold = 0.1;
    xnew = map(xold, beta);
    fprintf(file,"%lf\t%lf\t%lf\t%lf\n", xold, 0.0, 0.0, xnew);
    fprintf(file,"%lf\t%lf\t%lf\t%lf\n", xold, xnew, xnew-xold, 0.0);
    xold = xnew;
    for (int i = 0; i < iter; i++) { // x += h
        /* fprintf(file, "%12.7lf\t%12.7lf\n", x, map(x, beta)); */
        xnew = map(xold, beta);
        fprintf(file,"%lf\t%lf\t%lf\t%lf\n", xold, xold, 0.0, xnew-xold);
        fprintf(file,"%lf\t%lf\t%lf\t%lf\n", xold, xnew, xnew-xold, 0.0);
        xold = xnew;
    }

    fclose(file);

    return 0;
} 



