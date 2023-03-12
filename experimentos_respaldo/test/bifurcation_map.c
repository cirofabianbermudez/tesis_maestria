#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

double func(double x, double y);

int main(void){

    FILE *file = fopen("bifurcation.txt", "w");

    if (file == NULL) {
        printf("Error while opeing file.\n");
        return 1;
    }

    printf("See bifurcation.txt\n");

    double beta, xnew, xss = 0.0;
    double step = 0.01;

    for (beta = 0.0; beta <= 4.0; beta += step) {
        xnew = 0.5;
        for (int i = 0; i < 2000; i++) {
            xnew = beta*(xnew-xnew*xnew);
            /* xold = xnew; */
        }

        xss = xnew;
        for (int i = 0; i < 1000; i++) {
            xnew = beta*(xnew-xnew*xnew);
            /* xold = xnew; */
            fprintf(file, "%12.7lf\t%12.7lf\n", beta, xnew);
            if (fabs(xnew-xss)<1e-4) {
                break;
            }
        }
    }

    fclose(file);

    return 0;
} 

