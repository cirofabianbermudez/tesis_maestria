/*
 * Engineer: Ciro Fabian Bermudez Marquez
 * Date: 16/06/2022
 * Desing name: chaotic_map.c
 * Description: Sproot chaotic map simulation using floating point
 * Compile: gcc -o chaotic.exe A2_chaotic_map.c
 * Run: ./chaotic.exe
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){

    // Open file
    FILE *fpointer = fopen("output_chaotic.txt","w");
    
    double ai[12] = {-0.6, -0.1, 1.1, 0.2, -0.8, 0.6, -0.7, 0.7, 0.7, 0.3, 0.6, 0.9};
    double x0 = 0.1;
    double y0 = 0.2;
    double xn = x0;
    double yn = y0;
    double xni = 0.0;
    double yni = 0.0;
    int iter = 100000;

    // Initial conditions
    printf(" # x0: %lf\n", x0 );
    printf(" # y0: %lf\n", y0 );
    printf(" # iter: %d\n", iter );
    printf(" # chaotic map generated,see output_chaotic.txt\n");
       
    fprintf(fpointer,"%32.29lf\t%32.29lf\n",xn, yn);
    for(int i = 0; i < iter; i++){
        xni = ai[0] + ai[1]*xn + ai[2]*xn*xn + ai[3]*xn*yn + ai[4]*yn + ai[5]*yn*yn;
        yni = ai[6] + ai[7]*xn + ai[8]*xn*xn + ai[9]*xn*yn + ai[10]*yn + ai[11]*yn*yn;
        
        xn = xni;            
        yn = yni;
        fprintf(fpointer,"%32.29lf\t%32.29lf\n",xn, yn);
    }
    
    fclose(fpointer); // Close file
    return 0;
}
