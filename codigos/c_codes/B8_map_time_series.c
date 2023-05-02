/*
 * Author: Ciro Fabian Bermudez Marquez
 * Date: 16/06/2022
 * Desing name: B8_map_time_series.c
 * Description: Grafica para tesis cobwebs.
 * Compile: gcc -o B8_map_time_series.exe B8_map_time_series.c
 * Run: ./B8_map_time_series.exe 4.0 0.1 150
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
    char filename[] = "B8_map_time_series.txt";
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

    printf("See B8_map_time_series.txt\n");
    printf("   r = %5.3lf\n", r);
    printf("  ic = %5.3lf\n", ic);
    printf("iter = %5d\n", iter);

    double xnew = 0.0;
    xnew = ic;

    for (int i = 0; i < iter; i++) { // x += h
        fprintf(file,"%5d\t%lf\n", i, xnew);
        xnew = map(xnew, r);
    }

    fclose(file);

    return 0;
} 
