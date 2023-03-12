#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main(void){

    FILE *file = fopen("map.txt", "w");

    if (file == NULL) {
        printf("Error while opeing file.\n");
        return 1;
    }

    printf("See map.txt\n");

    double beta, xnew = 0.0;
    int iter = 50;

    xnew = 0.1;
    beta = 3.0;
    fprintf(file, "%12.7lf\n", xnew);
    for (int i = 0; i < iter; i++) {
        xnew = beta*(xnew-xnew*xnew);
        fprintf(file, "%12.7lf\n", xnew);
    }

    fclose(file);

    return 0;
} 

