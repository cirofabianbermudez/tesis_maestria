/*
 * Author: Ciro Fabian Bermudez Marquez
 * Date: 16/06/2022
 * Desing name: B7_cobwebs.c
 * Description: Grafica para tesis cobwebs.
 * Compile: gcc -o B7_cobwebs.exe B7_cobwebs.c
 * Run: ./B7_cobwebs.exe 4.0 0.2 150
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double map(double x, double r){
    float xn = 0.0;
    xn = r*(x-x*x);
    return xn;
}

int main(int argc, char *argv[]){

    /* Open file */
    char filename[] = "B7_cobwebs.txt";
    FILE *file = fopen(filename, "w");

    /* Check for errors*/
    if (file == NULL) {
        printf("Error while opeing file.\n");
        return 1;
    }

    /* Default r */
    double r = 3.0;
    double ic = 0.2;
    int iter = 150;

    /* Process input */
    if (argc >= 2) {
        r = atof(argv[1]);
    }
    if (argc >= 3) {
        ic = atof(argv[2]);
    }
    if (argc >= 4) {
        iter = atoi(argv[3]);
    }

    if (r == 0.0 || ic == 0.0 || iter == 0) {
        printf("Invalid input, empty %s.", filename);
        fclose(file);
        exit(1);
    }

    printf("See B7_cobwebs.txt\n");
    printf("   r = %5.3lf\n", r);
    printf("  ic = %5.3lf\n", ic);
    printf("iter = %5d\n", iter);

    double xnew, xold = 0.0;
    xold = ic;
    xnew = map(xold, r);
    fprintf(file,"%lf\t%lf\n", xold, 0.0);
    fprintf(file,"%lf\t%lf\n", xold, xnew);
    xold = xnew;

    for (int i = 0; i < iter; i++) { // x += h
        xnew = map(xold, r);
        fprintf(file,"%lf\t%lf\n", xold, xold);
        fprintf(file,"%lf\t%lf\n", xold, xnew);
        xold = xnew;
    }

    fclose(file);

    return 0;
} 
