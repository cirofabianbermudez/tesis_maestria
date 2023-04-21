/*
 * Author: Ciro Fabian Bermudez Marquez
 * Date: 16/06/2022
 * Desing name: B1_logistic_curve.c
 * Description: Grafica para tesis de curva logistica.
 * Compile: gcc -o B1_logistic_curve.exe B1_logistic_curve.c
 * Run: ./B1_logistic_curve.exe
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double logistic_curve(double x, double A){
    return A*x*(1.0 - x);
}

int main(void){

    FILE *fptr = fopen("B1_logistic_curve.txt","w");

    if (fptr == NULL) {
        printf("Error while opening the file.\n");
        exit(1);
    }

    for (double xn = 0.0; xn <=1.0; xn += 1e-3) {
        fprintf(fptr,"%10.5lf \t%10.5lf\n", xn, logistic_curve(xn,4) );
    }
    
    return 0;
}
