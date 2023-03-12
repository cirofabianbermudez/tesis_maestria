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

    FILE *file = fopen("map_form.txt", "w");

    if (file == NULL) {
        printf("Error while opeing file.\n");
        return 1;
    }

    printf("See map_form.txt\n");

    double x = 0.0;
    double a = 0.0;
    double b = 1.0;
    double h = 0.001;
    int    n = (b-a)/h + 1;

    for (int i = 0; i < n; i++, x += h) {
        fprintf(file, "%12.7lf\t%12.7lf\n", x, map(x, 1.0));
    }

    fclose(file);

    return 0;
} 


