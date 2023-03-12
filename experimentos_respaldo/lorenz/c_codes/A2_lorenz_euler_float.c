/*
 * Author: Ciro Fabian Bermudez Marquez
 * Date: 16/06/2022
 * Desing name: A2_lorenz_euler_float.c
 * Description: Lorenz oscillator solve with forward euler, for unix and windows
 * Compile: gcc -o A2_lorenz_float.exe A2_lorenz_euler_float.c
 * Run: ./A2_lorenz_float.exe
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){

    // Open file
    FILE *fpointer = fopen("output_lorenz.txt","w");
    
    double sigma = 10.0;
    double beta  = 8.0/3.0;
    double rho   = 28.0;
    double h = 0.005;
    double x0 = 1.0;
    double y0 = 0.0;
    double z0 = 1.0;
    double xn = x0;
    double yn = y0;
    double zn = y0;
    double xni, yni, zni = 0.0;
    int iter = 100000;

    // Initial conditions
    printf(" # x0: %lf\n", x0 );
    printf(" # y0: %lf\n", y0 );
    printf(" # z0: %lf\n", z0 );
    printf(" # iter: %d\n", iter );
    printf(" # lorenz oscillator generated, see output_lorenz.txt\n");
       
    fprintf(fpointer,"%32.29lf\t%32.29lf\t%32.29lf\n",xn, yn,zn);
    for(int i = 0; i < iter; i++){
        xni = xn + h*( sigma*( yn - xn ) );
        yni = yn + h*( xn*( rho - zn ) - yn );
        zni = zn + h*( xn*yn - beta*zn );
        
        xn = xni;            
        yn = yni;
        zn = zni;
        fprintf(fpointer,"%32.29lf\t%32.29lf\t%32.29lf\n",xn, yn,zn);
    }
    
    fclose(fpointer); // Close file
    return 0;
}
